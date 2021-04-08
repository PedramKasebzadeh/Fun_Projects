# include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

class SumOfDivided
{
public:
    static vector<int> primeFactors(int n){
        n = abs(n);
        vector<int> primes;
        for (int i = 2; i <= sqrt(n);i++){
            if (n % i == 0){
                primes.push_back(i);
                while(n%i==0){
                n = n/i;
                }
            }
        }
        if (n > 2)
            primes.push_back(n);
            return primes;
    }

    // Flatten the 2D vector 
    template<typename T>
    static std::vector<T> flatten(const std::vector<std::vector<T>> &orig)
    {   
        std::vector<T> ret;
        for(const auto &v: orig)
            ret.insert(ret.end(), v.begin(), v.end());                                                                                         
        return ret;
    }   

    static std::string sumOfDivided(std::vector<int> &lst){
        vector<vector<int>> mat;
        for (int i= 0; i <lst.size();i++){
        vector<int> temp = primeFactors(lst[i]);
        vector<int> v;
            for(int j=0; j< temp.size(); j++ ){
                v.push_back(temp[j]);
            }
        mat.push_back(v);
    }
        vector <int> primes = SumOfDivided::flatten(mat);
        sort( primes.begin(), primes.end() );
        primes.erase( unique( primes.begin(), primes.end() ), primes.end() );
        map<int,int> mymap; 
        std::string s;
        for (int i =0; i<mat.size();i++) {
            int count=0;
            for (int val: mat[i]) {
                if (find(primes.begin(), primes.end(),val)!=primes.end()){
                    mymap[val] += lst[i];
                }
            }
        }
        for (auto t:mymap){
        s += "(" + to_string(t.first)+" "+ to_string(t.second)  + ")";
    }
    return s;
    };

};


// for pritntig! not for submition
template<class T>
void printVector(vector<vector<T>> const &mat) {
    for (vector<T> row: mat) {
        for (T val: row) {
            cout << val << " ";
        }
        cout << '\n';
    }
}


void print(std::vector<int> const &input){
    for (int i = 0; i < input.size(); i++) {
        std::cout << input.at(i) << ' ';
    }
}

// for runing code here 
int main()
{
    vector<int> test;
    test.push_back(15);
    test.push_back(12);
    cout << SumOfDivided::sumOfDivided(test)<< endl;
	return 0;
}


