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

//void Kart::AddProduct(Product* product) {
//    int index = 0;
//    for (Item* item : m_itemList) {
//        if (item->GetProductReference() == product) {
//            break;
//        } else {
//            index++;
//        }
//    }
//    if (index < m_itemList.size()) {
//        m_itemList[index]->AddUnit();
//    }
//    else {
//    }
//}

//void Kart::RemoveProduct(Product *product) {
//}

//void Kart::PrintProducts() {
//    for (Product* product : m_productList) {
//        std::cout<<product->GetDescription()<<std::endl;
//    }
//}

void Kart::AddItem(Item* item) {
    m_itemList.push_back(item);
}

void Kart::AddKartItem(KartItem* kartItem) {
    m_kartItemList.push_back(kartItem);
}

void Kart::AddKartItem(Item* item, int quantity) {
    m_kartItemList.push_back(new KartItem(item, quantity));
}

void Kart::RemoveItem(Item* item) {
    m_itemList.erase(std::remove(m_itemList.begin(), m_itemList.end(), item), m_itemList.end());
}

void Kart::RemoveItem(int index) {
    m_itemList.erase(m_itemList.begin() + index);
}

void Kart::RemoveKartItem(int index) {
    m_kartItemList.erase(m_kartItemList.begin() + index);
}

void Kart::PrintItems() {
    std::cout<<"\n////////////////////////////\n// KART_CONTENTS"<<std::endl;
    int index = 0;
    for (Item* item : m_itemList) {
        std::cout<<"// INDEX: ";
        std::cout<<index<<std::endl;
        if (System* system = dynamic_cast<System*>(item)) {
            system->PrintDetails();
        }
        else {
            item->PrintDetails();
        }
        index++;
    }
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
