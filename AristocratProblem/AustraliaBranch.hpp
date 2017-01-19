//
//  AustraliaBranch.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 16/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Responsible for generating the Items for regional Australia branch
 * Displays the items available to the customer
 * Retrieves items by index
 */

#ifndef AustraliaBranch_hpp
#define AustraliaBranch_hpp

#include "Branch.hpp"
#include "Product.hpp"
#include "Item.hpp"

#include <stdio.h>

class AustraliaBranch : public Branch {
private:
    std::vector<Item*> m_itemList;
public:
    AustraliaBranch();
    ~AustraliaBranch();
    Item* GetItem(int index);
    std::vector<Item*> GetItemList() {return m_itemList;}
    void GenerateItemList();
    void PrintItemList();
};

#endif /* AustraliaBranch_hpp */
