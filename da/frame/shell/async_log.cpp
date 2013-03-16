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
 * @file asynclog.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Mar 15 14:54:34 2013
 *
 **/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

#include <zhuhai/zh_thread.h>
#include <zhuhai/zh_time.h>

#include "da_error.h"
#include "async_log.h"
#include "global_data.h"

#define STRING_FATAL   "FATAL"
#define STRING_WARN    "WARNING"
#define STRING_NOTICE  "NOTICE"
#define STRING_TRACE   "TRACE"
#define STRING_DEBUG   "DEBUG"
#define STRING_NONE    "NONE"

using namespace std;

#define DALOG_MSG_COOKIE "dalogmsg"

static da_ret_t __vwritelog(char *buff, size_t size, const char *log_name,
                            pid_t tid, const int event,
                            const char *fmt, va_list args);

int asynclog_send(const char *log_name, const int event,
                  const char *fmt, ...) {
    if (NULL == log_name || event <= DALOG_LEVEL_NONE ||
        event > DALOG_LEVEL_DEBUG || NULL == fmt) {
        fprintf(stderr, "asynclog_send() fails: invalid parameters\n");
        return DA_FAIL;
    }

    char buff[DALOG_BUFF_SIZE];
    int ret;
    pid_t tid = zh_gettid();
    va_list args;
    va_start(args, fmt);
    ret = __vwritelog(buff, sizeof(buff), log_name, tid, event, fmt, args);
    va_end(args);

    if (DA_FAIL == ret) {
        fprintf(stderr, "__vwritelog() fails\n");
        return DA_FAIL;
    }

    struct dalog_msg msg;
    msg.cookie = DALOG_MSG_COOKIE;
    msg.level = event;
    msg.text = buff;

    if (0 == g_thr_logger_num ||
        !g_logger_queue.try_push(msg)) {
        fprintf(stderr, "%s\n", buff);
    }

    return DA_SUCC;
}

da_ret_t __vwritelog(char *buff, size_t buff_size, const char *log_name,
                     pid_t tid, const int event,
                     const char *fmt, va_list args) {
    if (NULL == buff || 0 == buff_size || NULL == log_name) {
        return DA_FAIL;
    }

    char time_buff[ZH_TIME_BUFF_SIZE];
    zh_ctime(time_buff, sizeof(time_buff));

    switch (event) {
    case DALOG_LEVEL_FATAL:
        memcpy(buff, STRING_FATAL, strlen(STRING_FATAL) + 1);
        break;
    case DALOG_LEVEL_WARN:
        memcpy(buff, STRING_WARN, strlen(STRING_WARN) + 1);
        break;
    case DALOG_LEVEL_NOTICE:
        memcpy(buff, STRING_NOTICE, strlen(STRING_NOTICE) + 1);
        break;
    case DALOG_LEVEL_TRACE:
        memcpy(buff, STRING_TRACE, strlen(STRING_TRACE) + 1);
        break;
    case DALOG_LEVEL_DEBUG:
        memcpy(buff, STRING_DEBUG, strlen(STRING_DEBUG) + 1);
        break;
    default:
        memcpy(buff, STRING_NONE, strlen(STRING_NONE) + 1);
        break;
    }

    size_t bpos = 0;
    bpos += strlen(buff);
    bpos += snprintf(&buff[bpos], buff_size - bpos, " %s: %s * %d ",
                     time_buff, log_name, tid);
    vsnprintf(&buff[bpos], buff_size - bpos, fmt, args);

    return DA_SUCC;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
