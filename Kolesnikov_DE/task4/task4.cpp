#include <iostream>
#define NUMBEROFDATES 50
using namespace std
class Termo
{
    private:
        struct Data
        {
                int day,month,year;
                double *temp;
        };
        int n;
        int inhour;
        struct *mass;
        operator = (const Termo& other);
    public:
        Termo() : n(0)
        {
            mass = new Data [NUMBEROFDATES];
            
        }
        Termo(int _day,int _month,int _year,int _hour) : n(1)
        {
            mass = new Data [NUMBEROFDATES];
            mass[0].day = _day;
            mass[0].month = _month;
            mass[0].year = _year;
            mass[0].hour = new double[24-_hour];
            inhour = _hour;
        }
        void Get_Init(int& _day,int& _month,int& _year,int& _hour)
        {
            _day  = mass[0].day;
            _month  = mass[0].month;
            _year  = mass[0].year;
            _hour = inhour;
        }
        int Set_Init(int _day,int _month,int _year,int _hour) : n(1)
        {
            if(n){return 1}
            mass = new Data [NUMBEROFDATES];
            mass[0].day = _day;
            mass[0].month = _month;
            mass[0].year = _year;
            mass[0].temp = new double[24-_hour];
            inhour = _hour;
            return 0;
        }
        int Set_Obs(int _day,int _month,int _year,int _hour,double _temp)
        {
            if((mode[0].day == _day) && (mode[0].month == _month) && 
                    (mode[0].year == year) && (_hour < inhour)){return -1;}    
            mass[n].temp = new double [24];
            for(int i = 0;i < 24;i++){
                mass[n].temp = -255;
            }
            mass[n].temp[_hour] = _temp;
            mass[n].day = _day;
            mass[n].month = _month;
            mass[n].year = _year;
            n++;
            return 0;
        }
        double Get_Obs(int _day,int _month,int _year,int _hour)
        {
            if(!n){return -1;}
            for(int i = 0;i < n;i++){
              if((mode[i].day == _day) && (mode[i].month == _month) &&
                      (mode[i].year == year) && 
                      (mass[i].temp[_hour - 1] ! = -255){
                      return mass[i].temp;
                      }            
            }
        int Set_Obs_Serial(int _day,int _month,int _year,
            int _shour,int _ehour,double _temp[])
        {
            if((mode[0].day == _day) && (mode[0].month == _month) && 
                    (mode[0].year == year) && (_hour < inhour)){return -1;}    
            mass[n].temp = new double [24];
            for(int i = _shour - 1;i < _ehour;i++){
                mass[n].temp[i] = temp[i + 1 - _shour];
            }
            mass[n].temp[_hour] = _temp;
            mass[n].day = _day;
            mass[n].month = _month;
            mass[n].year = _year;
            n++;
	    }
	    int To_File(string path )
        {
            ofstream fout;
            fout.open(path);
            if(!fout){return -1;}
            for(int i = 0;i < store;i++){
                fout << mass[i].day << ';' << mass[i].month << ';' << mass[i].year << endl;
                 for(int k = 0;k < 24;k++){
                    if(mass[i].temp[k] != -255){
                        fout << k <<';'<< mass[i].temp[k]<<endl;
                    }
                }
                fout << "end" << endl;
            }
            fout.close();
            return 0;
        }
        int From_File(string path)
        {
            string buf;
            ifstream fin;
            fin.open(path);
            string columns[3];
            if(!fin){return -1;}
            else{
                delete [] mass;
                mass = new Date [DEFAULT_HISTROY_SIZE];
                int i = 0;
                int k = 0; //if 0 read new record
                while (getline(fin,buf)){
                    split(buf,';',string);
                    if(string[0]=="end"){
                        k = 0;
                        n++;
                        i++;
                    }
                    if(k!=1){
                        delete [] mass[i].temp;
                        mass[i].temp = new int[24];
                        mass[i].day = columns[0];
                        mass[i].month = columns[1];
                        mass[i].year = columns[2];
                        k = 1;
                    }
                    if (k != 0){
                        mass[i].temp[columns[0]] = columns[1];
                    }
                }
                fin.close();
                len = DEFAULT_DICT_SIZE;
                store = i-1;
                }
            return 0;
        }
        }

        }

};
