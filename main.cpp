/**************************************************************
* Main driver file.                                           *
*                                                             *
* Queue implemented with singly linked list.                  *
* FIFO data structure- new items added to back of queue       *
* Nathan Groves & Jayden Fleisher                               
* CMPS 1063- Fall 2021                                        *
***************************************************************/
#include <iostream>
#include "queue.h"
#include <fstream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

void sleep_and_clear(int s, int n)
{
  //Need to use flush OR endl command to force output (flush buffer)
  cout << n;
  cout << flush;
  sleep(s);
  system("clear");
}

int main() 
{
  //Create a queue object (instance of our class)
  Queue Q1;

  int amountOfNums, randomNum, secondsToLook;
  int numGuess;
  srand(time(NULL));


  cout << "How many numbers do you want in the list? ";
  cout << endl;

  cin >> amountOfNums;

  for (int i = 0; i < amountOfNums; i++)
    {
      randomNum = rand() % 899999 + 100000;
      Q1.Enqueue(randomNum);
    }

  Q1.Print();
  cout << endl;

  cout << "How many seconds do you want to look at each number? ";
  cout << endl;
  

  cin >> secondsToLook;

  while (!Q1.isEmpty())
    {

      sleep_and_clear(secondsToLook, Q1.Peek());
      cout << "What number was just shown? ";
      cout << endl;
      cin >> numGuess;
      if (numGuess == Q1.Peek())
      {
        Q1.Dequeue();
      }
      else 
      {
        //Q1.Reshuffle();
        Q1.Enqueue(Q1.Peek());
        Q1.Dequeue();
        cout << "Try Again!" << endl;
      }
      
    }


  cout << "Congratulations, you got them all! ";

  /*
  //Add some items to the back of the queue
  Q1.Enqueue(90);
  Q1.Enqueue(302);
  Q1.Enqueue(32);
  Q1.Enqueue(12);
  Q1.Enqueue(85);
  Q1.Enqueue(57);
  Q1.Enqueue(4);

  //Print out the list to see the result
  cout << "Starting queue: ";
  Q1.Print();

  cout << endl;

  //Remove some items from the top of the stack
  for(int i = 0; i < 4; i++)
  {
    if(!Q1.isEmpty())
      cout << "Removing from queue: " << Q1.Dequeue() << endl;
    else  
      cout << "Cannot remove from empty queue.";
  }

  cout << endl;

  //Print out the list to see the result
  cout << "Queue after removing: ";
  Q1.Print();

  //Add some items to the top of the stack
  Q1.Enqueue(90);
  Q1.Enqueue(302);
  Q1.Enqueue(32);
  Q1.Enqueue(12);

  cout << endl << endl;

  //Print out the list to see the result
  cout << "Queue after adding new items: ";
  Q1.Print();  

  //Test emptying the list
  cout << endl << endl << "Empty out list: ";
  while(!Q1.isEmpty())
    cout << Q1.Dequeue() << " ";

  //Test dequeueing from an empty list
  cout << endl << "Dequeue from empty list: ";
  cout << Q1.Dequeue();

  //Test enqueueing after deleting all items
  Q1.Enqueue(90);
  Q1.Enqueue(302);
  Q1.Enqueue(32);
  Q1.Enqueue(12);

  cout << endl << endl;

  //Print out the list to see the result
  cout << "Queue after adding new items: ";
  Q1.Print();
  */
} 