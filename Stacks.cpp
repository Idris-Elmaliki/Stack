#include <iostream>

template<class T>
class Node {
public: 
    T data; 
    Node<T>* next; 

    Node(const T &data) 
    : data(data) {
        next = nullptr; 
    }
}; 

template<class T>
class Stack {
protected: 
    int height; 
    Node<T> *top; 

public: 
    Stack(const T &data) {
        Node<T>* newNode = new Node<T>(data); 
        top = newNode; 
        height = 1; 
    }

    bool isEmpty() {
        if(top == nullptr) 
            return true; 

        return false; 
    }

    int size() {
        return height; 
    }

    void push(const T &data) {
        Node<T>* newNode = new Node<T>(data); 

        newNode->next = top; 
        top = newNode; 
        
        height++; 
    }

    T pop() {
        if(height == 0)
            return nullptr; 

        Node<T>* temp = top; 
        T poppedValue = top->data;  

        if(height == 1) {
            top = nullptr; 
        }
        else {
            top = temp->next;
            temp->next = nullptr; 
        }
        delete temp; 
        height--;

        std::cout << "Removed ";
        return poppedValue; 
    }

    void printStack() {
        Node<T>* temp = top; 

        while(temp != nullptr) {
            std::cout << temp->data << ' ';
            temp = temp->next; 
        }
    
        std::cout << '\n'; 
    }

    ~Stack() {
        Node<T>* temp = top; 

        while(top != nullptr) {
            top = temp->next; 
            delete temp;
            temp = top;  
        }
    }
}; 
