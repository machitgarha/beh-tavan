#include "functions/sorting.hpp"

using namespace BehTavan::Functions;

template<typename T>
static void buildHeap(std::vector<T> &);

template<typename T>
static void siftDown(std::vector<T> &, size_t, size_t);

template<typename T>
static size_t getNextSwapingIndex(std::vector<T> &, size_t, size_t);

template<typename T>
void Sorting::heapSort(std::vector<T> &arr)
{
    buildHeap(arr);

    const size_t size = arr.size();
    for (size_t last = size - 1; last != -1; last--) {
        std::swap(arr[last], arr[0]);
        siftDown(arr);
    }
}

template<typename T>
static void buildHeap(std::vector<T> &arr)
{
    const size_t size = arr.size();

    size_t j;
    // A tree with one node is always heap, so we start from 1 and not 0
    for (size_t i = 1; i < size; i++) {
        j = i;

        /*
         * No need to check whether j is zero or not, because, in this case, both values
         * are equal and the condition is false then.
         */
        while (arr[j] > arr[j / 2]) {
            std::swap(arr[j], arr[j / 2]);
            j /= 2;
        }
    }
}

template<typename T>
static void siftDown(std::vector<T> &arr, size_t curIndex, size_t lastIndex)
{
    size_t nextSwapingIndex;

    while (true) {
        nextSwapingIndex = getNextSwapingIndex(arr, curIndex, lastIndex);

        // If the next swaping node is the current node (i.e. no swap remained)
        if (nextSwapingIndex == curIndex) {
            return;
        }

        std::swap(arr[curIndex], arr[nextSwapingIndex]);
        curIndex = nextSwapingIndex;
    }
}

template<typename T>
static size_t getNextSwapingIndex(std::vector<T> &arr, size_t curIndex, size_t lastIndex)
{
    size_t
        leftChildIndex = curIndex * 2 + 1,
        rightChildIndex = leftChildIndex + 1;

    // If the element has no left child (and subsequently right child)
    if (leftChildIndex > lastIndex) {
        return curIndex;
    }

    /*
     * Now, we know the left child exists, so we find the index of the node with maximum
     * value based on the existence of the right child.
     */
    size_t resultIndex = curIndex;
    if (arr[resultIndex] < arr[leftChildIndex]) {
        resultIndex = leftChildIndex;
    }
    if (rightChildIndex <= lastIndex && arr[resultIndex] < arr[rightChildIndex]) {
        resultIndex = rightChildIndex;
    }
    return resultIndex;
}
