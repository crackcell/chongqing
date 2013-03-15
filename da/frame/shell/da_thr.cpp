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
 * @file da_thr.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Mar 15 00:14:21 2013
 *
 **/

#include <log4cxx/logger.h>

#include "global_data.h"
#include "da_thr.h"

void* da_log(void *arg);
void* da_detect(void *arg);
void* da_core(void *arg);


/* vim: set expandtab shiftwidth=4 tabstop=4: */
