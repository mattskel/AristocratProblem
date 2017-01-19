//
//  NZBranch.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 16/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Responsible for generating the Items for regional NZ branch
 * Displays the items available to the customer
 * Retrieves items by index
 */

#ifndef NZBranch_hpp
#define NZBranch_hpp

#include "Branch.hpp"
#include "Product.hpp"
#include "Item.hpp"

#include <stdio.h>

class NZBranch : public Branch {
private:
    Item* m_itemList[6];
public:
    NZBranch();
    ~NZBranch();
    Item* GetItem(int index);
    void GenerateItemList();
    void PrintItemList();
};

#endif /* NZBranch_hpp */
