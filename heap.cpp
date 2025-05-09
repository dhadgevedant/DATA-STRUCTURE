#include<iostream>
#include<vector>
using namespace std;

int n;

class Heap{

    vector <int> key;

    public:
        void accept(){
    
            cout<<"enter number of elements: ";
            cin>>n;
        
            cout<<"Enter keys: ";
            for(int i=0; i<n; i++){
                int data;
                cin>>data;
                key.push_back(data);
                build(i);
            }
        }
        
        // 1 2 3 4 5 
        //      1 
        //   2     3
        // 4   5
        void build(int i){
            
            int parent = i/2;
            int curr = i;
            
            while(curr>0){
                
                if(key[parent] < key[curr]){
                    
                    swap(key[parent],key[curr]);

                    curr = parent;
                    parent = curr/2;
                }
                else{
                    return;
                }
            }
        }
        void insert(){
            cout<<"\n\nenter value to insert: ";
            int data; cin>> data;

            key.push_back(data);
            build(n);
            n++;
        };
        void display(){
            
            cout<<"\n\nHeap: ";
            for(int i=0;i<n;i++){
                cout<<key[i]<<" ";
            }
        }
};


int main(){
    Heap a;

    a.accept();
    a.display();
    a.insert();
    a.display();

}