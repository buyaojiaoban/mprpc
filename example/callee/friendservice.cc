#include <iostream>
#include <string>
#include "friend.pb.h"
#include "mprpcapplication.h"
#include "rpcprovider.h"
#include <vector>
#include "logger.h"

class FriendService : public boozeban::FriendServiceRpc
{
public:
    std::vector<std::string> GetFriendsList(uint32_t userid)
    {
        std::cout << "do GetFriendsList service! userid:" << userid << std::endl;
        std::vector<std::string> vec;
        vec.push_back("jiao ban");
        vec.push_back("yi lin");
        vec.push_back("li si");
        return vec;
    }

    // 重写基类方法
    void GetFriendsList(::google::protobuf::RpcController *controller,
                        const ::boozeban::GetFriendsListRequest *request,
                        ::boozeban::GetFriendsListResponse *response,
                        ::google::protobuf::Closure *done)
    {
        uint32_t userid = request->userid();

        std::vector<std::string> friendsList = GetFriendsList(userid);
        response->mutable_result()->set_errcode(0);
        response->mutable_result()->set_errmsg("");
        for (std::string &name : friendsList)
        {
            std::string *p = response->add_friends();
            *p = name;
        }
        done->Run();
    }
};

int main(int argc, char **argv)
{
    LOG_INFO("first log message!");
    LOG_ERR("%s:%s:%d", __FILE__, __FUNCTION__, __LINE__);



    // 调用框架的初始化操作   provider -i config.conf     表示从这个config去读取相关的网络服务器的以及配置中心的相关的ip地址和端口号
    MprpcApplication::Init(argc, argv);

    // provider是一个rpc网络服务对象 把FriendService对象发布到rpc节点上
    RpcProvider provider;
    provider.NotifyService(new FriendService());

    // 启动一个rpc服务发布节点   Run以后，进程进入阻塞状态，等待远程的rpc调用请求
    provider.Run();

    return 0;
}