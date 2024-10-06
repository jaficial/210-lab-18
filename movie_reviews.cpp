#include <iostream>

using namespace std;

/* Need to incorporate strings into linked lists in the form of movie reviews.
   Code needs to be able to add nodes to the head and tail of the linked list.
   At startup, the program asks which mode the user would like to use (adding by head or tail)
   There should be 2 pieces of data obtained (rating and the comments/review of the movie)*/

// CITED: Will be reusing some of my code from my previous lab submission (Lab 17) for linked list functions

struct Node {
    float value;
    Node *next;
};

void output(Node *);
void delete_node()