#include "canvaslist.h"

#include <iostream>

using namespace std;

//creates an empty canvas list
CanvasList::CanvasList() {
    list_size = 0;
    list_front = nullptr;
}

//Copy constructor. Creates a deep copy of the given `CanvasList`, where each `Shape` is copied as well.
CanvasList::CanvasList(const CanvasList& other) {
    //initialize list_size and list_front
    this->list_size = 0;
    this->list_front = nullptr;

    ShapeNode* current = other.list_front;

    //return if list is empty
    if(current == nullptr){
        return;
    }

    //iterate through list and copy each shape
    while(current != nullptr){
        Shape* copy = current->value->copy();
        this->push_back(copy);
        current = current->next;
    }

    list_size = other.list_size;
}

CanvasList& CanvasList::operator=(const CanvasList& other) {
    //check for self assignment
    if(this != &other){
        //clear current list
        this->clear();

        //traverse through other list and make a deep copy of each node
        ShapeNode* current = other.list_front;

        //add value to node
        while(current != nullptr){
            Shape* copy = current->value->copy();
            push_back(copy);
            current = current->next;
        }
        list_size = other.list_size;
    }

    //return this CanvasList
    return *this;
}

CanvasList::~CanvasList(){
    clear();
}

void CanvasList::clear() {
    //if list is empty, return
    if(list_front == nullptr){
        return;
    }

    //start from front of list
    ShapeNode* current = list_front;

    //iterate through each node
    while(current != nullptr){
        ShapeNode* next = current->next;
        delete current->value;
        delete current;
        current = next;
    }

    list_size = 0;
    list_front = nullptr;
}

void CanvasList::insert_after(int index, Shape* s) {
    //if index is invalid, return
    if(index < 0 || index >= list_size){
        return;
    }

    //create a new node with value s
    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;

    //if list is empty, assign newNode to list_front
    if(list_front == nullptr){
        list_front = newNode;
        list_size++;
        return;
    }

    //current node will point to front_list
    ShapeNode* current = list_front;
    //iterate through list until index is found
    int i = 0;
    while(current != nullptr){
        //if index is found, insert newNode after current
        if(i == index){
            newNode->next = current->next;
            current->next = newNode;
            list_size++;
            return;
        }
        //else, move to next node
        current = current->next;
        i++;
    }

    //if index was not found, delete newNode
    delete newNode;
}

void CanvasList::push_front(Shape* s) {
    //create a new node and assign value s
    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;

    //insert newNode at the front of the list
    newNode->next = list_front;
    list_front = newNode;
    list_size++;
}

void CanvasList::push_back(Shape* s) {
    ShapeNode* newNode = new ShapeNode();
    newNode->value = s;
    newNode->next = nullptr;

    //if list is empty, assign newNode to list_front
    if(list_front == nullptr){
        list_front = newNode;
    } else{
        ShapeNode* lastNode = list_front;
        //iterate through list until last node is found
        while(lastNode->next != nullptr){
            lastNode = lastNode->next;
        }
        //assign newNode to the last node
        lastNode->next = newNode;
    }
    list_size++;
}

void CanvasList::remove_at(int index) {
    //if index is invalid, return
    if(index < 0 || index >= list_size){
        return;
    }

    //if list is empty, return
    if(list_front == nullptr){
        return;
    }

    //if index is 0, remove front of list
    if(index == 0){
        ShapeNode* toDelete = list_front;
        list_front = list_front->next;

        //delete
        delete toDelete->value;
        delete toDelete;
        list_size--;
        return;
    }

    //temp node will point to front_list
    ShapeNode* current = list_front;
    //iterate through list until index is found
    int i = 0;
    while(current->next != nullptr){
        //if index is found, remove node
        if(i == index - 1){
            ShapeNode* toDelete = current->next;
            current->next = current->next->next;

            //delete
            delete toDelete->value;
            delete toDelete;
            list_size--;
            return;
        }
        //else move to next node
        current = current->next;
        i++;
    }

    //if index was not found, return
    return;
}

void CanvasList::remove_every_other(){
    ShapeNode* current = list_front;

    //iterate through list and remove every other node
    while(current && current->next){
        ShapeNode* toDelete = current->next;
        current->next = toDelete->next;

        //delete
        delete toDelete->value;
        delete toDelete;
        list_size--;
        current = current->next;
    }
}

Shape* CanvasList::pop_front() {
    //if list is empty, return nullptr
    if(list_front == nullptr){
        return nullptr;
    }

    //temp node will point to front-list
    ShapeNode* toDelete = list_front;
    list_front = toDelete->next;

    //store value of the deleted node
    Shape* value = toDelete->value;

    //delete
    delete toDelete;
    list_size--;

    //return the value of the deleted node
    return value;
}

Shape* CanvasList::pop_back(){
    //if list is empty, return nullptr
    if(list_front == nullptr){
        return nullptr;
    }

    //if list has one node
    if(list_front->next == nullptr){
        //store value of the deleted node
        Shape* value = list_front->value;

        //delete
        delete list_front;
        list_front = nullptr;
        list_size = 0;
        return value;
    }

    //traverse list and find second to last node
    ShapeNode* secondToLast = list_front;
    while(secondToLast->next->next != nullptr){
        secondToLast = secondToLast->next;
    }

    //get last node
    ShapeNode* last = secondToLast->next;
    //get value of last node
    Shape* lastValue = last->value;
    delete last;

    //update linkedlist
    secondToLast->next = nullptr;
    list_size--;

    return lastValue;
}

ShapeNode* CanvasList::front() const {
    //return the front of the list
    if(list_front != nullptr){
        return list_front;
    }

    //else return nullptr
    return nullptr;
}

bool CanvasList::empty() const {
    //if list is empty, return true
    if(list_size == 0){
        return true;
    }

    //else return false
    return false;
}

int CanvasList::size() const {
    return list_size;
}

int CanvasList::find(int x, int y) const {
    //if list is empty, return -1
    if(list_front == nullptr){
        return -1;
    }

    //temp node will point to front_list
    ShapeNode* current = list_front;
    //iterate through list until last node is found
    int index = 0;
    while(current != nullptr){
        //if x and y are found, return index
        if(current->value->getX() == x && current->value->getY() == y){
            return index;
        }
        //move to next node
        current = current->next;
        index++;
    }

    //if x and y are not found, return -1
    return -1;
}

Shape* CanvasList::shape_at(int index) const {
    //if index is invalid, return nullptr
    if(index < 0 || index >= list_size){
        return nullptr;
    }

    //temp node will point to front_list
    ShapeNode* current = list_front;
    //iterate through list until index is found
    int i = 0;
    while(current != nullptr){
        //if index is found, return value of node
        if(i == index){
            return current->value;
        }
        //else move to next node
        current = current->next;
        i++;
    }

    //if index was not found, return nullptr
    return nullptr;
}

void CanvasList::draw() const {
    //if list is empty, return
    if(list_front == nullptr){
        return;
    }

    ShapeNode* current = list_front;
    //iterate through list and print each shape
    while(current != nullptr){
        cout << current->value->as_string() << endl;
        current = current->next;
    }
}

void CanvasList::print_addresses() const {

    //if list is empty, return
    if(list_front == nullptr){
        return;
    }

    ShapeNode* current = list_front;
    //iterate through list and print address of each node and shape
    while(current != nullptr){
        cout << "Node Address: " << &current << "\tShape Address: " << &current->value << endl;
        current = current->next;
    }
}
