#include <iostream>
#include "UniqueVector.h"
#include "MyQueue.h"
#include "MyString.h"
#include "MyUniquePTR.h"
#include <string>
#include <vector>
#include <list>
#include <algorithm>

int main()
{
    UniqueVector<int> uv ({1, 2, 4, 4, 5}, 0, 10);
    uv.push_back({25,43,34,34,34});
    uv.erase({2,5,34});
    uv.sort(std::less<int>());
    //uv.print();
    //uv.sort();
    uv.push(376);
    uv.print();
    uv.pop();
    uv.print();



    MyQueue<MyString> q1{ MyString("AAA")};
    //использование MyQueue в диапазонном for:

//    for (auto& el : q1) { std::cout << el << ' '; }     //такое чтение не получается всегда хорошо сделать
//    std::cout<<'\n';

    q1.push("qwe");
    q1.push("asdfasde");
    q1.push("qnba");
    q1.push("qn12312a");
    for(int i=0; i<4; i++){
        q1.pop();
    }
    q1.push("qvns");
    q1.push("1111");
    std::cout<<q1.size()<<q1.capacity();
    q1.print();




    MyQueue < MyString > q2{};
    q2 = q1;
    //q2.print();
    //q1.print();


    MyQueue < MyString > q22 = std::move(q1);
    q22.print();

    MyQueue < MyString > q3{10, MyString ("!")}; //очередь должна содержать 10 элементов со строкой «!»

    q1 = q3;

    q1.print();

    q2 = MyQueue < MyString > (5, MyString ("?"));

    q2.print();
    q1 = { MyString("bbb"), MyString ("ssss")};
    q1.print();



    MyUniquePTR<MyString> p1(new MyString ("abc"));

    std:: cout<<p1->GetString();

    p1->SetNewString("qwerty");

    std:: cout << '\n' << p1->GetString() << '\n';
    MyString s2 = *p1;


//    MyUniquePTR< MyString > p2=p1; //здесь компилятор должен выдавать ошибку =>

//    Исправьте!
    MyUniquePTR<MyString> p11;
    if(p11) {std::cout<<"have object!";} //а это должно работать
    else {std::cout<<"no object";}

    MyUniquePTR< MyString > p3(new MyString ("vvv"));
    MyUniquePTR< MyString > p2;
    //p3 = p2; //и здесь компилятор должен выдавать ошибку

    MyUniquePTR< MyString >  const  pc(new MyString("PCPCPC"));
    std::cout<< (*pc).GetString();

    std::vector< MyUniquePTR< MyString >> v;

    v.push_back(new MyString("QWE"));
    v.push_back(new MyString("Qeqwe"));
    v.push_back(new MyString("123E"));
    v.emplace_back(new MyString("faxd"));


    std::list< MyUniquePTR< MyString >> l(make_move_iterator(v.begin()), make_move_iterator(v.end()));

    l.insert(l.end(), new MyString("QWE"));

//    l.clear();

//    for(auto it = v.begin(); it != v.end(); ++it)
//    {
//        l.insert(l.end(), std::move(*it));
//    }

    //в векторе остались недействительные указатели.

    return 0;
}
