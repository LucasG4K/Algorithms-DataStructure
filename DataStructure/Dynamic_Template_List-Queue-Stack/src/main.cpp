#include "methods.hpp"
#include "methods.cpp"

void printer(Sequence<int>& list, Sequence<int>& queue, Sequence<int>& stack) {
    list.Print();
    queue.Print();
    stack.Print();
}

int main () {
    Sequence<int> list;
    Sequence<int> queue;
    Sequence<int> stack;

    for (int i = 0; i < 5; ++i) {
        list.Insert(i);
        queue.Insert(i);
        stack.Insert(i);
    }
    
    cout << "Original:\n";
    printer(list, queue, stack);
    
    list.listRemove(2);
    queue.queueLeave();
    stack.stackPop();

    cout << "Removing some elements:\n";
    printer(list, queue, stack);
    
    list.reverse();
    queue.reverse();
    stack.reverse();

    cout << "Reverse:\n";
    printer(list, queue, stack);

    return 0;
}