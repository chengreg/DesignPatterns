/*****************************************************************************
*  Copyright @ 颐希科技 2023. All rights reserved.                            *
*                                                                            *
*                                                                            *
*                                                                            *
*  @file     SingletonEager.h                                                *
*  @brief    饿汉式                                                           *
*                                                                            *
*  @author   陈钢强                                                           *
*  @version  1.0.0.1(版本号)                                                  *
*  @date     2023/8/24 14:35                                                 *
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

class SingletonEager {
public:
    static SingletonEager& getInstance();

    SingletonEager(const SingletonEager&) = delete;            // Delete copy constructor
    SingletonEager& operator=(const SingletonEager&) = delete; // Delete assignment operator

private:
    SingletonEager() = default;;  // Private constructor
    static SingletonEager instance;
};