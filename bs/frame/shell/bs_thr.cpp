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
 * @file bs_detect.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Mar  3 16:42:11 2013
 *
 **/

#include <stdio.h>
#include <unistd.h>

__thread pid_t tid;

void *bs_detect(void *arg) {
    //tid = gettid();
    return NULL;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
