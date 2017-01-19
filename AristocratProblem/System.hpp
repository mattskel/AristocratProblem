//
//  System.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 17/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

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
    //    void AddProductReference(Product* productReference);
    void CalcSalePrice();
    void PrintDetails();
    void PrintPrice();
    void PrintCategory();
};

#endif /* System_hpp */
