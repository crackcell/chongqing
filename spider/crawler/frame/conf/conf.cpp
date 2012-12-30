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
 * @file conf.cpp
 * @author Tan Menglong <tanmenglong@gmail.com>
 * @date Sun Dec 30 11:02:12 2012
 *
 **/

#include <zhuhai/zh_conf.h>
#include <zhuhai/zh_log.h>
#include <pub/crawler_pub.h>

#include "conf.h"

#define GET_CONF_INT_DFT(conf, key, v, dft)                             \
    do {                                                                \
        if (ZH_FAIL == zh_conf_get((conf), (key), (v), (dft))) {        \
            ZH_WARN("get conf fail for key[" key "], use dft[%d]",      \
                    dft);                                               \
        }                                                               \
    } while(0);

#define GET_CONF_STR_DFT(conf, key, buff, dft)                          \
    do {                                                                \
        if (ZH_FAIL == zh_conf_get_str((conf), (key), (buff),           \
                                       sizeof((buff)),(dft))) {         \
            ZH_WARN("get conf fail for key[" key "], use dft[" dft "]"); \
        }                                                               \
    } while(0);

int load_static_conf(crawler_conf_t *conf_ptr) {
    if (NULL == conf_ptr) {
        return CR_FAIL;
    }

    zh_conf_t *c = zh_conf_open(conf_ptr->conf_path, conf_ptr->conf_file);
    if (NULL == c) {
        ZH_FATAL("zh_conf_open fail");
        goto err;
    }

    GET_CONF_STR_DFT(c, "crawler_name", conf_ptr->crawler_name,
                     CRAWLER_NAME_DFT);

    GET_CONF_STR_DFT(c, "log_path", conf_ptr->log_path, LOG_PATH_DFT);
    GET_CONF_INT_DFT(c, "log_level", &(conf_ptr->log_level), LOG_LEVEL_DFT);

    GET_CONF_INT_DFT(c, "master_thr_num", &(conf_ptr->master_thr_num),
                     MASTER_THR_NUM_DFT);
    GET_CONF_INT_DFT(c, "worker_thr_num", &(conf_ptr->worker_thr_num),
                     WORKER_THR_NUM_DFT);

    if (c != NULL) {
        zh_conf_close(c);
    }
    return CR_SUCC;
err:
    if (c != NULL) {
        zh_conf_close(c);
    }
    return CR_FAIL;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
