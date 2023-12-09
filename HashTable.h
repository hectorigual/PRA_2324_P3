#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "ListLinked.h"  // ¡¡¡¡MODIFICAR!!!!

template <typename V>
class HashTable: public Dict<V> {

    private:
        int n;
	int max;
	ListLinked<TableEntry<V>>* table;
	int h(std::string key){
		int suma= 0;
		for(int i=0; key.length(); i++){
			char c= key.at(i);
			int s= static_cast<int>(c);
			suma += s;
		}
		int posicion= suma % max;
		return posicion;
	}
    public:
        HashTable(int size){
		n= 0;
		max= size;
		table = new ListLinked<TableEntry<V>>[max];
	}
	~HashTable(){
		delete[] table;
	}
	int capacity(){
		return max;
	}
	friend std::ostream& operator<<(std::ostream &out, const HashTable<V>&th){
		out<<th.n<<" "<<th.table<<std::endl;
	      return out;	
	}
	V operator[](std::string key){
		V valor= table[h(key)].search(key);
		if(valor != ""){
		return valor;
		}else{
			throw std::runtime_error("error");
		}
	}
        
};

#endif
