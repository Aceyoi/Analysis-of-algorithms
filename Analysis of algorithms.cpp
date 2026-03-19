#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstdlib>

#include  "Analysisofalgorithmsmodul.h"

using namespace std;

const size_t MAX = 10000; // Максимальное число для случайного числа
const size_t MIN = 1;  // Минимальное число для случайного числа

int main() {
    setlocale(LC_ALL, "Russian");
    testcheck();
	srand(static_cast<unsigned int>(time(0)));// Инициализация генератора случайных чисел

    int n;
    cout << "Введите размер массива: ";
    cin >> n;

    vector<int> array; // Создание интового векторногго массива
    array.resize(n);

    Random_array(array, MAX, MIN);

    ofstream outFile("output.txt", ios::app);
    if (!outFile.is_open()) {
        cout << "Ошибка открытия файла!" << endl;
        return 1;
    }

	getMedianWithTiming(array); // Вывод на экран

	getMedianWithTimingFile(outFile); // Запись в файл

    outFile.close();

    return 0;
}



