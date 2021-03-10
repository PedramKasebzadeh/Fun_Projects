#include <iostream>
#include <iomanip>
#include <cmath>


void Input_Part(double &first,double &last,double &stride,double &tax,bool &Negative_Error)
{
    std::cout<< "INPUT PART\n";
    std::cout<< "==========\n";
    do{
        std::cout << "Enter first price: ";
        std::cin>> first;
        Negative_Error = (first < 0);
        if(Negative_Error){
            std::cout << "ERROR: First price must be at least 0 (zero) SEK" << std::endl;
        }
    } while (Negative_Error);
    std::cout << "Enter last price: ";
    std::cin>> last;
    do{
        std::cout << "Enter stride: ";
        std::cin>> stride;
        Negative_Error = (stride < 0);
        if(Negative_Error){
            std::cout << "ERROR: Stride must be at least 0.01" << std::endl;
        }
    } while (Negative_Error);
    std::cout << "Enter tax percent: ";
    std::cin>> tax;
}
void Ttable(double &first,double &last,double &stride,double &tax)
{
    tax = tax/100.00;
    std::cout<< "TAX TABLE\n";
    std::cout<< "=========\n";
    std::cout << "\t Price \t\t Tax \t\t Price with tax"<<std::endl;
    std::cout << "-------------------------------------------------------"<<std::endl;
    std::cout << "\t" << std::setprecision(2)<< std::fixed<<first<< "\t\t" << tax*first << "\t\t\t" << (tax*first) + first <<std::endl;
    std::cout << "\t" << std::setprecision(2)<< std::fixed<<first+stride<< "\t\t" << tax*(first+stride) << "\t\t\t" << (tax*(first+stride)) + (first+stride) <<std::endl;
    std::cout << "\t" << std::setprecision(2)<< std::fixed<<(first+(stride*2))<< "\t\t" << tax*(first+(stride*2)) << "\t\t\t" << (tax*(first+(stride*2))) + (first+(stride*2)) <<std::endl;
    std::cout << "\t" << "."<< "\t\t" << "." << "\t\t\t" << "." <<std::endl;
    std::cout << "\t" << "."<< "\t\t" << "." << "\t\t\t" << "." <<std::endl;
    std::cout << "\t" << std::setprecision(2)<< std::fixed<<last<< "\t\t" << tax*last << "\t\t\t" << (tax*last) + last <<std::endl;
}
void fix_interval(double &first,double &last,double &stride)
{
    double roundup;
    roundup = floor((last - first) / stride);
    last = roundup*stride+first;
}

int main()
{
    double first;
    double last;
    double stride;
    double tax;
    bool Negative_Error; 

    Input_Part(first,last,stride,tax,Negative_Error);
    fix_interval(first,last,stride);
    //std::cout << first << std::endl << last << std::endl << stride <<std::endl << tax << std::endl;
    Ttable(first,last,stride,tax);
    std::cout << last; 
    return 0; 
}