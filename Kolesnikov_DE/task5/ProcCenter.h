#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
class ProcCenter
{
    private:
        struct Data
        {
            int PayrollN;
            string password;
            string name;
            string surname;
            string middlename;
            int sum;
            bool CrStatus;
            struct CrInfo{
                int day;
                int month;
                int year;
                int MPayment; //month payment
                int RMonths; //remain months
                int Months; //loan period
                int Sum;
                int DMonths; //debt months
            }CrInf;
        };
        Data* PersDt;
        int DataCnt;
        friend class Credit;
        ProcCenter(const ProcCenter& other) = default;
    public:
        ProcCenter(string path = "Data.txt"){Read_From_File(path);}
        ~ProcCenter(){delete [] PersDt;}
        bool Read_From_File(string path = "Data.txt"); 
        bool Write_To_File(string path = "Data_Out.txt");
};
