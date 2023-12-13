#include <iostream>
#include <vector>
using namespace std;

class HashTable {
private:
    int size;
    vector<vector<int>> hash_table;

    int hashFunction(int key) {
        return key % size;
    }

public:
    HashTable(int table_size) : size(table_size), hash_table(table_size) {}

    void insert(int key) {
        int index = hashFunction(key);
        hash_table[index].push_back(key);
    }

    bool search(int key) {
        int index = hashFunction(key);
        for (int val : hash_table[index]) {
            if (val == key) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    HashTable hash_table(10);

    hash_table.insert(5);
    hash_table.insert(15);
    hash_table.insert(25);

    int search_key = 15;
    if (hash_table.search(search_key)) {
        cout << "Key " << search_key << " found in the hash table." << endl;
    } else {
        cout << "Key " << search_key << " not found in the hash table." << endl;
    }

    search_key = 35;
    if (hash_table.search(search_key)) {
        cout << "Key " << search_key << " found in the hash table." << endl;
    } else {
        cout << "Key " << search_key << " not found in the hash table."
    }

    return 0;
}

