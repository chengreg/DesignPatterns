/*****************************************************************************
*  Copyright @ 颐希科技 2023. All rights reserved.                            *
*                                                                            *
*                                                                            *
*                                                                            *
*  @file     ConfigManager.h                                                    *
*  @brief                                                                    *
*                                                                            *
*  @author   陈钢强                                                           *
*  @version  1.0.0.1(版本号)                                                  *
*  @date     2023/8/24 15:39                                                 *
*                                                                            *
*----------------------------------------------------------------------------*
*  Change History :                                                          *
*  <Date>     | <Version> | <Author>       | <Description>                   *
*----------------------------------------------------------------------------*
*  2023/8/24   | 1.0.0.1   | 陈钢强           | Create file                   *
*----------------------------------------------------------------------------*
*                                                                            *
*****************************************************************************/


#ifndef SINGLETON_CONFIGMANAGER_H
#define SINGLETON_CONFIGMANAGER_H


#include <string>
#include <unordered_map>

class ConfigManager {
public:
    static ConfigManager& getInstance();

    std::string get(const std::string& section, const std::string& key);
    void set(const std::string& section, const std::string& key, const std::string& value);

private:
    ConfigManager(); // 私有构造函数
    ConfigManager(const ConfigManager&) = delete; // 阻止复制
    ConfigManager& operator=(const ConfigManager&) = delete; // 阻止赋值

    // Add members for actual config data storage and file access
    std::unordered_map<std::string, std::string> config_data;

};

#endif //SINGLETON_CONFIGMANAGER_H
