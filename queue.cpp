/***************************************************************
* The queue .cpp file is the class implementation file.        *
* This is where we put the full class implementation. Notice   *   
* we have to include the header file with the class definition.*
***************************************************************/
#include <iostream>
#include "queue.h"

using namespace std;

  //Default constructor
  Queue::Queue()
  {
    head = NULL;
    tail = NULL;
    size = 0;
  }

  //Method to add a new item to the back of the queue
  void Queue::Enqueue(int num)
  {
    //Create a new node to add to list
    Node * temp = new Node(num);

    //Check if queue is empty
    if(head == NULL && tail == NULL)
    {
      head = temp;
      tail = temp;
    }

    else
    {
      //Use the tail pointer to add the new node at the end without having to traverse
      tail->next = temp;
      tail = temp;
    }

    size++;
  }//End of Enqueue method

void Queue::Reshuffle()
{
  Node * temp = head;
  head = temp -> next;
  temp = tail -> next;
  tail = temp;
}

  int Queue::Peek()
{
  return head ->data;
}

  //Method to delete item from the front of the queue and return it
  int Queue::Dequeue()
  {
    //Check to see if list is empty (cannot return from empty queue)
    if(head != NULL)
    {
      //Get data from top node to return it after deletion
      int num_to_return = head->data;

      //Make a temporary pointer to top of stack so we can delete it later
      Node * temp = head;

      //Move head pointer to next item in list (deleting old head)
      head = head->next;

      //Delete the previous head
      delete temp;

      size--;

      //See if we just deleted the last item in the list
      //If we did, we should set the head and tail pointers to NULL
      if(size == 0)
      {
        head = NULL;
        tail = NULL;
      }

      //Return the saved value
      return num_to_return;
    }

    //Empty list
    else
    {
      cout << "Cannot return from empty queue.";
      
      //Sentinel value to signify invalid return
      return -1;
    }
  }//End of Dequeue method

  //Method to traverse list and print out each item
  void Queue::Print()
  {
    //Create a temporary Node pointer to traverse the list
    Node * traverse = head;

    //Move to each node and print them out
    while(traverse != NULL)
    {
      cout << traverse->data << " ";
      traverse = traverse->next;
    }
  }//End of Print method

  //Method to see if the queue is empty (don't remove from empty queue)
  bool Queue::isEmpty()
  {
    return head == NULL;
  }//End of isEmpty method