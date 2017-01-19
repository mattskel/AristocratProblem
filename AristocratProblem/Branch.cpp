//
//  Branch.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Branch.hpp"

Branch::Branch() {}
Branch::~Branch() {}

Order* Branch::Checkout(Kart* kart) {
    
    // Remove the items from the Kart
    std::vector<KartItem*> kartItemList = kart->GetKartItemList();
    
    // Create an order from the itemList
    Order* order = new Order(kart->GetKartItemList());
    order->CalcSubTotal();
    order->CalcDiscount();
    order->CalcOrderTotal();
    
    // Set the Branch instance
    order->SetBranch(this);
    
    // Place order on list
    m_orderList.push_back(order);
    
    // Return the order
    return order;
}

// Updates OrderStatus
// ORDERED to READY_FOR_DELIVERY
void Branch::PrepareOrders() {
    for (Order* order : m_orderList) {
        if (order->GetStatus() == Order::OrderStatus::ORDERED) {
            order->SetStatus(Order::OrderStatus::READY_FOR_DELIVERY);
        }
    }
}

// Updates OrderStatus
// READY_FOR_DELIVERY to DELIVERED
void Branch::DeliverOrders() {
    for (Order* order : m_orderList) {
        if (order->GetStatus() == Order::OrderStatus::READY_FOR_DELIVERY) {
            order->SetStatus(Order::OrderStatus::DELIVERED);
        }
    }
}
