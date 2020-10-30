#ifndef MYQUEUE_H
#define MYQUEUE_H

#include <stddef.h>
#include <iostream>

template <typename T>
class MyQueue
{

    size_t m_first;
    size_t m_last;
    size_t m_cap;
    size_t m_size;
    size_t add = 4;
    T* m_data;

    void _realloc()
    {
        size_t old_cap = m_cap;
        m_cap = m_size + add;
        T* tmp = new T[m_cap]{};

        for(size_t i = 0; i < m_size; i++)
        {
            tmp[i] = std::move(m_data[(m_first + i) % old_cap]);
        }
        delete[] m_data;
        m_data = tmp;

        m_first = 0;
        m_last = (m_first + m_size) % m_cap;
    }


public:

    ~MyQueue()
    {
        delete[] m_data;
        //m_data = nullptr;
    }

    MyQueue(size_t n) : m_cap(n + add), m_first(0), m_last(n), m_size(n)
    {
        m_data = new T[m_cap]{};
    }

    MyQueue(std::initializer_list<T> il) : m_size(il.size()),
        m_first(0), m_last(il.size())
    {
        m_cap = il.size() + add;
        m_data = new T[il.size() + add]{};

        size_t iter = 0;
        for(auto &elem : il)
        {
            m_data[iter] = elem;
            ++iter;
        }
    }

    MyQueue(const MyQueue& other) : m_size(other.m_size), m_first(0),
        m_last(m_size), m_cap(m_size + add)
    {
        m_data = new T[other.m_size + add];
        for (size_t i=0; i<m_size; i++)
        {
            m_data[i] = other.m_data[(other.m_first + i) % other.m_size];
        }
    }

    //копирующий оператор и тд
    //
    T* begin() const
    {
        return m_data + m_first;
    }

    T* end() const
    {
        return m_data + m_last;
    }

    void push(const T& t)
    {
        if(m_size == m_cap)
        {
            _realloc();
        }
        m_data[m_last] = t;
        ++m_size;//проверить
        m_last = (m_first + m_size) % m_cap;
    }

    size_t size() const
    {
        return m_size;
    }

    size_t capacity() const
    {
        return m_cap;
    }

    T pop()
    {
        size_t old_first = m_first;
        m_first++;
        m_first %= m_cap;
        --m_size;
        return m_data[old_first];
    }

    void print()
    {
        for(size_t i=0; i<m_size; i++)
        {
            std::cout << m_data[(m_first + i) % m_cap] << ' ';
        }
        std::cout<<'\n';
    }


};

#endif // MYQUEUE_H
