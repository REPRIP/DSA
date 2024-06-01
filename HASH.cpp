#include <iostream>
#include <string>
using namespace std;
// Open Hashing: Linear probing
class HashTable
{
public:
    int *table;
    int size = 19;
    int occupied;
    float LF;

    int hashfunc(int key)
    {
        if (key < 0)
        {
            return (-key) % size;
        }
        return key % size;
    }

    int rehash(int index)
    {
        return (index + 1) % size; // Linear
    }

    /*
    int rehash(int index, int i){
    return (index + i*i) % size; //Quadratic
    }

    int rehash(int index, int i){
    return (index + i * (7 - (index % 7))) % size; //Double hashing
    }
    */

    int strhash(string str)
    {
        int n = str.length();
        int index = 0;
        for (int i = 0; i < n; i++)
        {
            index += int(str[i]);
        }
        return index % size;
    }

    HashTable()
    {
        occupied = 0;
        table = new int[size];
        for (int i = 0; i < size; i++)
        {
            table[i] = 0;
        }
    }

    void insert(int key)
    {
        int index = hashfunc(key);
        while (table[index] != 0)
        {
            index = rehash(index);
        }
        table[index] = key;
        occupied++;
        calc_load_factor();
        if (LF > 0.5)
        {
            rehash_table();
        }
    }

    bool is_prime(int num)
    {
        if (num <= 1)
        {
            return false;
        }
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                return false;
            }
        }
        return true;
    }

    int next_prime(int num)
    {
        while (!is_prime(++num))
            return num;
    }

    void rehash_table()
    {
        // Code to increase size of table and rehash all elements
        int new_size = next_prime(size * 2); // Find the next prime number
        int *new_table = new int[new_size];  // Create a new table with the new size
        for (int i = 0; i < new_size; i++)
        {
            new_table[i] = 0; // Initialize all elements of the new table to 0
        }

        int data[occupied];
        int j = 0;
        for (int i = 0; i < size; i++) //Saving old data
        {
            if (table[i] != 0)
            {
                data[j++] = table[i];
            }
        }

        size = new_size;   
        delete[] table;   
        table = new_table; 

        for (int i = 0; i < occupied; i++)
        {
            int index = data[i] % size; // Calculate the new index for the element
            while (table[index] != 0)
            {                               // Handle collisions
                index = (index + 1) % size; // Linear probing
            }
            table[index] = data[i]; // Insert the element into the new table
        }
    }

    int search(int key)
    {
        int index = hashfunc(key);
        int FLAG = 0;
        while (table[index] != key)
        {
            index = rehash(index);
        }
        return index;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
        {
            cout << "Index:" << i << " Element:" << table[i];
            cout << endl;
        }
    }

    float load_factor()
    {
        return LF;
    }

    void calc_load_factor()
    {
        LF = float(occupied) / size;
    }
};

int main()
{
    HashTable hash;
    hash.insert(40);
    hash.insert(10);
    hash.insert(20);
    hash.insert(-40);
    hash.display();
    // cout << hash.search(10) << endl;
    cout << hash.load_factor();
}
