#include "doublist.h"

template <class type> doublist <type> :: doublist(){   
  //constructor, create header node
  head = pcurrent = new node <type>();
  head->prior = head->next = head;
}
template <class type>
int doublist <type> ::Length() const{  
  //get the length of dll
  node <type> * p = head->next;  //define pointer p，points to the first element in list
  int sum = 0;
  while ( p != head) {sum++; p= p-> next;}
  return sum;
}
template <class type> 
int doublist <type> :: Locate (const type & x){ 
  /* find the node which has value x, p (current pointer) points to this node, and return 1; or return 0 and don't change the pointer*/
  node <type> * p = head->next;
  while ( p != head && p-> data!= x)   //find the node with data x
    p = p->next;
  if (p != head) {pcurrent = p; return 1;}    //got it
  else return 0;                         //didn't find it
}
template <class type>
void doublist <type> :: Insert (const type & x){ 
  /* create a new node that has data x, then insert it prior to current node. ??How about an empty list??*/
  node <type> * newnode = new node <type> (x , pcurrent->prior , pcurrent);      
  /* create new node, its data is x, its prior (prior pointer) points to the node piror to current node (pointed by pcurrent), its next (next pointer) points to current node (pointed by pcurrent).*/
  pcurrent->prior->next = newnode;  //If list is empty, which means head->next = newnode, at this time, pcurrent->prior is head
  pcurrent->prior = newnode;
  pcurrent = pcurrent->prior;
}

template <class type>
void doublist <type> :: DeleteCurrent(){
  /*delete current node in dll, and pcurrent points to next node*/
  if (pcurrent != head )  {
    node <type> * p = pcurrent;  /* define p, which points to the node pointed by pcurrrent */
    pcurrent = pcurrent->next;  // move pcurrent to next node
    pcurrent->prior = p->prior;  // change pcurrent in order to pull out p
    p->prior->next = pcurrent;  
    delete p;        //
  }
  if (pcurrent == head) pcurrent = head->next;
}
template <class type>
void doublist <type> :: Next(){
  /* Make pcurrent point to next node; if current node is the last node, then make pcurrent point to the first node in dll */
  pcurrent = pcurrent->next;  // pcurrent move to next node
  if (pcurrent == head) pcurrent = head->next;
  /* If the list is empty, pcurrent points to header node.*/
  /* If current node is tailer node, at this time, pcurrent points to header node. ???? */
  return pcurrent;
} 

template <class type>
void doublist <type> :: Prior(){
  /* Make pcurrent point to the node prior to current node; if the node is header node, then make pcurrent point to tailer node */
  pcurrent = pcurrent->prior;  // pcurrent前移一个位置
  if(pcurrent == head) pcurrent = head->prior;
  /* If the list is empty, pcurrent points to header node.*/
  /* If current node is header node, at this time, pcurrent points to tailer node. ???? */
}




