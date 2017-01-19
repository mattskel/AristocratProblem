//
//  Kart.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Responsible for storing KartItem instances
 * Displays current KartItems
 */

#ifndef Kart_hpp
#define Kart_hpp

#include "Product.hpp"
#include "System.hpp"
#include "Component.hpp"
#include "KartItem.hpp"

#include <stdio.h>
#include <vector>
#include <iostream>

class Kart {
private:
    std::vector<KartItem*> m_kartItemList;
public:
    Kart();
    ~Kart();
    
    void AddKartItem(KartItem* kartItem);
    void AddKartItem(Item* item, int quantity);
    void RemoveItem(int index);
    void RemoveKartItem(int index);
    
    std::vector<KartItem*> GetKartItemList() {return m_kartItemList;}
    
    void PrintKartItems();
};

#endif /* Kart_hpp */
