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
    Node *current = head; // current points to head node

    int choice;
    cout << "Which linked list method should we use?" << endl;
    cout << setw(15) << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(15) << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << setw(15) << "Choice: ";
    cin >> choice;

    bool more_reviews = 1; // if 0, while loop ends
    
    if (choice == 1){ // adding node to the head of the linked list
        while(more_reviews){
            cout << "Enter review rating 0-5: ";
            Node *new_value = new Node;
            float temp_rating;
            cin >> temp_rating;
            string temp_comment;
            cout << "Enter review comments: ";
            cin.ignore();
            getline(cin, temp_comment);
        
            if (!head){ // if its the first node
                head = new_value;
                new_value->next = nullptr;
                new_value->rating = temp_rating;
            }
            else{ // if its not the first node
                new_value->next = head;
                // taking short break, brb
            }
            
        }
    }
    else { // adding node to the tail of the linked list
    

    }

    delete_linked_list(current, head);
    head = nullptr;
    return 0;
}