//
// Created by sun on 2021/4/22.
//

#include "../include/VNode.h"

#include <utility>

// 因为现在我们是在实现类中的成员函数，所以我们实在VNode类中，所以我们可以直接获取类中所有的成员变量。

VNode::VNode(string nodename) {
    node_name = std::move(nodename);
}


//set
void VNode::set_node_name(string nodename) {
    node_name = std::move(nodename);
}

void VNode::set_adjacency_nodes(vector<VNode> adjacencynodes) {
    adjacency_nodes = std::move(adjacencynodes);
}

void VNode::set_adjacency_nodes_str(vector<string> adjacencynodes_str) {
    adjacency_nodes_str = std::move(adjacencynodes_str);
}

void VNode::set_node_degrees(int degrees) {
    node_degrees = degrees;
}


//get
string VNode::get_node_name() {
    return node_name;
}

vector<VNode> VNode::get_adjacency_nodes() {
    return adjacency_nodes;
}

vector<string> VNode::get_adjacency_nodes_str() {
    return adjacency_nodes_str;
}

int VNode::get_node_degrees() {
    return node_degrees;
}




