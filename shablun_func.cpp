// shablun_func.cpp

#include <iostream>
#include <algorithm>
#include <time.h>

using namespace std;
unsigned const int size = 10;

template<typename T>
T shablonMINMAX(T a, T b)
{
    if (a > b)
    {
        return a;
    }
    else
        return b;

} 

template<typename T>
T shablonMIN(T a, T b)
{
    if (a < b)
    {
        return a;
    }
    else
        return b;

}

template<typename T, size_t n>
void sortirovka(T(&arr)[n]) {
    for (size_t i = 0; i < n-1; ++i) {
        for (size_t j = 0; j < n-i-1; ++j) {
            if (arr[j] > arr[j+1]) {
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

template<typename T, size_t n>
void vivod(const T(&arr)[n]) {
    for (size_t i = 0; i < n; ++i) {
        cout << arr[i] << ' ';
    }
    cout << endl;
}

template<typename T, size_t n>
void zamena(T(&arr)[n], T(&arr2)[n]) {
    for (size_t i = 0; i < n; ++i) {
       

            arr[i] = arr2[i];
            
        
    }
    cout << endl;
}

template<typename T, size_t n>
void binarnpoisk(T(&arr)[n])
{
    int chislo;
    sort(arr, arr + 10);
    cout << endl;
    cout << "Введите число которок хотите найти: ";
    cin >> chislo;
    bool flag = false;
    int l = 0;
    int r = 9;
    int mid;
    while ((l <= r) && (flag != true)) {
        mid = (l + r) / 2;
        if (arr[mid] == chislo) flag = true;
        if (arr[mid] > chislo) r = mid - 1;
        else l = mid + 1;
    }
    if (flag) cout << "Индекс элемента " << chislo << " в массиве равен: " << mid;
    else cout << "Извините, но такого элемента в массиве нет";
}


int main()
{
    setlocale(NULL, "RU");
    srand(time(NULL));
    int vodA{};
    int vodB{};
    int Massiv[] = {10,9,8,7,6,5,4,3,2,1};
    
    cout << "A: "; cin >> vodA;
    cout << "B: "; cin >> vodB;

    cout << endl;

    cout <<"Большое число из A и B: " << shablonMINMAX(vodA, vodB)<<endl;
    cout << "Меньше число из A и B: " << shablonMIN(vodA, vodB) << endl;
   
    cout << endl;

    for (size_t i = 0; i < 10; ++i) {
        cout << Massiv[i] << ' ';
    }
    cout << endl;

    sortirovka(Massiv);
    vivod(Massiv);

    //замены элемента массива на переданное значение.
    int Massiv2[] = { 3,2,4,5,3,6,4,2,3,2 };
    zamena(Massiv, Massiv2);
    vivod(Massiv);
    cout << endl;
    cout << "----------Бинарный поиск----------" << endl<<endl;
    vivod(Massiv);
    binarnpoisk(Massiv);

}

