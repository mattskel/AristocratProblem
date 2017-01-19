//
//  Order.hpp
//  AristocratPractical
//
//  Created by Matthew Skelley on 13/01/2017.
//  Copyright © 2017 Matthew Skelley. All rights reserved.
//

/*
 * Handles order items and status
 * Stores the branch and customer responsible for an order
 * Calculates the sub total, discount and order total
 */

#ifndef Order_hpp
#define Order_hpp

#include "Product.hpp"
#include "Item.hpp"
#include "System.hpp"
#include "Component.hpp"
#include "KartItem.hpp"

#include <stdio.h>
#include <vector>

class Branch;
class Customer;

class Order {
    public:
    enum class OrderStatus {
        AWAITING_PAYMENT,
        ORDERED,
        READY_FOR_DELIVERY,
        DELIVERED
    };
private:
    OrderStatus m_orderStatus;
    float m_subTotal;
    float m_discount;
    float m_orderTotal;
    std::vector<KartItem*> m_kartItemList;
    Customer* m_customer;
    Branch* m_branch;
public:
    Order();
    Order(std::vector<KartItem*> kartItemList);
    ~Order();
    
    void CalcSubTotal();
    void CalcDiscount();
    void CalcOrderTotal();
    
    OrderStatus GetStatus() {return m_orderStatus;}
    float GetSubTotal() {return m_subTotal;}
    Customer* GetCustomer() {return m_customer;}
    Branch* GetBranch() {return m_branch;}
    void SetStatus(OrderStatus status) {m_orderStatus = status;}
    void SetCustomer(Customer* customer) {m_customer = customer;}
    void SetBranch(Branch* branch) {m_branch = branch;}
    float GetOrderTotal() {return m_orderTotal;}
    
    void PrintStatus();
    void PrintOrder();
};

#endif /* Order_hpp */
