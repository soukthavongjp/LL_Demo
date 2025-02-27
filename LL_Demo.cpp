#include <iostream>
#include <string>

using namespace std;

//Test Commit 1

//Test Commit 2

//Test Commit 3
struct dbl_node {
    string word;
    dbl_node* prev;
    dbl_node* next;
};

struct sngl_node {
    string word;
    sngl_node* next;
};


sngl_node* sngl_head = nullptr;
sngl_node* sngl_tail = nullptr;

dbl_node* dbl_head = nullptr;
dbl_node* dbl_tail = nullptr;


// Insert at beginning of a DLL
void insertDouble(const string& w)
{
    dbl_node* temp = new dbl_node;
    if (dbl_head == nullptr)
    {
        temp->word = w;
        temp->next = nullptr;
        temp->prev = nullptr;
        dbl_head = temp; // Update the front of the list
        dbl_tail = temp;
    }
    else
    {
        temp->word = w;
        temp->next = dbl_head; // Point to the front of the list
        temp->prev = nullptr;
        dbl_head->prev = temp;
        dbl_head = temp; // Update the front of the list
    }
}

// Insert at beginning of a SLL
void insertSingle(const string &w) {
    sngl_node* temp = new sngl_node;

    if (sngl_head == nullptr) {
        sngl_tail = temp;
    }
    temp->word = w;
    temp->next = sngl_head; // Point to the front of the list
    sngl_head = temp; // Update the front of the list

}

// Insert at the end of a SLL with tail
void insertEndSingle(const string& w) {
    sngl_node* temp = new sngl_node;
    temp->word = w;
    temp->next = nullptr;
    sngl_tail->next = temp;
    sngl_tail = temp;
}

// Insert at the end of a DLL with tail
void insertEndDouble(const string& w) {
    dbl_node* temp = new dbl_node;
    temp->word = w;
    temp->next = nullptr;
    dbl_tail->next = temp;
    temp->prev = dbl_tail;
    dbl_tail = temp;
}

void deleteSingle(const string& w) {
    sngl_node* curr = new sngl_node;
    sngl_node* prev = nullptr;
    if (sngl_head != nullptr) {
        curr = sngl_head;
    }
    while (curr != nullptr && curr->word != w) {
        prev = curr;
        curr = curr->next;
    }
    if (curr == nullptr)
        cout << w << " is not present in the list." << endl;
    else if (curr == sngl_head){
        sngl_head = curr->next;
        delete curr;
    }
    else {
        prev->next = curr->next;
        if (curr == sngl_tail)
            sngl_tail = prev;
        delete curr;
    }
}

// Print the SLL
void displaySingle()
{
    cout << "The list: ";
    sngl_node* temp = sngl_head;
    while (temp != nullptr)
    {
        cout << temp->word << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Print the DLL
void displayDouble()
{
    cout << "The list: ";
    dbl_node* temp = dbl_head;
    while (temp != nullptr)
    {
        cout << temp->word << " ";
        temp = temp->next;
    }
    cout << endl;
}

void displayHead() {
  cout << "The head: ";
  cout << sngl_head->word << "\n";
}

void displayTail() {
  cout << "The tail: ";
  cout << sngl_tail->word << "\n";
}

int main() {
    insertSingle("Fred");
    displayHead();
    displayTail();
    insertSingle("Mike");
    displayHead();
    displayTail();
    insertSingle("Sarah");
    displayHead();
    displayTail();
    insertEndSingle("Kyle");
    displayHead();
    displayTail();
    displaySingle();
    deleteSingle("Sarah");
    displaySingle();
    deleteSingle("Fred");
    displaySingle();
    deleteSingle("Kyle");
    displaySingle();
    cout << endl;

    insertDouble("Erin");
    insertDouble("Kate");
    insertDouble("Nadine");
    insertEndDouble("Ann");
    displayDouble();
    return 0;
}