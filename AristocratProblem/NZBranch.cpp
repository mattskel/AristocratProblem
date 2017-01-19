//
//  NZBranch.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 16/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "NZBranch.hpp"

NZBranch::NZBranch() : Branch() {}
NZBranch::~NZBranch() {}

Item* NZBranch::GetItem(int index) {
    return m_itemList[index];
}

void NZBranch::GenerateItemList() {
    System* entrySystem = new System(m_exchangeRate, m_profitMargin, System::TheatreCategory::ENTRY);
    std::vector<Product*> entrySystemProductList;
    entrySystemProductList.push_back((*m_productList)[1]);
    entrySystemProductList.push_back((*m_productList)[2]);
    entrySystemProductList.push_back((*m_productList)[4]);
    entrySystemProductList.push_back((*m_productList)[17]);
    entrySystem->SetProductReferenceList(entrySystemProductList);
    entrySystem->CalcSalePrice();
    m_itemList[0] = entrySystem;
    
    System* intermediateSystem = new System(m_exchangeRate, m_profitMargin, System::TheatreCategory::INTERMEDIATE);
    std::vector<Product*> intermediateSystemProductList;
    intermediateSystemProductList.push_back((*m_productList)[6]);
    intermediateSystemProductList.push_back((*m_productList)[8]);
    intermediateSystemProductList.push_back((*m_productList)[10]);
    intermediateSystemProductList.push_back((*m_productList)[17]);
    intermediateSystem->SetProductReferenceList(intermediateSystemProductList);
    intermediateSystem->CalcSalePrice();
    m_itemList[1] = intermediateSystem;
    
    System* cinematicSystem = new System(m_exchangeRate, m_profitMargin, System::TheatreCategory::CINEMATIC);
    std::vector<Product*> cinematicSystemProductList;
    cinematicSystemProductList.push_back((*m_productList)[12]);
    cinematicSystemProductList.push_back((*m_productList)[14]);
    cinematicSystemProductList.push_back((*m_productList)[16]);
    cinematicSystemProductList.push_back((*m_productList)[17]);
    cinematicSystem->SetProductReferenceList(cinematicSystemProductList);
    cinematicSystem->CalcSalePrice();
    m_itemList[2] = cinematicSystem;
    
    Component* cableComponent = new Component(m_exchangeRate, m_profitMargin);
    cableComponent->SetProductReference((*m_productList)[18]);
    cableComponent->CalcSalePrice();
    m_itemList[3] = cableComponent;
    
    Component* remoteComponent = new Component(m_exchangeRate, m_profitMargin);
    remoteComponent->SetProductReference((*m_productList)[19]);
    remoteComponent->CalcSalePrice();
    m_itemList[4] = remoteComponent;
    
    Component* headphonesComponent = new Component(m_exchangeRate, m_profitMargin);
    headphonesComponent->SetProductReference((*m_productList)[20]);
    headphonesComponent->CalcSalePrice();
    m_itemList[5] = headphonesComponent;
}

void NZBranch::PrintItemList() {
    for (Item* item : m_itemList) {
        item->PrintDetails();
    }
}
