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
 * @file main.cpp
 * @author Tan Menglong <tanmenglong@gmail.com>
 * @date Thu Dec 20 03:37:28 2012
 *
 **/

#include <unistd.h>
#include <signal.h>
#include <zhuhai/zh_log.h>
#include <zhuhai/zh_conf.h>

#include <pub/crawler_pub.h>

#include "version.h"

#define ARG_BUFF_SIZE 1024
#define MAX_CONF_ITEM_NUM 1024
#define MAX_CONF_BUFF_SIZE 1024

crawler_conf_t g_conf;

#define GET_CONF_STR_DFT(conf, key, buff, dft)                          \
    do {                                                                \
        if (ZH_FAIL == zh_conf_get_str((conf), (key), (buff),           \
                                       sizeof((buff)),(dft))) {         \
            ZH_WARN("get conf fail for key[" key "], use dft[" dft "]"); \
        }                                                               \
    } while(0);

int load_conf(crawler_conf_t *conf_ptr) {
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

void work() {
    while (1) {
        sleep(100000);
    }
}

int main(int argc, char *argv[]) {

    char conf_buff[ARG_BUFF_SIZE];
    conf_buff[0] = '\0';
    int init_flags = 0;

    int c = 0;
    while ((c = getopt(argc, argv, "d:f:hv")) != -1) {
        switch (c) {
        case 'd':
            snprintf(g_conf.conf_path, sizeof(g_conf.conf_path), "%s", optarg);
            g_conf.conf_path[sizeof(g_conf.conf_path) - 1] = '\0';
            init_flags |= 0x01;
            break;
        case 'f':
            snprintf(g_conf.conf_file, sizeof(g_conf.conf_file), "%s", optarg);
            g_conf.conf_file[sizeof(g_conf.conf_file) - 1] = '\0';
            init_flags |= 0x02;
            break;
        case 'v':
            show_version();
            goto err;
        case 'h':
        default:
            show_help();
            goto err;
        }
    }

    if (!((init_flags & 0x01) && (init_flags & 0x02))) {
        show_help();
        goto err;
    }

    if (CR_FAIL == load_conf(&g_conf)) {
        ZH_FATAL("load_conf fail");
        goto err;
    }

    signal(SIGPIPE, SIG_IGN);

    //work();

    return 0;
err:

    return 1;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
