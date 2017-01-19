//
//  KartItem.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 18/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Represents an item in a kart
 * Has an item value and a quantity
 */

#ifndef KartItem_hpp
#define KartItem_hpp

#include "Item.hpp"

#include <stdio.h>

class KartItem {
private:
    int m_quantity;
    Item* m_item;
    float m_itemTotal;
public:
    KartItem();
    KartItem(Item* item);
    KartItem(Item* item, int quantity);
    ~KartItem();
    
    int GetQuantity() {return m_quantity;}
    Item* GetItem() {return m_item;}
    float GetItemTotal() {return m_itemTotal;}
    void SetQuantity(int quantity) {m_quantity = quantity;}
    void SetItem(Item* item) {m_item = item;}
    
    void PrintKartItem();
};

#endif /* KartItem_hpp */
