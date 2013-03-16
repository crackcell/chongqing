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
 * @file da_logger.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Mar 15 22:38:21 2013
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

#include <string>
#include <tbb/tbb_exception.h>

#include "../shell/global_data.h"
#include "../shell/async_log.h"
#include "da_logger.h"

using namespace std;
using namespace tbb;

void *da_logger(void *arg) {
    pthread_detach(pthread_self());

    FILE *fp = NULL;
    FILE *fp_wf = NULL;
    dalog_msg_t msg;

    char buff[PATH_MAX];
    snprintf(buff, sizeof(buff), "%s/%s.log", g_conf.log_path, g_conf.log_name);
    buff[sizeof(buff) - 1] = '\0';

    fp = fopen(buff, "a+");
    if (NULL == fp) {
        DALOG_FATAL("da_logger", "open log file fail");
        goto quit;
    }
    setbuf(fp, NULL);

    snprintf(buff, sizeof(buff), "%s/%s.log.wf", g_conf.log_path,
             g_conf.log_name);
    fp_wf = fopen(buff, "a+");
    if (NULL == fp_wf) {
        DALOG_FATAL("da_logger", "open log file fail");
        goto quit;
    }
    setbuf(fp_wf, NULL);

    g_thr_logger_num++;
    while (1) {
        try {
            g_logger_queue.pop(msg);
            // TODO: log cache
            if (msg.level <= DALOG_LEVEL_WARN) {
                fprintf(fp_wf, "in logger: %s\n", msg.text.c_str());
            } else {
                fprintf(fp, "in logger: %s\n", msg.text.c_str());
            }
        } catch (user_abort &e) {
            while (g_logger_queue.size() > 0) {
                if (g_logger_queue.try_pop(msg)) {
                    // TODO: log cache
                    if (msg.level <= DALOG_LEVEL_WARN) {
                        fprintf(fp_wf, "in logger: %s\n", msg.text.c_str());
                    } else {
                        fprintf(fp, "in logger: %s\n", msg.text.c_str());
                    }
                }
            }
            break;
        }
    }

quit:
    if (fp != NULL) {
        fclose(fp);
    }
    if (fp_wf != NULL) {
        fclose(fp_wf);
    }
    g_thr_logger_num = 0;

    return NULL;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
