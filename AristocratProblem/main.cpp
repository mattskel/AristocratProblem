//
//  main.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Branch.hpp"
#include "Customer.hpp"
#include "Product.hpp"
#include "Kart.hpp"
#include "AustraliaBranch.hpp"
#include "NZBranch.hpp"
#include "System.hpp"
#include "KartItem.hpp"

#include <iostream>

std::vector<Product*> productList;
int PopulateProductList();
void TEST_AUS_BRANCH();
void TEST_KART();
void TEST_CHECKOUT();
void TEST_MAKE_PAYMENT();
void TEST_DELIVER_ORDERS();
void TEST_NZ_BRANCH();

void SCENARIO();

int main(int argc, const char * argv[]) {
    // insert code here...
    
    PopulateProductList();
    
//    TEST_AUS_BRANCH();
//    TEST_KART();
//    TEST_CHECKOUT();
//    TEST_MAKE_PAYMENT();
//    TEST_DELIVER_ORDERS();
//    TEST_NZ_BRANCH();
    
    SCENARIO();
    
    std::cout<<"\n////////////////////////////\n// END"<<std::endl;
    std::cout<<"\n";
    
    return 0;
}

int PopulateProductList () {
    
    //    std::vector<Product*> productList;
    productList.push_back(new Product(400.0f, "32\" Samsung Plasma TV"));
    productList.push_back(new Product(400.0f, "32\" Sony Plasma TV"));
    productList.push_back(new Product(150.0f, "400Watts LG Amplifier/AV Receiver"));
    productList.push_back(new Product(50.0f, "2-channel Panasonic speakers"));
    productList.push_back(new Product(50.0f, "2-channel Samsung speakers"));
    productList.push_back(new Product(900.0f, "Song LCD TV"));
    productList.push_back(new Product(900.0f, "Sony LCD TV"));
    productList.push_back(new Product(300.0f, "500Watts Yamaha Amplifier/AV Receiver"));
    productList.push_back(new Product(300.0f, "500Watts Kenwood Amplifier/AV Receiver"));
    productList.push_back(new Product(120.0f, "5-channel Sony speakers"));
    productList.push_back(new Product(110.0f, "5-channel Samsung speakers"));
    productList.push_back(new Product(1800.0f, "60\" LED TV"));
    productList.push_back(new Product(1600.0f, "55\" LED TV"));
    productList.push_back(new Product(950.0f, "650Watts Onkyo Amplifier/AV Receiver"));
    productList.push_back(new Product(950.0f, "650Watts Onkyo Amplifier/AV Receiver"));
    productList.push_back(new Product(1500.0f, "7-channel Bose speaker system"));
    productList.push_back(new Product(1500.0f, "7-channel Bose speaker system"));
    productList.push_back(new Product(80.0f, "Sony Blu-ray Player"));
    productList.push_back(new Product(5.0f, "HDMI Cables"));
    productList.push_back(new Product(200.0f, "Universal remote"));
    productList.push_back(new Product(120.0f, "Wireless headphones"));
    
    return 0;
}

// TEST AUS BRANCH
void TEST_AUS_BRANCH() {
    // CREATE BRANCH
    AustraliaBranch* ausBranch = new AustraliaBranch();
    ausBranch->SetProductList(&productList);
    ausBranch->SetExchangRate(0.75f);
    ausBranch->SetProfitMargin(0.0f);
    ausBranch->GenerateItemList();
    ausBranch->PrintItemList();
}

// TEST KART
// Test the ability to add and remove KartItems
void TEST_KART() {
    std::cout<<"\n////////////////////////////\n// TEST_KART"<<std::endl;
    
    Component* cableComponent = new Component(1.0f, 0.0f);
    cableComponent->SetProductReference(productList[18]);
    
    Component* remoteComponent = new Component(1.0f, 0.0f);
    remoteComponent->SetProductReference((productList)[19]);
    
    System* entrySystem = new System(1.0f, 0.0f, System::TheatreCategory::ENTRY);
    std::vector<Product*> entrySystemProductList;
    entrySystemProductList.push_back((productList)[0]);
    entrySystemProductList.push_back((productList)[2]);
    entrySystemProductList.push_back((productList)[4]);
    entrySystemProductList.push_back((productList)[17]);
    entrySystem->SetProductReferenceList(entrySystemProductList);
    
    // CREATE A NEW KART
    Kart* kart = new Kart();
    
    // ADD THE ITEMS TO THE KART
    kart->AddKartItem(cableComponent, 1);
    kart->AddKartItem(remoteComponent, 1);
    kart->PrintKartItems();
    
    // REMOVE AN ITEM BY INDEX
    kart->RemoveKartItem(0);
    kart->PrintKartItems();
    
    // ADD A NEW ITEM TO THE KART
    kart->AddKartItem(entrySystem, 1);
    kart->PrintKartItems();
}

// TEST CHECKOUT
void TEST_CHECKOUT() {
    std::cout<<"\n////////////////////////////\n// TEST_CHECKOUT"<<std::endl;
    
    // CREATE BRANCH
    AustraliaBranch* ausBranch = new AustraliaBranch();
    ausBranch->SetProductList(&productList);
    ausBranch->SetExchangRate(0.75f);
    ausBranch->SetProfitMargin(0.0f);
    ausBranch->GenerateItemList();
    
    // CREATE KART
    Kart* kart = new Kart();
    
    // ADD ITEMS TO KART
    kart->AddKartItem(ausBranch->GetItemList()[3], 1);
    kart->AddKartItem(ausBranch->GetItemList()[4], 1);
    kart->AddKartItem(ausBranch->GetItemList()[0], 1);
    kart->PrintKartItems();
    
    // GENERATE ORDER
    Order* order = ausBranch->Checkout(kart);
    order->PrintOrder();
}

// TEST MAKE PAYMENT
void TEST_MAKE_PAYMENT() {
    std::cout<<"\n////////////////////////////\n// TEST_MAKE_PAYMENT"<<std::endl;
    
    AustraliaBranch* ausBranch = new AustraliaBranch();
    ausBranch->SetProductList(&productList);
    ausBranch->SetExchangRate(0.75f);
    ausBranch->SetProfitMargin(0.0f);
    ausBranch->GenerateItemList();
    
    Kart* kart = new Kart();
    
    kart->AddKartItem(ausBranch->GetItemList()[3], 1);
    kart->AddKartItem(ausBranch->GetItemList()[4], 1);
    kart->AddKartItem(ausBranch->GetItemList()[0], 1);
    
    Order* order = ausBranch->Checkout(kart);
    order->PrintStatus();
    
    std::cout<<"\n// CUSTOMER_PAYMENT";
    Customer* customer = new Customer();
    customer->MakePayment(order);
    customer->CheckOrderStatus();
}

// TEST DELIVER ORDERS
void TEST_DELIVER_ORDERS() {
    std::cout<<"\n////////////////////////////\n// TEST_DELIVER_ORDERS"<<std::endl;
    
    AustraliaBranch* ausBranch = new AustraliaBranch();
    ausBranch->SetProductList(&productList);
    ausBranch->SetExchangRate(0.75f);
    ausBranch->SetProfitMargin(0.0f);
    ausBranch->GenerateItemList();
    
    Kart* kart = new Kart();
    kart->AddKartItem(ausBranch->GetItemList()[3], 1);
    kart->AddKartItem(ausBranch->GetItemList()[4], 1);
    kart->AddKartItem(ausBranch->GetItemList()[0], 1);
    
    Order* order = ausBranch->Checkout(kart);
    Customer* customer = new Customer();
    customer->MakePayment(order);
    
    std::cout<<"\n// PREPARE_ORDERS";
    ausBranch->PrepareOrders();
    customer->CheckOrderStatus();
    std::cout<<"\n// DELIVER_ORDERS";
    ausBranch->DeliverOrders();
    customer->CheckOrderStatus();
}

// TEST NZ BRANCH
void TEST_NZ_BRANCH() {
    std::cout<<"\n////////////////////////////\n// TEST_NZ_BRANCH"<<std::endl;
    
    NZBranch* nzBranch = new NZBranch();
    nzBranch->SetProductList(&productList);
    nzBranch->SetExchangRate(0.72f);
    nzBranch->SetProfitMargin(0.0f);
    nzBranch->GenerateItemList();
    nzBranch->PrintItemList();
    
    Kart* kart = new Kart();
    kart->AddKartItem(nzBranch->GetItem(3), 1);
    kart->AddKartItem(nzBranch->GetItem(4), 1);
    kart->AddKartItem(nzBranch->GetItem(0), 1);
    kart->PrintKartItems();
}

// SCENARIO DESCRIBED IN PROBLEM
// The following method describes the scenario from the original problem
void SCENARIO() {
    std::cout<<"\n////////////////////////////\n// SCENARIO DESCRIBED IN PROBLEM"<<std::endl;
    
    // INITIALISE REGIONAL BRANCHES
    AustraliaBranch* ausBranch = new AustraliaBranch();
    ausBranch->SetProductList(&productList);
    ausBranch->SetExchangRate(0.75f);
    ausBranch->SetProfitMargin(0.0f);
    ausBranch->GenerateItemList();
    
    NZBranch* nzBranch = new NZBranch();
    nzBranch->SetProductList(&productList);
    nzBranch->SetExchangRate(0.72f);
    nzBranch->SetProfitMargin(0.0f);
    nzBranch->GenerateItemList();
    
    // INITIALISE CUSTOMERS AND SET KART CONTENTS
    
    Customer* customerA = new Customer();
    Kart* kartA = new Kart();
    customerA->SetKart(kartA);
    
    kartA->AddKartItem(ausBranch->GetItemList()[1], 1);
    kartA->AddKartItem(ausBranch->GetItemList()[3], 2);
    kartA->AddKartItem(ausBranch->GetItemList()[4], 1);
    
    Customer* customerB = new Customer();
    Kart* kartB = new Kart();
    customerB->SetKart(kartB);
    
    kartB->AddKartItem(nzBranch->GetItem(2), 1);
    kartB->AddKartItem(nzBranch->GetItem(3), 4);
    kartB->AddKartItem(nzBranch->GetItem(4), 1);
    kartB->AddKartItem(nzBranch->GetItem(5), 1);
    
    Customer* customerC = new Customer();
    Kart* kartC = new Kart();
    customerC->SetKart(kartC);
    
    kartC->AddKartItem(ausBranch->GetItemList()[4],1);
    
    // CHECKOUT KARTS
    std::cout<<"\n////////////////////////////\n// CHECKOUT_KARTS"<<std::endl;
    
    std::cout<<"\n////////////////////////////\n// ORDER_A"<<std::endl;
    Order* orderA = ausBranch->Checkout(customerA->GetKart());
    orderA->PrintOrder();
    
    std::cout<<"\n////////////////////////////\n// ORDER_B"<<std::endl;
    Order* orderB = nzBranch->Checkout(customerB->GetKart());
    orderB->PrintOrder();
    
    std::cout<<"\n////////////////////////////\n// ORDER_C"<<std::endl;
    Order* orderC = ausBranch->Checkout(customerC->GetKart());
    orderC->PrintOrder();
    
    // CUSTOMER A MAKES PAYMENT
    std::cout<<"\n////////////////////////////\n// CUSTOMER_A_MAKES_PAYMENT"<<std::endl;
    customerA->MakePayment(orderA);
    
    // CUSTOMER CHECK ORDER STATUS
    // Only CustomerA has made payment
    // Expect only CustomerA to return an OrderStatus
    std::cout<<"\n////////////////////////////\n// CUSTOMER_CHECK_ORDER_STATUS"<<std::endl;
    std::cout<<"\n// CUSTOMER_A: ";
    customerA->CheckOrderStatus();
    std::cout<<"\n// CUSTOMER_B: ";
    customerB->CheckOrderStatus();
    std::cout<<"\n// CUSTOMER_C: ";
    customerC->CheckOrderStatus();
    
    // BRANCH PREPARES ORDERS
    std::cout<<"\n////////////////////////////\n// BRANCH_PREPARES_ORDERS"<<std::endl;
    ausBranch->PrepareOrders();
    nzBranch->PrepareOrders();
    
    // CUSTOMER CHECK ORDER STATUS
    // Only one order has been paid
    // Expect only one order will change status to READY_FOR_DELIVERY
    std::cout<<"\n////////////////////////////\n// CUSTOMER_CHECK_ORDER_STATUS"<<std::endl;
    std::cout<<"\n// CUSTOMER_A";
    customerA->CheckOrderStatus();
    std::cout<<"\n// CUSTOMER_B";
    customerB->CheckOrderStatus();
    std::cout<<"\n// CUSTOMER_C";
    customerC->CheckOrderStatus();
    
    // CUSTOMERS B AND C MAKE PAYMENT
    std::cout<<"\n////////////////////////////\n// CUSTOMER_B_AND_C_MAKE_PAYMENT"<<std::endl;
    customerB->MakePayment(orderB);
    customerC->MakePayment(orderC);
    
    // BRANCH PREPARES ORDERS
    std::cout<<"\n////////////////////////////\n// BRANCH_PREPARES_ORDERS"<<std::endl;
    ausBranch->PrepareOrders();
    nzBranch->PrepareOrders();
    
    // CUSTOMER CHECK ORDER STATUS
    // Only one order has been paid
    // Expect all orders will change status to READY_FOR_DELIVERY
    std::cout<<"\n////////////////////////////\n// CUSTOMER_CHECK_ORDER_STATUS"<<std::endl;
    std::cout<<"\n// CUSTOMER_A";
    customerA->CheckOrderStatus();
    std::cout<<"\n// CUSTOMER_B";
    customerB->CheckOrderStatus();
    std::cout<<"\n// CUSTOMER_C";
    customerC->CheckOrderStatus();
    
    // DELIVER ORDERS
    std::cout<<"\n////////////////////////////\n// DELIVER_ORDERS"<<std::endl;
    ausBranch->DeliverOrders();
    nzBranch->DeliverOrders();
    
    // CUSTOMER CHECK ORDER STATUS
    // Expect all orders DELIVERED
    std::cout<<"\n////////////////////////////\n// CUSTOMER_CHECK_ORDER_STATUS"<<std::endl;
    std::cout<<"\n// CUSTOMER_A";
    customerA->CheckOrderStatus();
    std::cout<<"\n// CUSTOMER_B";
    customerB->CheckOrderStatus();
    std::cout<<"\n// CUSTOMER_C";
    customerC->CheckOrderStatus();
}
