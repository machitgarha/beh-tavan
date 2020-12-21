#ifndef BEH_TAVAN_FUNCTIONS_SORTING_QUICK_HPP
#define BEH_TAVAN_FUNCTIONS_SORTING_QUICK_HPP

#include "base.hpp"

namespace BehTavan::Functions::Sorting
{
    template<typename T>
    void quickSortRecursive(std::vector<T> &arr, size_t start, size_t end);

    template<typename T>
    size_t partition(std::vector<T> &arr, size_t start, size_t end);

    template<typename T>
    void quickSort(std::vector<T> &arr)
    {
        quickSortRecursive(arr, 0, arr.size() - 1);
    }

    template<typename T>
    void quickSortRecursive(std::vector<T> &arr, size_t start, size_t end)
    {
        if (start < end) {
            size_t pivotIndex = partition(arr, start, end);

            if (pivotIndex != 0) {
                quickSortRecursive(arr, start, pivotIndex - 1);
            }
            quickSortRecursive(arr, pivotIndex + 1, end);
        }
    }

    template<typename T>
    size_t partition(std::vector<T> &arr, size_t start, size_t end)
    {
        size_t
            cur = start,
            pivotIndex = end;

        while (cur < pivotIndex) {
            if (arr[cur] > arr[pivotIndex]) {
                std::swap(arr[cur], arr[pivotIndex - 1]);
                std::swap(arr[pivotIndex - 1], arr[pivotIndex]);
                pivotIndex--;
            } else {
                cur++;
            }
        }

        return pivotIndex;
    }
}

#endif // BEH_TAVAN_FUNCTIONS_SORTING_QUICK_HPP
