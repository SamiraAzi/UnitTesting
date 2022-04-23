//assignment1-2720-OCt-04-2021- Samira Azimi
#include "Order.h"
#include "Product.h"
#include "Waitlist.h"
#include "Warehouse.h"
#include "gtest/gtest.h"

TEST(TestOrderState, TestInCart) {
    Waitlist* w = new Waitlist();
    Warehouse* wh = new Warehouse(w);
    Order* o = new Order(wh, w);
    Product* p = new Product("Hello", 20);

    o->editContents(p, 42);
    EXPECT_NO_THROW(o->view());
}

TEST(TestOrderState, TestPending) {
    Waitlist* w = new Waitlist();
    Warehouse* wh = new Warehouse(w);
    Order* o = new Order(wh, w);
    Product* p1 = new Product("Hello", 20);
    Product* p2 = new Product("BYe", 20);
    o->editContents(p1, 42);
    o->editContents(p2, 42);
    wh->changeQuantity(p1, 42);
    wh->changeQuantity(p1, 41);
    EXPECT_EQ(false, o->submit());
}

TEST(TestOrderState, TestCanceling) {
    Waitlist* w = new Waitlist();
    Warehouse* wh = new Warehouse(w);
    Order* o = new Order(wh, w);
    Product* p = new Product("Hello", 20);
    o->editContents(p, 42);
    o->cancel();
    EXPECT_EQ(true, o->submit());
}

TEST(TestOrderState, TestPendingCancel) {
    Waitlist* w = new Waitlist();
    Warehouse* wh = new Warehouse(w);
    Order* o = new Order(wh, w);
    Product* p = new Product("Hello", 20);
    o->editContents(p, 0);
    EXPECT_NO_THROW(o->submit());
    EXPECT_EQ(true, o->submit());
    EXPECT_NO_THROW(o->cancel());
}

TEST(TestOrderState, TestCompeletingCancel) {
    Waitlist* w = new Waitlist();
    Warehouse* wh = new Warehouse(w);
    Order* o = new Order(wh, w);
    Product* p1 = new Product("Hello", 20);
    Product* p2 = new Product("Bye", 20);
    Product* p3 = new Product("How", 20);
    o->editContents(p1, 2);
    o->editContents(p2, 2);
    o->editContents(p3, 2);
    wh->changeQuantity(p1, 2);
    wh->changeQuantity(p2, 2);
    wh->changeQuantity(p3, 2);

    EXPECT_EQ(true, o->submit());
    EXPECT_NO_THROW(o->cancel());
  }
