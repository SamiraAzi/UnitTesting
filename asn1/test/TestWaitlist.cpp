//assignment1-2720-OCt-04-2021- Samira Azimi
#include "gtest/gtest.h"
#include "Waitlist.h"
#include "Warehouse.h"
#include "Order.h"

TEST(TestWaitlist, testAddingWaitlist) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
Order* o = new Order(wh, w);

  w->addOrder(o);
EXPECT_EQ(w->size(), 1);
  delete w;
  delete wh;
  delete o;
}

TEST(TestWaitlist, testRemovingWaitlist) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order* o = new Order(wh, w);

  w->addOrder(o);
  w->removeOrder(o);

  EXPECT_EQ(w->size(), 0);
  delete w;
  delete wh;
  delete o;
}

TEST(TestWaitlist, testCheckingAll) {
  Waitlist* w = new Waitlist();
  Warehouse* wh = new Warehouse(w);
  Order o(wh, w);
  Product* pro1 = new Product("sam", 2);
  Product* pro2 = new Product("sam", 2);
  Product* pro3 = new Product("sam", 2);

  o.editContents(pro1, 1);
  o.editContents(pro2, 1);
  o.editContents(pro3, 1);
  o.submit();
  wh->changeQuantity(pro1, 1);
  wh->changeQuantity(pro2, 1);
  wh->changeQuantity(pro3, 1);
  EXPECT_NO_THROW(w->checkAll());
  delete w;
  delete wh;
  delete pro1;
  delete pro2;
  delete pro3;
}
