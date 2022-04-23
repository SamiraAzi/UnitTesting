//assignment1-2720-OCt-04-2021- Samira Azimi
#include "Order.h"
#include "Product.h"
#include "Waitlist.h"
#include "Warehouse.h"
#include <map>
#include "gtest/gtest.h"

TEST(TestOrder, testingForEmpty) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);

  EXPECT_TRUE(o->isEmpty());
  delete w;
  delete wh;
}

TEST(TestOrder, testingIsEmpty) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  Product* p = new Product("Hello", 20);

  o->editContents(p, 42);
  EXPECT_FALSE(o->isEmpty());
  delete w;
  delete wh;
  delete p;
}

TEST(TestOrder, TestingEditContentNull) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  Product* p = nullptr;

  EXPECT_THROW(o->editContents(p, 21), invalid_parameter_error);
  delete w;
  delete wh;
  delete p;
}

TEST(TestOrder, TestingEditContent) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  Product* p = new Product("Hello", 20.0);

  EXPECT_TRUE(o->editContents(p, 42));
  EXPECT_NO_THROW(o->displayContent());
  delete w;
  delete wh;
  delete p;
  delete o;
}

TEST(TestOrder, TestingContructorNull) {
Waitlist* w = nullptr;
Warehouse* wh = new Warehouse(w);

EXPECT_THROW(Order* o = new Order(wh, w), invalid_parameter_error);
}

TEST(TestOrder, TestingEditContentForNegative) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  Product* p = new Product("Hello", 20);

  o->editContents(p, 42);
  EXPECT_TRUE(o->editContents(p, -20));
  delete w;
  delete wh;
  delete p;
  delete o;
}

TEST(TestOrder, TestGettingContent) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  Product* p1 = new Product("Hello", 20);
  Product* p2 = new Product("Hello", 30);
  Product* p3 = new Product("Hello", 40);

  o->editContents(p1, 20);
  o->editContents(p1, 30);
  o->editContents(p1, 40);

  map<Product* , int> methodList = o->getContents();
  map<Product* , int> list;
  list.insert({p1, 20});
  list.insert({p2, 30});
  list.insert({p3, 40});
}

TEST(TestOrder, TestGettingStatusIn) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  OrderState* oS = nullptr;
  Product* p = new Product ("sam", 20);
  o->editContents(p, 10);
  oS = o->getStatus();
  EXPECT_EQ(oS, o->getStatus());
}

TEST(TestOrder, TestGettingComplete) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  OrderState* oS = nullptr;
  Product* p = new Product ("sam", 20);
  oS = o->getStatus();
  o->editContents(p, 10);
  o->submit();
  oS = o->getStatus();
  EXPECT_EQ(oS, o->getStatus());
}

TEST(TestOrder, TestShippingTruck) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  OrderState* oS = nullptr;
  Product* p = new Product ("sam", 20);

  o->editContents(p, 10);
  o->setShipping(1);
  EXPECT_EQ(o->getShipping()->name(), "Truck");
  EXPECT_NE(o->getShipping()->name(), "Train");
}

TEST(TestOrder, TestShippingTrain) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  OrderState* oS = nullptr;
  Product* p = new Product ("sam", 20);

  o->editContents(p, 10);
  o->setShipping(5000);
  EXPECT_EQ("Train", o->getShipping()->name());
  EXPECT_NE("Air", o->getShipping()->name());
}

TEST(TestOrder, TestShippingAir) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  OrderState* oS = nullptr;
  Product* p = new Product ("sam", 20);

  o->editContents(p, 10);
  o->setShipping(950);
  EXPECT_EQ("Air", o->getShipping()->name());
  EXPECT_NE("Ship", o->getShipping()->name());
}

TEST(TestOrder, TestShippingShip) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  OrderState* oS = nullptr;
  Product* p = new Product ("sam", 20);

  o->editContents(p, 10);
  o->setShipping(25000);
  EXPECT_EQ("Ship", o->getShipping()->name());
  EXPECT_NE("Truck", o->getShipping()->name());
}

TEST(TestOrder, TestDisplay) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);
  Product* p1 = new Product ("sam", 20);
  Product* p2 = new Product ("sam", 30);
  Product* p3 = new Product ("sam", 40);

  o->editContents(p1, 20);
  o->editContents(p2, 30);
  o->editContents(p3, 40);

  EXPECT_NO_THROW(o->displayContent());
}
