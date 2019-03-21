#include <iostream>
using namespace std;

int max(int a, int b) { return a >= b ? a : b; }
struct knapsack
{
    int value;
    int weight;
};
int main()
{
    int i, j, n, volume;
    cin >> n >> volume;
    int store[n + 2][volume + 2];
    knapsack elem[n + 1];
    for (i = 0; i <= volume; ++i)
        store[0][i] = 0;
    for (i = 1; i <= n; ++i)
    {
        store[i][0] = 0;
        cin >> elem[i].value >> elem[i].weight;
    }
    for (i = 1; i <= n; ++i)
    {
        for (j = 1; j <= volume; ++j)
        {
            if (elem[i].weight > j)
                store[i][j] = store[i - 1][j];
            else
            {
                store[i][j] = max(store[i - 1][j], store[i - 1][j - elem[i].weight] + elem[i].value);
            }
        }
    }
    cout << store[n][volume] << endl;
    system("pause");
    return 0;
}
/*
5 11
1 1
6 2
18 5
22 6
28 7
*/