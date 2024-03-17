﻿#include <iostream>
#include <vector>
#include <ctime>
#include <chrono>

using namespace std;
using namespace std::chrono;

static void HoareSort(vector<int>& vect, int beginIndex, int endIndex) {
    int pivot = vect[(beginIndex + endIndex) / 2];
    int leftIndex = beginIndex;
    int RightIndex = endIndex;

    while (leftIndex <= RightIndex) {
        while (vect[leftIndex] < pivot) {
            leftIndex++;
        }
        while (vect[RightIndex] > pivot) {
            RightIndex--;
        }
        if (leftIndex <= RightIndex) {
            swap(vect[leftIndex++], vect[RightIndex--]);
        }
    }
    if (beginIndex < RightIndex) {
        HoareSort(vect, beginIndex, RightIndex);
    }
    if (leftIndex < endIndex) {
        HoareSort(vect, leftIndex, endIndex);
    }
}

const int SIZE = 25;
int main() {
    
    system("chcp 1251 > Null");
    vector<int> vect;

    for (int i = 0; i < SIZE; i++) {
        vect.push_back(rand() % 26 - 10);
    }

    cout << "Неотсортированный массив: ";
    for (int i : vect) {
        cout << i << " ";
    }
    cout << endl;
    
    auto start = high_resolution_clock::now();

    HoareSort(vect, 0, vect.size() - 1);

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << endl << "Отсортированный массив: ";
    for (int i : vect) {
        cout << i << " ";
    }
    cout << endl << endl << "Время выполнения (в микросекундах): " << duration.count() << endl;

    return 0;
}

