/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2012, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _INDEX_H_
#define _INDEX_H_

/**
 * Index formats definations
 *
 * @file index.h
 * @author Tan Menglong <tanmenglong@gmail.com>
 * @date Mon Aug  6 19:57:33 2012
 *
 **/

#include <stdint.h>

#include "public_def.h"

struct Posting {
    uint32_t weight;
    uint32_t freq;
    uint64_t offset;

    /* cache line alignment */
    uint8_t cache_line_align[PAKHAR_CACHE_LINE_ALIGN_SIZE(sizeof(uint32_t) +
                                                          sizeof(uint32_t) +
                                                          sizeof(uint64_t))];
};

struct PostingEntry {
    uint64_t term_id;
    //    std::priority_queue<Posting> *posting_data_ptr;

    /* cache line alignment */
    uint8_t cache_line_align[PAKHAR_CACHE_LINE_ALIGN_SIZE(sizeof(uint64_t) +
                                                          sizeof(void*))];
};

int AddPostingToEntry(struct PostingEntry *posting_entry_ptr,
                      struct Posting *posting_ptr);

struct TermDict {
    size_t term_count;
    //    std::map<uint64_t, PostingEntry> *posting_entry_map_ptr;
};

int InitTermDict(struct TermDict *term_dict_ptr);

int DestoryTermDict(struct TermDict *term_dict_ptr);

int AddPostingToDict(struct TermDict *term_dict_ptr,
                     const uint64_t term_id,
                     const struct Posting *posting_ptr);

#endif /* _INDEX_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
