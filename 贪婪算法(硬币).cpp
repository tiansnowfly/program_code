#include <iostream>
using namespace std;

int main(){
    int total,number=0;
    int face_value[]={1, 2, 5, 10, 20, 50, 100};
    cin >> total;
    while(total!=0){
        while(total>=100){
            total = total - 100;
            ++number;
        }
        while(total>=50){
          total = total - 50;
          ++number;
        }
        while (total >= 20) {
          total = total - 20;
          ++number;
        }
        while (total >= 10) {
          total = total - 10;
          ++number;
        }
        while (total >= 5) {
          total = total - 5;
          ++number;
        }
        while (total >= 2) {
          total = total - 2;
          ++number;
        }
        while (total >= 1) {
          total = total - 1;
          ++number;
        }
    }
    cout << number << endl;
    system("pause");
    return 0;
}