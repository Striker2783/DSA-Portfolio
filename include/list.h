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