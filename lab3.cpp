#include <iostream>
#include <time.h>
#include <stdlib.h>

void inuputToArr(const int size) {
    srand(time(0));

    float* arr = new float[size];

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 50 - 25;
        // std::cout << "arr[" << i << "]: ";
        // std::cin >> arr[i];
        // std::cout << std::endl;
    }

    float* pn = new float[size];

    float sumN = 0;
    float sumP = 0;

    std::cout << "arr =[";
    int pos = 0, neg = size - 1;
    for (int k = 0; k < size; k++) {
        if (*arr > 0) {
            pn[pos] = *arr;
            pos++;
            sumP += *arr;
        }
        else {
            pn[neg] = *arr;
            neg--;
            sumN += *arr;
        }

        std::cout << " " << *(arr++) << " ";
    }
    std::cout << "]\n\n";

    std::cout << "pos =[";
    for (int i = 0; i < pos; i++) std::cout << " " << pn[i] << " ";
    std::cout << "]\n";
    std::cout << "sum positive: " << sumP << "\n\n";

    std::cout << "neg =[";
    for (int i = size - 1; i > neg; i--) std::cout << " " << pn[i] << " ";
    std::cout << "]\n";
    std::cout << "sum negative: " << sumN << "\n\n";

    bool evnels = true;
    bool incr = true;
    bool decr = true;

    bool evnel = false;

    for (int s = 1; s < size; s++) {
        if (arr[s] <= arr[s - 1]) incr = false;
        if (arr[s] >= arr[s - 1]) decr = false;
        if (arr[s] == arr[s - 1]) evnel = true;
        if (arr[s] != arr[s - 1]) evnels = false;
    }

    if (!(incr && decr)) {
        std::cout << "array not sorted" << evnel ? "have even elements" : "";
    }
    else if (evnels) {
        std::cout << "all elements of array are equal";
    }

    delete[] arr;
    delete[] pn;
}

int main() {
    inuputToArr(10);
    return 0;
}