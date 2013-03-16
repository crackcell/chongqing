/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _DA_CONF_H_
#define _DA_CONF_H_

/**
 * 
 *
 * @file da_conf.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Mar  3 16:05:45 2013
 *
 **/

#include <linux/limits.h>

struct da_conf {
    char work_path[PATH_MAX];
    char conf_file[NAME_MAX];

    int log_level;
    char log_name[NAME_MAX];
    char log_path[PATH_MAX];

    int dacore_thread_num;
};

#endif /* _DA_CONF_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
