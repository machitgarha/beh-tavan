#ifndef BEH_TAVAN_FUNCTIONS_SORTING_MERGE_HPP
#define BEH_TAVAN_FUNCTIONS_SORTING_MERGE_HPP

#include "base.hpp"

namespace BehTavan::Functions::Sorting
{
    template<typename T>
    static void mergeSortRecursive(std::vector<T> &, size_t, size_t);

    template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
    static void mergeSorted(
        InputIterator1, InputIterator1,
        InputIterator2, InputIterator2,
        OutputIterator, OutputIterator
    );

    template<typename T>
    void mergeSort(std::vector<T> &arr)
    {
        mergeSortRecursive(arr, 0, arr.size() - 1);
    }

    template<typename T>
    static void mergeSortRecursive(std::vector<T> &arr, size_t from, size_t to)
    {
        // Every array with one element is sorted
        // (to - from < 1) (not to overflow)
        if (to < from + 1) {
            return;
        }

        size_t mid = (from + to) / 2;

        mergeSortRecursive(arr, from, mid);
        mergeSortRecursive(arr, mid + 1, to);

        std::vector<T> arrCopy = arr;

        mergeSorted(
            arrCopy.cbegin() + from, arrCopy.cbegin() + mid + 1,
            arrCopy.cbegin() + mid + 1, arrCopy.cbegin() + to + 1,
            arr.begin() + from, arr.end()
        );
    }

    template<typename InputIterator1, typename InputIterator2, typename OutputIterator>
    static void mergeSorted(
        InputIterator1 it1, InputIterator1 it1End,
        InputIterator2 it2, InputIterator2 it2End,
        OutputIterator outIt, OutputIterator outItEnd
    ) {
        for (; it1 != it1End && it2 != it2End && outIt != outItEnd; outIt++) {
            if (*it1 < *it2) {
                *outIt = *it1;
                it1++;
            } else {
                *outIt = *it2;
                it2++;
            }
        }

        if (it1 == it1End) {
            for (; it2 != it2End && outIt != outItEnd; outIt++, it2++) {
                *outIt = *it2;
            }
        }
        if (it2 == it2End) {
            for (; it1 != it1End && outIt != outItEnd; outIt++, it1++) {
                *outIt = *it1;
            }
        }
    }
}

#endif // BEH_TAVAN_FUNCTIONS_SORTING_MERGE_HPP
