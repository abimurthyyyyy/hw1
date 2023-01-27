/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include "split.h"
#include "iostream"

int main(int argc, char* argv[])
{
    Node* head = new Node(0,nullptr);
    head->value = 1;
    head->next = nullptr;

    
    for (int i = 2; i <= 10; i++)
    {
      Node* temp = head;
      while (temp->next!=nullptr){
        temp=temp->next;
      }
      temp->next = new Node(i,nullptr);
    }
    

    Node* current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    Node* odds = nullptr;
    Node* evens = nullptr;

    split(head, odds, evens);

    current = odds;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    current = evens;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;

    current = head;
    while (current != nullptr)
    {
        std::cout << current->value << " ";
        current = current->next;
    }
    std::cout << std::endl;
    

    
    Node* temp;
    while (evens != nullptr)
    {
        temp = evens;
        evens = evens->next;
        delete temp;
    }
    while (odds != nullptr)
    {
        temp = odds;
        odds = odds->next;
        delete temp;
    }

    return 0;
}
