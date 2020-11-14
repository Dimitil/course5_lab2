#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stddef.h>
#include <iostream>
#include <new>



template <typename T>
class MyQueue
{

    class iter{                     //добавленно
        T* base = nullptr;
        size_t cap = 0;
        size_t first = 0;
        size_t last = 0;

        T* data = nullptr;
    public:
        iter(T* p, size_t c, size_t f, size_t l) :
            base(p), cap(c), first(f), last(l) {}

        void make_first() { data = base + first; }

        void make_last() { data = base + last; }

        T& operator*()  { return *data; }

        bool operator!=(const iter& r) { return data != r.data; }

        iter& operator++() {
            if (data+1 == base+cap) {
                data = base;
            }
            else {
                data++;
            }
            return *this;
        }//переделать

    };

    const size_t add = 2;
    size_t m_size;
    size_t m_cap;               //в т. ч. под end
    size_t m_first = 0;
    size_t m_last  = 0;          //указывать на за последний должен!!!!!!!!!!!!!!!!!!!!!!
    T* m_data;                      //после последнего - специальное значение для end

    void _nullify()
    {
        m_data  = nullptr;
        m_size  = 0;
        m_cap   = 0;
        m_first = 0;
        m_last  = 0;
    }

    void _realloc() {
        T* new_m_data = new T[m_size + add];

        for (size_t i = 0; i < m_size; i++) {
            new_m_data[i] = m_data[(m_first + i) % m_cap];
        }

        delete[] m_data;
        m_data = new_m_data;
        m_cap = m_size + add;
        m_first = 0;
        m_last = m_size;
    }

public:


    ~MyQueue() {
        delete[] m_data;
        _nullify();
    }

    MyQueue(size_t n, const T &t) : m_size(n), m_cap(m_size + add), m_last(m_size)
    {
        m_data = new T[m_cap];
        for(size_t i = 0 ; i < m_size; i++) {
             m_data[i] = t;
        }
    }

    MyQueue(size_t n) : m_size(n), m_cap(m_size + add), m_last(m_size)
    {
        m_data = new T[m_cap]{};
    }

    MyQueue(std::initializer_list<T> il) : m_size(il.size()),
        m_cap(m_size + add), m_last(m_size)
    {
        m_data = new T[m_cap];

        size_t indx = 0;
        for(auto &elem : il) {
            m_data[indx] = elem;
            ++indx;
        }
    }

    MyQueue(const MyQueue& other) :  m_size(other.m_size), m_cap(m_size + add),
        m_last(m_size)
    {
        m_data = new T[m_cap];
        for (size_t i=0; i<m_size; i++)
        {
            m_data[i] = other.m_data[(other.m_first + i) % other.m_cap];
        }
    }

    MyQueue& operator=(const MyQueue& other) {
        if(this == &other) {
            return *this;
        }
        if (m_cap < other.m_size) {
            delete[] m_data;            //исправленно
            m_cap   = other.m_size + add;
            m_data  = new T[m_cap];
        }

        m_size  = other.m_size;
        m_first = 0;
        m_last  = m_size;

        for (size_t i = 0; i < m_size; i++) {
            m_data[i] = other.m_data[(other.m_first + i) % other.m_cap];
        }

        return *this;
    }

    MyQueue(MyQueue &&other) {
        m_size  = other.m_size;
        m_cap   = other.m_cap;
        m_first = other.m_first;
        m_last  = other.m_last;
        m_data  = other.m_data;

        other._nullify();
    }

    MyQueue& operator=(MyQueue&& other) {
        delete[] m_data;

        m_data  = other.m_data;
        m_size  = other.m_size;
        m_cap   = other.m_cap;
        m_first = other.m_first;
        m_last  = other.m_last;

        other._nullify();

        return *this;
    }

    const T* begin() const {
        return m_data + m_first;
    }

    const T* end() const {
        return m_data + (m_first+m_size) % m_cap;
    }

    iter begin() {
        iter m(m_data, m_cap, m_first, m_last);
        m.make_first();
        return m;
    }

    iter end() {
        iter m(m_data, m_cap, m_first, m_last);
        m.make_last();
        return m;
    }

    void push(const T& t) {
        if ( (m_size + 1) == m_cap) {
            _realloc();
        }
        m_data[m_last] = t;
        m_size++;                                  //исправленно
        m_last = (m_first + m_size) % m_cap;
    }

    size_t size() const {
        return m_size;
    }

    size_t capacity() const
    {
        return m_cap - 1;
    }

    T pop() {
        size_t old_first = m_first;
        m_first++;
        m_size--;
        m_first %= m_cap;

        return m_data[old_first];
    }

    void print() {
        for(size_t i = 0; i < m_size - 1; i++) {
            std::cout << m_data[(m_first + i) % m_cap] << ' ';
        }
        std::cout<<'\n';
    }
};

#endif // MYQUEUE_H
