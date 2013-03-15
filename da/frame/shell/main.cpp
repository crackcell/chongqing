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
 * @file main.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Mar  3 15:42:00 2013
 *
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <signal.h>

#include "global_data.h"
#include "da_main.h"
#include "version.h"

void getopts(int argc, char *argv[]) {
    const char *work_path = NULL;
    const char *conf_file = NULL;

    struct option long_options[] = {
        //{"debug",    0, &g_conf.debug, 0},
        {"work_path",  1, NULL,          'd'},
        {"config",     1, NULL,          'f'},
        {"help",       0, NULL,          'h'},
        {"version",    0, NULL,          'v'},
    };
    char c;
    int option_index = 0;
    while ((c = getopt_long(argc, argv, "d:f:hv", long_options,
                            &option_index)) != -1) {
        switch (c) {
        case 0:
            //printf ("option %s", long_options[option_index].name);
            break;
        case 'd':
            work_path = optarg;
            break;
        case 'f':
            conf_file = optarg;
            break;
        case 'h':
            show_help();
            break;
        case 'v':
            show_version();
            break;
        default:
            exit(1);
            break;
        }
    }

    if (NULL == work_path || NULL == conf_file) {
        show_help();
        exit(1);
    }

    snprintf(g_conf.work_path, sizeof(g_conf.work_path), "%s", work_path);
    snprintf(g_conf.conf_file, sizeof(g_conf.conf_file), "%s", conf_file);
}

int main(int argc, char *argv[]) {
    bzero(&g_conf, sizeof(g_conf));
    getopts(argc, argv);

    signal(SIGPIPE,SIG_IGN);

    return da_main();
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
