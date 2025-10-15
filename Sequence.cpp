#include "Sequence.h"
#include <stdexcept>
using namespace std;

SequenceNode::SequenceNode() {
    next = nullptr;
    prev = nullptr;
    item = "";
}

SequenceNode::SequenceNode(string item) {
    this->item = item;
    next = nullptr;
    prev = nullptr;
}

Sequence::Sequence(size_t sz) {
    head = nullptr;
    tail = nullptr;
    numElts = 0;
    for (size_t i = 0; i < sz; i++) {
        push_back("");
    }
}

Sequence::Sequence(const Sequence& s) {
    head = nullptr;
    tail = nullptr;
    numElts = 0;
    SequenceNode* curr = s.head;
    while (curr != nullptr) {
        push_back(curr->item);
        curr = curr->next;
    }
}

Sequence::~Sequence() {
    clear();
}

Sequence& Sequence::operator=(const Sequence& s) {
    if (this != &s) {
        clear();
        SequenceNode* curr = s.head;
        while (curr != nullptr) {
            push_back(curr->item);
            curr = curr->next;
        }
    }
    return *this;
}

string& Sequence::operator[](size_t position) {
    if (position >= numElts) {
        throw out_of_range("Invalid index");
    }
    SequenceNode* curr = head;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }
    return curr->item;
}

void Sequence::push_back(string item) {
    SequenceNode* newNode = new SequenceNode(item);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    numElts++;
}

void Sequence::pop_back() {
    if (tail == nullptr) {
        throw out_of_range("Sequence is empty");
    }
    SequenceNode* temp = tail;
    tail = tail->prev;
    if (tail != nullptr) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    delete temp;
    numElts--;
}

void Sequence::insert(size_t position, string item) {
    if (position > numElts) {
        throw out_of_range("Invalid insert position");
    }
    if (position == numElts) {
        push_back(item);
        return;
    }
    SequenceNode* curr = head;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }
    SequenceNode* newNode = new SequenceNode(item);
    newNode->next = curr;
    newNode->prev = curr->prev;
    if (curr->prev != nullptr) {
        curr->prev->next = newNode;
    } else {
        head = newNode;
    }
    curr->prev = newNode;
    numElts++;
}

void Sequence::erase(size_t position) {
    erase(position, 1);
}

void Sequence::erase(size_t position, size_t count) {
    if (position + count > numElts || position >= numElts) {
        throw out_of_range("Invalid erase range");
    }
    SequenceNode* curr = head;
    for (size_t i = 0; i < position; i++) {
        curr = curr->next;
    }
    for (size_t i = 0; i < count; i++) {
        SequenceNode* temp = curr;
        curr = curr->next;
        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }
        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }
        delete temp;
        numElts--;
    }
}

void Sequence::clear() {
    SequenceNode* curr = head;
    while (curr != nullptr) {
        SequenceNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    numElts = 0;
}

string Sequence::front() const {
    if (head == nullptr) {
        throw out_of_range("Sequence is empty");
    }
    return head->item;
}

string Sequence::back() const {
    if (tail == nullptr) {
        throw out_of_range("Sequence is empty");
    }
    return tail->item;
}

bool Sequence::empty() const {
    return numElts == 0;
}

size_t Sequence::size() const {
    return numElts;
}

ostream& operator<<(ostream& os, const Sequence& s) {
    os << "< ";
    SequenceNode* curr = s.head;
    while (curr != nullptr) {
        os << curr->item;
        if (curr->next != nullptr) {
            os << ", ";
        }
        curr = curr->next;
    }
    os << " >";
    return os;
}
