//
// Created by sun on 2021/4/24.
//

#include "../include/VNode.h"

#ifndef ADJACENCYLIST_ARC_H
#define ADJACENCYLIST_ARC_H


/*
 * 这个就是边类，这个类很简单，只需要存放与某个边直接相邻的两个节点即可。
 * */
using namespace std;

class Arc{
private:
    VNode first_node;
    VNode second_node;

public:
    Arc(VNode firstnode, VNode secondnode);
    string get_first_nodename();
    string get_second_nodename();
    VNode get_first_node();
    VNode get_second_node();
};


#endif //ADJACENCYLIST_ARC_H
