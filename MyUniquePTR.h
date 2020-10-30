#ifndef MYUNIQUEPTR_H
#define MYUNIQUEPTR_H

template<typename T>
class MyUniquePTR{

    T* m_ptr;

public:

    MyUniquePTR(T *obj)
    {
        m_ptr = obj;
    }

    MyUniquePTR()
    {
        m_ptr = nullptr;
    }

    ~MyUniquePTR()
    {
        delete m_ptr;
    }

    MyUniquePTR(const MyUniquePTR& other) = delete;

    MyUniquePTR operator=(const MyUniquePTR& other) = delete;

    MyUniquePTR(MyUniquePTR&& other)
    {
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    T& operator*()
    {
        return *m_ptr;
    }

    T& operator*() const
    {
        return *m_ptr;
    }

    T* operator->()
    {
        return m_ptr;
    }

    T* operator->() const
    {
        return m_ptr;
    }

    operator bool()
    {
        return m_ptr;
    }

};

#endif // MYUNIQUEPTR_H
