//
//  Product.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#ifndef Product_hpp
#define Product_hpp

#include <stdio.h>
#include <string>

using namespace std;

class Product {
    private:
    int m_ID;
    float m_cost;
    string m_productDescription;
    public:
    static int productCount;
    Product();
    Product(float cost, string description);
    ~Product();
    int GetID() {return m_ID;}
    float GetCost() {return m_cost;}
    string GetDescription() {return m_productDescription;}
    void SetCost(float cost) {m_cost = cost;}
    void SetDescription(string description) {m_productDescription = description;}
};

#endif /* Product_hpp */
