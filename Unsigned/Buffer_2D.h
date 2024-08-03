

#ifndef UNSIGNED_BUFFER_2D_H
#define UNSIGNED_BUFFER_2D_H

#endif

#include <iostream>
#pragma once
#include <vector>

template<typename T>
class Buffer2D
{
protected:
    T* data;
    unsigned int w, h;
public:
    Buffer2D(unsigned int width, unsigned int height)
            : w(width), h(height), data(nullptr) {}

    unsigned int getWidth() { return this->width; }
    unsigned int getHeight() { return this->height; }



};

class Icon : public Buffer2D<int>
{

public:
    Icon(unsigned int size)
            :Buffer2D(size, size)
    {
        data = new int[size * size];
    }

    Icon& operator++ ()
    {
        for (int i = 0; i < w * h; i++)
        {
            ++data[i];
        }
        return *this;
    }

    bool operator < (const Icon& right) const
    {
        if (this->w < right.w)
            return true;
        return false;
    }
};



