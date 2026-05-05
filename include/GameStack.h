#ifndef GAMESTACK_H
#define GAMESTACK_H

#include <vector>
#include <stdexcept>

using namespace std;

template <typename T>
class GameStack {
private:
    vector<T> data;

public:
    void push(T item) {
        data.push_back(item);
    }

    T pop() {
        if (isEmpty())
            throw runtime_error("Stack is empty!");
        T top = data.back();
        data.pop_back();
        return top;
    }

    T peek() const {
        if (isEmpty())
            throw runtime_error("Stack is empty!");
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