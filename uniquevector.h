#ifndef UNIQUEVECTOR_H
#define UNIQUEVECTOR_H

#include <vector>
#include <algorithm>
#include <iostream>
#include <functional>

template<typename T>
class UniqueVector
{

    std::vector<T> m_data;

public:
    UniqueVector() = default;

    UniqueVector(std::initializer_list<T> il)
    {
        for( auto &elem : il)
        {
            auto it = std::find(m_data.begin(), m_data.end(), elem);
            if(it == m_data.end())
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

    void sort(char ch='g') //'g' - for >, 'l' for <
    {
        if (ch=='g')
        {
            std::sort(m_data.begin(), m_data.end(), std::greater<T>());
        }
        else {
            std::sort(m_data.begin(), m_data.end(), std::less<T>());
        }

    }
};

#endif // UNIQUEVECTOR_H
