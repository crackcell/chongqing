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
 * @file da_detect.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sat Mar 16 03:39:12 2013
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "../shell/async_log.h"
#include "../shell/global_data.h"

#define SLEEP_SEC 2

void *da_detect(void *arg) {
    int i = 0;
    int exit;
    while ((exit = g_exit.compare_and_swap(1, 1)) != 1) {
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
    int thr_logger_num;
    while ((thr_logger_num = g_thr_logger_num.compare_and_swap(0, 0)) > 0) {
        sleep(SLEEP_SEC);
    }

    DALOG_DEBUG("da_detect", "all threads quit");

    return NULL;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
