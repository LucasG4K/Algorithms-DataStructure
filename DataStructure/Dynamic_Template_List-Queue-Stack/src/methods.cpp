#include "methods.hpp"

template<typename T>
Sequence<T>::Sequence() {
    begin = new Node<T>;
    end = begin;
    begin->next = nullptr;
};

template<typename T>
void Sequence<T>::Insert(T value) {
    end->next = new Node<T>;
    end = end->next;
    end->value = value;
    end->next = nullptr;
}

template<typename T>
void Sequence<T>::Print() {
    Node<T>* current = begin->next;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "\n";
}

template<typename T>
T Sequence<T>::queueLeave() {
    if (begin->next == end) {
        cout << "No elements on queue!";
        return T();
    }

    T leaving = begin->next->value;
    begin->next = begin->next->next;
    if(begin->next == nullptr)
        end = begin;

    cout << leaving << " left the queue!\n";
    return leaving;
}

template<typename T>
T Sequence<T>::stackPop() {
    if (begin->next == end) {
        cout << "No elements on stack!";
        return 0;
    }

    T leaving = end->value;
    Node<T>* prev = begin;
    while(prev->next != end)
        prev = prev->next;
    delete end;
    end = prev;
    end->next = nullptr;
    
    cout << leaving << " has been popped from stack!\n";
    return leaving;
}

template<typename T>
T Sequence<T>::listRemove(T value) {
    if (begin->next == end) {
        cout << "No elements on stack!";
        return 0;
    }

    Node<T>* temp = begin->next, *swap;
    while (temp->next != nullptr) {
        if (temp->value == value) {
            T leaving = temp->value;
            swap = temp;
            *temp = *swap->next;
            temp = nullptr;
            cout << leaving << " has been removed from list!\n";
            return leaving;
        }
        temp = temp->next;
    }
    cout << "Given value wasn't in list!\n";
    return 0;
}

template<typename T>
void Sequence<T>::reverse() {
    Node<T>* previous = nullptr;
    Node<T>* current = begin->next;
    Node<T>* next = nullptr;

    while (current != nullptr) {
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    Node<T>* temp = begin;
    begin->next = end;
    end = temp;
}