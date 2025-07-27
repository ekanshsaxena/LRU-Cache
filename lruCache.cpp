#include<bits/stdc++.h>
using namespace std;

class ListNode{
public:
    int value;
    ListNode *previous = NULL;
    ListNode *next = NULL;
    ListNode(int value, ListNode *prev = NULL, ListNode *next = NULL){
        this->value = value;
        this->previous = prev;
        this->next = next;
    }
};

class DoublyLinkedList{
private:
    // Actual head is at dummyHead->next.
    ListNode *dummyHead = new ListNode(-1);
    ListNode *tail = dummyHead;
    int length = 0;
public:
    ListNode* insertAtHead(int value){
        ListNode *new_node = new ListNode(value, tail);
        tail->next = new_node;
        tail = new_node;
        length++;
        return new_node;
    }

    void insertAtHead(ListNode *node){
        node->prev = tail;
        tail->next = node;
        tail = node;
        length++;
    }

    void removeFirst(){
        ListNode *first_node = dummyHead->next;
        if(first_node){
            ListNode *second_node = first_node->next;
            dummyHead->next = second_node;
            if(second_node) second_node->prev = dummyHead;
            delete first_node;
            length--;
        }
    }

    void deleteNode(ListNode *node){
        ListNode *previous_node = node->prev;
        ListNode *next_node = node->next;
        prev_node->next = next_node;
        if(next_node) next_node->prev = prev_node;
        node->prev = NULL;
        node->next = NULL;
        length--;
        if(tail->value == node->value){
            tail = prev_node;
        }
    }

    void printList(){
        ListNode *it = dummyHead->next;
        while(it){
            cout<<it->value<<" ";
            it = it->next;
        }
        cout<<endl;
    }

    int getLength(){
        return length;
    }
};

class Cache{
private:
    int capacity;
    DoublyLL list;
    unordered_map<int, ListNode*> value_to_node;
public:
    Cache(int capacity){
        this->capacity = capacity;
    }

    void insert(int value){
        if(value_to_node.find(value) != value_to_node.end()){
            list.deleteNode(value_to_node[value]);
            list.insertAtHead(value_to_node[value]);
        }else{
            if(list.getLength() >= capacity){
                list.removeFirst();
            }
            ListNode *node = list.insertAtHead(value);
            value_to_node[value] = node;
        }
    }

    void printCache(){
        if(list.getLength() == 0){
            cout<<"Cache is Empty Currently!"<<endl;
            return;
        }
        list.printList();
    }
};

class InputHelper{
public:
    static int getIntegerInput(string message, bool isPositive = false){
        int value;
        while(true){
            try{
                cout<<message;
                cin>>value;
                if(isPositive && value <= 0){
                    cout<<"Value cannot be 0 or negative!"<<endl;
                }else{
                    return value;
                }
            }catch(exception e){
                cout<<"Invalid Input, Please try again!"<<endl;
            }
        }
    }
    static char getCharacterInput(string message, vector<char> validInputs){
        char value;
        while(true){
            try{
                cout<<message;
                cin>>value;
                if(find(validInputs.begin(), validInputs.end(), value) == validInputs.end()){
                    cout<<"Invalid Input, Please try again!"<<endl;
                }
                return value;
            }catch(exception e){
                cout<<"Invalid Input, Please try again!"<<endl;
            }
        }
    }
};

int main(){
    int capacity = InputHelper::getIntegerInput("Enter the capacity of Cache: ", true);
    Cache cache = Cache(capacity);
    while(true){
        int value = InputHelper::getIntegerInput("Enter the value to be inserted in Cache: ", true);
        cache.insert(value);
        cout<<"Cache after inserting "<<value<<" is: ";
        cache.printCache();
        char choice = InputHelper::getCharacterInput("Do you want to insert more values? (y/n): ", {'y', 'n'});
        if(choice == 'n') break;
    }
    return 0;
}