// Ref: https://www.geeksforgeeks.org/trie-insert-and-search/

#include<iostream>
#define ALPHABET_SIZE 26
using namespace std;

struct TrieNode{
    TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNode()
{
    TrieNode* new_node = new TrieNode;
    new_node->isEndOfWord = false;

    for(int i=0; i<ALPHABET_SIZE; i++){
        new_node->children[i] = NULL;
    }

    return new_node;
}

void insert(TrieNode* root, string key)
{
    TrieNode* temp_node = root;

    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if(!temp_node->children[index])
            temp_node->children[index] = getNode();
        temp_node = temp_node->children[index];
    }

    temp_node->isEndOfWord = true;
}

bool search(TrieNode* root, string key)
{
    TrieNode* temp_node = root;

    for(int i=0; i<key.length(); i++){
        int index = key[i] - 'a';
        if(!temp_node->children[index])
            return false;
        temp_node = temp_node->children[index];
    }

    return temp_node && temp_node->isEndOfWord;
}

int main()
{
    string keys[] = {"many", "man", "my", "lie", "a"};
    int n = sizeof(keys) / sizeof(keys[0]);

    TrieNode* root = getNode();
    for(int i=0; i<n; i++)
        insert(root, keys[i]);

    if(search(root, "man")) cout << "Yes" << endl;
    else    cout << "No" << endl;

    if(search(root, "lay")) cout << "Yes" << endl;
    else    cout << "No" << endl;

    return 0;
}