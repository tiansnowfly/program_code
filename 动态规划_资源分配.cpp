#include <iostream>
#include <ctime>
using namespace std;

int per_profit[100][100];
int total_profit[100][100];
int main(){
    clock_t start, end;
    start = clock();
    int resource, workshop,i,j,k;
    cin >> resource >> workshop;
    for (i = 1; i <= resource;++i){
        for (j = 1; j <= workshop;++j){
            total_profit[i-1][j-1] = 0;
            cin >> per_profit[i][j];
        }
    }
    int max = 0;
    for (i = 1; i < resource;++i){
        for (j = 1; j < workshop;++j){
            for (k = 0; k <= i;++k){
                total_profit[i][j] = per_profit[i][k] + total_profit[i - k][j - 1];
                max = total_profit[i][j] >= max ? total_profit[i][j] : max;
            }
        }
    }
    cout << max<<endl;
    end = clock();
    cout << double(start - end) / CLOCKS_PER_SEC << endl;
    system("pause");
    return 0;
}