//
//  Kart.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

#ifndef Kart_hpp
#define Kart_hpp

#include "Product.hpp"
#include "Item.hpp"
#include "System.hpp"
#include "Component.hpp"
#include "KartItem.hpp"

#include <stdio.h>
#include <vector>
#include <iostream>

class Kart {
    private:
    //    std::vector<Product*> m_productList;
    std::vector<Item*> m_itemList;
    std::vector<KartItem*> m_kartItemList;
    public:
    Kart();
    ~Kart();
    
    //    void AddProduct(Product* product);
    //    void RemoveProduct(Product* product);
    //    std::vector<Product*> GetProductList() {return m_productList;}
    //    void PrintProducts();
    
    void AddItem(Item* item);
    void AddKartItem(KartItem* kartItem);
    void AddKartItem(Item* item, int quantity);
    void RemoveItem(Item* item);
    void RemoveItem(int index);
    void RemoveKartItem(int index);
    std::vector<Item*> GetItemList() {return m_itemList;}
    std::vector<KartItem*> GetKartItemList() {return m_kartItemList;}
    void PrintItems();
    void PrintKartItems();
};

#endif /* Kart_hpp */
