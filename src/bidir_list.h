#pragma once

#include <iostream>
#include <iterator>

template <typename T>
struct Node {
    T data;
    Node<T> *next;
    Node<T> *prev;

};


template <typename T>
class BidirList {

private:
    Node<T> *first;
    Node<T> *last;
    int lenght;
    

public:

    BidirList() {
        first = nullptr;
        last = nullptr;
        lenght = 0;
    }

    BidirList(const BidirList& obj) {
        ClearList();
        Node<T>* el = first;
        while (el != nullptr) {
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
          ClearList();
    }

    
class  Iterator {
        friend class BidirList<T>;
private:
        Node<T>* m_node;
        BidirList<T>* m_list;
       
        Iterator() : m_list(nullptr), m_node (nullptr) {}
       

public:

        Iterator(const Iterator &obj) : m_node(obj.m_node) {};
        Iterator(BidirList<T>* list, Node<T>* node) : m_list(list), m_node(node) {};

        Iterator next_it() const {
        if (m_node != nullptr)
            return Iterator(m_list, m_node->next);
        return *this;
        }

        T &operator*() const {
            return m_node -> data;
        }

        T *operator->() const {
            return &m_node  -> data;
        }

        T &operator[](int j) {
            return m_node [j].data();
        }

        bool operator==(const Iterator &other) const {
            return m_list ==  other.m_list && m_node ==  other.m_node;
        }

        bool operator!=(const Iterator &other) const {
            return !(*this == other);
        }
        
        bool operator<(const Iterator &other) const {
            return m_node < other.m_node;
        }       
        
        bool operator<=(const Iterator &other) const {
            return m_node <= other.m_node;
        }

        bool operator>(const Iterator &other) const {
            return  m_node > other.m_node; 
        }

        bool operator>=(const Iterator &other) const {
            return  m_node >= other.m_node; 
        }

        Iterator &operator++() {
            if (m_node != nullptr)
                m_node = m_node -> next;
            return *this;
        }
        
        Iterator operator++(int) {
            ++m_node;
            return *this;
        }
        
        Iterator &operator--() {
           if (m_node != nullptr)
                m_node = m_node -> prev;
            return *this;
        }

        Iterator operator--(int) {
            Node<T> n = m_node;
            m_node--;
            return n;
        }

        Iterator &operator-=(int j) {
            m_node-=j; return *this;
        }

        Iterator &operator+=(int j) { 
           m_node+=j; return *this;
        }

        Iterator operator+(int j) const { 
            return Iterator(m_node +j);
        }


        Iterator operator-(int j) const { 
            return Iterator(m_node -j);
        }

        int operator-(Iterator j) const { 
            return int(m_node - j.m_node );
        }
    };


    Iterator  begin() {
       return Iterator(this, first);
    }

    Iterator end() {
        return Iterator(this, last).next_it();
    }


    T GetNode(int index){
        if((index < 0) && (index >= lenght)) {
            throw std::out_of_range("Incorrect index");
        }
        size_t s = 0;
        for(BidirList<T>::Iterator it = this -> begin(); it != this -> end(); ++it) {
            s++;
            if (s == index) return *it;
        }
        return first->data;
    }

  

    void SetNode(T node_data, int index) {
        if((index < 0) && (index >= lenght)) {
             throw std::out_of_range("Incorrect index");
        }
        size_t s = 0;
        for(BidirList<T>::Iterator it = this -> begin(); it != this -> end(); ++it) {
            s++;
            if (s == index) *it = node_data;
        }
       
    }

    bool IsNoEmpty() {
        if (first == nullptr)
            return 0;
        else return 1;
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
    
    void InsertNodeTo(T node_data, Iterator it) {
        if((it < begin()) && (it >= end())) {
            return;
        }

        if(it == end()) {
            AddNodeToEnd(node_data);
            return;
        }

        if (it == begin()) {
            AddNodeToBegin(node_data);
            return;
        }
        
        try {
            Node<T>* prev = it.m_node -> prev;
            prev -> next = new Node<T>;
            prev -> next -> data = node_data;
            prev -> next -> next = it.m_node;
            prev -> next -> prev = prev;
            it.m_node -> prev = prev -> next;
     
         //  Node<T>* prev_item = it.m_node -> prev;

         //  Node<T>* current_item = it.m_node;
         //  Node<T>* new_item = new Node<T>;

         //  new_item -> data = node_data;
         //  new_item -> next = current_item;
         //  new_item -> prev = prev_item;

         //  prev_item -> next = new_item;
         //  current_item -> prev = new_item;

           lenght++;
        }
        catch(std::bad_alloc ex) {
                   std::cout << ex.what() << std::endl;
               }
    }
    
    void ClearList() {
        auto temp = first;
        first = nullptr;
        last = nullptr;
        while(temp) {
            auto removed = temp;
            temp = temp -> next;
            delete removed;
        }

        lenght = 0;
    }
    
 
    int LenghtOfList() {
        return lenght;
    }


};

