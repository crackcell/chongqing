/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2012, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _CRAWLER_CONF_H_
#define _CRAWLER_CONF_H_

/**
 * 
 *
 * @file conf.h
 * @author Tan Menglong <tanmenglong@gmail.com>
 * @date Sun Dec 30 08:15:11 2012
 *
 **/

#include <stdint.h>

#define CRAWLER_NAME_SIZE 32
#define MAX_FILEPATH 1024
#define MAX_FILENAME 256

typedef struct {
    #define CRAWLER_NAME_DFT "unnamed_crawler"
    char crawler_name[CRAWLER_NAME_SIZE + 1];

    #define CONF_PATH_DFT "./conf"
    char conf_path[MAX_FILEPATH + 1];

    #define CONF_FILE_DFT "crawler.conf"
    char conf_file[MAX_FILENAME + 1];

    #define LOG_PATH_DFT "./log"
    char log_path[MAX_FILEPATH + 1];

    #define LOG_NAME_DFT "crawler"
    char log_name[MAX_FILENAME + 1];

    #define LOG_LEVEL_LOW  1
    #define LOG_LEVEL_HIGH 16
    #define LOG_LEVEL_DFT  16
    int log_level;

    #define MASTER_THR_NUM_DFT 1
    int master_thr_num;

    #define WORKER_THR_NUM_DFT 1
    int worker_thr_num;
} crawler_conf_t;

int load_static_conf(crawler_conf_t *conf_ptr);

#endif /* _CRAWLER_CONF_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
