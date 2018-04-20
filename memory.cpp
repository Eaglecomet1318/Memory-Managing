/*
FILENAME: pr2.cpp
AUTHOR:   Venkata Ponakala
PROJECT GOAL: To simulate the management of a memory sytem by 'feeding' several values that act as processes into a main memory simulation and find the total execution time of all the processes while obeying the memory constraints. A solution must also be found to more efficiently ru all the processes.
*/

//HEADERS
#include <iostream>
#include <stdio.h>
#include <queue>
#include <list>

using namespace std;

struct process {
   int pid; // pid
   int pagus; // number of pages of process
   int time; // time required for process
};

int main() 
{
   queue<struct process> Novum;    // NEW queue of processes
   list<struct process> Suspended; // SUSPENEDED queue of processes; technically a list (which doesn't precisely care for a sequential order as queue does)

   // Process data input (for both parts)
   struct process a = { .pid = 1,.pagus = 23,.time = 2 };
   Novum.push(a);
   Suspended.push_front(a);
   struct process b = { .pid = 2,.pagus = 26,.time = 3 };
   Novum.push(b);
   Suspended.push_front(b);
   struct process c = { .pid = 3,.pagus = 3,.time = 5 };
   Novum.push(c);
   Suspended.push_front(c);
   struct process d = { .pid = 4,.pagus = 7,.time = 4 };
   Novum.push(d);
   Suspended.push_front(d);
   struct process e = { .pid = 5,.pagus = 9,.time = 3 };
   Novum.push(e);
   Suspended.push_front(e);
   struct process f = { .pid = 6,.pagus = 29,.time = 5 };
   Novum.push(f);
   Suspended.push_front(f);
   struct process g = { .pid = 7,.pagus = 12,.time = 2 };
   Novum.push(g);
   Suspended.push_front(g);
   struct process h = { .pid = 8,.pagus = 32,.time = 1 };
   Novum.push(h);
   Suspended.push_front(h);
   struct process i = { .pid = 9,.pagus = 30,.time = 1 };
   Novum.push(i);
   Suspended.push_front(i);
   struct process j = { .pid = 10,.pagus = 30,.time = 3 };
   Novum.push(j);
   Suspended.push_front(j);
   struct process k = { .pid = 11,.pagus = 24,.time = 1 };
   Novum.push(k);
   Suspended.push_front(k);
   struct process l = { .pid = 12,.pagus = 24,.time = 4 };
   Novum.push(l);
   Suspended.push_front(l);
   struct process m = { .pid = 13,.pagus = 26,.time = 1 };
   Novum.push(m);
   Suspended.push_front(m);
   struct process n = { .pid = 14,.pagus = 28,.time = 4 };
   Novum.push(n);
   Suspended.push_front(n);
   struct process o = { .pid = 15,.pagus = 11,.time = 2 };
   Novum.push(o);
   Suspended.push_front(o);
   struct process p = { .pid = 16,.pagus = 8,.time = 4 };
   Novum.push(p);
   Suspended.push_front(p);
   struct process q = { .pid = 17,.pagus = 21,.time = 4 };
   Novum.push(q);
   Suspended.push_front(q);
   struct process r = { .pid = 18,.pagus = 11,.time = 2 };
   Novum.push(r);
   Suspended.push_front(r);
   struct process s = { .pid = 19,.pagus = 25,.time = 3 };
   Novum.push(s);
   Suspended.push_front(s);
   struct process t = { .pid = 20,.pagus = 17,.time = 2 };
   Novum.push(t);
   Suspended.push_front(t);
   struct process u = { .pid = 21,.pagus = 25,.time = 3 };
   Novum.push(u);
   Suspended.push_front(u);
   struct process v = { .pid = 22,.pagus = 29,.time = 5 };
   Novum.push(v);
   Suspended.push_front(v);
   struct process w = { .pid = 23,.pagus = 15,.time = 2 };
   Novum.push(w);
   Suspended.push_front(w);
   struct process x = { .pid = 24,.pagus = 24,.time = 5 };
   Novum.push(x);
   Suspended.push_front(x);
   struct process y = { .pid = 25,.pagus = 8,.time = 2 };
   Novum.push(y);
   Suspended.push_front(y);


   int tempus = 0; // total time units
   list<struct process> Running; // RUNNING Queue of processes
   //list<struct process> Exitus; // EXIT Queue of processes

   list<struct process>::iterator numer;
   list<struct process>::iterator numer1;

   int framus = 32; // symbolizes the 32 page space in memory

   /*
    Procedure name: while(frame>0)..loop
    Procedure author:Venkata Ponakala
    Procedure description:The while loop takes in the process FIFO, and adds onto the RUNNINg queue as long as there is enough 
                          space in the memory. As soon as the process is added, it's popped off the NEW queue. There is also a 
                          counter that exists to chek if the process is sucessfully being added onto the running queue or not.

     */
   while (!Running.empty() || !Novum.empty()) 
   {
      int count = 0; // counter to check if loop is running
      numer = Running.begin();
      while ((framus > 0) && (!Novum.empty())) 
      {
         if ((framus - Novum.front().pagus) >= 0) // if there is any space in memory left
         {
            Running.insert(numer, Novum.front()); //
            framus -= Novum.front().pagus; // frame is taken up by current process pages
            Novum.pop();                   // remove process from NEW queue
            count++;
            cout << count << endl;
         }
         else 
         {
            break;
         }
      }
      // Prints the pid, pages, and time required values of each process to check that it's being implemented
      cout << "Running:[pid,pages,time], tempus" << endl;
      for (numer = Running.begin(); numer != Running.end(); ++numer) 
      {
         cout << "[" << numer->pid;
         cout << "," << numer->pagus;
         cout << "," << numer->time << "]" << endl;
      }

      cout << endl;

      bool b1 = true;

      /*
      Procedure name: while (bl)loop
      Procedure author:Venkata Ponakala
      Procedure description: As long as the boolean stays true, this loop will run
      Procedure argument: bl, input, boolean, this variable is in control of continuing the loop
      */
      while (b1) 
      {
         /*
         Procedure name: for(numer=Running.begin...) loop
         Procedure author:Venkata Ponakala
         Procedure description: for loo[ initializes iterator and pases through the entire RUNNING queue
         Procedure argument: (numer=Running.begin();numer!=Running.end();,
         */
         for (numer = Running.begin(); numer != Running.end();)
         {
            cout << "Numer.time: " << numer->time << endl;
            if (numer->time == 0) // if the time required, as the iterator points to the the time req of the process currently running, hits 0,
            {
               cout << "framus: " << framus << endl;
               cout << "numerpagus: " << numer->pagus << endl;
               framus += numer->pagus;
               numer = Running.erase(numer); // remove the process from RUNNING queue
               b1 = false; // and switch b1 value to false.
            }
            else {
               ++numer; // if there are no proceses to be removed, iterator continues to next process in line
            }

         }
         if ((!b1) || (Running.empty())) // if either b1 is false or Running queue is empty, break off loop
         {
            break;
         }

         for (numer = Running.begin(); numer != Running.end(); ++numer) 
         {
            numer->time = numer->time - 1;
         }
         tempus++; // Adds up Total execution time (FIFO) 
      }// END while (b1)

   }
   cout << endl;
   cout << "FIFO Algorithm Execution Time: " << tempus << endl << endl;  // Prints total FIFO execution time
   cout << endl;

   cout << "PART 2: OPTIMIZATION OF EXECUTION TIME." << endl; // Prints distinction between two times
   cout << endl << endl;


   tempus = 0;
   while (!Running.empty() || !Suspended.empty())  // While neither RUNNING or SUSPENDED queue is not full, loop continues
   {
      numer = Running.begin();                     
      while ((framus > 0) && (!Suspended.empty())) // While the number of frames is greater than 0 
                                                   // and SUSPENDED queue is empty, continue while loop
      {
         int maximuspage = 0;// starting value of maximum number of pages
         std::list<struct process>::iterator cool = Suspended.end(); //iterator starts at end, basically equivalent to null																		
         for (std::list<struct process>::iterator i = Suspended.begin(); i != Suspended.end(); ++i) // iterator goes through Suspended Queue
         {
            if (((i->pagus)>maximuspage) && ((framus - (i->pagus)) >= 0))
            {
               maximuspage = i->pagus; //The maximum number of pages is currently that of whichever process the pointer is pointing towards
               cool = i;               // cool is set equal to the iterator variable value
            }
         }
         if (cool != Suspended.end()) //if the iterator is not at the end of the list, then add process to Running
         {
            Running.push_front(*cool);  // Inserts at the front of the newly running process for best time
            framus -= (*cool).pagus; // Frame is taken up by current process pages
            Suspended.erase(cool);   // Removes process from queue
         }
         else 
         {
            break;
         }
      }
      bool b1 = true;
      /*
      Procedure name: while (bl)loop
      Procedure author:Venkata Ponakala
      Procedure description: As long as the boolean stays true, this loop will run
      Procedure argument: bl, input, boolean, this variable is in control of continuing the loop
      */
      while (b1) 
      {
         /*
         Procedure name: for(numer=Running.begin...) loop
         Procedure author:Venkata Ponakala
         Procedure description: for loo[ initializes iterator and pases through the entire RUNNING queue
         Procedure argument: (numer=Running.begin();numer!=Running.end();,
         */
         for (numer = Running.begin(); numer != Running.end();) 
         {
            if (numer->time == 0) // If the time required, as the iterator points to the the time req of the process currently running, 
                                  // hits 0,
            {
               framus += numer->pagus;       // Frees up the frames that were being used
               numer = Running.erase(numer); // remove the process from RUNNING queue
               b1 = false;                   // and switch b1 value to false.
            }
            else 
            {
               ++numer; // If there are no proceses to be removed, iterator continues to next process in line
            }

         }// END for (numer = Running.begin()....)

         if ((!b1) || (Running.empty())) // if either b1 is false or Running queue is empty, break off loop
         {
            break; //  end 
         }

         for (numer = Running.begin(); numer != Running.end(); ++numer)   // iterates through RUNNING queue
         {
            numer->time = numer->time - 1; //The time required of the process decrements
         }
         tempus++; //Increment total exececution (in this case, for greedy approach)
      }

   }//END while (!Running.empty()... loop

   cout << "Greedy Approach Algorithm Execution Time: " << tempus << endl << endl; // Prints total execution time of greedy approach
   return 0;

}// END int main()
