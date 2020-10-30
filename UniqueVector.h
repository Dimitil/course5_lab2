#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

template<typename T>
class UniqueVector
{
    const T m_min{};
    const T m_max{};
    std::vector<T> m_data;

public:
    UniqueVector() = default;

    UniqueVector(std::initializer_list<T> il, T min, T max) : m_min(min), m_max(max)  //добавить мин и макс
    {
        m_data.reserve(il.size());
        for( auto &elem : il)
        {
            if((elem < m_min) || (elem > m_max))
            {
                continue;
            }
            auto it = std::find(m_data.begin(), m_data.end(), elem);
            if(it == m_data.end())              //проверку на мин и макс
            {
                m_data.push_back(elem);
            }
        }
    }

    void print() const
    {
        for(auto &el : m_data)
        {
            std::cout << el << ' ';

        }
        std::cout<<'\n';
    }

    size_t size() const
    {
        return m_data.size();
    }

    void push_back(std::initializer_list<T> il)
    {
        m_data.reserve(m_data.size() + il.size());
        for( auto &elem : il)
        {
            auto it = std::find(m_data.begin(), m_data.end(), elem);
            if(it == m_data.end())
            {
                m_data.push_back(elem);
            }
        }
    }

    void erase(std::initializer_list<T> il)
    {
        for( auto &elem : il)
        {
            auto it = std::find(m_data.begin(), m_data.end(), elem);
            if(it != m_data.end())
            {
                m_data.erase(it);
            }
        }
    }

    template<typename A>
    void sort(A lamb)
    {
        std::sort(m_data.begin(), m_data.end(), lamb);
    }

    void push(const T &t)
    {
        m_data.push_back(t);
    }

    void pop()
    {
        m_data.pop_back();
    }

    void push(T &&t)
    {
        m_data.push_back(std::move(t));
    }


};

#endif // UNIQUEVECTOR_H
