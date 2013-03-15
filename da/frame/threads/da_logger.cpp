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
#include "da_logger.h"

using namespace std;
using namespace tbb;

void *da_logger(void *arg) {
    pthread_detach(pthread_self());

    dalog_msg_t msg;
    while (1) {
        try {
            g_logger_queue.pop(msg);
            fprintf(stderr, "in logger: %s\n", msg.text.c_str());
        } catch (user_abort &e) {
            g_thr_logger_num.fetch_and_decrement();
        }
    }
    return NULL;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
