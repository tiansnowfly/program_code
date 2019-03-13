#include <iostream>
#include <algorithm>
using namespace std;

bool compare(pair<int,int>& a,pair<int,int>& b){
    return a.second < b.second;
}
int main(){
    pair<int, int> work[10];
    int n,i, temp = 0, count = 0;
    cin >> n;
    for (i = 0; i < n;++i)
        cin >> work[i].first >> work[i].second;
    sort(work,work+n,compare);
    for (i = 0; i < n;++i){
        if(temp<=work[i].first){
            ++count;
            temp = work[i].second;
        }
    }
    cout << count << endl;
    system("pause");
    return 0;
}