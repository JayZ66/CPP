
#pragma once

#include <iostream>
#include <stdexcept>
#include <stdlib.h>

class Base {
    private:

    public:

    virtual ~Base();

    Base*   Base::generate(void);
    void    Base::identify(Base* p);
    void    Base::identify(Base& p);

};