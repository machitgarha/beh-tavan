#include "functions/sorting.hpp"

using namespace BehTavan::Functions;

template<typename T>
void insertionSort(std::vector<T> &arr)
{
    const size_t size = arr.size();

    for (size_t i = 1; i < size; i++) {
        for (size_t j = i - 1; j != -1; j--) {
            if (arr[i] < arr[j]) {
                std::swap(arr[j], arr[j + 1]);
            } else {
                break;
            }
        }
    }
}
