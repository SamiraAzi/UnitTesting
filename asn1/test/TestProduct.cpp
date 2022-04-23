//assignment1-2720-OCt-04-2021- Samira Azimi
#include "gtest/gtest.h"
#include "Product.h"

TEST(testProduct, defaultConstructorTest) {
Product p("sam", 3.5);

EXPECT_EQ("sam", p.getName());
EXPECT_EQ(3.5, p.getWeight());
}

TEST(testProduct, testGetWeight) {
Product p("sam", 3.5);

EXPECT_EQ(3.5, p.getWeight());
}

TEST(testProduct, testGetWeightforNagative) {
Product p("sam", -3.5);

EXPECT_EQ(-3.5, p.getWeight());
}
TEST(testProduct, testGetName) {
Product p("sam", 3.5);

EXPECT_EQ("sam", p.getName());
}
