#ifndef SEQUENCE_H
#define SEQUENCE_H

#include <string>
#include <iostream>

class SequenceNode {
public:
    std::string item;
    SequenceNode* next;
    SequenceNode* prev;

    SequenceNode();
    SequenceNode(std::string item);
};

class Sequence {
public:
    Sequence(size_t sz = 0);
    Sequence(const Sequence& s);
    ~Sequence();

    Sequence& operator=(const Sequence& s);

    std::string& operator[](size_t position);

    void push_back(std::string item);
    void pop_back();
    void insert(size_t position, std::string item);
    void erase(size_t position);
    void erase(size_t position, size_t count);
    void clear();

    std::string front() const;
    std::string back() const;
    bool empty() const;
    size_t size() const;

    friend std::ostream& operator<<(std::ostream& os, const Sequence& s);

private:
    SequenceNode* head;
    SequenceNode* tail;
    size_t numElts;
};

#endif
