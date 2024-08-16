#include <string>
#include <map>
#include "functions.h" // Include the header file again to access declarations
using namespace std;

const map<string, map<string, double>> priceTable = {
    {"LP", {{"S", 1.50}, {"M", 4.90}, {"L", 6.90}}},
    {"MR", {{"S", 2.00}, {"M", 3.00}, {"L", 4.00}}}
};

map<string, int> lpLargeCount;
map<string, double> monthlyDiscount;

string getMonth(string &date) {
    return date.substr(0, 7);
}

void getPrice(Transaction &trans, string date, string size, string provider)
{
    trans.date = date;
    trans.size = size;
    trans.provider = provider;
    trans.price = priceTable.at(provider).at(size);
    trans.discount = 0.0;
}

void applyDiscounts(Transaction &trans) {
    string month = getMonth(trans.date);

    if (trans.size == "S") {
        double lowestPrice = min(priceTable.at("LP").at("S"), priceTable.at("MR").at("S"));
        trans.discount = trans.price - lowestPrice;
        trans.price = lowestPrice;
    }

    else if (trans.size == "L" && trans.provider == "LP") {
        lpLargeCount[month]++;
        if (lpLargeCount[month] == 3) {
            trans.discount = trans.price;
            trans.price = 0.0;
        }
    }

    if (monthlyDiscount[month] + trans.discount > 10.0) {
        double remainingDiscount = 10.0 - monthlyDiscount[month];
        if (remainingDiscount > 0) {
            trans.price += trans.discount - remainingDiscount;
            trans.discount = remainingDiscount;
        } else {
            trans.price += trans.discount;
            trans.discount = 0.0;
        }
    }
    monthlyDiscount[month] += trans.discount;
}