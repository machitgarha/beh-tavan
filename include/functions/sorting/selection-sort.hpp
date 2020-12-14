#ifndef BEH_TAVAN_FUNCTIONS_SORTING_SELECTION_HPP
#define BEH_TAVAN_FUNCTIONS_SORTING_SELECTION_HPP

#include "base.hpp"

#include <algorithm>

namespace BehTavan::Functions::Sorting
{
    template<typename T>
    void selectionSort(std::vector<T> &arr)
    {
        const size_t size = arr.size();

        for (size_t i = 0; i < size - 1; i++) {
            T &minimum = *min_element(arr.begin() + i, arr.end());
            std::swap(minimum, arr[i]);
        }
    }
}

#endif // BEH_TAVAN_FUNCTIONS_SORTING_SELECTION_HPP
