//
//  System.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 17/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Stores a list of product references
 * Calculates the sale price based on exchange rate and profit margin
 */

#ifndef System_hpp
#define System_hpp

#include "Item.hpp"

#include <stdio.h>
#include <vector>

class System : public Item {
public:
    enum class TheatreCategory {
        ENTRY,
        INTERMEDIATE,
        CINEMATIC
    };
private:
    vector<Product*> m_productReferenceList;
    TheatreCategory m_theatreCategory;
public:
    System();
    System(float exchangeRate, TheatreCategory category);
    System(float exchangeRate, float profitMargin, TheatreCategory category);
    ~System();
    
    void SetProductReferenceList(vector<Product*> productReferenceList);
    void CalcSalePrice();
    void PrintDetails();
    void PrintPrice();
    void PrintCategory();
};

#endif /* System_hpp */
