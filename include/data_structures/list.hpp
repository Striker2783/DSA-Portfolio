#pragma once

#include <stddef.h>
#include <stdexcept>
#include <iostream>
#include "list.h"
namespace DataStructures
{
    template <typename T>
    std::ostream &operator<<(std::ostream &o, const List<T> &list)
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
    T &List<T>::operator[](size_t i) const
    {
        if (i >= index)
            throw std::out_of_range("");
        return arr[i];
    }
    template <typename T>
    void List<T>::push_back(T e)
    {
        if (index >= max())
            this->resize(max() * 2);
        arr[index] = e;
        index++;
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
    template <typename T>
    bool List<T>::operator==(List<T> &o) const
    {
        if (o.size() != size())
            return false;
        for (size_t i = 0; i < size(); i++)
            if (arr[i] != o[i])
                return false;
        return true;
    }
    template <typename T>
    List<T>::List(List<T> &o)
    {
        index = o.index;
        max_size = o.max_size;
        arr = new T[max_size];
        for (size_t i = 0; i < index; i++)
            arr[i] = o[i];
    }
}