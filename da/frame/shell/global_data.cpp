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
 * @file global_data.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Mon Mar  4 00:40:38 2013
 *
 **/

#include "global_data.h"

using namespace tbb;

struct da_conf g_conf;

volatile int g_thr_logger_num;
concurrent_bounded_queue<dalog_msg_t> g_logger_queue;

volatile int g_thr_core_num;
volatile int g_exit;

/* vim: set expandtab shiftwidth=4 tabstop=4: */
