//assignment1-2720-OCt-04-2021- Samira Azimi
#include "gtest/gtest.h"
#include "Product.h"
#include "Waitlist.h"
#include "Warehouse.h"
#include "Exceptions.h"

TEST(TestWarehouse, TestChangingQuantity) {
  Waitlist* w = new Waitlist();
  Product* pro = new Product("product-type", 3);
  Warehouse* wh = new Warehouse(w);

  EXPECT_TRUE(wh->changeQuantity(pro, 2));
  delete pro;
  delete w;
  delete wh;
}

TEST(TestWarehouse, TestingcheckQuantity) {
  Waitlist *w = new Waitlist();
  Product* pro = new Product("Hello", 29);
  Warehouse* wh = new Warehouse(w);
  wh -> changeQuantity(pro, 2);
EXPECT_EQ(2, wh->checkQuantity(pro));
}

TEST(TestWarehouse, DISABLED_TestingcheckQuantityNull) {
  Waitlist *w = new Waitlist();
  Product* pro = new Product("Hello", 29);
  Warehouse* wh = new Warehouse(w);
  wh -> changeQuantity(pro, 2);
  pro = nullptr;
  EXPECT_THROW(wh->checkQuantity(pro), invalid_parameter_error);
}
