/*****************************************************************************
*  Copyright @ 颐希科技 2023. All rights reserved.                            *
*                                                                            *
*                                                                            *
*                                                                            *
*  @file     SingletonLazy.h                                                    *
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


#pragma once
#include <mutex>

class SingletonLazy {
public:
    static SingletonLazy& getInstance();

    SingletonLazy(const SingletonLazy&) = delete;            // Delete copy constructor
    SingletonLazy& operator=(const SingletonLazy&) = delete; // Delete assignment operator

private:
    SingletonLazy() = default;; // Private constructor
    static void initSingleton();

    static std::once_flag initInstanceFlag;
    static SingletonLazy* instance;
};