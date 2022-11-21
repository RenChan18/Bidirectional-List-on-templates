#pragma once

#include <iostream>
#include <vector>
#include <iterator>

template <typename T>
struct Node {
    T data;
    struct Node<T> *next;
    struct Node<T> *prev;

};

template <typename T>
class BidirList {

private:
    Node<T> *first;
    Node<T> *last;
    int lenght;
    
    Node<T>* ReturnEl(int index) {
        Node<T>* el = first;
        for (int i = 0; i < index; i++) {
            el = el -> next;
        }
        return el;
    }
    void Copy(const BidirList<T>& obj);
    

public:
    BidirList(const BidirList& obj) {
        ClearList();
        Node<T>* el = obj.first;
        while (el!= nullptr) {
            AddNodeToBegin(el-> data);
            el = el -> next;
        }
    }

    BidirList() {
        first = nullptr;
        last = nullptr;
        lenght = 0;
    }
    
    ~BidirList() {
        while(first != last) {
            Node<T> tmp = first;
            first = first -> next;
            delete tmp;
        }
    }
    
    T GetNode(int index) {
        if((index >= 0) && (index < lenght)) {
            throw std::out_of_range("Incorrect index");
        }
        Node<T> *el = ReturnEl(index);
        return el -> data;
    }

    void SetNode(T node_data, int index) {
         if((index >= 0) && (index < lenght)) {
             throw std::out_of_range("Incorrect index");
        }
        Node<T> *el = ReturnEl(index);
        el -> data = node_data;
   
    }

    void AddNodeToEnd(T node_data) {
        try {
            Node<T>* el = new Node<T>;
            el -> next = nullptr;
            el -> prev = last;
            el -> data = node_data;

            if (last != nullptr)
                last -> next = el;
            if (lenght == 0) {
                first = last = el;
            }
            else {
                last = el;
            }
            lenght++;
        }   
        catch(std::bad_alloc ex) {
            std::cout << ex.what() << std::endl;
        }
    }

    void AddNodeToBegin(T node_data);
    void InsertNodeTo(T node_data, int index);
    void DeleteNode(int index);
    void ClearList();
    void PrintList();
    int LenghtOfList();


};

