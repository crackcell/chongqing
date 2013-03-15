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

struct da_conf g_conf;

tbb::atomic<int> g_thr_logger_num;
tbb::concurrent_bounded_queue<std::string> g_logger_queue;

extern tbb::atomic<int> g_thr_core_num;
extern tbb::atomic<int> g_exit;

/* vim: set expandtab shiftwidth=4 tabstop=4: */
