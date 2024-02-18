#pragma once  // 防止头文件被重复包含

#include "mprpcconfig.h"
#include "mprpcchannel.h"
#include "mprpccontroller.h"

// mprpc框架的基础类,负责框架的一些初始化操作
class MprpcApplication // 单例模式
{
public:
    static void Init(int argc, char** argv);
    static MprpcApplication& GetInstance(); // 获取唯一的实例
    static MprpcConfig& GetConfig();
    
private:
    static MprpcConfig m_config;

    MprpcApplication(){}
    MprpcApplication(const MprpcApplication&) = delete;
    MprpcApplication(MprpcApplication&&) = delete;
};
