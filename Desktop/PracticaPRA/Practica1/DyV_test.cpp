#include "Practica1.h"
#include <vector>
#include <iostream>

using namespace std;

int main(){
    vector<int> a = {1,23,4,5,3,45,3,4,12,43,3};
    QuickSort(a,0,a.size()- 1);
    int pos1 = BusquedaBinaria(3,a,0,a.size()-1);
    cout << "Posicion 3: " << pos1 << endl;

    vector<double> b = {0.3,1.2,3.2,0.4,0.5,0.8,0.2};
    QuickSort(b,0,b.size()- 1);
    int pos2 = BusquedaBinaria(0.2,b,0,b.size()-1);
    cout << "Posición 0.2: "  << pos2 << endl;
    return 0;
}