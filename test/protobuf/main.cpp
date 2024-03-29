#include "test.pb.h"
#include <iostream>
#include <string>
using namespace boozeban;

int main()
{
    LoginResponse rsp;
    ResultCode *rc = rsp.mutable_result();
    rc->set_errcode(1);
    rc->set_errmsg("登录处理失败了");

    GetFriendListsResponse rspF;
    ResultCode *rcF = rspF.mutable_result();
    rcF->set_errcode(0);

    User *user1 = rspF.add_friend_list();
    user1->set_name("zhang san");
    user1->set_age(21);
    user1->set_sex(User::MAN);

    User *user2 = rspF.add_friend_list();
    user2->set_name("li si");
    user2->set_age(22);
    user2->set_sex(User::MAN);

    std::cout << rspF.friend_list_size() << std::endl;


    return 0;
}

int main1()
{
    // 封装了login请求对象的数据
    LoginRequest req;
    req.set_name("zhang san");
    req.set_pwd("123456");

    // 对象数据序列化 => char*
    std::string send_str;
    if (req.SerializeToString(&send_str)) // 序列化
    {
        std::cout << send_str.c_str() << std::endl;
    }

    // 从send_str反序列化一个login请求对象
    LoginRequest reqB;
    if (reqB.LoginRequest::ParseFromString(send_str))
    {
        std::cout << reqB.name() << std::endl;
        std::cout << reqB.pwd() << std::endl;
    }

    return 0;
}