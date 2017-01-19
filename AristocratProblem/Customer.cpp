//
//  Customer.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Customer.hpp"

Customer::Customer() {}

Customer::~Customer() {}

// Responsible for making the payment
bool Customer::MakePayment(Order* order) {
    
    // Set the status of the order to ORDERED
    order->SetStatus(Order::OrderStatus::ORDERED);
    
    // Set the customer on the Order instance
    order->SetCustomer(this);
    
    m_orderList.push_back(order); // So the customer has a copy
    
    return true;
}

void Customer::CheckOrderStatus() {
    for (Order* order : m_orderList) {
        order->PrintStatus();
    }
}
