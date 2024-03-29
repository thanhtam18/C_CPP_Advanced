/*
    File:   employer.hpp
    Author: Thanh Tam
    Date:   13/2/2024
    Description: This header file declare functions and macro for file employer.cpp
*/
#ifndef _EMPLOYER_H
#define _EMPLOYER_H

#include <table.hpp>
#include <vector>
#include <order.hpp>
#include <stdarg.h>

using namespace std;

typedef enum{
    ORDER,
    CANCEL,
    CHANGE,
    PAYMENT,
}Type;

class Employer{
    private:
        vector<Table> listTable;
        list<Food> listFood;
        int quantity;
        string passWord;
    public:
        Employer(list<Food> dataBase = {}, int quantity = 0, string passWord = "EMPLOYER");

        vector<Table> getListTable();
        list<Food>  getListFood();
        Table getTable(int tableNumber);
        void tableHandle(int tableNumber, Type type, ...);
        void setStatus(int tableNumber, bool status);
};

#endif