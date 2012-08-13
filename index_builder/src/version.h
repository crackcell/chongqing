/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2012, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _VERSION_H_
#define _VERSION_H_

/**
 * Module version info
 *
 * @file version.h
 * @author Tan Menglong <tanmenglong@gmail.com>
 * @date Sat Jun  2 13:25:29 2012
 *
 **/

#include <stdio.h>

/* version */
#ifdef __VERSION_ID__
static const char *version_id = __VERSION_ID__;
#else
static const char *version_id = "unknown";
#endif

/* date of building */
#if defined(__DATE__) && defined(__TIME__)
static const char server_built[] = __DATE__ " " __TIME__;
#else
static const char server_built[] = "unknown";
#endif

inline void print_version_info(void) {
    printf(" Version\t: %s\n", version_id);
    printf(" Built date\t: %s\n", server_built);
}

inline void print_usage(void) {
    printf("\nUsage:\n"
           "index_builder -d  config file path\n"
           "              -f  config file name\n"
           "              -v  print the version\n"
           "              -h  print this help message\n"
}

#endif /* _VERSION_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
