#ifndef LINKEDLIST_CPP
#define LINKEDLIST_CPP
using namespace std;
#include "LinkedList.h"

template<typename ItemType>
bool LinkedList<ItemType>::BuildList(const string& fileName) {
    ifstream file(fileName);
    if (!file) return false;

    ItemType* temp = nullptr;
    while (file) {
        temp = new ItemType();
        if(file >> *temp) {
            Insert(temp);
        } else {
            delete temp;
        }
    }
    file.close();
    return true;
}

template<typename ItemType>//******* Bug
bool LinkedList<ItemType>::Insert(ItemType* obj) {
    Node* newNode = new Node(obj);

    if (!head || *(newNode->data) < *(head->data)) {
        newNode->next = head;
        head = newNode;
        //cout <<"Inserted at head: " << *(newNode->data) << endl;
        return true;
    }


    //Traverse the list
    Node* current = head;
    while (current->next && *(current->next->data) < *(newNode->data)) {
        current = current->next;
    }

    //checking for duplicates
    if (current->next && *(current->next->data) == *(newNode->data)) {
        delete newNode;
        //cout << "Duplicate not inserted: " << *(obj) << endl;
        return false;
    }

    //Insert the new code
    newNode->next = current->next;
    current->next = newNode;
    //cout << "Inserted: " << *(newNode->data) << endl;
    return true;
}

template<typename ItemType>
bool LinkedList<ItemType>::Remove(const ItemType& target, ItemType& result) {
    if (!head) return false;

    if (*(head->data) == target) {
        Node* temp = head;
        head = head->next;
        result = *(temp->data);
        delete temp;
        return true;
    }

    Node* current = head;
    while (current->next && *(current->next->data) != target) {
        current = current->next;
    }

    if (current->next) {
        Node* temp = current->next;
        current->next = temp->next;
        result = *(temp->data);
        delete temp;
        return true;
    }

    return false;
}

template<typename ItemType>
bool LinkedList<ItemType>::Peek(const ItemType& target, ItemType& result) const {
    Node* current = head;
    while (current) {
        if (*(current->data) == target) {
            result = *(current->data);
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename ItemType>
void LinkedList<ItemType>::DeleteList() {
    while (head) {
        Node* temp = head;
        // delete head->data;
        // head = head->next;
        head = head->next;
        delete temp->data;
        delete temp;
    }
    head = nullptr;
}

template<typename ItemType> //*** key learned insert creates a new copy of data
//but then the deleteList delete the original data thats still being using by the first
//Cause---> delete everything caused my hours to fix T_T
bool LinkedList<ItemType>::Merge(LinkedList& list1) {
    if (this == &list1) return false;  // Prevent self-merge

    Node* current = list1.head;
    while (current) {
        Node* next = current->next;  
        
        // Insert current node into this list
        if (!head || *(current->data) < *(head->data)) {
            current->next = head;
            head = current;
        } else {
            Node* pos = head;
            while (pos->next && *(pos->next->data) < *(current->data)) {
                pos = pos->next;
            }
            
            // verify duplicates
            if (pos->next && *(pos->next->data) == *(current->data)) {
                ItemType* temp = current->data;
                delete current;
                delete temp;
            } else {
                current->next = pos->next;
                pos->next = current;
            }
        }
        current = next;
    }

    list1.head = nullptr;
    
    return true;
}



template<typename ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList& other) : head(nullptr) {
    CopyList(other);
}

template<typename ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator=(const LinkedList& other) {
    if (this != &other) {
        DeleteList();
        CopyList(other);
    }
    return *this;
}

template<typename ItemType>
bool LinkedList<ItemType>::operator==(const LinkedList& other) const {
    Node* current1 = head;
    Node* current2 = other.head;

    while (current1 && current2) {
        if (*(current1->data) != *(current2->data)) return false;
        current1 = current1->next;
        current2 = current2->next;
    }

    return !current1 && !current2;
}

template<typename ItemType>
bool LinkedList<ItemType>::operator!=(const LinkedList& other) const {
    return !(*this == other);
}

template<typename ItemType>
LinkedList<ItemType> LinkedList<ItemType>::operator+(const LinkedList& other) const {
    LinkedList result(*this);
    result += other;
    return result;
}

template<typename ItemType>
LinkedList<ItemType>& LinkedList<ItemType>::operator+=(const LinkedList& other) {
    Node* current = other.head;
    while (current) {
        Insert(current->data);
        current = current->next;
    }
    return *this;
}

template<typename ItemType>
ostream& operator<<(ostream& os, const LinkedList<ItemType>& list) {
    typename LinkedList<ItemType>::Node* current = list.head;
    if(!current) {
        os << "(empty)"; 
        return os;
    }

    while (current) {
        os << *(current->data);
        if(current->next) os << " ";
        current = current->next;
    }
    return os;
}

template<typename ItemType>
void LinkedList<ItemType>::CopyList(const LinkedList& other) {
    Node* current = other.head;
    while (current) {
        Insert(current->data);
        current = current->next;
    }
}

#endif
