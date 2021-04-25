//
// Created by sun on 2021/4/22.
//
#include "string"
#include "vector"

#ifndef ADJACENCYLIST_VNODE_H
#define ADJACENCYLIST_VNODE_H

/*
 * include 文件夹，专门用来存放头文件，即.h文件，这里是类或者函数的声明，一般想写什么功能都会在头文件里写。
 * lib 文件夹，专门用来存放source文件，即.cpp文件，这里是.h文件中，声明的类或者函数的实现。
 *
 * */

using namespace std;

class VNode{

    // private 后面的成员变量是私有变量，本类以外的所有变量和函数不能直接访问和获取。
private:
    //成员变量
    string node_name;
    vector<VNode> adjacency_nodes; // 定义邻接节点数组。
    vector<string> adjacency_nodes_str; // 定义字符串数组。

    int node_degrees = 0;

    // public 后面的成员变量是公有变量，本类以外的所有变量和函数可以直接访问和获取。
    // 因此，我们可以把重要的成员变量都声明为私有变量，如果在本类的外面来获取这个类的对象的成员变量，通过公有的成员函数来获取，这就叫 “封装”。
    // 这样做的好处是保证了类的封闭性，不会让任何变量都能随意的更改本类对象的成员变量。在大型程序开发中，或者多人合作程序开发中，封装是提高开发效率一定会选择的。
public:
    //构造函数
    VNode(string nodename);

    //设置成员变量的成员函数
    void set_node_name(string nodename);
    void set_adjacency_nodes(vector<VNode> adjacencynodes);
    void set_adjacency_nodes_str(vector<string> adjacencynodes_str);
    void set_node_degrees(int degrees);

    //获取成员变量的成员函数
    string get_node_name();
    vector<VNode> get_adjacency_nodes();
    // 你看，现在下面这一行，43行是黄色的，对不对，那我要用快捷键创建出它的函数体，怎么做呢？
    // alt + 回车 键。就会有语法提示：
    // 对应的函数体就会在对应的source文件中自动创建出来。
    // 这里我在VNode.h中声明函数，然后alt + 回车 键。就会有语法提示，选择生成函数体，就会在VNode.cpp文件中自动创建出函数体.
    vector<string> get_adjacency_nodes_str();
    int get_node_degrees();
};

#endif //ADJACENCYLIST_VNODE_H
