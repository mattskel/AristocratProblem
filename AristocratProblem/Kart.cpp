//
//  Kart.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Kart.hpp"

Kart::Kart() {}
Kart::~Kart() {}

void Kart::AddKartItem(KartItem* kartItem) {
    m_kartItemList.push_back(kartItem);
}

void Kart::AddKartItem(Item* item, int quantity) {
    m_kartItemList.push_back(new KartItem(item, quantity));
}

void Kart::RemoveKartItem(int index) {
    m_kartItemList.erase(m_kartItemList.begin() + index);
}

void Kart::PrintKartItems() {
    std::cout<<"\n////////////////////////////\n// KART_CONTENTS\n//"<<std::endl;
    int index = 0;
    for (KartItem* kartItem : m_kartItemList) {
        std::cout<<"////////////////////////////\n// INDEX: ";
        std::cout<<index<<std::endl;
        std::cout<<"//";
        kartItem->PrintKartItem();
        std::cout<<"//"<<std::endl;
        index++;
    }
}
