// Сапожников Юрий
#pragma once

#include <cstdlib>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <iostream>
#include <vector>
#include <chrono>
#include <cassert>

using namespace std;
using namespace chrono;

void testcheck() {

    vector<int> abc{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    assert(getMedian(abc) == 5);

    vector<int> abc1{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    assert(getMedian(abc1) == 5);

    vector<int> abcd{ 6, 8, 3, 4, 10, 1, 7, 2, 9, 5 };
    assert(getMedian(abcd) == 5);

    vector<int> abcd1{ 6, 8, 3, 4, 1, 7, 2, 9, 5 };
    assert(getMedian(abcd1) == 5);

    cout << "Тест пройден" << endl;
}

/// Функция заполняет массив случайными числами в диапазоне [MIN, MAX]
/// a - ссылка на массив, который нужно заполнить
/// MAX - верхняя граница случайных чисел
/// MIN - нижняя граница случайных чисел
void Random_array(vector<int>& a, size_t MAX, size_t MIN) {
	for (int i = 0; i < a.size(); i++) {
		a[i] = rand() % MAX + MIN;  // Случайное значение массива от MIN до MAX
	}
}

/// Функция выводит элементы массива на экран через пробел
/// a - ссылка на массив, элементы которого нужно вывести
void print_array_vector(const vector<int>& a) {
	for (size_t i = 0; i < a.size(); i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}

// Функция для нахождения медианы с замером времени
int getMedianWithTiming(vector<int> nums) {
    auto start = high_resolution_clock::now(); // Старт таймера

    int median;
    int n = nums.size();

    // Средний и наихудший случаи O(n log n)
	// Наилучший случай O(n) 
    sort(nums.begin(), nums.end());
    median = nums[(n - 1) / 2]; // Всегда находит левую медиану

    auto stop = high_resolution_clock::now(); // Стоп таймера
    auto duration = duration_cast<microseconds>(stop - start);

    // Запись результатов
    cout <<  ": " << duration.count() << " микросекунд | Медиана: " << median << endl;

    return median;
}

void getMedianWithTimingFile(ofstream& file) {

    file << "n,time_mcs" << endl;

    for (int i = 1; i < 1000; i++) {

        vector<int> timetest;
        timetest.resize(i);

        Random_array(timetest, 10000, 1);

        auto start = high_resolution_clock::now(); // Старт таймера

        int median;
        int n = timetest.size();

        // Средний и наихудший случаи O(n log n)
        // Наилучший случай O(n) 
        sort(timetest.begin(), timetest.end());
        median = timetest[(n - 1) / 2]; // Всегда находит левую медиану

        auto stop = high_resolution_clock::now(); // Стоп таймера
        auto duration = duration_cast<microseconds>(stop - start);

        // Запись результатов
        file << i << "," << duration.count() << endl;
    }
}

// Функция для нахождения
int getMedian(vector<int> nums) {

    int median;
    int n = nums.size();

    // Средний и наихудший случаи O(n log n)
    sort(nums.begin(), nums.end());
    median = nums[(n - 1) / 2]; // Всегда находит левую медиану

    return median;
}
