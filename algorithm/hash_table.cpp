#include<iostream>
using namespace std;

struct Node{
    int val;
    Node* next;
    Node(): val(0), next(NULL) {}
    Node(int x): val(x), next(NULL) {}
};

class Hash
{
public:
    Hash(int V){
        this->BUCKET = V;
        table = new Node*[BUCKET];
        for(int i=0; i<BUCKET; i++)
            table[i] = NULL;
    }

    void insertItem(int key){
        int index = hashFunction(key);

        Node* new_node = new Node();
        new_node->val = key;
        new_node->next = table[index];
        table[index] = new_node;
    }

    void deleteItem(int key){
        int index = hashFunction(key);

        Node* prev_node = NULL;
        Node* temp_node = table[index];
        while(temp_node){
            if(temp_node->val == key)   break;
            prev_node = temp_node;
            temp_node = temp_node->next;
        }

        if(temp_node){
            if(prev_node == NULL)
                table[index] = temp_node->next;
            else
                prev_node->next = temp_node->next;
        }
    }

    int hashFunction(int key){
        return key % BUCKET;
    }

    void displayHash(){
        Node* temp_node;
        for(int i=0; i<BUCKET; i++){
            cout << i;
            temp_node = table[i];
            while(temp_node){
                cout << " --> " << temp_node->val;
                temp_node = temp_node->next;
            }
            cout << endl;
        }
    }

private:
    int BUCKET;
    Node** table;
};

int main()
{
    int a[] = {15, 11, 27, 8, 12};
    int n = sizeof(a) / sizeof(a[0]);

    Hash h(7);

    for(int i=0; i<n; i++){
        h.insertItem(a[i]);
    }

    h.displayHash();
    h.deleteItem(15);
    cout << endl;
    h.displayHash();
}
