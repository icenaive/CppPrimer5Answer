/*
 * 题目: 
 * 题意: 
 * 类型: 
 * 算法: 
 * Date: 2020-05-17 10:32:57
 * LastEditors: loeije
 * LastEditTime: 2020-05-17 10:36:00
*/
#include "../ch07/ex7_11.h"
#include <fstream>
#include <iostream>
using namespace std;

int main(int argc, char **argv)
{
    ifstream input(argv[1]);
    ofstream output(argv[2], ofstream::app);
    
    Sales_data total;
    if (read(input, total))
    {
        Sales_data trans;
        while (read(input, trans))
        {
            if (total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(output, total) << endl;
                total = trans;
            }
        }
        print(output, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
    }
    
    return 0;
}