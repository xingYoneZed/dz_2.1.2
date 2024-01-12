
#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
// 
//class Address {
//private:
//    std::string city;
//    std::string street;
//    int houseNumber;
//    int apartmentNumber;
//
//public:
//    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
//        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}
//
//    std::string getOutputAddress() const {
//        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
//    }
//};
//
//int main() {
//    std::ifstream inFile("in.txt");
//    std::ofstream outFile("out.txt");
//
//    if (!inFile.is_open() || !outFile.is_open()) {
//        std::cerr << "Unable to open files." << std::endl;
//        return 1;
//    }
//
//    int N;
//    inFile >> N;
//
//    Address** addresses = new Address * [N];
//
//    for (int i = 0; i < N; ++i) {
//        std::string city, street;
//        int houseNumber, apartmentNumber;
//
//        inFile >> city >> street >> houseNumber >> apartmentNumber;
//
//        addresses[i] = new Address(city, street, houseNumber, apartmentNumber);
//    }
//
//    // Вывод в обратном порядке
//    outFile << N << std::endl;
//    for (int i = N - 1; i >= 0; --i) {
//        outFile << addresses[i]->getOutputAddress() << std::endl;
//    }
//
//    // Очистка памяти
//    for (int i = 0; i < N; ++i) {
//        delete addresses[i];
//    }
//    delete[] addresses;
//
//    inFile.close();
//    outFile.close();
//
//    return 0;
//}




class Address {
private:
    std::string city;
    std::string street;
    int houseNumber;
    int apartmentNumber;

public:
    Address() : houseNumber(0), apartmentNumber(0) {}

    Address(const std::string& city, const std::string& street, int houseNumber, int apartmentNumber)
        : city(city), street(street), houseNumber(houseNumber), apartmentNumber(apartmentNumber) {}

    std::string getOutputAddress() const {
        return city + ", " + street + ", " + std::to_string(houseNumber) + ", " + std::to_string(apartmentNumber);
    }

    std::string getCity() const {
        return city;
    }

    // Для сравнения адресов при сортировке
    bool operator<(const Address& other) const {
        return city < other.getCity();
    }
};

void sortAddresses(Address* addresses, int size) {
    std::sort(addresses, addresses + size);
}

int main() {
    std::ifstream inFile("gg.txt");
    std::ofstream outFile("wp.txt");

    if (!inFile.is_open() || !outFile.is_open()) {
        std::cerr << "Unable to open files." << std::endl;
        return 1;
    }

    int N;
    inFile >> N;

    Address* addresses = new Address[N];

    for (int i = 0; i < N; ++i) {
        std::string city, street;
        int houseNumber, apartmentNumber;

        inFile >> city >> street >> houseNumber >> apartmentNumber;

        addresses[i] = Address(city, street, houseNumber, apartmentNumber);
    }

    // Сортировка адресов по названию города
    sortAddresses(addresses, N);

    // Вывод отсортированного списка адресов
    outFile << N << std::endl;
    for (int i = 0; i < N; ++i) {
        outFile << addresses[i].getOutputAddress() << std::endl;
    }

    // Очистка памяти
    delete[] addresses;

    inFile.close();
    outFile.close();

    return 0;
}
