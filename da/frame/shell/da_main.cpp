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

#include <zhuhai/zh_conf.h>

#include "async_log.h"
#include "global_data.h"
#include "../threads/da_detect.h"
#include "../threads/da_logger.h"

#define SLEEP_SEC 2

static int __init_global() {
    g_thr_logger_num = 0;

    g_thr_core_num = 0;
    g_exit = 0;

    return DA_SUCC;
}

static int __load_conf() {
    zh_conf_t *conf = zh_conf_open(g_conf.work_path, g_conf.conf_file);
    if (NULL == conf) {
        DALOG_FATAL("da_main", "open conf fail");
        return DA_FAIL;
    }

    /***************************************************************/
    // log
    if (ZH_FAIL == zh_conf_get(conf, "log_level", &g_conf.log_level)) {
        DALOG_FATAL("da_main", "read conf fail: no log_level");
        goto error;
    }
    DALOG_DEBUG("da_main", "log_level : %d", g_conf.log_level);

    if (ZH_FAIL == zh_conf_get_str(conf, "log_name", g_conf.log_name,
                                   sizeof(g_conf.log_name))) {
        DALOG_FATAL("da_main", "read conf fail: no log_name");
        goto error;
    }
    DALOG_DEBUG("da_main", "log_name : %s", g_conf.log_name);

    if (ZH_FAIL == zh_conf_get_str(conf, "log_path", g_conf.log_path,
                                   sizeof(g_conf.log_path))) {
        DALOG_FATAL("da_main", "read conf fail: no log_path");
        goto error;
    }
    DALOG_DEBUG("da_main", "log_path : %s", g_conf.log_path);

    return DA_SUCC;
error:
    if (conf != NULL) {
        zh_conf_close(conf);
    }
    return DA_FAIL;
}

int da_main() {
    if (DA_FAIL == __init_global()) {
        return DA_FAIL;
    }

    if (DA_FAIL == __load_conf()) {
        return DA_FAIL;
    }

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

    while (g_thr_logger_num != 1) {
        sleep(1);
    }

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
