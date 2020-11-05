#ifndef MYUNIQUEPTR_H
#define MYUNIQUEPTR_H

template<typename T>
class MyUniquePTR{

    T* m_ptr;

public:

    MyUniquePTR(T *obj = nullptr) : m_ptr(obj)  { }

    ~MyUniquePTR()
    {
        delete m_ptr;
    }

    MyUniquePTR(const MyUniquePTR& other) = delete;

    MyUniquePTR operator=(const MyUniquePTR& other) = delete;

    MyUniquePTR& operator=(MyUniquePTR&& other)
    {
        if(&other != this)
        {
            delete m_ptr;
            m_ptr = other.m_ptr;
            other.m_ptr = nullptr;
        }
        return *this;
    }

    MyUniquePTR(MyUniquePTR&& other)
    {
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    T& operator*()
    {
        return *m_ptr;
    }

    const T& operator*() const
    {
        return *m_ptr;
    }

    T* operator->()
    {
        return m_ptr;
    }

    const T* operator->() const
    {
        return m_ptr;
    }

    operator bool() const
    {
        return m_ptr;
    }

};

#endif // MYUNIQUEPTR_H
