//
//  Customer.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 *
 */

#ifndef Customer_hpp
#define Customer_hpp

#include "Kart.hpp"
#include "Order.hpp"

#include <stdio.h>
#include <iostream>

class Customer {
private:
//    int m_ID;
    Kart* m_kart;
    std::vector<Order*> m_orderList;
public:
    static int customerCount;
    Customer();
    ~Customer();
//    int GetID() {return m_ID;}
    void SetKart(Kart *kart) {m_kart = kart;}
    Kart* GetKart() {return m_kart;}
    bool MakePayment(Order* order);
    void CheckOrderStatus();
};

#endif /* Customer_hpp */
