#include <iostream>
#include <string>
#include <iomanip>

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
void insert_node(Node *, Node *, Node *);
void add_front_node(Node *, Node *, int);
void add_tail_node();
void delete_linked_list(Node *, Node *);

void delete_linked_list(Node*current, Node *head){
    while(current){
        head = current->next;
        delete current;
        current = head;
    }
}

int main(){
    Node *head = nullptr;
    int choice;
    cout << "Which linked list method should we use?" << endl;
    cout << setw(15) << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(15) << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << setw(15) << "Choice: ";
    cin >> choice;
    bool review = 1;
    float rating;

    if (choice == 1){
        while(review){
            cout << "Enter review rating 0-5: ";
            cin >> rating;
            cout << endl; 
        }
        
    }

    else{

    
    }

    head = nullptr;
    return 0;
}