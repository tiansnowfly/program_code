#include <iostream>
#include <fstream>
using namespace std;

int main(){
    char *cstring = "hello";
    //*p=a与p=&a的区别
    int *p;//int类型的指针不能初始化
    int a = 10;
    p = &a;//将a的地址赋给p
    cout << p << " " << *p << "  "<<(void*)p<<" "<<&a<<endl;
    int **q;
    q = &p;
    cout << *q <<" "<<q<<endl;
    cout << "====================" << endl;
    int *pt;
    cout << pt<<" "<<*pt<<endl;//pt指向的地址是内存分配的，地址中的初始值为0
    *pt = a;//将a的值赋给p
    cout << pt << " " << *pt << "  " << (void *)pt << " " << &a << endl;
    int **qt;
    qt = &p;
    cout << *qt << " " << qt << endl;

    cout << "====================" << endl;
    cout << (void*)cstring<<endl;//指针的地址要用void
    cout << cstring <<endl;
    cout << "cstring \" " << cstring << "\" "
         << "is located at address:" << static_cast<void *>(cstring) << endl;
    cout << "cstring \" " << cstring << "\" "
         << "is located at address:" << (void *)cstring<<endl;
    system("pause");
    return 0;
}