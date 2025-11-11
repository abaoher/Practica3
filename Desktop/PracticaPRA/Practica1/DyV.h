#include<vector>
#include<iostream>
template <typename T>
int BusquedaBinaria(T X, std::vector<T>& v, int ini, int fin){
        if(ini > fin) return -1;
        int medio = (ini+fin)/2;
        if(v[medio] == X) return medio;
        else if (v[medio] > X){
                return BusquedaBinaria(X,v,ini, medio - 1);
        }
        else{                                        
                return BusquedaBinaria(X,v,medio + 1, fin);
        }
}
template <typename T>                                
    int Partition(std::vector<T>& v, int ini, int fin){
        T x = v[fin];
        int i = ini;
        for(int j = ini; j < fin; j++){
                if(v[j] <= x){
                        int aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                        i +=1;
                }
        }
        int aux = v[i];
        v[i] = v[fin];
        v[fin] = aux;
        return i;
} 
template <typename T>                   
void QuickSort(std::vector<T>& v, int ini, int fin){
        if(ini<fin){
                int pivot = Partition(v, ini, fin);
                QuickSort(v, ini, pivot - 1);
                QuickSort(v, pivot + 1, fin);
        }
}                           
