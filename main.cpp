#include <cstdlib>
#include <iostream>

using namespace std;

void print(int numbers[], int size);
void countingSort(int numbers[], int size);

int main(int argc, char *argv[]) {
    int numbers[] = {1, 4, 1, 2, 7, 5, 2};
    int size = sizeof(numbers) / sizeof(*numbers);

    print(numbers, size);
    countingSort(numbers, size);
    print(numbers, size);

    system("read");
    return EXIT_SUCCESS;
}

void print(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

void countingSort(int numbers[], int size) {

    int menor=numbers[0];
    int mayor=numbers[0];
    int re[size];
    for (int i=0; i<size; i++){
        if (numbers[i]> mayor){
        mayor=numbers[i];
        }
        if (numbers[i]< menor){
        menor=numbers[i];
        }
    }
    const int t=mayor-menor+1;
    int a[t]={0};
    for (int i = 0; i < size; i++)
    {
        a[numbers[i]-menor]++;

    }
    int cc=0;
    for (int i = 0; i < t; i++)
    {
        a[i]=cc+a[i];
        cc=a[i];

    }
    for (int i = 0; i < size; i++)
    {
        re[a[numbers[i]-menor]-1]=numbers[i];
        a[numbers[i]-menor]--;
    }
    for (int i = 0; i < size; i++)
    {
        numbers[i]=re[i];
    }

}
