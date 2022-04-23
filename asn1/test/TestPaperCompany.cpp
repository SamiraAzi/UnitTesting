//assignment1-2720-OCt-04-2021- Samira Azimi
#include "PaperCompany.h"
#include "Exceptions.h"
#include "Waitlist.h"
#include "Warehouse.h"
#include "Order.h"
#include "Product.h"
#include "gtest/gtest.h"

TEST(TestPaperCompany, TestAddingProduct) {
  PaperCompany* pC = new PaperCompany();
  EXPECT_EQ(pC->addProduct("sam", 5), true);
  delete pC;
}

TEST(TestPaperCompany, TestfindingProduct) {
  PaperCompany* pC = new PaperCompany();
  pC->addProduct("sami", 1);
  pC->addProduct("sara", 3);
  Product* ProToExp = new Product("sami", 1);

EXPECT_EQ(pC->findProduct("sami")->getName(), ProToExp->getName());
  delete pC;
  delete ProToExp;
}

TEST(TestPaperCompany, TestfindingProductFalse) {
  PaperCompany* pC = new PaperCompany();
pC->addProduct("sami", 1);
pC->addProduct("sara", 2);
  Product* ProToExp = new Product("Hannah", 1);

EXPECT_NE(pC->findProduct("sami")->getName(), ProToExp->getName());
  delete pC;
  delete ProToExp;
}

TEST(TestPaperCompany, TestadjustingInventory) {
  PaperCompany* pC = new PaperCompany();
  Product* p = new Product("sami", 1);
pC->addProduct(p->getName(), p->getWeight());

EXPECT_FALSE(pC->adjustInventory(p->getName(), -34));
  delete pC;
  delete p;
}

TEST(TestPaperCompany, TestVoidInventory) {
  PaperCompany* pC = new PaperCompany();
pC->addProduct("sam", 2);
pC->addProduct("sar", 4);

EXPECT_NO_THROW(pC->listInventory());
delete pC;
}

TEST(TestPaperCompany, TestVoidView) {
PaperCompany* pC = new PaperCompany();
pC->addProduct("sam", 2);
pC->addProduct("sar", 4);

Order* oD1 = nullptr;
oD1 = pC->createOrder();
Order* oD2 = nullptr;
oD2 = pC->createOrder();

pC->addToOrders(oD1);
pC->addToOrders(oD2);
EXPECT_NO_THROW(pC->viewOrders());
}

TEST(TestPaperCompany, TestAddingToOrder) {
  PaperCompany* pC = new PaperCompany();
  Order* o = nullptr;
EXPECT_THROW(pC->addToOrders(o), invalid_parameter_error);
delete pC;
delete o;
}
