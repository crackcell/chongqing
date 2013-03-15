/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

/**
 * 
 *
 * @file da_main.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Mar  3 16:30:30 2013
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "async_log.h"
#include "global_data.h"
#include "../threads/da_detect.h"
#include "../threads/da_logger.h"

#define SLEEP_SEC 2

int da_main() {
    pthread_t logger_id;
    if (pthread_create(&logger_id, NULL, da_logger, NULL)) {
        DALOG_FATAL("da_main", "create logger thread fail");
        return DA_FAIL;
    }

    pthread_t detect_id;
    if (pthread_create(&detect_id, NULL, da_detect, NULL)) {
        DALOG_FATAL("da_main", "create detect thread fail");
        return DA_FAIL;
    }

    g_thr_logger_num = 1;
    g_exit = 0;

    int i = 0;
    while (g_exit != 1) {
        if (i == 2) {
            break;
        }
        DALOG_NOTICE("da_detect", "i: %d", i);
        sleep(SLEEP_SEC);
        i++;
    }

    // destroy logger
    g_logger_queue.abort();

    // wait workers to quit
    while (g_thr_logger_num > 0) {
        sleep(SLEEP_SEC);
    }

    DALOG_DEBUG("da_main", "all threads quit");

    return 0;
}


/* vim: set expandtab shiftwidth=4 tabstop=4: */
