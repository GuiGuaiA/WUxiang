//
// Created by sun on 2021/4/24.
//

#include "../include/Arc.h"

//类每一个成员变量都需要初始化，否则，就需要在类的构造函数中初始化。这里我们没有初始化两个VNode成员变量。所以需要在构造函数中这么写，
// 为什么不能像刚才那样直接赋值呢？你思考下。
Arc::Arc(VNode firstnode, VNode secondnode) : first_node(move(firstnode)), second_node(move(secondnode)){
    //first_node = firstnode;
    //second_node = secondnode;
}

string Arc::get_first_nodename() {
    //这里通过first_node调用了VNode类的成员函数get_node_name，来获取first_node的名字。
    //为什么可以在这里调用VNode类的成员函数？ 思考一下。
    return first_node.get_node_name();
}

string Arc::get_second_nodename() {
    return second_node.get_node_name();
}

VNode Arc::get_first_node() {
    return first_node;
}

VNode Arc::get_second_node() {
    return second_node;
}
