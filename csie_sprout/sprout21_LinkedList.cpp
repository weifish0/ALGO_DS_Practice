// Q: https://neoj.sprout.tw/problem/21/
// concept: linked list
// date: 2024/03/13

#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *next;
};

int main() {  
    int n, rounds;
    cin >> n;

    Node *head = new Node;
    head->data = 1;
    head->next = NULL;
    
    Node *current = head;

    // 建立linked list
    for(int player_num=2;player_num<=n;player_num++){
        current->next = new Node;
        current = current->next;
        current->data = player_num;
        current->next = NULL;
    }

    cin >> rounds;
    for(int i=0;i<rounds;i++){
        int event, player;
        cin >> event >> player;
        
        if(event==0){
            Node *temp;
            
            // 處理刪除Node是head的狀況 
            if(head->data == player){
                temp = head;
                head = head->next;
                delete temp;
                continue;
            }
            
            // 刪除Node
            current = head;
            while(true){
                // current - temp 
                temp = current->next;
                
                if(temp->data == player){
                    current->next = temp->next;
                    delete temp;
                    break;
                }
                current = current->next;
            }
        }
        else{
            current = head;
            Node *first_player = NULL;
            Node *second_player = NULL;
            while(true){
                // Node交換
                if(current->data == player){
                    if(second_player == NULL){
                        break;
                    }
                    else if(first_player == NULL){
                        // second_player -> current
                        head = current;
                        second_player->next = current->next;
                        current->next = second_player;
                        break;
                    }
                    else{
                        // before: first_player -> second_player -> current -> last_player
                        // after: first_player -> current -> second_player -> last_player
                        first_player->next = current;
                        second_player->next = current->next;
                        current->next = second_player;
                        break;
                    }
                }
                
                first_player = second_player;
                second_player = current;
                current = current->next;
            }
        }
    }

    current = head;
    while (true){
        if(current->next == NULL){
            cout << current->data << endl;
            break;
        }
        else{
            cout << current->data << " ";
            current = current->next;
        }
    }

    return 0;
}
