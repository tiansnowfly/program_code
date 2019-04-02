#include <iostream>
#include <stack>
using namespace std;

struct scholar{
    int influnce;
    char chr[20];
};
bool operator<=(const scholar& a,const scholar& b){
    return a.influnce <= b.influnce;
}
bool operator>(const scholar& a, const scholar& b) {
  return a.influnce > b.influnce;
}
int main(){
    int number,count=0;
    cin >> number;
    stack<scholar> sch;
    scholar elem[number];
    for (int i = 0; i < number;++i){
        cin >> elem[i].influnce;
        cin.getline(elem[i].chr,20,'\n');
    }
    scholar arr[number];
    sch.push(elem[0]);
    for (int i = 1; i < number;++i){
        if(elem[i]<=sch.top()){
            sch.push(elem[i]);
        }
        else{
            while(elem[i]>sch.top()&&!sch.empty()){
                arr[count++]=sch.top();
                sch.pop();
            }
        }
    }
    system("pause");
    return 0;
}