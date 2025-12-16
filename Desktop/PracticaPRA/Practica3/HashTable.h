#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../ExamenPRA/ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

template <typename V>
class HashTable: public Dict<V>{

    private:
	    int n;
	    int max;

	    ListLinked<TableEntry<V>>* table;
		
	    int h(std::string key){	
		int sum = 0;
    		for(int i = 0; i < (int)key.size(); i++){
			sum += int(key.at(i));
		}
		return sum % max;
	    }		

    public:
	    HashTable(int size){
		    max = size;
		    n = 0;
		    table = new ListLinked<TableEntry<V>>[max];

	    }
	    ~HashTable(){
		    delete[] table;
	    }

	    int entries() override{
		    return n;
	    }

	    int capacity(){
		    return max;
	    }

	    void insert(std::string key, V value) override{
		    int idx = h(key);

		    for(int i = 0; i < table[idx].size();i++){
			    if(table[idx].get(i).key == key){
				    throw std::runtime_error("Key '" + key + " ' ya existe");
			    }
		    }
		    table[idx].insert(0, TableEntry<V>(key, value));
		    n++;
	    }

	    V search(std::string key) override {
		    int idx = h(key);

		    for (int i = 0; i < table[idx].size(); i++){
			    if(table[idx].get(i).key == key){
				    return table[idx].get(i).value;
			    }
		    }
		    throw std::runtime_error("Key '" + key + "'no encontrada");
	    }

	    V remove(std::string key) override{
		    int idx = h(key);

		    for(int i = 0; i < table[idx].size();i++){
			    if(table[idx].get(i).key == key){
			    	V val = table[idx].get(i).value;
			    	table[idx].remove(i);
			    	n--;
			    	return val;
			    }
		    }
		    throw std::runtime_error("Key ' " + key + " ' no encontrada ");
	    }

	    V operator[](std::string key){
		    return search(key);
	    }



	    friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
	    out << "HashTable[entries: " << th.n 
		<< ", capacity: " << th.max << "]\n";
	    out << "==============\n\n";

	    for(int i = 0; i < th.max; i++){
		    out << "== Cubeta " << i << " ==\n\n";
		    out << th.table[i] << "\n";
	    }

	    out << "=============\n";
	    return out;
	    }
        
};

#endif
