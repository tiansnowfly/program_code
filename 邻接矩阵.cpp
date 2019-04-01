#include <iostream>
#include <queue>
using namespace std;

struct edge{
    int point2;
    int weight;
    edge *next;
    edge(int p = 0, int w = 0,edge *n = NULL) {
        point2 = p;
        next = n;
        weight = w;
    }
};
struct vertex {
  int point;
  edge *head;
  vertex(int p = 0, edge *h = NULL) {
    point = p;
    head = h;
  }
};
vertex *elem = new vertex[10];
bool visited[10] = {false};
void dfs(int s){
    for (edge *p = elem[s].head; p != NULL;p=p->next){
        if(visited[p->point2]==true)
            continue;
        dfs(p->point2);
    }
}
void bfs(int s){
    bool visited2[10] = {false};
    queue<int> que;
    visited[s] = true;
    que.push(s);
    while(!que.empty()){
        int cur = que.front();
        que.pop();
        for (edge *p = elem[cur].head; p != NULL;p=p->next){
            if(visited[p->point2]==true)
                continue;
            que.push(p->point2);
        }
    }
}
int main(){
    int num1, num2,num3;
    for (int i = 0; i <= 8;++i){
        cin >> num1 >> num2>>num3;
        elem[num1].head=new edge(num2,num3,elem[num1].head);
    }
    int start;
    cin >> start;
    visited[start] = true;
    dfs(start);
    return 0;
}