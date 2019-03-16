#include <iostream>
using namespace std;

void merge(int a[],int low,int mid,int high){
    int i = low, j = mid+1,k=0;
    int tmp[12];
    while(i<=mid&&j<=high){
        if(a[i]<a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }
    while(i<=mid)
        tmp[k++] = a[i++];
    while(j<=high)
        tmp[k++] = a[j++];
    for (i = 0; i < k&&low<=high;)
        a[low++] = tmp[i++];
}
int main(){
    int t, s, i;
    int arr[12] = {6, 10, 9, 5, 3, 11, 4, 8, 1, 2, 7};
    t = 1;
    while(t<11){
        s = t;
        t = 2 * s;
        i = 0;
        while(i+t<=11){
            merge(arr, i, i + s-1, i + t-1);
            i = i + t;
        }
    }
    if(i+s<11)
        merge(arr,i,i+s-1,10);
    for (i = 0; i < 11;++i)
        cout << arr[i] << " ";
    cout << endl;
    system("pause");
    return 0;
}