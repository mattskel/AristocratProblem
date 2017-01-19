//
//  AustraliaBranch.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 16/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "AustraliaBranch.hpp"

AustraliaBranch::AustraliaBranch() : Branch() {}

AustraliaBranch::~AustraliaBranch() {}

Item* AustraliaBranch::GetItem(int index) {
    return m_itemList[index];
}

void AustraliaBranch::GenerateItemList() {
    
    System* entrySystem = new System(m_exchangeRate, m_profitMargin, System::TheatreCategory::ENTRY);
    std::vector<Product*> entrySystemProductList;
    entrySystemProductList.push_back((*m_productList)[0]);
    entrySystemProductList.push_back((*m_productList)[2]);
    entrySystemProductList.push_back((*m_productList)[4]);
    entrySystemProductList.push_back((*m_productList)[17]);
    entrySystem->SetProductReferenceList(entrySystemProductList);
    entrySystem->CalcSalePrice();
    m_itemList.push_back(entrySystem);
    
    System* intermediateSystem = new System(m_exchangeRate, m_profitMargin, System::TheatreCategory::INTERMEDIATE);
    std::vector<Product*> intermediateSystemProductList;
    intermediateSystemProductList.push_back((*m_productList)[5]);
    intermediateSystemProductList.push_back((*m_productList)[7]);
    intermediateSystemProductList.push_back((*m_productList)[9]);
    intermediateSystemProductList.push_back((*m_productList)[17]);
    intermediateSystem->SetProductReferenceList(intermediateSystemProductList);
    intermediateSystem->CalcSalePrice();
    m_itemList.push_back(intermediateSystem);
    
    System* cinematicSystem = new System(m_exchangeRate, m_profitMargin, System::TheatreCategory::CINEMATIC);
    std::vector<Product*> cinematicSystemProductList;
    cinematicSystemProductList.push_back((*m_productList)[11]);
    cinematicSystemProductList.push_back((*m_productList)[13]);
    cinematicSystemProductList.push_back((*m_productList)[15]);
    cinematicSystemProductList.push_back((*m_productList)[17]);
    cinematicSystem->SetProductReferenceList(cinematicSystemProductList);
    cinematicSystem->CalcSalePrice();
    m_itemList.push_back(cinematicSystem);
    
    Component* cableComponent = new Component(m_exchangeRate, m_profitMargin);
    cableComponent->SetProductReference((*m_productList)[18]);
    cableComponent->CalcSalePrice();
    m_itemList.push_back(cableComponent);
    
    Component* remoteComponent = new Component(m_exchangeRate, m_profitMargin);
    remoteComponent->SetProductReference((*m_productList)[19]);
    remoteComponent->CalcSalePrice();
    m_itemList.push_back(remoteComponent);
    
    Component* headphonesComponent = new Component(m_exchangeRate, m_profitMargin);
    headphonesComponent->SetProductReference((*m_productList)[20]);
    headphonesComponent->CalcSalePrice();
    m_itemList.push_back(headphonesComponent);
    
}

void AustraliaBranch::PrintItemList() {
    for (Item* item : m_itemList) {
        item->PrintDetails();
    }
}
