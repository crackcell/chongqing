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
 * Index builder
 *
 * @file index.c
 * @author crackcell <tanmenglong@gmail.com>
 * @date Sat Jun  2 08:02:47 2012
 *
 **/

#include "index.h"

#include <string.h>

int InitTermDict(struct TermDict *term_dict_ptr) {
    if (NULL == term_dict_ptr) {
        return RET_FAIL;
    }

    term_dict_ptr->term_count = 0;

    return RET_SUCC;
}

int DestoryTermDict(struct TermDict *term_dict_ptr) {
    if (NULL == term_dict_ptr) {
        return RET_FAIL;
    }

    return RET_SUCC;
}

int AddPostingToDict(struct TermDict *term_dict_ptr,
                     const uint64_t term_id,
                     const struct Posting *posting_ptr) {
    if (NULL == term_dict_ptr || NULL == posting_ptr) {
        return RET_FAIL;
    }

    return RET_SUCC;
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
