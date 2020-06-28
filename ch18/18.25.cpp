#include <iostream>

class Base1 {
public:
    virtual void print() { std::cout << "Base1::print" << std::endl; }
    virtual ~Base1() {}
};
class Base2 {
public:
    virtual void print() { std::cout << "Base2::print" << std::endl; }
    virtual ~Base2() {}
};

class D1 : public Base1 {
public:
    virtual void print() override { std::cout << "D1::print" << std::endl; }
};

class D2 : public Base2 {
public:
    virtual void print() override { std::cout << "D2::print" << std::endl; }
};

class MI : public D1, public D2 {
public:
    virtual void print() override { std::cout << "MI::print" << std::endl; }
};

int main() {
    Base1 *pb1 = new MI;
    Base2 *pb2 = new MI;
    D1 *pd1 = new MI;
    D2 *pd2 = new MI;

    //(a)
    pb1->print();
    //(b)
    pd1->print();
    //(c)
    pd2->print();
    //(d)
    delete pb2;
    //(e)
    delete pd1;
    //(f)
    delete pd2;

    // All calls MI version because MI overides print function and all objects' dynamic type are MI
}