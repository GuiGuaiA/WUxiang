#include <iostream>
#include "string"
#include "vector"
#include "fstream"
#include "./include/VNode.h"
#include "./include/Arc.h"
#include "algorithm"

#define FILE_PATH "E:/ClionProject/AdjacencyList/data/data.txt"
using namespace std;

// 这里是我个人编程习惯，函数声明放在main函数上方，实现放在main函数下方。


std::vector<std::string> data_extract(std::string file_path);  //  file path (文件路径) vector（可变大小的数组）
//std::string是标准C++的字符串实现 (如果我们使用名空间std中的类，为了防止和其他的类库名称冲突，就需要在程序中加入语句：using namespace std )
// hanming
int hanming_distance(std::string string1, std::string string2);  //定义汉明距离，字符串1，字符串2.

int main() {
    // 读取数据
    vector<string> node_list_str = data_extract(FILE_PATH);
    // 存放所有节点
    vector<VNode> node_list;
    // 根据读取的数据初始化所有节点
    for (int i = 0; i < node_list_str.size(); i++){
        //cout << node_list_str[i] << endl;
        node_list.push_back(node_list_str[i]);
        cout << i << " " << node_list[i].get_node_name() << endl;
    }


    //到这里，已经完成所有节点的初始化了，我们输出一下看看

    //上回我们写了一个VNode类来存储所有的节点，并且完成了初始化。
    //这回我们需要构造所有的边，并根据所有的边来构建邻接表。
    //先从边的类开始写起。
    //还是跟上次一样，先在头文件中声明好类和函数以及成员变量，然后在对应的source文件中写成员函数的函数体。


    /*
     * 现在，我们已经有了边类，然后就可以初始化是有的边了。现在开始
     *
     * */
    //存放所有的边
    vector<Arc> arc_list; // 数组边表。
    vector<VNode> temp_list = node_list;  // 临时节点表。

    for (int i = 0; i < node_list.size(); i++){
        // 因为你要判断任意两个节点之间都有没有边，所以，你就需要有两层循环，每一层循环都是所有的节点，这样就可以枚举出，所有的节点对的所有情况。
        // 明白了吗？
        for (int j = 0; j < node_list.size(); j++){
            // 这里就是对 任意两个节点对，判断汉明距离是不是为1，是1的话，就新建一个 边arc对象，并且把这两个节点对存储下来。然后把这个对象加到arc_list
            if (hanming_distance(node_list[i].get_node_name(), temp_list[j].get_node_name()) == 1){
                Arc k(node_list[i], temp_list[j]);
                arc_list.push_back(k);
            }
        }
    }

    //到这里就完成所有边的初始化了，看懂了吗？？

    //好了，现在我们有节点列表，和边的列表了。我们可以开始构造邻接表了。

    cout << " the adjacency list of the node list is as following: " << endl;
    for (int i = 0; i < node_list.size(); i++){
        //下面这个两个vector用于存放，每个节点所相连的节点，两种格式
        // temp_adjacency存储的是VNode类型，temp_adjacency_str存储的是string类型。
        vector<VNode> temp_adjacency;
        vector<string> temp_adjacency_str;
        //现在对于每个节点，我们找出所有与他直接相连的节点，并将与其直接相连的节点放到上面我们刚刚创建的两个vector中。看好了。
        for (auto & j : arc_list){
            if (j.get_first_nodename() == node_list[i].get_node_name() &&
                //find是algorithm头文件中的一个函数，用于寻找一个vector中的某个元素，若该元素在vector中，则返回该元素的索引，否则，返回vector的尾指针。
                find(temp_adjacency_str.begin(), temp_adjacency_str.end(), j.get_second_nodename()) == temp_adjacency_str.end()){
                    temp_adjacency.push_back(j.get_second_node());
                    temp_adjacency_str.push_back(j.get_second_nodename());
            }
            if (j.get_second_nodename() == node_list[i].get_node_name() &&
                //find是algorithm头文件中的一个函数，用于寻找一个vector中的某个元素，若该元素在vector中，则返回该元素的索引，否则，返回vector的尾指针。
                find(temp_adjacency_str.begin(), temp_adjacency_str.end(), j.get_first_nodename()) == temp_adjacency_str.end()){
                temp_adjacency.push_back(j.get_first_node());
                temp_adjacency_str.push_back(j.get_first_nodename());
            }
        }

        node_list[i].set_adjacency_nodes(temp_adjacency);
        node_list[i].set_adjacency_nodes_str(temp_adjacency_str);
        node_list[i].set_node_degrees(temp_adjacency.size());
        //到这里，我们就完成了邻接表的构造了。所有我让你做的到目前都写完了。也是就是一两百行的代码。
        //我们输出看一下效果

        cout << "the degrees of the node is :" << node_list[i].get_node_degrees() << endl;
        cout << i << " " << node_list[i].get_node_name();
        for (int j = 0; j < temp_adjacency.size(); j++){
            if (j < temp_adjacency.size() - 1)
                cout << "  ->  " << node_list[i].get_adjacency_nodes_str()[j];
            else
                cout << "  ->  " << node_list[i].get_adjacency_nodes_str()[j] << endl;
        }

    }

    std::cout << "Hello, World!" << std::endl;
    return 0;
}


std::vector<std::string> data_extract(std::string file_path) {  //数据提取。
    std::string temp;  //定义临时变量 （换数思想）
    std::vector<std::string> data;   // 提取数据。
    std::ifstream file(file_path);   // 已输入的方式打开文件
    while (getline(file, temp)){  // 获取文件中的字符串和定义temp的字符串。
        data.push_back(temp); // 数据返回。
        //std::cout << temp << std::endl;
    }
    return data;
}

int hanming_distance(std::string string1, std::string string2) // 定义汉明距离 字符串1，字符串2.
{
    int sum = 0,n = 0;
    if  (string1.length() == string2.length())  //若字符串1的长度等于字符串2的长度，
    {
        for (int i = 0; i < string1.length(); i++) //定义i，循环字符串1的长度，
        {
            if (string1.substr(i,n+1) != string2.substr(i,n+1))
                ++ sum;  // 若字符串1和字符串2每有一个字符不同，则sum数值加一。
        }
        return sum;
    }
    else{
        std::cout<< string1.length() << std::endl << string2.length() << std::endl; // 输出字符串1 然后换行输出字符串2.
        std::cout<< "The length of the strings are not equivalence." << std::endl; //  输出长度不等的字符串。
        return 0;
    }
}
