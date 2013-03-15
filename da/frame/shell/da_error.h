/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _DA_ERROR_H_
#define _DA_ERROR_H_

/**
 * 
 *
 * @file da_error.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Mar 15 15:05:29 2013
 *
 **/

typedef enum da_ret {
    DA_SUCC,
    DA_FAIL
} da_ret_t;

char *da_strerror(int errnum);

#endif /* _DA_ERROR_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
