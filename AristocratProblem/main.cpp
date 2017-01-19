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
    
    TEST_AUS_BRANCH();
    TEST_KART();
    TEST_CHECKOUT();
    TEST_MAKE_PAYMENT();
    TEST_DELIVER_ORDERS();
    TEST_NZ_BRANCH();
    
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
    //    order->PrintOrder();
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
