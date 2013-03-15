/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

/**
 * 
 *
 * @file da_asynclog_unittest.cpp
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Fri Mar 15 20:36:47 2013
 *
 **/

#include <stdio.h>
#include <gtest/gtest.h>
#include <frame/shell/async_log.h>

TEST(asynclog_test, asynclog_send) {
    ASSERT_EQ(DA_SUCC, asynclog_send("unittest", DALOG_LEVEL_NOTICE, "test"));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

/* vim: set expandtab shiftwidth=4 tabstop=4: */
