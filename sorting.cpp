#include<iostream>
#include<vector>
#include<random>

/** Implement the sorting algorithms below.
 Don't change the main function. You can define helper functions
 if you need to. 
 If you run the program now, it shoulprint : sorted:0
 As you implement the sorting algorithms,
  the sorted value increment by 1 for each sorting algorithm
  successfully implemented. 
  When all functions are correctly defined,
  your program should display: sorted:5
**/

template<typename T>
void bubbleSort(std::vector<T>& v)
{
    //your code goes here
    
    for (size_t i = 0; i < v.size() - 1; ++i) {
        for (size_t j = 0; j < v.size() - i - 1; ++j) {
            if (v[j] > v[j + 1]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
      
}

template <typename T>
void insertionSort(std::vector<T>& v)
{
    
    //your code goes here
    for (size_t i = 1; i < v.size(); ++i) {
        T key = v[i];
        int j = i - 1;
        while (j >= 0 && v[j] > key) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }

}


template <typename T>
void selectionSort (std::vector<T>& v)
{
    //Your code goes here
    for (size_t i = 0; i < v.size() - 1; ++i) {
        size_t min_idx = i;
        for (size_t j = i + 1; j < v.size(); ++j) {
            if (v[j] < v[min_idx]) {
                min_idx = j;
            }
        }
        std::swap(v[i], v[min_idx]);
    }

}


template <typename T>
size_t partition(std::vector<T>& v, size_t low, size_t high)
{
    T pivot = v[high];
    size_t i = low - 1;
    for (size_t j = low; j < high; ++j) {
        if (v[j] < pivot) {
            ++i;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]);
    return i + 1;
}

template <typename T>
void quickSortHelper(std::vector<T>& v, size_t low, size_t high)
{
    if (low < high) {
        size_t pi = partition(v, low, high);
        quickSortHelper(v, low, pi - 1);
        quickSortHelper(v, pi + 1, high);
    }
}

template <typename T>
void quickSort(std::vector<T>& v)
{
    quickSortHelper(v, 0, v.size() - 1);
}



template<typename T>
void merge(std::vector<T>& v, size_t left, size_t middle, size_t right) {
    size_t n1 = middle - left + 1;
    size_t n2 = right - middle;

    std::vector<T> L(n1);
    std::vector<T> R(n2);

    for (size_t i = 0; i < n1; ++i)
        L[i] = v[left + i];
    for (size_t j = 0; j < n2; ++j)
        R[j] = v[middle + 1 + j];

    size_t i = 0;
    size_t j = 0;
    size_t k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            v[k] = L[i];
            ++i;
        } else {
            v[k] = R[j];
            ++j;
        }
        ++k;
    }

    while (i < n1) {
        v[k] = L[i];
        ++i;
        ++k;
    }

    while (j < n2) {
        v[k] = R[j];
        ++j;
        ++k;
    }
}

template<typename T>
void mergeSortHelper(std::vector<T>& v, size_t left, size_t right) {
    if (left >= right)
        return;

    size_t middle = left + (right - left) / 2;
    mergeSortHelper(v, left, middle);
    mergeSortHelper(v, middle + 1, right);
    merge(v, left, middle, right);
}

template<typename T>
void mergeSort(std::vector<T>& v) {
    if (v.size() <= 1)
        return;

    mergeSortHelper(v, 0, v.size() - 1);
}

template<typename T>
bool isSorted(const std::vector<T>& v )
{
    for(size_t i=0; i<v.size()-1;++i)
      if(v.at(i)>v.at(i+1)) return false;
    return true;
}
int main()
{
 std::vector<int> v1{23,45,12,7,6,9,3};
 std::vector<int> v3{4,3,2,1,7,8,9,6};
 std::vector<int> v4{3,6,1,7,9,8,2,4,5};
 std::vector<int> v5{22,44,33,11,66,55,88,77};
 std::vector<int> v2{9,2,3,1,7,8,6,4,5};
 bubbleSort(v1);
 insertionSort(v2);
 selectionSort(v3);
 quickSort(v4);
 mergeSort(v5);
 std::vector<std::vector<int>> vectors;
 vectors.push_back(v1);
 vectors.push_back(v2);
 vectors.push_back(v3);
 vectors.push_back(v4);
 vectors.push_back(v5);
 int sorted=0;
 for (auto v: vectors)
     if( isSorted(v)) ++sorted;
 std::cout<<"sorted :"<<sorted<<"\n";

}