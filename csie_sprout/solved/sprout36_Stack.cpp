#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    int *bag = new int[t];
    int top = 0;

    for(int i=0;i<t;i++){
        int instruction;
        int num;
        cin >> instruction;
        if (instruction == 1){
            cin >> num;
            bag[top++] = num;
        }
        else{
            if(top == 0){
                cout << "empty!" << endl;
            }
            else{
                cout << bag[--top] << endl;
            }
        }
    }
    delete[] bag;
}