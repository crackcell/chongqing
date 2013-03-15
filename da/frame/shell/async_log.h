/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _DA_ASYNCLOG_H_
#define _DA_ASYNCLOG_H_

/**
 * 
 *
 * @file async_log.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Mar 15 14:42:40 2013
 *
 **/

#include "da_error.h"

#define DALOG_BUFF_SIZE 2048

#define DALOG_LEVEL_NONE    0
#define DALOG_LEVEL_FATAL   0x01
#define DALOG_LEVEL_WARN    0x02
#define DALOG_LEVEL_NOTICE  0x04
#define DALOG_LEVEL_TRACE   0x08
#define DALOG_LEVEL_DEBUG   0x10
#define DALOG_LEVEL_ALL     0xff

#define DALOG_FATAL(fmt, arg...)                                        \
    do {                                                                \
        asynclog_send(DALOG_LEVEL_FATAL, "[%s:%s:%d]" fmt, __FILE__,    \
                      __FUNCTION__, __LINE__, ##arg);                   \
    } while(0)

#define DALOG_WARN(fmt, arg...)                                         \
    do {                                                                \
        asynclog_send(DALOG_LEVEL_WARN, "[%s:%s:%d]" fmt, __FILE__,     \
                      __FUNCTION__, __LINE__, ##arg);                   \
    } while(0)

#define DALOG_NOTICE(fmt, arg...)                                       \
    do {                                                                \
        asynclog_send(DALOG_LEVEL_NOTICE, "[%s:%s:%d]" fmt, __FILE__,   \
                      __FUNCTION__, __LINE__, ##arg);                   \
    } while(0)

#define DALOG_TRACE(fmt, arg...)                                        \
    do {                                                                \
        asynclog_send(DALOG_LEVEL_TRACE, "[%s:%s:%d]" fmt, __FILE__,    \
                      __FUNCTION__, __LINE__, ##arg);                   \
    } while(0)

#ifdef _DEBUG
#define DALOG_DEBUG(fmt, arg...)                                        \
    do {                                                                \
        asynclog_send(DALOG_LEVEL_DEBUG, "[%s:%s:%d]" fmt, __FILE__,    \
                      __FUNCTION__, __LINE__, ##arg);                   \
    } while(0)
#else
#define DALOG_DEBUG(fmt, arg...) do {} while(0)
#endif

int asynclog_send(const char *log_name, const int event,
                     const char *format, ...);

#endif /* _ASYNCLOG_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
