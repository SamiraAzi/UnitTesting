//assignment1-2720-OCt-04-2021- Samira Azimi
#include "gtest/gtest.h"
#include "ShippingMethod.h"
#include "ShippingMethodFactory.h"

TEST(TestShippingMethod, TestForTruck) {
ShippingMethodFactory* Fac = new ShippingMethodFactory();
ShippingMethod* truck = Fac->getShippingMethod(10);

EXPECT_EQ("Truck", truck->name());
  delete truck;
  delete Fac;
}

TEST(TestShippingMethod, TestForTruckOverLimit) {
ShippingMethodFactory* Fac = new ShippingMethodFactory();
ShippingMethod* truck = Fac->getShippingMethod(150);

EXPECT_NE("Truck", truck->name());
  delete truck;
  delete Fac;
}

TEST(TestShippingMethod, TestForTrain) {
ShippingMethodFactory* Fac = new ShippingMethodFactory();
ShippingMethod* train = Fac->getShippingMethod(5000);

EXPECT_EQ("Train", train->name());
  delete train;
  delete Fac;
}

TEST(TestShippingMethod, TestForTrainOverLimit) {
ShippingMethodFactory* Fac = new ShippingMethodFactory();
ShippingMethod* train = Fac->getShippingMethod(11000);

EXPECT_NE("Train", train->name());
  delete train;
  delete Fac;
}

TEST(TestShippingMethod, TestForAir) {
ShippingMethodFactory* Fac = new ShippingMethodFactory();
ShippingMethod* air = Fac->getShippingMethod(900);

EXPECT_EQ("Air", air->name());
  delete air;
  delete Fac;
}

TEST(TestShippingMethod, TestForAiroverlimit) {
ShippingMethodFactory* Fac = new ShippingMethodFactory();
ShippingMethod* air = Fac->getShippingMethod(1020);

EXPECT_NE("Air", air->name());
  delete air;
  delete Fac;
}

TEST(TestShippingMethod, TestForShip) {
ShippingMethodFactory* Fac = new ShippingMethodFactory();
ShippingMethod* ship = Fac->getShippingMethod(25000);

EXPECT_EQ("Ship", ship->name());
  delete ship;
  delete Fac;
}

TEST(TestShippingMethod, TestnameingTruck) {
Truck* truck = new Truck();
EXPECT_EQ("Truck", truck->name());
  delete truck;
}

TEST(TestShippingMethod, TestnameingTrain) {
Train* train = new Train();
EXPECT_EQ("Train", train->name());
  delete train;
}

TEST(TestShippingMethod, TestnameingAir) {
Air* air = new Air();
EXPECT_EQ("Air", air->name());
  delete air;
}

TEST(TestShippingMethod, TestnameingShip) {
Ship* ship = new Ship();
EXPECT_EQ("Ship", ship->name());
  delete ship;
}
