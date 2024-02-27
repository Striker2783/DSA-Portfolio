#pragma once
#include "list.hpp"
namespace DataStructures
{
    template <typename T>
    class Stack : public List<T>
    {
        void push(T e) { push_back(e); }
    };
}