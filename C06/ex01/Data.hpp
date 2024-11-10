
#pragma once

class Data {
    private:
    int id;
    std::string name;
    float value;

    public:

    Data();
    Data(const Data& other);
    ~Data();

    Data& operator=(const Data& other);

};