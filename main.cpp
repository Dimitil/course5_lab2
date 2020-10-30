#include <iostream>
#include "UniqueVector.h"
#include "MyQueue.h"
#include "MyString.h"
#include <string>
//class Point{
//public:
//  int x;
//  int y;
//public:
//  Point(int a, int b):x(a), y(b){}
//friend std::ostream& operator<<(std::ostream& out, const Point& p)
//{
//    out<<p.x<<' '<<p.y;
//    return out;
//}
//};

//bool operator>(const Point &a, const Point &b)
//{
//    return a.x>b.x;
//}
//bool operator<(const Point &a, const Point &b)
//{
//    return a.x<b.x;
//}

//bool operator==(const Point &a, const Point &b)
//{
//    return a.x==b.x;
//}

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
    //UniqueVector<Point> uvp = {Point(3,2),Point(2,4),Point(4,2)};
    //uvp.sort('g');
    //uvp.print();


    MyQueue<std::string> q1{ std::string("AAA"), std::string ("qwerty"), std::string("lkasje")};
    //использование MyQueue в диапазонном for:
    for (auto& el : q1) { std::cout << el << ' '; }
    std::cout<<'\n';

    std::string s("abc");
    q1.push(s);

    q1.push(std::string("123"));
    //for (auto& el : q1) { std::cout << el << ' '; }     //такое чтение не получается всегда хорошо сделать
    //std::cout<<'\n';
    std::string s1 = q1.pop();

    q1.push("sss");

    q1.push("WWW");
    q1.push("FFF");
    q1.push("SDA");

    q1.print();
    std::cout<<q1.size();

    //MyQueue < MyString > q2 = q1;
    //q2.print();
    //q1.print();

    //MyQueue < MyString > q22 = std::move(q1);

    //MyQueue < MyString > q3{10, MyString (“!”)}; //очередь должна содержать 10 элементов со строкой «!»

    //q1 = q3;

    //q2 = MyQueue < MyString > (5, MyString (“?”));

    //q1 = { MyString(“bbb”), MyString (“ssss”)};



    return 0;
}
