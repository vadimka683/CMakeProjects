#ifndef LIB_STACK_STACK_H_
#define LIB_STACK_STACK_H_
#include <iostream>
template <typename T> class ExampleClass;
//template <typename T>
//std::ostream& operator<<(std::ostream& out, const ExampleClass<T>& obj) noexcept;
template <typename T>
class Stack {
    T* data;
    int size;
    int count;
public:
    Stack(int _size) {              // конструктор
        size = _size;
        count = -1;
        data = new T[size];
    }
    Stack(const Stack& tmp) {
        size = tmp.size;
        data = new T[size];
        count = tmp.count;
        for (int i = 0; i <= count; i++) {
            data[i] = tmp.data[i];
        }
    }
    ~Stack() {
        delete[] data;
        data = nullptr;
    };                      // деструктор
    bool Stack::isFull() {
        return size == count + 1; // проверка на заполненость стека
    }
    bool Stack::isEmpty() {
        return count == -1;          // проверка на пустоту стэка
    }
     void push(T a){            // добавление элемента
        if (isFull())
        {
            throw std::logic_error("Stek isFull");
        }
        data[++count] = a;
    }
     T Top() {               // Возвращение последнего элемента
        if (!isEmpty()) {
            return data[count];
        }
        else {
            throw std::logic_error("Stek isEmpty");
        }
    }
    void pop() {              // удаление последнего элемента
        if (isEmpty())
        {
            throw std::logic_error("Stek isEmpty");
        }
        //std::cout << "Delete  << Top();
        --count;
    }
    void print() {
        Stack copy(*this);
        while (copy.count != -1) {
            std::cout << copy.Top()<< "\n";
            copy.pop();
        }
    }
};
#endif  // LIB_EXAMPLE_EXAMPLE_H_
