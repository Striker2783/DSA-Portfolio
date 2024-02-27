#ifndef LIST_H
#define LIST_H

#include <stddef.h>
#include <stdexcept>
#include <iostream>

template <typename T>
class List
{
private:
    T *arr;
    size_t index;
    size_t max_size;

    void resize(size_t n);
    void move_back(size_t i);

public:
    List() : arr(new T[10]), index(0), max_size(10){};
    List(size_t size) : arr(new T[size]), index(0), max_size(size){};
    ~List() { delete[] arr; };
    bool push_back(T e);
    void insert(size_t i, T e);
    inline bool is_empty() { return index == 0; }
    inline bool is_full() { return index == max(); }
    inline size_t size() { return index; }
    inline size_t max() { return max_size; }
    inline T &first() { return size() == 0 ? throw std::exception() : arr[0]; };
    inline T &last() { return size() == 0 ? throw std::exception() : arr[index - 1]; }
    T pop_back();
    T &operator[](size_t i);
    template <typename U>
    friend std::ostream &operator<<(std::ostream &o, List<U> &list);
};
template <typename T>
std::ostream &operator<<(std::ostream &o, List<T> &list)
{
    if (list.is_empty())
    {
        o << "[]";
        return o;
    }
    o << '[';
    for (size_t i = 0; i < list.index - 1; i++)
        o << list[i] << ", ";
    o << list.last();
    o << ']';
    return o;
}
template <typename T>
T &List<T>::operator[](size_t i)
{
    if (i >= index)
        throw std::out_of_range("");
    return arr[i];
}
template <typename T>
bool List<T>::push_back(T e)
{
    if (index >= max())
        this->resize(max() * 2);
    arr[index] = e;
    index++;
    return true;
}
template <typename T>
void List<T>::resize(size_t size)
{
    if (size == 0)
        size = 1;
    T *new_arr = new T[size];
    for (size_t i = 0; i < this->index; i++)
        new_arr[i] = arr[i];
    this->max_size = size;
}
template <typename T>
T List<T>::pop_back()
{
    if (is_empty())
        throw std::exception();
    index--;
    if (index * 3 < max())
        resize(index * 2);
    return arr[index];
}
template <typename T>
void List<T>::move_back(size_t i)
{
    if (i >= index)
        throw std::out_of_range("");
    if (is_full())
        resize(max() * 2);
    T temp = arr[i];
    for (size_t j = i; j < index - 1; j++)
    {
        T temp2 = arr[j + 1];
        arr[j + 1] = temp;
        temp = temp2;
    }
    arr[index] = temp;
    index++;
}
#endif

template <typename T>
void List<T>::insert(size_t i, T e)
{
    if (i == index)
    {
        push_back(e);
        return;
    }
    move_back(i);
    arr[i] = e;
}