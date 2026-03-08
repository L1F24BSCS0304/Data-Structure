#ifndef RANGE_H
#define RANGE_H

template <typename T>
class Range
{
    T min;
    T max;

public:
    Range(T minimum, T maximum);
    bool contains(T value);
};


#endif