/*****************************************************************************
*  Copyright @ 颐希科技 2023. All rights reserved.                            *
*                                                                            *
*                                                                            *
*                                                                            *
*  @file     main.cpp                                                    *
*  @brief                                                                    *
*                                                                            *
*  @author   陈钢强                                                           *
*  @version  1.0.0.1(版本号)                                                  *
*  @date     2023/8/24 13:21                                                 *
*                                                                            *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2023/8/24   | 1.0.0.1   | 陈钢强           | Create file                   *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/
#include <iostream>
#include <thread>
#include <vector>
#include "SingletonEager.h"
#include "SingletonLazy.h"
#include "inicpp.hpp"

void threadFuncLazy() {
    SingletonLazy& instance = SingletonLazy::getInstance();
    std::cout << "Lazy Instance address from thread " << std::this_thread::get_id() << ": " << &instance << std::endl;
}

void test_SingletonEager_SingletonLazy()
{
    /********************************************************************************
 * 饿汉式
********************************************************************************/
    std::cout << "*************************************************************************************************" << std::endl;

    SingletonEager& eagerInstance1 = SingletonEager::getInstance();
    SingletonEager& eagerInstance2 = SingletonEager::getInstance();

    std::cout << "eagerInstance1 = %x" << &eagerInstance1 << "\teagerInstance2 = %x" << &eagerInstance2 << std::endl;
    if (&eagerInstance1 == &eagerInstance2) {
        std::cout << "Both references point to the same instance (Eager)." << std::endl;
    } else {
        std::cout << "Different instances (Eager)." << std::endl;
    }
    std::cout << "*************************************************************************************************" << std::endl;
    /********************************************************************************
     *  懒汉式
    ********************************************************************************/
    SingletonLazy& lazyInstance1 = SingletonLazy::getInstance();
    SingletonLazy& lazyInstance2 = SingletonLazy::getInstance();

    std::cout << "lazyInstance1 = %x" << &lazyInstance1 << "\tlazyInstance2 = %x" << &lazyInstance2 << std::endl;
    if (&lazyInstance1 == &lazyInstance2) {
        std::cout << "Both references point to the same instance (Lazy)." << std::endl;
    } else {
        std::cout << "Different instances (Lazy)." << std::endl;
    }
    std::cout << "*************************************************************************************************" << std::endl;

    /********************************************************************************
     * 多线程测试懒汉式
    ********************************************************************************/
    const int NUM_THREADS = 10; // 你可以根据需要调整线程数量
    std::vector<std::thread> threads;

    threads.reserve(NUM_THREADS); // 预分配容量
    // 启动多个线程
    for (int i = 0; i < NUM_THREADS; ++i) {
        threads.emplace_back(threadFuncLazy);
    }

    // 等待所有线程完成
    for (auto& th : threads) {
        th.join();
    }
}

void test_inicpp()
{
    inicpp::IniManager _ini("config.ini");
    std::cout << _ini["General"]["ServerName"] << std::endl;
}

int main()
{

    test_inicpp();


    return 0;
}