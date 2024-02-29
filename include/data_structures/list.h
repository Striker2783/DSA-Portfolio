#pragma once
namespace DataStructures
{
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
        List(List<T> &o);
        ~List() { delete[] arr; };
        void push_back(T e);
        void insert(size_t i, T e);
        const inline bool is_empty() { return index == 0; }
        const inline bool is_full() { return index == max(); }
        const inline size_t size() { return index; }
        const inline size_t max() { return max_size; }
        inline T &first() { return size() == 0 ? throw std::exception() : arr[0]; };
        inline T &last() { return size() == 0 ? throw std::exception() : arr[index - 1]; }
        T pop_back();
        T &operator[](size_t i);
        bool operator==(List<T> &o);
        template <typename U>
        friend std::ostream &operator<<(std::ostream &o, List<U> &list);
    };
} // namespace DataStructures