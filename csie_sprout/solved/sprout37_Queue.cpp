// Q: https://neoj.sprout.tw/problem/37/
// concept: linked list

#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    int *queue = new int[t];
    int head = 0, tail = 0;

    for(int i=0;i<t;i++){
        int instruction, num;
        cin >> instruction;
        if(instruction == 1){
            cin >> num;
            queue[tail++] = num;
        }
        else{
            if(tail-head == 0){
                cout << "empty!" << endl;
            }
            else{
                cout << queue[head++] << endl;
            }
        }
    }



    return 0;
}
