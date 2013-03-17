/* -*- encoding: utf-8; indent-tabs-mode: nil -*- */

/***************************************************************
 *
 * Copyright (c) 2013, Tan Menglong <tanmenglong@gmail.com>
 *
 * This program is free software; you can redistribute it
 * and/or modify it under the terms of the GPL licence
 *
 **************************************************************/

#ifndef _DA_COMPONENT_H_
#define _DA_COMPONENT_H_

/**
 * 
 *
 * @file component.h
 * @author Menglong TAN <tanmenglong@gmail.com>
 * @date Sun Mar 17 08:15:13 2013
 *
 **/

#include <string.h>
#include "dapub/da_pub.h"

DA_NS("da")

class Component {
public:
    std::string name;

    Component();
    virtual ~Component();
};

DA_BS_END

#endif /* _DA_COMPONENT_H_ */

/* vim: set expandtab shiftwidth=4 tabstop=4: */
