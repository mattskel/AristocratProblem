//
//  System.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 17/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "System.hpp"

#include <math.h>

System::System() : Item() {}
System::System(float exchangeRate, TheatreCategory category) : Item(exchangeRate) {
    m_theatreCategory = category;
}
System::System(float exchangeRate, float profitMargin, TheatreCategory category) : Item(exchangeRate, profitMargin) {
    m_theatreCategory = category;
}
System::~System() {}

void System::SetProductReferenceList(vector<Product*> productReferenceList) {
    m_productReferenceList = productReferenceList;
}
void System::CalcSalePrice() {
    m_salePrice = 0.0f;
    for (Product* reference : m_productReferenceList) {
        m_salePrice += (reference->GetCost() / m_exchangeRate) / (1.0f-m_profitMargin);
    }
}

void System::PrintDetails() {
    std::cout<<"\n// Home Theatre System: ";
    PrintCategory();
    for (Product* reference : m_productReferenceList) {
        std::cout<<"// ";
        std::cout<<reference->GetDescription() + "\t$";
        std::cout<<ceilf(reference->GetCost() / m_exchangeRate * 100) / 100<<std::endl;
    }
    CalcSalePrice();
    std::cout<<"// PRICE: $";
    std::cout<<m_salePrice<<std::endl;
}

void System::PrintPrice() {
    CalcSalePrice();
    std::cout<<"// TOTAL: $";
    std::cout<<m_salePrice<<std::endl;
}

void System::PrintCategory() {
    switch (m_theatreCategory) {
        case TheatreCategory::ENTRY:
        std::cout<<"ENTRY"<<std::endl;
        break;
        case TheatreCategory::INTERMEDIATE:
        std::cout<<"INTERMEDIATE"<<std::endl;
        break;
        case TheatreCategory::CINEMATIC:
        std::cout<<"CINEMATIC"<<std::endl;
        break;
        
        default:
        break;
    }
}
