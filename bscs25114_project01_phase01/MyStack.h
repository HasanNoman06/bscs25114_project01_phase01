#ifndef MYSTACK_H
#define MYSTACK_H

template <typename T>
class MyStack {
private:
    T* arr;            // dynamically allocated array storage
    int cap;           // current total capacity of the stack
    int topIndex;      // index of the top element (-1 when empty)

    void reallocate(int newCap) // helper method to resize underlying array
    {
        T* temp = new T[newCap];

        for (int i = 0; i <= topIndex; i++)
            temp[i] = arr[i];

        delete[] arr;
        arr = temp;
        temp = nullptr;
    }

public:
    MyStack(int initialCapacity = 10)
    {
        if (initialCapacity < 1)
            cap = 10;
        else
            cap = initialCapacity;

        topIndex = -1;
        arr = new T[cap];
    }

    MyStack(const Stack<T>& other)    // deep copy constructor
    {
        cap = other.cap;
        topIndex = other.topIndex;

        for (int i = 0; i <= topIndex; i++)
            arr[i] = other.arr[i];
    }

    ~MyStack()                       // destructor
    {
        delete[] arr;
    }

    void push(const T& val)          // insert element onto top
    {
        if (topIndex + 1 == cap)
            reallocate(cap *= 2);

        arr[++topIndex] = val;
    }

    void pop()                       // remove element from top
    {
        if (empty())
            throw std::underflow_error("Underflow Error!\n\n");
        else
            --topIndex;
    }

    T& top()                         // access top element
    {
        if (empty())
            throw std::underflow_error("Underflow Error!\n\n");
        else
            return arr[topIndex];
    }

    const T& top() const             // read-only access to top element
    {
        if (empty())
            throw std::underflow_error("Underflow Error!\n\n");
        else
            return arr[topIndex];
    }

    bool empty() const               // check if stack is empty
    {
        if (topIndex == -1)
            return 1;
        else
            return 0;
    }

    int size() const                 // return current number of elements
    {
        return (topIndex + 1);
    }

    int capacity() const             // return total current capacity
    {
        return cap;
    }
};


/////
#endif