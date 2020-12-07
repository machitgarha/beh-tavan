#ifndef BEH_TAVAN_SORTING_HPP
#define BEH_TAVAN_SORTING_HPP

#include <vector>

namespace BehTavan::Functions::Sorting
{
    template<typename T>
    void bubbleSort(std::vector<T> &);

    template<typename T>
    void countingSort(std::vector<T> &);

    template<typename T>
    void heapSort(std::vector<T> &);

    template<typename T>
    void insertionSort(std::vector<T> &);

    template<typename T>
    void mergeSort(std::vector<T> &);

    template<typename T>
    void quickSort(std::vector<T> &);

    template<typename T>
    void radixSort(std::vector<T> &);

    template<typename T>
    void selectionSort(std::vector<T> &);
}

#endif // BEH_TAVAN_SORTING_HPP
