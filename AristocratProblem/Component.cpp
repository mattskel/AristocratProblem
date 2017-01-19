//
//  Component.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 18/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Component.hpp"

#include <math.h>

Component::Component() : Item() {}
Component::Component(float exchangeRate) : Item(exchangeRate) {}
Component::Component(float exchangeRate, float profitMargin) : Item(exchangeRate, profitMargin) {}
Component::~Component() {}

void Component::CalcSalePrice() {
    m_salePrice = (m_productReference->GetCost() / m_exchangeRate) / (1.0f-m_profitMargin);
}

void Component::PrintDetails() {
    std::cout<<"\n// ";
    std::cout<<m_productReference->GetDescription();
    CalcSalePrice();
    std::cout<<"\n// PRICE: $";
    std::cout<<ceilf(m_salePrice * 100) / 100<<std::endl;
}

void Component::PrintPrice() {
    CalcSalePrice();
    std::cout<<"\n// PRICE: $";
    std::cout<<ceilf(m_salePrice * 100) / 100<<std::endl;
}
