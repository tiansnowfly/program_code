#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <set>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

//vector=================================================
//vector=================================================
/*struct st{
    int id;
    double db;
};
void origin(int num,vector<st>& student){
    int m=num;
    st temp;
    for(int i=0;i<m;++i){
        temp.id=i+1;
        temp.db=(i+1)*10;
        student.push_back(temp);
    }
}
void iter_for(vector<st>& student){
    st temp;
    vector<st>::iterator itr;
    for(itr=student.begin();itr!=student.end();++itr){
        //temp=*itr;
        cout<<"id:"<<(*itr).id<<",db:"<<(*itr).db<<endl;
    }
    cout<<endl;
}
void at_for(vector<st>& student){
    st temp;
    int i=0;
    int m=student.size();
    for(i=0;i<m;++i){
        temp=student.at(i);
        cout<<"id:"<<temp.id<<",db:"<<temp. db<<endl;
    }
}
int main(){
    st temp;
    vector<st> my_student;
    origin(5,my_student);
    int size=my_student.size();
    cout<<"size:"<<size<<endl;
    cout<<"iterator output!"<<endl;
    iter_for(my_student);
    cout<<"at() output!"<<endl;
    at_for(my_student);
    cout<<"empty usage!"<<endl;
    while(!my_student.empty()){
        temp=my_student.back();
        cout<<"id:"<<temp.id<<",db:"<<temp. db<<endl;
        my_student.pop_back();
    }
    return 0;
}*/
//===============================================================
/*class student{
    public:
    string name;
    double score;
    student(const string &a,double b):name(a),score(b){}
    bool operator<(const student& st)const{
        return score<st.score;
    }
};
bool name_sort_less(const student& m,const student& n){
    return m.name<n.name;
}
bool name_sort_greater(const student& m,const student& n){
    return m.name>n.name;
}
bool score_sort(const student& m,const student& n){
    return m.score>n.score;
}
void print(student& s){
    cout<<s.name<<"   "<<s.score<<endl;
}
void origin(vector<student>& st){}//初始化暂时不写
int main(){
    vector<student> st;
    origin(st);
    for_each(st.begin(),st.end(),print);
    //默认从小到大排序，重载了<符号
    //以及其他几种不同自定义排序方式
    sort(st.begin(),st.end());
    sort(st.begin(),st.end(),name_sort_less);
    sort(st.begin(),st.end(),name_sort_greater);
    sort(st.begin(),st.end(),score_sort);
    //插入元素
    vector<student> st2;
    st.insert(st.begin(),-1);//在起始位置之前插入元素
    st,insert(st.end(),st2.begin(),st2.end());//在st后面插入整个st2
    //还有clear(),swap(),pop_back(),push_back(),back(),remove(),erase()函数
    return 0;
}*/
//list============================================================
//list============================================================
//定义的方法
/*list<int> list1;
list<int> list2(5);
list<int> list3(5,2);
list<int> list4(list3);

void push_back(const int& x){}
void push_front(const int& x){}
void pop_back(){}
void pop_front(){}

int size(){}
int max_size(){}
void resize(int n){}//重新指定容器大小
bool empty(){}
void merge(list<int>& list1){}//可以实现两个list合并，也可以用splice()
void sort(){}//对list进行排序
//此外还有insert(),remove(),erase()等
*/

//deque===========================================================
//deque===========================================================
//写过，在这先不写

//map=============================================================
//map=============================================================
/*typedef pair<int,double> my_pair;
typedef map<int,double,less<int>> my_map;
typedef multimap<int,double,greater<int>> my_multimap;
typedef pair<my_map::iterator,bool> my_p;
void print(my_map& m){
    my_map::iterator itr;
    my_pair temp;
    for(itr=m.begin();itr!=m.end();++itr){
        temp=(*itr);
        cout<<temp.first<<","<<temp.second<<endl;
    }
    cout<<endl;
}
void print(my_multimap& m){
    my_multimap::iterator itr;
    my_pair temp;
    for(itr=m.begin();itr!=m.end();++itr){
        temp=(*itr);
        cout<<temp.first<<","<<temp.second<<endl; 
   }
   cout<<endl;
}
int main(){
    my_map m1;
    my_multimap m2;
    my_multimap::iterator itr1,itr2;
    my_p p1,p2;
    my_map::value_compare vc1=m1.value_comp();
    my_multimap::value_compare vc2=m2.value_comp();
    return 0;
}*/
