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
	//	for(int i= 0; i< max; i++){
	//		delete table[i];
	//	}
		delete[] table;
	}
	int capacity(){
		return max;
	}
	friend std::ostream& operator<<(std::ostream &out, const HashTable<V>&th){
		out << "HashTable [Entries: " << th.n << ", Capacity: " << th.max << "]\n";
		for(int i = 0; i < th.max; i++){

			out << "Cubeta : " << i << " \n";
	
			out<<th.table[i]<<std::endl;
		}
	      return out;	
	}
	V operator[](std::string key){
		int pos = table[h(key)].search(key);

		if(pos < 0)
			throw std::runtime_error("Error en la búsqueda");
		
		V valor = table[h(key)].get(pos).value;
		return valor;
	}

	 void insert(std::string key, V value) override{	

		int pos = table[h(key)].search(key);

                if(pos >= 0)
                        throw std::runtime_error("Error al introducir");

		TableEntry<V> aux(key, value);
		table[h(key)].prepend(aux);
		n++;
	}
	 V search(std::string key) override{

		int hash = h(key);
		int pos = table[h(key)].search(key);

                if(pos < 0)
                        throw std::runtime_error("No encontrado");

                V aux = table[hash].get(pos).value;
                return aux;
	}
        V remove(std::string key) override{
		
		int pos = table[h(key)].search(key);

                if(pos > max || pos < 0)
                        throw std::runtime_error("No encontrado");

		V aux = table[h(key)].remove(pos).value;
		n--;
		return aux;
	}

        int entries() override{
		return n;
	}
        
};

#endif
