/*****************************************************************************
*                    
*  Author:           Miguel Mendoza
*  Email:            Miguelmen.1017@gmail.com
*  Label:            Vector Class
*  Title:            P01
*  Course:           2143 Objective Oriented Programming
*  Semester:         Fall 2022
* 
*  Description:
*     In this Program I will be Making Classes and implementing the use of other data 
      structures such as arrays, linked list, and Vectors in Methods.
* 
*  Usage:
*        In Order to Use & Run this program you will need an IDE Or Source Editor That                that can compile C++                      
* 
*  Files:            (list of all source files used in this program)
*****************************************************************************/

//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// Below I am making a Singly linkedlist 

//Create a Node struct
struct Node
{
  int data;
  Node * next;

  Node(int num)
  {
    data = num;
    next = NULL;
  }
};
/*
 
  /$$       /$$           /$$                       /$$       /$$       /$$             /$$          
 | $$      |__/          | $$                      | $$      | $$      |__/            | $$          
 | $$       /$$ /$$$$$$$ | $$   /$$  /$$$$$$   /$$$$$$$      | $$       /$$  /$$$$$$$ /$$$$$$        
 | $$      | $$| $$__  $$| $$  /$$/ /$$__  $$ /$$__  $$      | $$      | $$ /$$_____/|_  $$_/        
 | $$      | $$| $$  \ $$| $$$$$$/ | $$$$$$$$| $$  | $$      | $$      | $$|  $$$$$$   | $$          
 | $$      | $$| $$  | $$| $$_  $$ | $$_____/| $$  | $$      | $$      | $$ \____  $$  | $$ /$$      
 | $$$$$$$$| $$| $$  | $$| $$ \  $$|  $$$$$$$|  $$$$$$$      | $$$$$$$$| $$ /$$$$$$$/  |  $$$$/      
 |________/|__/|__/  |__/|__/  \__/ \_______/ \_______/      |________/|__/|_______/    \___/        
                                                                                                     
                                                                                                     
                                                                                                     
 
*/
                                                                                                     
//Create a class to implement the linked list
class Linked_List
{
  private:
    //Head pointer always points to start of list
    Node * head;
    Node * tail;
    int length;

  public:
    //Default constructor
    Linked_List()
    {
      head = NULL;
    }

    //Method to create new node and link to beginning of list
    void insert_front(int num)
    {
      //Create a new node
      Node * temp = new Node(num);

      //Check if empty list. If it is, new node is head (first element)
      if(head == NULL)
      {
        head = temp;
      }
      //Otherwise, link in rest of list and make new head (first element)
      else
      {
        temp->next = head;
        head = temp;
      }
    } //End of insert_front method

    //Method to create new node and link at back of list
    void insert_back(int num)
    {
      //Create a new node to link in
      Node * temp = new Node(num);

      //Check if empty list
      if(head == NULL)
        head = temp;
      else
      {
        //Make temp pointer to traverse list
        Node * traverse = head;

        //Traverse list until you reach last node
        while(traverse->next != NULL)
        {
          traverse = traverse->next;
        }

        traverse->next = temp;
      }
    }//End of insert_back method

    //Method to create a new node and insert in order
    void insert_in_order(int num)
    {
      //Create a new node
      Node * temp = new Node(num);

      //Check if empty list
      if(head == NULL)
        head = temp;
      else
      {
        //Temp pointer to traverse list
        Node * traverse = head;

        //Check if new node should be first
        if(num < head->data)
          insert_front(num);

        else
        {
          //Traverse points to node in list to link
          while(traverse->next != NULL && (num > traverse->next->data))
          {
            traverse = traverse->next;
          }

          if(traverse->next == NULL)
            insert_back(num);
          else
          {
            //Link new node to rest of list
            temp->next = traverse->next;
            traverse->next = temp;
          }
        }
      }//End of insert in order
    }//End of insert_in_order method

    //Method to remove a node from list
    void remove(int num)
    {
      Node * traverse = head;

      //Delete node if front of list
      if(num == head->data)
      {
        head = head->next;
        delete traverse;
      }

        //Otherwise, traverse the list
        else
        {
          //Traverse the list until you find the item
          //STOP BEFORE you get to the actual node (can't back up)
          //ORDER MATTERS- we need short circuiting here (why?)
          while(traverse->next != NULL && traverse->next->data != num)
            traverse = traverse->next;

          //If item to be deleted is the last element in list
          if(traverse->next == NULL)
          {
            //Don't need to link anything for last element. Just delete it.
            delete traverse;
            traverse = NULL;
          }
          else
          {
            //Use a temp pointer to delete this node later
            Node * remove_temp = traverse->next;

            //Link the list together skipping the node to be removed
            traverse->next = traverse->next->next;

            //Delete node to be removed using temp pointer
            delete remove_temp;
            remove_temp = NULL;
          }
        }
    }

    //Method to print out the list
    void print()
    {
      //Make a temporary pointer to traverse the list
      //NEVER traverse using the head pointer itself!! You will lose your list
      Node * traverse = head;

      //Move through each node one at a time until you reach the end of list (NULL)
      while(traverse != NULL)
      {
        //At each node, print out the data and move to next node
        cout << traverse->data << " ";
        traverse = traverse->next; 
      }
    } //End of print method

 
};

/*
 
  /$$    /$$                      /$$                                /$$$$$$  /$$                             
 | $$   | $$                     | $$                               /$$__  $$| $$                             
 | $$   | $$ /$$$$$$   /$$$$$$$ /$$$$$$    /$$$$$$   /$$$$$$       | $$  \__/| $$  /$$$$$$   /$$$$$$$ /$$$$$$$
 |  $$ / $$//$$__  $$ /$$_____/|_  $$_/   /$$__  $$ /$$__  $$      | $$      | $$ |____  $$ /$$_____//$$_____/
  \  $$ $$/| $$$$$$$$| $$        | $$    | $$  \ $$| $$  \__/      | $$      | $$  /$$$$$$$|  $$$$$$|  $$$$$$ 
   \  $$$/ | $$_____/| $$        | $$ /$$| $$  | $$| $$            | $$    $$| $$ /$$__  $$ \____  $$\____  $$
    \  $/  |  $$$$$$$|  $$$$$$$  |  $$$$/|  $$$$$$/| $$            |  $$$$$$/| $$|  $$$$$$$ /$$$$$$$//$$$$$$$/
     \_/    \_______/ \_______/   \___/   \______/ |__/             \______/ |__/ \_______/|_______/|_______/ 
                                                                                                              
                                                                                                              
                                                                                                              
 
*/
template<typename T>
class Vector{
  private:
    T *array;
    int size;
    int capacity;

  public:
      Vector(){
        size = capacity = 0;//Starting Size is 0
      }
      Vector(int num){
                size = capacity = 10;
                array = new T[num]; 
                          
      }
  
      // size < capacity push
      // if size == capacity we allocate new array .. copy contents
      void new_allocation(){
        T* temp = new T[size+5];
        capacity = size + 5;

        for(int i = 0;i < size; i++){
          temp[i] = array[i];
        }
        array = temp;
        delete []temp;
        
      }
      void push_back(T x ){
        if(size == capacity){
          new_allocation();// Increase array size by 5
        }
        array[size] = x; // PUSHES BACK.
        size++;
      }
      // This function will delete from list but cout that statement if empty
      void pop_back(){
        if(size == 0){
            cout << "Cant Pop Anymore List is Empty" <<endl;
            return;
        }
        size--;
      }
      int s(){
          return size;// Will return Size of List
        }
      int c(){
        return capacity;//Will return capacity of List
      }
      //Overloading Functions
      T operator[](int index){
        return array[index];
      }
};

int main() 
{
  //Create a linked list object
  Linked_List L1, L2, L3;
  cout<< "Below is the use Of Single Link List Methods output " << endl;
  cout << "--------------------------------------------------------- " <<endl;
   //Example of using front insert method
  L1.insert_front(3);
  L1.insert_front(6);
  L1.insert_front(72);
  L1.insert_front(9);
  L1.insert_front(12);
  L1.insert_front(0);

  //Example of using back insert method
  L2.insert_back(3);
  L2.insert_back(6);
  L2.insert_back(9);
  L2.insert_back(12);
  L2.insert_back(50);
  L2.insert_back(0);

  //Example of using back insert method
  L3.insert_in_order(3);
  L3.insert_in_order(50);
  L3.insert_in_order(9);
  L3.insert_in_order(0);
  L3.insert_in_order(82);
  L3.insert_in_order(12);

  //Print out the list to test it
  cout << "Insert at front: ";
  L1.print();

  cout << endl;

  cout << "Insert at back: ";
  L2.print();

  cout << endl;

  cout << "Insert in order: ";
  L3.print();

  L1.remove(9);
  L2.remove(9);
  L3.remove(9);

  cout << endl;

  //Print out the list to test it
  cout << "Insert at front: ";
  L1.print();

  cout << endl;

  cout << "Insert at back: ";
  L2.print();

  cout << endl;

  cout << "Insert in order: ";
  L3.print(); 
  cout << " " << endl;
  cout<< "-------------------------------------------------- " <<endl;
  cout<< "Custom Vector Class Below" << endl;

    Vector<int> v;
  v.push_back(1);
  v.push_back(2);
  v.push_back(4);
  v.pop_back();
  for(int i = 0; i <v.s();i++){
    cout << v[i]<< " ";
    cout << endl;
    
  }
    cout << v.s() << " "<< v.c()<< endl;
  };
