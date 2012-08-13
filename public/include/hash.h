/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2012, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _HASH_H_
#define _HASH_H_

/**
 * Hash
 *
 * @file hash.h
 * @author Tan Menglong <tanmenglong@gmail.com>
 * @date Mon Aug 13 15:18:26 2012
 *
 **/

#include <stdint.h>

typedef struct {
    size_t bucket_count;
} Hash;

#endif /* _HASH_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
