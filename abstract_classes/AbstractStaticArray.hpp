#ifndef STATIC_ARRAY_HPP
#define STATIC_ARRAY_HPP

class AbstractStaticArray {
public:
    virtual int get(int position) = 0;
    virtual void insert(int position, int value) = 0;
    virtual int remove(int position) = 0;
    virtual int getSize()  = 0;
};

#endif // STATIC_ARRAY_HPP 
