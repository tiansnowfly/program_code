#include <iostream>
#include <algorithm>
using namespace std;

struct interval_task{
    int beign;
    int end;
    int weight;
    int pre;
}; 
interval_task elem[20];
void init_elem(){
    for(int i=0;i<20;++i) elem[i].pre==0;
}
bool compare_end(const interval_task& item1,const interval_task& item2){
    return item1.end<item2.end;
}
int dynamic_function(int i){
    if(i==0) return 0;
    int sum1=elem[i].weight+dynamic_function(elem[i].pre);
    int sum2=dynamic_function(i-1);
    return sum1>sum2?sum1:sum2;
}
int main(){
    int i,j,n;
    cin>>n;
    for(i=0;i<n;++i){
        cin>>elem[i].begin>>elem[i].end>>elem[i].weight;
    }
    sort(elem,elem+n,compare_end);
    for(i=n-1;i>=0;--i){
        int temp=i-1;
        while(elem[temp].end>elem[i].begin&&temp!=0) --temp;
        elem[i].pre=temp;
    }
    cout<<dynamic_function(n-1)<<endl;
    return 0;
}