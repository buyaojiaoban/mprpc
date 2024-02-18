#include "mprpccontroller.h"

MprpcContrller::MprpcContrller()
{
    m_failed = false;
    m_errText = "";
}

void MprpcContrller::Reset()
{
    m_failed = false;
    m_errText = "";
}

bool MprpcContrller::Failed() const
{
    return m_failed;
}

std::string MprpcContrller::ErrorText() const
{
    return m_errText;
}

void MprpcContrller::SetFailed(const std::string& reason)
{
    m_failed = true; // 表示发生错误了
    m_errText = reason;
}

// 目前未实现具体的功能
void MprpcContrller::StartCancel(){}
bool MprpcContrller::IsCanceled() const{return false;}
void MprpcContrller::NotifyOnCancel(google::protobuf::Closure* callback) {}