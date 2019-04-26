#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
#define MAX 100

int matrix[MAX][MAX];
int flow = 0;
struct node{
    int start;
    int end;
    int weight;
};

int agument_path(int start,int end,int n){
    bool visited[n];
    bool find_path = false;
    memset(visited,false,sizeof(visited));
    queue<int> que;
    int current;
    int node_pre[n];
    que.push(start);
    visited[start] = true;
    while(!que.empty()){
        current = que.front();
        que.pop();
        for (int i = 0; i < n;++i){
            if(matrix[current][i]>0&&!visited[i]){
                node_pre[i] = current;
                visited[i] = true;
                if(start==end){
                    find_path = true;
                    break;
                }
                que.push(i);
            }
        }
    }
    if(!find_path){
        return 0;
    }
    //找出增广路中的最小流
    int min = 99999;
    int cur = end;
    while(cur!=start){
        int pre = node_pre[cur];
        min = min > matrix[pre][cur] ? matrix[pre][cur] : min;
        cur = pre;
    }
    //更新剩余图
    cur = end;
    while(cur!=start){
        int pre = node_pre[cur];
        matrix[pre][cur]=matrix[pre][cur]-min;
        matrix[cur][pre] = matrix[cur][pre] + min;
        cur = pre;
    }
    return min;
}
int main(){
    node connect_point[MAX];
    vector<node> vec;
    int flow = 0;
    int n;
    cin >> n;
    for (int i = 0; i < n;++n){
        cin >> connect_point[i].start >> connect_point[i].end>>connect_point[i].weight;
        vec.push_back(connect_point[i]);
    }
    for (int i = 0; i < n;++i){
        for (int j = 0; j < n;++j){
            matrix[i][j] = 0;
        }
    }
    for (vector<node>::iterator ptr = vec.begin(); ptr != vec.end(); ++ptr) {
        matrix[(*ptr).start][(*ptr).end] = (*ptr).weight;
    }
    int start,end;
    cin >> start >> end;
    int temp_agu=1;
    while(temp_agu){
        flow += agument_path(start,end,n);
    }
    cout << flow - 1;
    system("pause");
    return 0;
}