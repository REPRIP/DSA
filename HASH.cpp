#include <iostream>
#include<string>
using namespace std;
//Open Hashing: Linear probing
class HashTable{
public:
    int* table;
    int size = 19;
    int occupied;
    int hashfunc(int key){
        if (key < 0){
            return (-key) % size;
        }
        return key % size;
    }

    int rehash(int index){
        return (index + 1) % size;
    }

    int strhash(string str){
        int n = str.length();
        int index = 0;
        for (int i = 0;i < n;i++){
            index = int(str[i]);
        }
        return index % size;
    }

    HashTable(){
        table = new int[size];
        for(int i = 0; i < size; i++){
            table[i] = 0;
        }
    }

    void insert(int key){
        int index = hashfunc(key);
        while(table[index] != 0){
            index = rehash(index);
        }
        table[index] = key;
        occupied++;
    }

    int search(int key){
        int index = hashfunc(key);
        int FLAG = 0;
        while(table[index] != key){
            index = rehash(index);
        }
        return index;
    }

    void display(){
        for (int i = 0;i < size ; i++){
            cout << "Index:" << i << " Element:" << table[i];
            cout << endl;
        }
    }
    
};

int main(){
    HashTable hash;
    hash.insert(40);
    hash.insert(10);
    hash.insert(20);
    hash.insert(-40);
    hash.display();
    cout << hash.search(10);
}

