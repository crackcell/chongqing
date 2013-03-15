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

void *da_detect(void *arg) {
    pthread_detach(pthread_self());

    return NULL;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
