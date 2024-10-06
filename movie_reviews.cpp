#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
//
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
void add_front_node(Node *, Node *, string, int);
void add_tail_node();
void delete_linked_list(Node *, Node *);

void delete_linked_list(Node*current, Node *head){
    while(current){
        head = current->next;
        delete current;
        current = head;
    }
}

// front node function works
void add_front_node(Node *new_value, Node *head, string temp_comment, int temp_rating){
	new_value->next = head;
	new_value->comments = temp_comment;
	new_value->rating = temp_rating;
}

void add_tail_node(Node *new_value, Node *tail, string temp_comment, int temp_rating){
	new_value->next = tail;
	new_value->comments = temp_comment;
	new_value->rating = temp_rating;
}

// output is fixed
void output(Node * list){
    if (!list){
        cout << "Empty list." << endl;
        return;
    }

    else{
        int count = 1;
        Node * current = list;
        cout << "Outputting all reviews:" << endl;
        float average;
        while(current){
            cout << setw(4) << "" << "> Review " << count++ << ": " << current->rating << ": " << current->comments;
            cout << endl;
            average += current->rating;
            current = current->next;
        }
        count--;
        average = average / count;
        cout << setw(4) << "" << "> Average: " << average << endl;
    }
}

int main(){
    Node *head = nullptr;
    Node *current = head; // current points to head node

    int choice;
    cout << "Which linked list method should we use?" << endl;
    cout << setw(4) << "" << "[1] New nodes are added at the head of the linked list" << endl;
    cout << setw(4) << "" << "[2] New nodes are added at the tail of the linked list" << endl;
    cout << setw(4) << "" << "Choice: ";
    cin >> choice;

    bool more_reviews = 1; // if 0, while loop ends
    char temp_more_reviews;
    
    if (choice == 1){ // adding node to the head of the linked list
        while(more_reviews){
            float temp_rating;
            string temp_comment;

            cout << "Enter review rating 0-5: ";
            Node *new_value = new Node; // Node *new_value is in loop as a new one has to get defined for each new node
            cin >> temp_rating;
            cout << "Enter review comments: ";
            cin.ignore();
            getline(cin, temp_comment);
        
            if (!head){ // if its the first node
                head = new_value;
                new_value->next = nullptr;
                new_value->rating = temp_rating;
                new_value->comments = temp_comment;
            }
            else{ // if its not the first node
                add_front_node(new_value, head, temp_comment, temp_rating);
                head = new_value; // head node is now the most recently added node
            }
            cout << "Enter another review? Y/N: ";
            cin >> temp_more_reviews;
            if (temp_more_reviews == 'n'){
                more_reviews = 0;
            }
        }
   }
    
    else { // adding node to the tail of the linked list, 
	    /* this needs to be formatted in a way where new value needs to 
	     be pointing to a null in order to add to the tail. Return to this function afterwards. */ 
        while(more_reviews){
            float temp_rating;
            string temp_comment;
            cout << "Enter review rating 0-5: ";
            Node *new_value = new Node;
            cin >> temp_rating;
            cout << "Enter review comments: ";
            cin.ignore();
            getline(cin, temp_comment);
            Node *tail = new Node; // tail node
            
            if (!head){ // in the case that it is the first node
                head = new_value;
                new_value->next = nullptr;
                new_value->rating = temp_rating;
                new_value->comments = temp_comment;
                tail = head; // tail-> is now pointing to nullptr
            }
            else{
                // add_tail_node(new_value, tail, temp_comment, temp_rating);
                new_value->next = tail;
                new_value->comments = temp_comment;
                new_value->rating = temp_rating;
                tail = new_value; // tail node is now the most recently added node
            }
            cout << "Enter another review? Y/N: ";
            cin >> temp_more_reviews;
            if (temp_more_reviews == 'n'){
                more_reviews = 0;
            }
        }
    }

    //---------------------------------------------------------------------------------------
    
    // output is printing out correctly
    output(head);

    delete_linked_list(current, head);
    head = nullptr;
    // linked list is properly deallocated
    return 0;
}
