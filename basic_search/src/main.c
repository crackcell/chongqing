/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2012, crackcell <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

/**
 * index_builder
 *
 * @file main.c
 * @author crackcell <tanmenglong@gmail.com>
 * @date Wed Aug  8 13:51:29 2012
 *
 **/

#include <stdio.h>
#include <unistd.h>

#include "version.h"

inline static void print_usage(const char *name) {
    printf("Usage:\n");
    printf("%s [options]\n", name);
    printf("    options:\n"
           "        -d working path\n"
           "        -c config file path related to working path\n"
           "        -v print the version\n"
           "        -h print this help message\n");
}

int main(int argc, char *argv[]) {
    const char *work_path = NULL;
    const char *conf_file = NULL;
    char arg;
    while ((arg = getopt(argc, argv, "d:c:vh")) != -1) {
        switch (arg) {
        case 'd':
            work_path = optarg;
            break;
        case 'c':
            conf_file = optarg;
        case 'v':
            print_version();
            return 0;
        case 'h':
        default:
            print_usage(argv[0]);
            return 0;
        }
    }
    if (NULL == work_path || NULL == conf_file) {
        print_usage(argv[0]);
        return 0;
    }

    return 0;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
