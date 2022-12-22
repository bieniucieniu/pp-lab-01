//Mikołaj Bień
//pon 11:15
//24.10.2022 / 25.10.2022
//numer albumu: 272950


#include <iostream>
#include <random>

int power(int a, int b) {
	int out = 1;
	for (int i = 0; i < b; i++) {
		out *= a;
	}
	return out;
}

//zad. 1
void multipicationTable(int rowCount, int columnCount) {
	std::cout << "\t|";
	for (int i = 0; i < columnCount; i++) std::cout << i+1 << "\t";
	std::cout << "\n";

	for (int i = 0; i < columnCount*8 + 3; i++) std::cout << "-";
	std::cout << "\n";
	
	for (int i = 1; i <= rowCount; i++) {
		std::cout << i << "\t|";
		for (int j = 1; j <= columnCount; j++) {
			std::cout << i * j << "\t";
		}
		std::cout << "\n";
	}

}

//zad. 2
int sumOfDigit(unsigned long number){
	int out = 0;
	while (number > 0) {
		out += number % 10;
		number /= 10;
	}
	std::cout << out << "\n";
	return out;
}

int sumOfHexDigit(unsigned long number) {
	int out = 0;
	while (number > 0) {
		out += number % 16;
		number /= 16;
	}
	std::cout << out << "\n";
	return out;
}

//zad. 3
void numbersGCD_LCM(int a, int b) {
	int gcd;
	for (int i = 1; i <= a; i++) {
		if (a % i == 0 && b % i == 0) {
			gcd = i;
		}
	}
	std::cout << "GCD: " << gcd << "\n";
	std::cout << "LCM: " << (a * b) / gcd << "\n";
}

//zad. 4
void sumOfseries(double precision) {
	if (precision > 0.1) {
		std::cout << "Precision must be less than 0.1\n";
		return;
	}
	double sumS1 = 0;
	double sumS2 = 1;
	double prevS1 = 0;
	double prevS2 = 1;
	int i = 0;

	while (true){ 
		prevS1 = prevS1 > 0 ? -4/(i*2 + 1) : 4/(i*2 + 1);
		sumS1 += prevS1;
		if(prevS1 > precision) break;
		i++;
	}

	i = 1;
	while (true) {
		prevS2 *= 1/i;
		sumS2 += prevS2;
		if (prevS2 > precision) break;
		i++;
	}
	
	
	
}
//zad. 5
void meanOfRandom(int min, int max, int count) {
	srand(time(NULL));
	int sumP = 0;
	int countP = 0;
	int sumN = 0;
	int countN = 0;
	for (int i = 0; i < count; i++) {
		int random = min + rand()%(max - min +1);
		std::cout << random << " ";
		if (random > 0) {
			sumP += random;
			countP++;
		} else {
			sumN += random;
			countN++;
		}
	}
	std::cout << "\n";
	std::cout << "mean of positive numbers: " << (float)sumP / countP << "\n";
	std::cout << "mean of negative numbers: " << (float)sumN / countN << "\n";
}

void menu() {
	std::cout << "1. Multiplication table\n";
	std::cout << "2. Sum of digits\n";
	std::cout << "3. Sun of hex digits\n";
	std::cout << "4. GCD and LCM\n";
	std::cout << "5. Sum of series\n";
	std::cout << "6. Mean of random numbers\n";
	std::cout << "7. Exit\n";

	int choice;
	std::cin >> choice;
	switch (choice) {
	case 1:
		int rowCount, columnCount;
		std::cout << "Enter row count: ";
		std::cin >> rowCount;
		std::cout << "Enter column count: ";
		std::cin >> columnCount;
		multipicationTable(rowCount, columnCount);
		break;
	case 2:
		unsigned long number;
		std::cout << "Enter number: ";
		std::cin >> number;
		sumOfDigit(number);
		break;
	case 3:
		unsigned long number2;
		std::cout << "Enter number: ";
		std::cin >> number2;
		sumOfHexDigit(number2);
		break;
	case 4:
		int a, b;
		std::cout << "Enter first number: ";
		std::cin >> a;
		std::cout << "Enter second number: ";
		std::cin >> b;
		numbersGCD_LCM(a, b);
		break;
	case 5:
		double precision;
		std::cout << "Enter precision: ";
		std::cin >> precision;
		sumOfseries(precision);
		break;
	case 6:
		int min, max, count;
		std::cout << "Enter min: ";
		std::cin >> min;
		std::cout << "Enter max: ";
		std::cin >> max;
		std::cout << "Enter count: ";
		std::cin >> count;
		meanOfRandom(min, max, count);
		break;
	case 7:
		return;
	}
	menu();
}

int main() {
	menu();
	return 0;
}
