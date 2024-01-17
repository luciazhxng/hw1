/*
CSCI 104: Homework 1 Problem 1

Use this file to test your split.cpp file.

Create linked lists and split them with your split() function.

You can compile this file like this:
g++ split.cpp test_split.cpp -o test_split
*/

#include <iostream>
#include "split.h"
#include <cstddef>

using namespace std;


int main(int argc, char* argv[])
{
  Node* in = new Node(1, nullptr);
  Node* curr = in;
  curr->next = new Node(2, nullptr);
  curr = curr->next;
  curr->next = new Node(9, nullptr);
  curr = curr->next;
  curr->next = new Node(2, nullptr);
  curr = curr->next;
  curr->next = new Node(5, nullptr);
  curr = curr->next;
  curr->next = new Node(14, nullptr);

  // cout << "full list" <<endl;
  // print(in);

  Node* odds = nullptr;
  Node* evens = nullptr;

  split(in, odds, evens);

  // cout << "odds" << endl;
  // print(odds);

  // cout << "evens" << endl;
  // print(evens);

  // cout << "in"<<endl;
  // print(in);

  curr = odds;
  Node* temp = curr;
  while(curr != nullptr) {
    curr = curr->next;
    delete temp;
    temp = curr;
  }

  curr = evens;
  temp = curr;
  while(curr != nullptr) {
    curr = curr->next;
    delete temp;
    temp = curr;
  }

}


