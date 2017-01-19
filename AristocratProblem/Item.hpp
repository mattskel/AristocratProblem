//
//  Item.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 16/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Stores profit margin, exchange rate information and sale price
 * Calculates the sale price
 */

#ifndef Item_hpp
#define Item_hpp

#include "Product.hpp"

#include <stdio.h>
#include <iostream>

class Item {
protected:
    float m_profitMargin;
    float m_exchangeRate;
    float m_salePrice;
public:
    Item();
    Item(float exchangeRate);
    Item(float exchangeRate, float profitMargin);
    virtual ~Item();
    
    void SetExchangeRate(float exchangeRate) {m_exchangeRate = exchangeRate;}
    void SetProfitMargin(float profitMargin) {m_profitMargin = profitMargin;}
    float GetSalePrice() {return m_salePrice;}
    float GetProfitMargin() {return m_profitMargin;}
    
    virtual void CalcSalePrice() = 0;
    virtual void PrintDetails();
    virtual void PrintPrice();
};

#endif /* Item_hpp */
