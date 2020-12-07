#include "functions/sorting.hpp"

#include <algorithm>

using namespace BehTavan::Functions;

template<typename T>
void Sorting::countingSort(std::vector<T> &arr)
{
    if (arr.empty()) {
        return;
    }

    const size_t size = arr.size();
    T maxElement = *std::max_element(arr.cbegin(), arr.cend());

    std::vector<size_t> counts(maxElement + 1, 0);
    for (size_t i = 0; i < size; i++) {
        counts[arr[i]]++;
    }

    for (size_t i = 1; i < maxElement + 1; i++) {
        counts[i] = counts[i - 1];
    }

    std::vector<T> result(size);
    for (size_t i = 0; i < size; i++) {
        result[counts[arr[i]] - 1] = arr[i];
        counts[arr[i]]--;
    }

    swap(arr, result);
}
