//
//  Product.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Stores product description and cost
 */

#ifndef Product_hpp
#define Product_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Product {
private:
    float m_cost;
    string m_productDescription;
public:
    Product();
    Product(float cost, string description);
    ~Product();
    float GetCost() {return m_cost;}
    string GetDescription() {return m_productDescription;}
    void SetCost(float cost) {m_cost = cost;}
    void SetDescription(string description) {m_productDescription = description;}
};

#endif /* Product_hpp */
