#include <iostream>
#include <algorithm>
using namespace std;

struct work_condition{
    int start;
    int time_cost;
    int deadline;
};
bool compare(const work_condition& a,const work_condition& b){
    return a.deadline < b.deadline;
}
int main(){
    int number_work,lateness=0;
    cin >> number_work;
    work_condition elem[number_work+1];
    for (int i = 1; i <= number_work;++i){
        cin >> elem[i].start >> elem[i].time_cost >> elem[i].deadline;
    }
    sort(elem+1,elem+number_work,compare);
    int temp = elem[1].start;
    for (int i = 1; i < number_work;++i){
        if(temp+elem[i].time_cost>elem[i].deadline){
            lateness += temp + elem[i].time_cost - elem[i].deadline;
        }
        temp += elem[i].time_cost;
    }
    cout << lateness << endl;
    system("pause");
    return 0;
}