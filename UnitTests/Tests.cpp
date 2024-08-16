#include <gtest/gtest.h>
#include "functions.h"
using namespace std;

TEST(DateTest, GetMonth) {
    string date = "2015-02-01";
    EXPECT_EQ(getMonth(date), "2015-02");

    date = "2015-03-15";
    EXPECT_EQ(getMonth(date), "2015-03");

    date = "2023-12-31";
    EXPECT_EQ(getMonth(date), "2023-12");
}

TEST(simpleInputTest, HandlesSmallShipmentWithLP)
{
    Transaction trans;
    string date = "2023-08-10";
    string size = "S";
    string provider = "LP";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 1.50);
    EXPECT_EQ(trans.discount, 0.0);
}

TEST(simpleInputTest, HandlesMediumShipmentWithLP)
{
    Transaction trans;
    string date = "2023-08-24";
    string size = "M";
    string provider = "LP";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 4.90);
    EXPECT_EQ(trans.discount, 0.0);
}

TEST(simpleInputTest, HandlesLargeShipmentWithLP)
{
    Transaction trans;
    string date = "2023-08-31";
    string size = "L";
    string provider = "LP";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 6.90);
    EXPECT_EQ(trans.discount, 0.0);
}

TEST(simpleInputTest, HandlesSmallShipmentWithMR)
{
    Transaction trans;
    string date = "2023-09-17";
    string size = "S";
    string provider = "MR";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 1.5);
    EXPECT_EQ(trans.discount, 0.5);
}

TEST(simpleInputTest, HandlesMediumShipmentWithMR)
{
    Transaction trans;
    string date = "2023-09-27";
    string size = "M";
    string provider = "MR";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 3.0);
    EXPECT_EQ(trans.discount, 0.0);
}

TEST(simpleInputTest, HandlesLargeShipmentWithMR)
{
    Transaction trans;
    string date = "2023-09-31";
    string size = "L";
    string provider = "MR";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 4.0);
    EXPECT_EQ(trans.discount, 0.0);
}

TEST(applyDiscountTest, ThreeLShipmentWithLP) {
    Transaction trans;
    string date = "2023-09-02";
    string size = "L";
    string provider = "LP";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 6.9);
    EXPECT_EQ(trans.discount, 0.0);

    date = "2023-09-14";
    size = "L";
    provider = "LP";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 6.9);
    EXPECT_EQ(trans.discount, 0.0);

    date = "2023-09-20";
    size = "L";
    provider = "LP";
    getPrice(trans, date, size, provider);
    applyDiscounts(trans);
    EXPECT_EQ(trans.price, 0.0);
    EXPECT_EQ(trans.discount, 6.9);

}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

