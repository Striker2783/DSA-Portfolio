#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <exception>

template <typename T>
class List
{
private:
    T *arr;
    size_t index;
    size_t max;

    void resize(size_t n);

public:
    List() { *this = List(10); };
    List(size_t size) : arr(new T[size]), index(0), max(size){};
    ~List() { delete arr; };
    bool push_back(T e);
    bool is_empty() { return index == 0; }
    T pop_back();
};
template <typename T>
bool List<T>::push_back(T e)
{
    if (index >= max)
        this->resize(max * 2);
    arr[index] = e;
    index++;
    return true;
}
template <typename T>
void List<T>::resize(size_t size)
{
    T *new_arr = new T[size];
    for (size_t i = 0; i < this->index; i++)
        new_arr[i] = arr[i];
    this->max = size;
}
template <typename T>
T List<T>::pop_back()
{
    if (is_empty())
        throw std::exception();
    index--;
    return arr[index + 1];
}

#endif
