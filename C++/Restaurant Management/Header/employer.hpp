
#ifndef _EMPLOYER_H
#define _EMPLOYER_H

#include <table.hpp>
#include <vector>

using namespace std;

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
        Table getTable(int id);
};

#endif