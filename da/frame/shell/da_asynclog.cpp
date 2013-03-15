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
 * @file da_asynclog.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Mar 15 14:54:34 2013
 *
 **/

#include <stdio.h>
#include <stdarg.h>
#include <zhuhai/zh_time.h>

#include "da_error.h"
#include "da_asynclog.h"

static da_ret_t __vwritelog(char *buff, size_t size,
                            const int event, const char *fmt, va_list args);

int da_asynclog_send(const int event, const char *fmt, ...) {
    if (event < 0 || event > DALOG_LEVEL_DEBUG || NULL == fmt) {
        fprintf(stderr, "da_asynclog_send() fails: invalid parameters\n");
        return DA_FAIL;
    }

    char buff[DALOG_BUFF_SIZE];
    int ret;
    va_list args;
    va_start(args, fmt);
    ret = __vwritelog(buff, sizeof(buff), event, fmt, args);
    va_end(args);

    if (DA_FAIL == ret) {
        fprintf(stderr, "__vwritelog() fails\n");
        return DA_FAIL;
    }

    return DA_SUCC;
}

da_ret_t __vwritelog(char *buff, size_t size,
                     const int event, const char *fmt, va_list args) {
    if (NULL == buff || 0 == size) {
        return DA_FAIL;
    }

    //char time_buff[ZH_TIME_BUFF_SIZE];

    return DA_SUCC;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
