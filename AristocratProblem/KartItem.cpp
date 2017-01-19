//
//  KartItem.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 18/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "KartItem.hpp"

#include <math.h>

KartItem::KartItem() {}

KartItem::KartItem(Item* item) {
    m_item = item;
    m_quantity = 1;
    m_itemTotal = ceilf(m_quantity * m_item->GetSalePrice() * 100) / 100;
}

KartItem::KartItem(Item* item, int quantity) {
    m_item = item;
    m_quantity = quantity;
    m_itemTotal = ceilf(m_quantity * m_item->GetSalePrice() * 100) / 100;
}

KartItem::~KartItem() {}

void KartItem::PrintKartItem() {
    m_item->PrintDetails();
    std::cout<<"//\n// QTY: ";
    std::cout<<m_quantity<<std::endl;
    std::cout<<"// ITEM TOTAL: $";
    std::cout<<ceilf(m_quantity * m_item->GetSalePrice() * 100) / 100<<std::endl;
}
