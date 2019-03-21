#include <iostream>
#include <string>
using namespace std;

int arr[10][10];
string str1 = "abgckdelftghjk", str2 = "dsanbckdegtthjk";
int LCS(int i,int j){
    if(i==0||j==0)
        return 0;
    else if(str1[i]==str2[j])
        return LCS(i-1,j-1)+1;
    else
        return LCS(i, j - 1) > LCS(i - 1, j) ? LCS(i,j-1):LCS(i-1,j);
}
int main(){
    cout << LCS(13,14) << endl;
    system("pause");
    return 0;
}