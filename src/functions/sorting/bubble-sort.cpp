#include "functions/sorting.hpp"

using namespace BehTavan::Functions;

template<typename T>
void Sorting::bubbleSort(std::vector<T> &arr)
{
    const size_t n = arr.size();
    bool sorted;

    for (size_t i = 0; i < n - 1; i++) {
        sorted = true;

        for (size_t j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                // At least one swap is enough to make sure the numbers are not sorted
                sorted = false;
            }
        }

        if (sorted) {
            return;
        }
    }
}
