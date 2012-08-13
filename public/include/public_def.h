/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2012, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _PUBLIC_DEF_H_
#define _PUBLIC_DEF_H_

/**
 * Public definitions used in headers
 *
 * @file public_def.h
 * @author Tan Menglong <tanmenglong@gmail.com>
 * @date Sat Jun  2 07:24:28 2012
 *
 **/

#include <stdint.h>
#include <stdlib.h>

#define RET_SUCC 0
#define RET_FAIL 1

#define PAKHAR_CACHE_LINE_SIZE 64
#define PAKHAR_CACHE_LINE_ALIGN_SIZE(SZ) \
    (((((SZ) - 1) / PAKHAR_CACHE_LINE_SIZE) + 1) * PAKHAR_CACHE_LINE_SIZE)

#endif /* _PUBLIC_DEF_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
