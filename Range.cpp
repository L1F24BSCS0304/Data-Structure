#include "Range.h"

template <typename T>
Range<T>::Range(T minimum, T maximum)
{
    min = minimum;
    max = maximum;
}

template <typename T>
bool Range<T>::contains(T value)
{
    return (value >= min && value <= max);
}