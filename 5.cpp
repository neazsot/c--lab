#include <iostream>
#include <deque>

template <typename T>
class Queue {
private:
    std::deque<T> elements;

public:
    void push(const T& item) {
        elements.push_back(item);
    }

    void pop() {
        if (!elements.empty()) {
            elements.pop_front();
        }
    }

    T& front() {
        return elements.front();
    }

    bool empty() const {
        return elements.empty();
    }
};

int main() {
    Queue<std::string> stringQueue;
    stringQueue.push("First");
    stringQueue.push("Second");
    stringQueue.push("Third");

    std::cout << "String Queue:" << std::endl;
    while (!stringQueue.empty()) {
        std::cout << stringQueue.front() << std::endl;
        stringQueue.pop();
    }

    Queue<int> intQueue;
    intQueue.push(10);
    intQueue.push(20);
    intQueue.push(30);

    std::cout << "\nInteger Queue:" << std::endl;
    while (!intQueue.empty()) {
        std::cout << intQueue.front() << std::endl;
        intQueue.pop();
    }

    return 0;
}
