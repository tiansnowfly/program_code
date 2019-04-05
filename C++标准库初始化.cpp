#include <iostream>
#include <vector>

/*void print(std::initializer_list<int> vals){
    for (auto p = vals.begin(); p != vals.end();++p)
        std::cout << *p<< "\n";
}*/

int main(){
    //一致性初始化，面对任何初始化都可以用大括号来定义
    int values[]{1,2,3};
    int i;//i为随机值
    int j{};//j初始化为0
    //int *p;//p的值没有定义
    //int *q{};//q的值定义为nullptr空指针
    /*int x1(5.3);int x1=5.3是一样的*/
    //但是int x1{5.3}是错误的，不能这么定义
    //精度降低造成数值变动对于大括号来说是不可以的(窄化)
    //print({12,3,5,7,13,17});

    /*for(int k:{2,3,5,7,9,11})
        std::cout << k << std::endl;*/
    /*std::vector<int> v(values,values+3);
    for (std::vector<int>::iterator p = v.begin(); p!=v.end(); ++p)
        std::cout << *p << std::endl;
    for (auto q = v.begin(); q != v.end();++q)
        std::cout << *q << std::endl;*/
    //auto自动识别类型，std::vector<int>::iterator 要放在for里面begin()andend()才可以使用

    /*int array[] = {1, 2, 3, 4, 5};
    long sum = 0;
    for(int x:array)
        sum += x;
    for(auto elem:{sum,sum*2,sum*4})
        std::cout << elem << std::endl;*/

    system("pause");
    return 0;
}