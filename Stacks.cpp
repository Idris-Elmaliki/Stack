#include <iostream>

template<class T>
class Node {
public: 
    T term; 
    Node* next; 

    Node(const T &term) 
    : term(term) {
        next = nullptr; 
    }
}; 

template<class T>
class Stack {
protected: 
    int height; 
    Node<T> *top; 

public: 
    Stack(const T &term) {
        Node* newNode = new Node(term); 
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

    void push(const T &term) {
        Node* newNode = new Node(term); 

        newNode->next = top; 
        top = newNode; 
        
        height++; 
    }

    T pop() {
        if(height == 0)
            return INT32_MIN; 

        Node* temp = top; 
        T poppedValue = top->value;  

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
        Node* temp = top; 

        while(temp != nullptr) {
            std::cout << temp->value << ' ';
            temp = temp->next; 
        }
    
        std::cout << '\n'; 
    }

    ~Stack() {
        Node* temp = top; 

        while(top != nullptr) {
            top = temp->next; 
            delete temp;
            temp = top;  
        }
    }
}; 