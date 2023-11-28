#ifndef TABLEENTRY_H
#define TABLEENTRY_H

#include "Dict.h"
#include <string>
#include <ostream>

template <typename V> 
class TableEntry {
    public:
       std::string key;
       V value;       
       TableEntry(std::string key, V value){
	       this->value= value;
	       this->key= key;
       }
       TableEntry(std::string key){
		this->key= key;
       }
       TableEntry(){
		key= "";
       }
       friend bool operator==(const TableEntry<V> &te1, const TableEntry<V> &te2){
		if(te1.key == te2.key){
			return true;
		}
		return false;
       }
       friend bool operator!=(const TableEntry<V> &te1, const TableEntry<V> &te2){
		if(te1.key != te2.key){
                        return true;
                }
                return false;

       }
       friend std::ostream& operator<<(std::ostream &out, const TableEntry<V> &te){
		out<<"Clave: "<<te.key<<" Valor: "<<te.value<< std::endl;
		return out;
       }
	
};

#endif
