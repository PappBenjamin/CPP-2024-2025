#include "List.h"

List::List(const string &filename) {
    ifstream file(filename);
    if(!file.is_open()) { throw logic_error("File not found"); }

    int temp;
    while(file >> temp) {
        insertLast(temp);
    }
}

List::~List() {
    Node* temp = first;
    while(temp != nullptr) {
        first = first->next; // Move first pointer to the next node
        delete temp; // Delete the current node
        temp = first; // Move to the next node
    }
}

bool List::exists(int d) const {
    Node* temp = first;
    while(temp != nullptr) {
        if(temp->value == d) { return true; }
        temp = temp->next;
    }
    return false;
}

int List::size() const {
    return this->nodeCounter;
}

bool List::empty() const {
    return this->first == nullptr;
}

void List::insertFirst(int d) {
    Node* newV = new Node(d, first);
    first = newV;
    nodeCounter++;
}

void List::insertLast(int d) {
    if(empty()) {
        insertFirst(d);
        return;
    }

    Node* newV = new Node(d, nullptr);
    Node* temp = first;

    // Traverse to the end of the list
    while(temp->next != nullptr) {
        temp = temp->next;
    }

    temp->next = newV; // Set the last node's next to the new node
    nodeCounter++;
}

int List::removeFirst() {
    if(empty()) { throw logic_error("List is empty"); }

    int value = first->value;
    Node* temp = first; // Store the current first node
    first = first->next; // Move first pointer to the next node
    nodeCounter--;
    delete temp; // Delete the old first node
    return value;
}

void List::print(ostream &os) const {
    Node* temp = first;
    while(temp != nullptr) {
        os << temp->value << " ";
        temp = temp->next;
    }
    os << endl;
}

ostream &operator<<(ostream &os, const List &list) {
    list.print(os);
    return os;
}

List operator+(const List &list1, const List &list2) {
    List finalList;
    List::Node* node1 = list1.first;
    List::Node* node2 = list2.first;

    while (node1 != nullptr && node2 != nullptr) {
        finalList.insertLast(node1->value + node2->value);
        node1 = node1->next;
        node2 = node2->next;
    }

    // Append remaining elements from the longer list
    while (node1 != nullptr) {
        finalList.insertLast(node1->value);
        node1 = node1->next;
    }
    while (node2 != nullptr) {
        finalList.insertLast(node2->value);
        node2 = node2->next;
    }

    return finalList;
}

List::List(const List &what) {

    this->nodeCounter = what.nodeCounter;
    this->first = what.first;
}

List::List(List &&what) {
    first = what.first;
    nodeCounter = what.nodeCounter;

    what.first = nullptr;
    what.nodeCounter = 0;
}

List& List::operator=(List&& other)
{
    if (this != &other) { // Check for self-assignment
        // Clear existing nodes
        Node* temp = first;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }

        // Transfer ownership
        first = other.first;
        nodeCounter = other.nodeCounter;

        // Set `other` to an empty state
        other.first = nullptr;
        other.nodeCounter = 0;
    }
    return *this;
}

List& List::operator=(const List& other)
{
    if (this != &other) { // Check for self-assignment
        // Clear existing nodes
        Node* temp = first;
        while (temp != nullptr) {
            Node* next = temp->next;
            delete temp;
            temp = next;
        }

        // Reset the list to an empty state
        first = nullptr;
        nodeCounter = 0;

        // Copy nodes from the other list
        Node* current = other.first;
        while (current != nullptr) {
            insertLast(current->value);
            current = current->next;
        }
    }
    return *this;
}
