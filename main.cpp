#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <iomanip>

#include "ShipmentDiscountCalculation_lib/functions.h"

using namespace std;

int main() {
    ifstream inputFile("input.txt");
    string line;
    if (!inputFile.is_open()) {
        cerr << "Failed to open input.txt" << endl;
        return 1;
    }


    while (getline(inputFile, line)) {
        stringstream ss(line);
        string date, size, provider;

        ss >> date >> size >> provider;

        if (priceTable.find(provider) == priceTable.end() || priceTable.at(provider).find(size) == priceTable.at(provider).end()) {
            cout << line << " Ignored" << endl;
            continue;
        }

        Transaction trans;
        getPrice(trans, date, size, provider);
        applyDiscounts(trans); // Call the function from functions.cpp

        cout << trans.date << " " << trans.size << " " << trans.provider << " "
                   << fixed << setprecision(2) << trans.price << " ";
        if (trans.discount > 0) {cout << fixed << setprecision(2) << trans.discount << endl;}
        else { cout << "-" << endl;}
    }

    inputFile.close();

    return 0;
}