//
//  Item.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 16/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Item.hpp"
#include <math.h>

Item::Item() {
    m_exchangeRate = 1.0f;
    m_profitMargin = 0.0f;
}

Item::Item(float exchangeRate) {
    m_exchangeRate = exchangeRate;
    m_profitMargin = 0.0f;
}

Item::Item(float exchangeRate, float profitMargin) {
    m_exchangeRate = exchangeRate;
    m_profitMargin = profitMargin;
}

Item::~Item() {}

void Item::CalcSalePrice() {}

void Item::PrintDetails() {}

void Item::PrintPrice() {}
