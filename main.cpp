/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: Eagleye
 *
 * Created on September 13, 2018, 7:42 PM
 */

#include <iostream>

class One {
    int _x;
public:
    One(int x) : _x{x}
    {
    }
};

class Two {
    One a;
    int _y;

public:
    Two(int y) : a{y} /* if you do not use initializer list here, 
                       * compiler give "no default constructor" error
                       */
    {
    }

};

class Base {
private:

    int _x;
public:

    Base(int x) : _x{x}
    {
    }
};

class Child : public Base {
    int _y;
public:

    Child(int x, int y) : Base{x}, _y{y}/*in order to initialize Base class
                                         * since _x is private;
                                         */
    {
    }
};

class ClassA {
    const int a;
public:
    ClassA(int x) : a{x}
    {
    } /* constant variable members can only be initialize 
                          * in initializer list*/
};

class Foo {
    int x;
public:

    Foo(int x) : x(x) // you cannot use x{x} here, 
    {
    }
};

class Base_ {
    int _x;
public:

    Base_() {
        std::cout << "base default\n";
    }

    Base_(int x) {
        _x = x;
        std::cout << "Base_ parameter constructor\n";
    }

    Base_(const Base_ &obj) {
        _x = obj._x;
        std::cout << "Base_ copy constructor\n";
    }

    Base_& operator=(const Base_& b) {
        _x = b._x;
        std::cout << "Base_ assignment operator\n";
    }

};

class Child_ : public Base_ {
    Base_ _b;

public:

    Child_() {
        std::cout << "Child_ default\n";
    }

    Child_(Base_ b) : _b(b) {

        std::cout << "Child_ parameter\n";
    }

};

int main(int argc, char** argv) {

    Child c(1, 2);

    Base_ b(10);
    
    Child_ ch(b);


    return 0;
}

