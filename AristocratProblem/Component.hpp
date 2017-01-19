//
//  Component.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 18/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#ifndef Component_hpp
#define Component_hpp

#include "Item.hpp"

#include <stdio.h>

class Component : public Item {
    private:
    Product* m_productReference;
    public:
    Component();
    Component(float exchangeRate);
    Component(float exchangeRate, float profitMargin);
    ~Component();
    void SetProductReference(Product* productReference) {m_productReference = productReference;}
    void CalcSalePrice();
    void PrintDetails();
    void PrintPrice();
};

#endif /* Component_hpp */
