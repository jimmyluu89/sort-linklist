#ifndef SORTEDNUMBERLIST_H
#define SORTEDNUMBERLIST_H
#include "Node.h"

class SortedNumberList {
private:
   // Optional: Add any desired private functions here

public:
   Node* head;
   Node* tail;

   SortedNumberList() {
      head = nullptr;
      tail = nullptr;
   }

   // Inserts the number into the list in the correct position such that the
   // list remains sorted in ascending order.
   void Insert(double number) {
      // Your code here
      Node* newNode = new Node(number);
       //If list is empty, insert at head.
       if (head == nullptr) {
           head = newNode;
           tail = newNode;
       }
       else if (newNode->GetData() <= head->GetData()) {
           newNode->SetNext(head);
           head->SetPrevious(newNode);
           head = newNode;
       }
       else {
           Node* currNode = head;
           while (currNode->GetNext() != nullptr && currNode->GetNext()->GetData() < newNode->GetData()) {
               currNode = currNode->GetNext();
           }
           
           if (currNode == nullptr && currNode->GetData() < newNode->GetData()) {
               currNode->SetNext(newNode);
               tail->SetNext(newNode);
               tail = newNode;
           }
           newNode->SetNext(currNode->GetNext());
           currNode->SetNext(newNode);
       }
   }

   // Removes the node with the specified number value from the list. Returns
   // true if the node is found and removed, false otherwise.
   bool Remove(double number) {
      // Your code here (remove placeholder line below)Node* temp = head;  //Make a temporary node point to head.
       Node* temp = head;
       
       if (temp == nullptr || head == nullptr) {  //if user don't provide input, return false.
           return false;
       }
       if (head->GetData() == number) {  //If number need to delete is at head.
           head = head->GetNext();
           return true;
       }
       else {
           while (temp != nullptr) {  //Travese temp node throught out a list.
               Node* curNode = temp->GetNext();  //Make a current node point at temp next.
               Node* preNode = temp;
               Node* sucNode = curNode->GetNext();
               if(curNode->GetData() == number) {  //Delete a node if number is found on the list
                   if (curNode->GetNext() == nullptr) {
                       preNode->SetNext(nullptr);
                       tail = preNode;
                       delete curNode;
                       return true;
                   }
                   if (curNode->GetNext() != nullptr) {
                       preNode->SetNext(sucNode);
                       sucNode->SetPrevious(preNode);
                       delete curNode;
                       return true;
                   }
               }
               temp = temp->GetNext();
           }
       }
       return false;
   }
};

#endif
