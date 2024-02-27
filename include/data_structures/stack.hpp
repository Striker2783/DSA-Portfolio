#pragma once
#include "list.hpp"
#include "stddef.h"
namespace DataStructures
{
    template <typename T>
    class Stack
    {
    private:
        List<T> vec;

    public:
        Stack(size_t size) : vec(List<T>(size)) {}
        Stack() : vec(List<T>()) {}
        void push(T e) { vec.push_back(e); }
        T pop() { return vec.pop_back(); }
        T &peek() { return vec.last(); }
    };
}