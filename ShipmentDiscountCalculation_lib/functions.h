#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
#include <map>

using namespace std;

struct Transaction {
    string date;
    string size;
    string provider;
    double price;
    double discount;
};

void applyDiscounts(Transaction& trans);
string getMonth(string& date);
void getPrice(Transaction &trans, string date, string size, string provider);

extern const map<string, map<string, double>> priceTable;
extern map<string, int> lpLargeCount;
extern map<string, double> monthlyDiscount;

#endif