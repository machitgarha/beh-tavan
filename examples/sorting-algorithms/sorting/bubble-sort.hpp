#ifndef BEH_TAVAN_FUNCTIONS_SORTING_BUBBLE_HPP
#define BEH_TAVAN_FUNCTIONS_SORTING_BUBBLE_HPP

#include "base.hpp"

namespace BehTavan::Functions::Sorting
{
    template<typename T>
    void bubbleSort(std::vector<T> &arr)
    {
        const size_t n = arr.size();
        bool sorted;

        for (size_t i = 0; i < n - 1; i++) {
            sorted = true;

            for (size_t j = 0; j < n - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                    // At least one swap is enough to make sure the numbers are not sorted
                    sorted = false;
                }
            }

            if (sorted) {
                return;
            }
        }
    }
}

#endif // BEH_TAVAN_FUNCTIONS_SORTING_BUBBLE_HPP
