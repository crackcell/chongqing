/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2012, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

/**
 * 
 *
 * @file version.cpp
 * @author Tan Menglong <tanmenglong@gmail.com>
 * @date Thu Dec 20 06:42:17 2012
 *
 **/

#include "version.h"

#include <stdio.h>

#ifdef __MODULE__
const char *g_module = __MODULE__;
#else
const char *g_module = "unknown";
#endif

#ifdef __VERSION_ID__
const char *g_version_id = __VERSION_ID__;
#else
const char *g_version_id = "unknown";
#endif

#if defined(__DATE__) && defined(__TIME__)
const char *g_built_date = __DATE__ " " __TIME__;
#else
const char *g_built_date = "unknown";
#endif

void show_help() {
    printf("Module: %s\n", g_module);
    printf("Usage: crawler -d -f -h -v\n");
    printf("\t-d\tworking path\n");
    printf("\t-f\tconf file\n");
    printf("\t-h\tshow help info\n");
    printf("\t-v\tshow version info\n");
    printf("\n");
}

void show_version() {
    printf("Module: %s\n", g_module);
    printf("Version: %s\n", g_version_id);
    printf("Built date: %s\n", g_built_date);
    printf("\n");
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
