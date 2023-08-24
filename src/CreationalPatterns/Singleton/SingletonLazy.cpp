/*****************************************************************************
*  Copyright @ 颐希科技 2023. All rights reserved.                            *
*                                                                            *
*                                                                            *
*                                                                            *
*  @file     SingletonLazy.cpp                                                    *
*  @brief                                                                    *
*                                                                            *
*  @author   陈钢强                                                           *
*  @version  1.0.0.1(版本号)                                                  *
*  @date     2023/8/24 14:36                                                 *
*                                                                            *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2023/8/24   | 1.0.0.1   | 陈钢强           | Create file                   *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/


#include "SingletonLazy.h"

std::once_flag SingletonLazy::initInstanceFlag;
SingletonLazy* SingletonLazy::instance = nullptr;

SingletonLazy& SingletonLazy::getInstance() {
    std::call_once(initInstanceFlag, &SingletonLazy::initSingleton);
    return *instance;
}

void SingletonLazy::initSingleton() {
    instance = new SingletonLazy();
}