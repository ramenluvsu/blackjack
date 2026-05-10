#ifndef GAMESTACK_H
#define GAMESTACK_H

#include <vector>
#include <stdexcept>
using namespace std;

//generic stack class works with any type not just cards
template <typename T>
class GameStack {
private:
    vector<T> data;  //holds the data

public:
    void push(T item) {
        data.push_back(item);
    }

    T pop() {
        //throws an error if u try to pop from an empty stack
        if (isEmpty())
            throw runtime_error("Stack is empty bro");
        T top = data.back();
        data.pop_back();
        return top;
    }

    T peek() const {
        //same as pop but doesnt remove the item
        if (isEmpty())
            throw runtime_error("Stack is empty bro ");
        return data.back();
    }

    bool isEmpty() const {
        return data.empty();
    }

    int size() const {
        return data.size();
    }

    void clear() {
        data.clear();
    }

};

#endif