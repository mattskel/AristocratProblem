//
//  Customer.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Responsible making payment of order
 * Stores a kart pointer
 */

#ifndef Customer_hpp
#define Customer_hpp

#include "Kart.hpp"
#include "Order.hpp"

#include <stdio.h>
#include <iostream>

class Customer {
private:
    Kart* m_kart;
    std::vector<Order*> m_orderList;
public:
    static int customerCount;
    Customer();
    ~Customer();
    void SetKart(Kart *kart) {m_kart = kart;}
    Kart* GetKart() {return m_kart;}
    bool MakePayment(Order* order);
    void CheckOrderStatus();
};

#endif /* Customer_hpp */
