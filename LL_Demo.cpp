#include <iostream>
#include <string>

using namespace std;

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
void insert(string w)
{
    dbl_node* temp = new dbl_node;
    if (temp == nullptr)
    {
        cerr << "NO MEMORY REMAINING!\n";
        exit(1);
    }

    if (dbl_head == nullptr)
    {
        temp->word = w;
        temp->next = nullptr; // Point to the front of the list
        temp->prev = nullptr;
        dbl_head = temp; // Update the front of the list
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
void insert(string w)
{

    sngl_node* temp = new sngl_node;
    if (temp == nullptr)
    {
        cerr << "NO MEMORY REMAINING!\n";
        exit(1);
    }

    temp->word = w;
    temp->next = nullptr; // Point to the front of the list
    sngl_head = temp; // Update the front of the list

}

// Print the SLL
void display()
{
    cout << "The list: \n";
    sngl_node* temp = sngl_head;
    while (temp != nullptr)
    {
        cout << temp->word << " ";
        temp = temp->next;
    }
    cout << endl;
}


int main() {
    insert("Fred");
    insert("Mike");
    insert("Sarah");
    display();
    return 0;
}