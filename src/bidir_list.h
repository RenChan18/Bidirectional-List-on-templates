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
    


    Node<T>* ReturnEl( int index) {
        Node<T>* el = first;
       
        for (int i = 0; i < index; i++)
            el  = el -> next;

        return el;
    }


    
    

public:

    BidirList() {
        first = nullptr;
        last = nullptr;
        lenght = 0;
    }

    BidirList(const BidirList& obj) {
        ClearList();
        Node<T>* el = obj.first;
        while (el!= nullptr) {
            AddNodeToBegin(el-> data);
            el = el -> next;
        }
    }

    BidirList(T el) {
        first = nullptr;
        last = nullptr;
        lenght = 0;
        AddNodeToEnd(el);
    }

    ~BidirList() {
      int n = lenght;
      for(int i = 0; i < n; i++)
          DeleteNode(0);
    }

    
    
   // template <typename T>
    class Iterator { 
    public:
        Node<T> i;
        typedef std::bidirectional_iterator_tag iterator_cathegory;
        typedef T value_type;
        typedef T *pointer;
        typedef T &reference;

        inline Iterator() : i(0) {}
        inline Iterator(Node<T> n) : i(n) {};
        inline Iterator(const Iterator &obj) : i(obj.i) {};

        T &operator*() const {
            return i -> data;
        }

        T *operator->() const;
        bool operator==(const Iterator &other) const;
        bool operator!=(const Iterator &o) const;
        Iterator &operator++();
        Iterator operator++(int);
        Iterator &operator--();
        Iterator operator--(int);
    };

    Iterator  begin() {
       return Iterator(first);
    }

    Iterator end() {
        return Iterator(last);
    }

  //  T GetNode(int index) {
  //      if((index >= 0) && (index < lenght)) {
  //          throw std::out_of_range("Incorrect index");
  //      }
  //      Node<T> *el = ReturnEl(index);
  //      return el -> data;
  //  }

    T GetNode(int index){
        if((index >= 0) && (index < lenght)) {
            throw std::out_of_range("Incorrect index");
        }
        size_t s;
        for(BidirList<int>::Iterator it = begin(); it != end(); it++) {
            s++;
            if (s == index) return *it;
        }
        return first;
    }

 //   void SetNode(T node_data, int index) {
 //        if((index >= 0) && (index < lenght)) {
 //            throw std::out_of_range("Incorrect index");
 //       }
 //       Node<T> *el = ReturnEl(index);
 //       el -> data = node_data;
 //  
 //   }
 

    void SetNode(T node_data, int index) {
        if((index >= 0) && (index < lenght)) {
             throw std::out_of_range("Incorrect index");
        }
        size_t s;
        Node<T> *el;
        for(BidirList<int>::Iterator it = begin(); it != end(); it++) {
            s++;
            if (s == index) *el = *it;
        }
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

    void AddNodeToBegin(T node_data) {
        try {
            Node<T>* el = new Node<T>;
            el -> data = node_data;
            el -> prev = nullptr;
            el -> next = first;

            if (lenght > 0) {
                first -> prev = el;
                first = el;
            }
            else {
                first = last = el;
            }
            lenght++;
        }
       catch(std::bad_alloc ex) {
            std::cout << ex.what() << std::endl;
        }

    }
    
    void InsertNodeTo(T node_data, int index) {
        if((index >= 0) && (index < lenght)) {
            return;
        }

        if(index == lenght) {
            AddNodeToEnd(node_data);
            return;
        }

        if (index == 0) {
            AddNodeToBegin(node_data);
            return;
        }
        
        try {
            Node<T>* prev_item = ReturnEl(index - 1);
            Node<T>* current_item = ReturnEl(index);
            Node<T>* new_item = new Node<T>;

            new_item -> data = node_data;
            new_item -> next = current_item;
            new_item -> prev = prev_item;

            prev_item -> next = new_item;
            current_item -> prev = new_item;

            lenght++;
        }
        catch(std::bad_alloc ex) {
                   std::cout << ex.what() << std::endl;
               }
    }
    
    void DeleteNode(int index) {
        if (lenght == 0)
            return;

        if((index >= 0) && (index < lenght)) {
                    return;
                }

        Node<T>* current_item = ReturnEl(index);
        Node<T>* prev_item = current_item -> prev;
        Node<T>* next_item = current_item -> next;

        if((lenght > 1) && (prev_item != nullptr)) {
            prev_item -> next = next_item;
        }
        
        if((lenght > 1) && (next_item != nullptr)) {
            next_item -> prev = prev_item;
        }
        
        if(index == 0) 
            first = next_item;
        
        if(index == lenght - 1)
            last = prev_item;

        delete current_item;
        lenght--;
    }
    
    void ClearList() {
        int lenght_list = lenght;
        for (int i = 0; i < lenght_list; i++)
            DeleteNode(0);
    }
    
    void PrintList() {
        Node<T>* el = first;
        for(int i = 0; i < lenght; i++) {
            std::cout << el -> data << " ";
            el = el -> next;
        }
        std::cout << std::endl;
    }
    
    int LenghtOfList() {
        return lenght;
    }

    template <class BidirIt> 
    void reverse(BidirIt Ifirst, BidirIt Ilast) {
        while (Ifirst != Ilast) {
            --Ilast;
            if(Ifirst == Ilast) 
                break;
            using std::swap;

            swap(*Ifirst, *Ilast);
            ++Ifirst;
        }
    }

};

