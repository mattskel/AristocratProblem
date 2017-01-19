//
//  Order.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Order.hpp"

#include <math.h>

Order::Order() {}

Order::Order(std::vector<KartItem*> kartItemList) {
    m_kartItemList = kartItemList;
    m_orderStatus = OrderStatus::AWAITING_PAYMENT;
}

Order::~Order() {}

void Order::CalcSubTotal() {
    m_subTotal = 0.0f;
    for (KartItem* kartItem : m_kartItemList) {
        m_subTotal += kartItem->GetItemTotal();
    }
}

void Order::CalcDiscount() {
    bool systemFound = false;
    float discountPercent = 0.0f;
    float componentSum = 0.0f;
    
    // Determine if a Home Theatre System Exists;
    for (KartItem* kartItem : m_kartItemList) {
        if (dynamic_cast<System*>(kartItem->GetItem())) {
            systemFound = true;
            break;
        }
    }
    // Count number of additional components
    if (systemFound) {
        
        int componentCount = 0;
        for (KartItem* kartItem : m_kartItemList) {
            if (dynamic_cast<Component*>(kartItem->GetItem())) {
                componentSum += kartItem->GetItemTotal();
                componentCount += kartItem->GetQuantity();
            }
        }
        switch (componentCount) {
            case 0:
            break;
            case 1:
            discountPercent = 0.1f;
            break;
            case 2:
            discountPercent = 0.2f;
            break;
            default:
            discountPercent = 0.3f;
            break;
        }
    }
    
    m_discount = ceilf(discountPercent * componentSum * 100) / 100;
}

void Order::CalcOrderTotal() {
    m_orderTotal = m_subTotal - m_discount;
}

void Order::PrintStatus() {
    std::cout<<"\n// ORDER_STATUS: ";
    switch (m_orderStatus) {
        case OrderStatus::AWAITING_PAYMENT:
        std::cout<<"AWAITING_PAYMENT"<<std::endl;
        break;
        case OrderStatus::ORDERED:
        std::cout<<"ORDERED"<<std::endl;
        break;
        case OrderStatus::READY_FOR_DELIVERY:
        std::cout<<"READY_FOR_DELIVERY"<<std::endl;
        break;
        case OrderStatus::DELIVERED:
        std::cout<<"DELIVERED"<<std::endl;
        break;
        
        default:
        break;
    }
}

void Order::PrintOrder() {
    std::cout<<"\n////////////////////////////\n// ORDER"<<std::endl;
    for (KartItem* kartItem : m_kartItemList) {
        std::cout<<"////////////////////////////";
        kartItem->PrintKartItem();
        std::cout<<"//"<<std::endl;
    }
    std::cout<<"////////////////////////////"<<std::endl;
    std::cout<<"// SUB_TOTAL: $";
    std::cout<<m_subTotal<<std::endl;
    std::cout<<"// DISCOUNT: $";
    std::cout<<m_discount<<std::endl;
    std::cout<<"// ORDER_TOTAL: $";
    std::cout<<m_orderTotal<<std::endl;
    std::cout<<"//"<<std::endl;
}
