/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _GLOBAL_DATA_H_
#define _GLOBAL_DATA_H_

/**
 * 
 *
 * @file global_data.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Mon Mar  4 00:39:48 2013
 *
 **/

#include <string>

#include <tbb/concurrent_queue.h>
#include <tbb/atomic.h>

#include "da_conf.h"

extern struct da_conf g_conf;

typedef struct dalog_msg {
    std::string cookie;
    int level;
    std::string text;
} dalog_msg_t;

extern volatile int g_thr_logger_num;
extern tbb::concurrent_bounded_queue<dalog_msg_t> g_logger_queue;

extern volatile int g_thr_core_num;
extern volatile int g_exit;

#endif /* _GLOBAL_DATA_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
