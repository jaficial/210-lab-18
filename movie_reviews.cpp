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
    float rating;
    string comments;
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
    Node *current = head;

    int choice;
    cout << "Which linked list method should we use?" << endl;
    cout << setw(15) << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(15) << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << setw(15) << "Choice: ";
    cin >> choice;

    bool more_reviews = 1;
    float rating;

    
    if (choice == 1){
        while(more_reviews){
            cout << "Enter review rating 0-5: ";
            Node *new_value = new Node;
            if (!head){
                head = new_value
                

            }
            
        }
    }
    else {


    }

    delete_linked_list(current, head);
    head = nullptr;
    return 0;
}