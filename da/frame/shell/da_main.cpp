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

#include "async_log.h"
#include "global_data.h"
#include "../threads/da_logger.h"

int da_main() {
    pthread_t logger_id;
    if (pthread_create(&logger_id, NULL, da_logger, NULL)) {
        DALOG_FATAL("da_main", "create logger thread fail");
        return DA_FAIL;
    }
    g_thr_logger_num = 1;
    return 0;
}


/* vim: set expandtab shiftwidth=4 tabstop=4: */