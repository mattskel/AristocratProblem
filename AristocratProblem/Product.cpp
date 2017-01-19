
//
//  Product.cpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#include "Product.hpp"

Product::Product() {}

Product::Product(float cost, string description) {
    m_cost = cost;
    m_productDescription = description;
}

Product::~Product() {}
