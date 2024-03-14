#include <bits/stdc++.h>
using namespace std;

// memory 用太多

int main(){
    int t, n;
    cin >> t;
    for(int i = 0;i < t;i++){

        cin >> n;
        // int tg_bag [100000] = {0}; //queue 
        // int normal_bag [100000] = {0}; //queue 
        // int bag [100000] = {0}; //stack

        int *tg_bag = new int[n];
        int *normal_bag = new int[n];
        int *bag = new int[n];

        int tg_tail = 0;
        int tg_head = 0;
        int normal_tail = 0;
        int normal_head = 0;

        int bag_top = 0;

        for(int k=1;k<=n;k++){
            int car;
            cin >> car;

            // queue
            tg_bag[tg_tail++] = car;
            normal_bag[normal_tail++] = k;
        }

        while(true){
            if(bag_top != 0 && bag[bag_top-1] == tg_bag[tg_head]){
                tg_head++;
                bag_top--;
            }
            else if(normal_tail - normal_head != 0){
                bag[bag_top++] = normal_bag[normal_head++];
            }
            else{
                break;
            }
        }

        if (tg_tail-tg_head == 0){
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
        delete[] tg_bag;
        delete[] normal_bag;
        delete[] bag;
    }
    return 0;
}