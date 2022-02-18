#include <string>
using namespace std;
#include "LibrarySystem.h"
#include "ClassReading.h"
extern ofstream myFile;

struct Node{
    struct Node *next;
    struct Node *prev;
    int userIds;
    string userNames;
};
struct Node *start;

struct Node1{
    struct Node1 *next1;
    int movieIds;
    string movieTitles;
    int years;
};
struct Node1 *head;

struct NodeCheck{ //check out node
    struct NodeCheck *next2;
    int movieId2;
    string movieTitles2;
    int years2;
    int userId2;
};
struct NodeCheck *last2;


void LibrarySystem::addMovie(const int movieId, const string movieTitle, const int year){

    Node1 *temp2 =new Node1();

    if (head == NULL){
        // Assigning the data.
        temp2 -> movieIds = movieId;
        temp2 -> years = year;
        temp2 -> movieTitles = movieTitle; //appending
        head = temp2;
        // Creating the link.
        head -> next1 = head;
        myFile<<"Movie "<<  movieId<<" has been added\n";
        return;
    }
    Node1 *s =  new Node1();
    s = head->next1;
    while (s != head){
        if (s->movieIds == movieId){
            myFile<<"Movie "<<movieId<<" already exists\n";
            return;
        }
        s = s->next1;
    }
    if (s->movieIds == movieId){
        myFile<<"Movie "<<movieId<<" already exists\n";
        return;
    }
    else{
        struct NodeCheck *p;
        // If list is empty, return.
        if (last2 == NULL){
            myFile<<"Movie "<<  movieId<<" has been added\n";
            temp2 -> movieIds = movieId;
            temp2 -> movieTitles = movieTitle;
            temp2 -> years = year;
            temp2 -> next1 = head -> next1;
            head -> next1 = temp2;
            head =temp2;
            return;
        }
        // Pointing to first Node of the list.
        p = last2 -> next2;
        // Traversing the list.
        do{
            if(p->movieId2 == movieId) {
                myFile<<"Movie "<<movieId<<" already exists\n";
                return;
            }
        }
        while(p != last2->next2);
    }

        myFile<<"Movie "<<  movieId<<" has been added\n";
        temp2 -> movieIds = movieId;
        temp2 -> movieTitles = movieTitle;
        temp2 -> years = year;
        temp2 -> next1 = head -> next1;
        head -> next1 = temp2;
        head =temp2;  //sonradan eklendi
        return;
    }


void LibrarySystem::deleteMovie(const int movieId) {
    // If linked list is empty
    if (head == NULL){
        struct NodeCheck *p;
        // If list is empty, return.
        if (last2 == NULL){
            myFile<<"movie "<<movieId<<" does not exist\n";
            return;
        }
        // Pointing to first Node of the list.
        p = last2 -> next2;
        // Traversing the list.
        do{
            if(p->movieId2 == movieId){
                DeleteChecked(movieId);
                myFile<<"movie "<<movieId <<" has been checked out \n";
                myFile<<"movie "<<movieId << " has been deleted \n";
                return;
            }
            p = p -> next2;
        }
        while(p != last2->next2);
        myFile<<"movie "<<movieId<<" does not exist\n";
        return;
    }

    // If the list contains only a single node
    if((head)->movieIds==movieId && (head)->next1==head)
    {
        free(head);
        head=NULL;
        myFile<<"movie "<<movieId <<" has not been checked out \n";
        myFile<<"movie "<<movieId << " has been deleted \n";
        return;
    }

    Node1 *last=head,*d;

    // If head is to be deleted
    if((head)->movieIds==movieId)
    {

        // Find the last node of the list
        while(last->next1!=head)
            last=last->next1;

        last->next1=(head)->next1;
        free(head);
        head=last->next1;
        myFile<<"movie "<<movieId <<" has not been checked out \n";
        myFile<<"movie "<<movieId << " has been deleted \n";
        return;

    }

    // Either the node to be deleted is not found
    // or the end of list is not reached
    while(last->next1!=head && last->next1->movieIds!=movieId)
    {
        last=last->next1;
    }

    // If node to be deleted was found
    if(last->next1->movieIds==movieId)
    {
        d=last->next1;
        last->next1=d->next1;
        free(d);
        myFile<<"movie "<<movieId <<" has not been checked out \n";
        myFile<<"movie "<<movieId << " has been deleted \n";
        return;
    }
    else{
        struct NodeCheck *p;
        // If list is empty, return.
        if (last2 == NULL){
            myFile<<"movie "<<movieId<<" does not exist\n";
            return;
        }
        // Pointing to first Node of the list.
        p = last2 -> next2;
        // Traversing the list.
        do{
            if(p->movieId2 == movieId){
                DeleteChecked(movieId);
                myFile<<"movie "<<movieId <<" has been checked out \n";
                myFile<<"movie "<<movieId << " has been deleted \n";
                return;
            }
            p = p -> next2;
        }
        while(p != last2->next2);
        myFile<<"movie "<<movieId<<" does not exist\n";
        return;
    }

}

void LibrarySystem::DeleteChecked(const int movieId) {
    // If the list contains only a single node,delete that node; list is empty
    if((last2)->movieId2==movieId && (last2)->next2==last2) {
        free(last2);
        last2=NULL;
    }
    NodeCheck *head= last2,*d1;

// If key is the head
    if((last2)->movieId2==movieId) {
        while(head->next2!=last2) // Find the last node of the list
            head=head->next2;

        // point last node to next of head or second node of the list
        head->next2=(last2)->next2;
        free(last2);
        last2 = head->next2;
    }

// end of list is reached or node to be deleted not there in the list
    while(head->next2!=last2 &&head->next2->movieId2 !=movieId) {
        head=head->next2;
    }
// node to be deleted is found, so free the memory and display the list
    if(head->next2->movieId2==movieId) {
        d1=head->next2;
        head->next2=d1->next2;
        free(d1);
    }
}

void LibrarySystem::display1(const int movieId){
    if (head == NULL){
        struct NodeCheck *p;
        // If list is empty, return.
        if (last2 == NULL){
            return;
        }
        // Pointing to first Node of the list.
        p = last2 -> next2;
        // Traversing the list.
        do{
            if(p->movieId2 == movieId){
                DeleteChecked(movieId);
                return;
            }
            p = p -> next2;
        }
        while(p != last2->next2);
        return;
    }

    // If the list contains only a single node
    if((head)->movieIds==movieId && (head)->next1==head){
        free(head);
        head=NULL;
        return;
    }
    Node1 *last=head,*d;
    // If head is to be deleted
    if((head)->movieIds==movieId){
        while(last->next1!=head)
            last=last->next1;
        last->next1=(head)->next1;
        free(head);
        head=last->next1;
        return;
    }

    // Either the node to be deleted is not found
    // or the end of list is not reached
    while(last->next1!=head && last->next1->movieIds!=movieId){
        last=last->next1;
    }

    // If node to be deleted was found
    if(last->next1->movieIds==movieId){
        d=last->next1;
        last->next1=d->next1;
        free(d);
        return;
    }
    else{
        struct NodeCheck *p;
        // If list is empty, return.
        if (last2 == NULL){
            myFile<<"movie "<<movieId<<" does not exist\n";
            return;
        }
        // Pointing to first Node of the list.
        p = last2 -> next2;
        // Traversing the list.
        do{
            if(p->movieId2 == movieId){
                DeleteChecked(movieId);
                return;
            }
            p = p -> next2;
        }
        while(p != last2->next2);
        return;
    }
}

void LibrarySystem::checkoutMovie(const int movieId, const int userId) {
    Node1 *s= new Node1();
    s = head->next1;
    while (s != head){
        if (s->movieIds == movieId){
            struct Node *temp = start;
            int flag=0,value;
            while(temp->next != start){
                if(temp->userIds == userId){
                    flag = 1;
                    break;
                }
                // Increment temp pointer
                temp = temp->next;
            }
            if(temp->userIds == userId){
                flag = 1;
            }
            if(flag == 1){
                myFile<<"Movie " <<movieId<<" has been checked out by User "<<userId<<"\n";
                addChecked(movieId,userId);
                LibrarySystem::display1(movieId);
                return;
            }
            else{
                myFile<<"User "<<userId<<" does not exist for checkout\n";
                return;
            }
        }
        s = s->next1;
    }
    if (s->movieIds == movieId){
        struct Node *temp = start;
        int flag=0,value;
        while(temp->next != start){
            if(temp->userIds == userId){
                flag = 1;
                break;
            }
            // Increment temp pointer
            temp = temp->next;
        }
        if(temp->userIds == userId){
            flag = 1;
        }
        if(flag == 1){
            myFile<<"Movie " <<movieId<<" has been checked out by User "<<userId<<"\n";
            addChecked(movieId,userId);
            display1(movieId);
            return;
        }
        else{
            myFile<<"User "<<userId<<" does not exist for checkout\n";
            return;
        }
    }
    else{
        myFile<<"Movie "<< movieId<<" does not exist for checkout\n";

    }
}

void LibrarySystem::main() {

}

void LibrarySystem::deleteUser(const int userId) {
    // If list is empty
    if (start == NULL){
        myFile<<"User "<<userId<< " does not exist\n";
        return;
    }

    // Find the required node
    // Declare two pointers and initialize them
    struct Node *curr = start, *prev_1 = NULL;
    while (curr->userIds != userId) {
        // If node is not present in the list
        if (curr->next == start) {
            myFile<<"User "<<userId<< " does not exist\n";
            return;
        }
        prev_1 = curr;
        curr = curr->next;
    }

    // Check if node is the only node in list
    if (curr->next == start && prev_1 == NULL) {
        (start) = NULL;
        free(curr);
        myFile<<"user "<<userId<<" has been deleted\n";
        return;
    }

    // If list has more than one node,
    // check if it is the first node
    if (curr == start) {
        // Move prev_1 to last node
        prev_1 = (start)->prev;
        // Move start ahead
        start = (start)->next;

        // Adjust the pointers of prev_1 and start node
        prev_1->next = start;
        (start)->prev = prev_1;
        free(curr);
        myFile<<"user "<<userId<<" has been deleted\n";
    }

        // check if it is the last node
    else if (curr->next == start) {
        // Adjust the pointers of prev_1 and start node
        prev_1->next = start;
        (start)->prev = prev_1;
        free(curr);
        myFile<<"user "<<userId<<" has been deleted\n";
    }
    else {
        // create new pointer, points to next of curr node
        struct Node* temp = curr->next;

        // Adjust the pointers of prev_1 and temp node
        prev_1->next = temp;
        temp->prev = prev_1;
        free(curr);
        myFile<<"user "<<userId<<" has been deleted\n";
    }
}

void LibrarySystem::addUser(const int userId, const string userName) {
    if (start == NULL){
        struct Node* new_node = new Node;
        new_node->userIds = userId;
        new_node->userNames=userName;

        new_node->next = new_node->prev = new_node;
        start = new_node;
        myFile<<"User "<<userId <<" has been added\n";
        return;
    }
    struct Node *temp = start;
    int count=0,flag=0,value;

    while(temp->next != start){
        count++;
        if(temp->userIds == userId){
            flag = 1;
            count--;
            break;
        }
        // Increment temp pointer
        temp = temp->next;
    }

    if(temp->userIds == userId){
        count++;
        flag = 1;
    }

    if(flag == 1){
        myFile<<"User "<<userId<<" already exists\n";
    }

    else{
        Node *last = (start)->prev;
        // Create Node dynamically
        struct Node* new_node = new Node;

        // pick elements one by one
        new_node->userIds = userId;
        new_node->userNames=userName;

        // Start is going to be next of new_node
        new_node->next = start;

        // Make new node previous of start
        (start)->prev = new_node;

        // Make last preivous of new node
        new_node->prev = last;

        // Make new node next of old last
        last->next = new_node;
        myFile<<"User "<<userId <<" has been added\n";
    }
}

void LibrarySystem::showAllMovies() {
    struct Node1 *p;
    struct NodeCheck *p1;
    myFile<<"Movie id - Movie name - Year - Status\n";
    // If list is empty, return.
    if (head == NULL){
        if (last2 == NULL){
            return;
        }
        // Pointing to first Node of the list.
        p1 = last2 -> next2;
        // Traversing the list.
        do{
            myFile << p1 -> movieId2 << " "<< p1 -> movieTitles2 << " "<< p1 -> years2 << " Checked out by User "<<p1->userId2<<"\n";
            p1 = p1 -> next2;
        }
        while(p1 != last2->next2);
        return;
    }

    // Pointing to first Node of the list.
    p = head -> next1;
    // Traversing the list.
    do{
        myFile << p -> movieIds << " "<< p -> movieTitles << " "<< p -> years <<" Not Checked out\n";
        p = p -> next1;
    }
    while(p != head->next1);

    // If list is empty, return.
    if (last2 == NULL){
        return;
    }
    // Pointing to first Node of the list.
    p1 = last2 -> next2;
    // Traversing the list.
    do{
        myFile << p1 -> movieId2 << " "<< p1 -> movieTitles2 << " "<< p1 -> years2 << " Checked out by User "<<p1->userId2<<"\n";
        p1 = p1 -> next2;
    }
    while(p1 != last2->next2);
}


void LibrarySystem::addChecked(const int movieId,const int userId) {
    int year;
    string movieTitle;
    struct Node1 *p;
    // If list is empty, return.
    if (head == NULL){
        return;
    }
    // Pointing to first Node of the list.
    p = head -> next1;
    // Traversing the list.
    do{
        if(p->movieIds == movieId){
            //cout << p -> movieIds << " ";
            //cout << p -> movieTitles << " ";
            movieTitle = p->movieTitles;
            //cout << p -> years << " ";
            year = p -> years;

        }
        p = p -> next1;
    }
    while(p != head->next1);
    NodeCheck *temp2 =new NodeCheck();

    if (last2 == NULL){
        // Assigning the data.
        temp2 -> movieId2 = movieId;
        temp2 -> years2 = year;
        temp2 -> movieTitles2 = movieTitle;
        temp2->userId2 = userId;
        last2 = temp2;
        // Creating the link.
        last2 -> next2 = last2;

        //myFile<<"movie "<<movieId<<"has been added\n";
        return;
    }
    NodeCheck *s =  new NodeCheck();
    s = last2->next2;
    while (s != last2){
        if (s->movieId2 == movieId){
            //printf("movie %d already exists \n", movieId);
            return;
        }
        s = s->next2;
    }
    if (s->movieId2 == movieId){
        //printf("movie %d already exists \n", movieId);
        return;
    }
    else{

        //myFile<<"movie "<<movieId<<"has been added\n";
        temp2 -> movieId2 = movieId;
        temp2 -> movieTitles2 = movieTitle;
        temp2 -> years2 = year;
        temp2->userId2 = userId;
        temp2 -> next2 = last2 -> next2;
        last2 -> next2 = temp2;
        last2 =temp2;  //sonradan eklendi
        return;
    }
}

void LibrarySystem::returnMovie(const int movieId) {
    struct Node1 *p;
    struct NodeCheck *p1;
    // If list is empty, return.
    if(head ==NULL&&last2 == NULL){
        myFile<<"movie "<<movieId<<" does not exist in library \n";
        return;
    }
    p = head -> next1;
    // Traversing the list.
    do{
        if(p->movieIds == movieId){

            myFile<<"movie "<<movieId<<" has not been checked out\n";
            return;
        }
        p = p -> next1;
    }
    while(p != head->next1);
    // Pointing to first Node of the list.
    p1 = last2 -> next2;
    // Traversing the list.
    do{
        if(p1->movieId2 == movieId){

            myFile<<"movie "<<movieId<<" has been returned \n";
            display1(movieId);
            addMovie(movieId,p1 -> movieTitles2,p1 -> years2);
            return;
        }
        p1 = p1 -> next2;

    }
    while(p1 != last2->next2);
    myFile<<"movie "<<movieId<<" does not exist in library \n";



}

LibrarySystem::LibrarySystem() {

}

LibrarySystem::~LibrarySystem() {

}

void LibrarySystem::showMovie(const int movieId) {
    struct Node1 *p;
    struct NodeCheck *p1;
    // If list is empty, return.
    if(head ==NULL&&last2 == NULL){
        myFile<<"Movie with the id "<<movieId<<" does not exist\n";
        return;
    }
    p = head -> next1;
    // Traversing the list.
    do{
        if(p->movieIds == movieId){

            myFile<< movieId<<" "<< p -> movieTitles.c_str()<<" "<<p -> years<<" Not checked out\n";
            return;
        }
        p = p -> next1;
    }
    while(p != head->next1);
    // Pointing to first Node of the list.
    p1 = last2 -> next2;
    // Traversing the list.
    do{
        if(p1->movieId2 == movieId){
            myFile<< p1 -> movieId2<<" "<<  p1 -> movieTitles2.c_str()<<" "<<p1 -> years2<<" Checked out by User "<<p1 -> userId2<<"\n";
            return;
        }
        p1 = p1 -> next2;
    }
    while(p1 != last2->next2);
    myFile<<"Movie with the id "<<movieId<<" does not exist\n";
}

void LibrarySystem::showUser(const int userId) {
    struct Node *temp = start;

    while (temp->next != start)
    {
        if(temp->userIds == userId){
            myFile<<"User id: "<<temp->userIds;
            myFile<<" User name: "<<temp->userNames.c_str()<<"\n";
            break;
        }
        temp = temp->next;
    }
    myFile<<"User "<<temp->userIds<<" checked out the following Movies:\n";
    myFile<<"Movie id - Movie name - Year\n";
    struct NodeCheck *p1;
    p1 = last2 -> next2;
    // Traversing the list.
    do{
        if(p1->userId2 == userId){
            myFile<<p1 -> movieId2<<" "<<p1 -> movieTitles2.c_str()<<" "<<p1 -> years2<<"\n";
        }
        p1 = p1 -> next2;

    }
    while(p1 != last2->next2);

}








