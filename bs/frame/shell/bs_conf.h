/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _BS_CONF_H_
#define _BS_CONF_H_

/**
 * 
 *
 * @file bs_conf.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Mar  3 16:05:45 2013
 *
 **/

#include <linux/limits.h>

struct bs_conf {
    char work_path[PATH_MAX];
    char conf_file[NAME_MAX];
};

#endif /* _BS_CONF_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
