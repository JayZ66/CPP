
#pragma once

#include <iostream>
#include <stdexcept>
#include <stdlib.h>

class A;
class B;
class C;

class Base {
    private:

    public:

    virtual ~Base();

};

Base*   generate(void);
void    identify(Base* p);
void    identify(Base& p);