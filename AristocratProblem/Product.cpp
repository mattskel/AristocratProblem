
//
//  Product.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Product.hpp"

int Product::productCount = 0;

Product::Product() {
    m_ID = productCount;
    productCount++;
}

Product::Product(float cost, string description) {
    m_ID = productCount;
    productCount++;
    m_cost = cost;
    m_productDescription = description;
}

Product::~Product() {}
