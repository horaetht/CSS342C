#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include<iostream>
#include<fstream>
#include<string>
#include<stdexcept>
#include "LinkedList.cpp"
using namespace std;

template<typename ItemType>
class LinkedList {
private:
    struct Node {
        ItemType* data;
        Node* next;

        Node(ItemType* newData) : data(new ItemType(*newData)), next(nullptr) {}
        ~Node() { delete data; }
            
    };
    
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    ~LinkedList() { DeleteList(); }

    bool BuildList(const string& fileName);
    bool Insert(ItemType* obj);
    bool Remove(const ItemType& target, ItemType& result);
    bool Peek(const ItemType& target, ItemType& result) const;
    bool isEmpty() const {return head == nullptr; }
    bool Merge(LinkedList& list1);
    void DeleteList();

    LinkedList(const LinkedList& other);
    LinkedList& operator = (const LinkedList& other);

    bool operator==(const LinkedList& other) const;
    bool operator!=(const LinkedList& other) const;

    LinkedList operator+(const LinkedList& other) const;
    LinkedList& operator+=(const LinkedList& other);

    template<typename U>
    friend ostream& operator<<(ostream& os, const LinkedList<U>& list);

private:
    void CopyList(const LinkedList& other);

};

#endif