//
//  Branch.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Responsible for kart checkout
 * Generates orders from a kart
 * Updates OrderStatus
 */

#ifndef Branch_hpp
#define Branch_hpp

#include "Kart.hpp"
#include "Customer.hpp"
#include "Order.hpp"

#include <stdio.h>
#include <vector>

class Branch {
protected:
    std::vector<Order*> m_orderList;
    std::vector<Product*>* m_productList;
    float m_exchangeRate;
    float m_profitMargin;
public:
    Branch();
    ~Branch();
    Order* Checkout(Kart* kart);
    void SetProductList(std::vector<Product*>* productList) {m_productList = productList;}
    void SetExchangRate(float exchangeRate) {m_exchangeRate = exchangeRate;}
    void SetProfitMargin(float profitMargin) {m_profitMargin = profitMargin;}
    virtual void GenerateItemList() = 0;
    void PrintItemList();
    void PrepareOrders();
    void DeliverOrders();
};

#endif /* Branch_hpp */
