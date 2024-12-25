#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

Node *head;

int isEmpty(){
    if(head == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

void addFirst(int databaru){
    Node *baru, *bantu;
    baru = new Node;
    baru->data = databaru;
    baru->next = baru;
    baru->prev = baru;
    if (isEmpty() == 1){
        head = baru;
        head->next = head;
        head->prev = head;
    }
    else{
        bantu = head->prev;
        baru->next = head;
        head->prev = baru;
        head = baru;
        head->prev = bantu;
        bantu->next = head;
    }
}

void addLast(int databaru){
    Node *baru, *bantu;
    baru = new Node;
    baru->data = databaru;
    baru->next = baru;
    baru->prev = baru;
    if (isEmpty() == 1){
        head = baru;
        head->next = head;
        head->prev = head;
    }
    else{
        bantu = head->prev;
        bantu->next = baru;
        baru->prev = bantu;
        baru->next = head;
        head->prev = baru;
    }
}

void addAt(int databaru, int index){
    if (isEmpty() == 1){
        addFirst(databaru);
    }
    else{
        Node *baru = new Node;
        baru->data = databaru;
        baru->next = baru;
        baru->prev = baru;

        Node *pointer = head;
        int counter = 0;
        while (counter < index){
            pointer = pointer->next;
            counter++;
        }

        baru->prev = pointer;
        baru->next = pointer->next;

        if (pointer->next != NULL){
            pointer->next->prev = baru;
        }

        pointer->next = baru;
    }
}

void removeFirst(){
    Node *hapus, *bantu;
    if (isEmpty() == 0){
        if (head->next != head){
            hapus = head;
            bantu = head->prev;
            head = head->next;
            bantu->next = head;
            head->prev = bantu;
            delete hapus;
        }
        else{
            head = NULL;
        }
    }
}

void removeLast(){
    Node *hapus, *bantu;
    if (isEmpty() == 0){
        if (head->next != head){
            bantu = head;
            while (bantu->next->next != head){
                bantu = bantu->next;
            }
            hapus = bantu->next;
            bantu->next = head;
            delete hapus;
        }
        else{
            head = NULL;
        }
    }
}

void removeAt(int index){
    if (isEmpty() == 0){
        Node *pointer = head;
        int counter = 0;
        while (counter < index){
            pointer = pointer->next;
            counter++;
        }

        if (pointer != head){
            pointer->prev->next = pointer->next;
            pointer->next->prev = pointer->prev;
            delete pointer;
        }
        else{
            delete head;
            head = NULL;
        }
    }
}

void rotasi(){
    if (isEmpty() == 0 && head->next != NULL){
        head = head->next;
    }
}

void print(){
    Node *bantu;
    bantu = head;
    if (isEmpty() == 0){
        do{
            cout << bantu->data << " ";
            bantu = bantu->next;
        }
        while (bantu != head);
        cout << endl;
    }
}

int main(){
    // command
    return 0;
}