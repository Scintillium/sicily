// Problem#: 1009
// Submission#: 4655829
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
using namespace std;  
const int M = 64;
bool is_primes[M + 1];
std::vector<int> primes;
void getPrimes() {
    for(int i = 0; i < M + 1; i++) {
        is_primes[i] = true;
    };
    is_primes[0] = false;
    is_primes[1] = false;
    for(int i = 2; i < M + 1; i++){
        if(is_primes[i]) {
            for(int j = i * 2; j < M + 1; j += i) {
                is_primes[j] = false;
            }
        }
    }
    for(int i = 0; i < M + 1; i++) {
        if(is_primes[i]) {
            primes.push_back(i);
        }
    }
}
void factor(int prime, std::vector<long long>& pf) {
    // note here base variabel must be long long type
    long long base = 1;
    long long mersenne = (base << prime) - 1;

    long long i;
    for(i = 3; i * i <= mersenne; i += 2) {
        while(mersenne % i == 0) {
            mersenne /= i;
            pf.push_back(i);
        }
    }
    if(mersenne > 1) {
        pf.push_back(mersenne);
    }
}
void printInfo(const std::vector<long long>& pf, long long mersenne, int prime) {
    int size = pf.size();
    for(int i = 0; i < size - 1; i++) {
        std::cout << pf[i] << " * ";
    }
    std::cout << pf[size - 1] << " = ";
    std::cout << mersenne << " = ( 2 ^ " << prime << " ) - 1";
    std::cout << std::endl; 
}
void getMersennes(const int minK) {
    int size = primes.size();
    for(int i = 0; i < size - 1 && primes[i] <= minK; i++) {
        std::vector<long long> pf;
        int prime = primes[i];
        factor(prime, pf);
        if(pf.size() > 1) {
            long long base = 1;
            long long mersenne = (base << prime) - 1;
            printInfo(pf, mersenne, prime);
        }
        pf.clear();
    }
}
int main() {
    int k;
    cin >> k;
    getPrimes();
    getMersennes(k);
    primes.clear();
    return 0;
}                                 
