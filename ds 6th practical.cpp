/******************************************************************************

problem statement : 


create a student management system software application used to  manage the storage 
and retrieval of student record hash table can be used as a data structure t o efficiently store 
and retrieve student information. 




*******************************************************************************/
#include <iostream>
#include<vector>
using namespace std;
class  student{
    private:
        string name,add;
        int prn;
        int per;
        // vector to store table;
        vector<int>mychain;
        vector<int>mykey;
        
        
 public :
    
            student(){
                prn = -1;
                name = add = "";
                per = 0;
                mychain = vector<int>(10, -2);
                mykey = vector<int>(10, -1);
            }
            void table();
            void accept();
            
            
}H[10];


  void student :: table() {
        cout << "\nPRN\tName\t\tAddress\t\tPercentage\n";
        for (int i = 0; i < 10; i++) {
            if (mykey[i] != -1) {
                cout << i << "\t" << H[i].prn << "\t" << H[i].name
                     << "\t\t" << H[i].add<< "\t\t" << H[i].per << "\n";
            } else {
                cout << i << "\t" << "-\t" << "-\t\t" << "-\t\t" << "-" << "\n";
            }
        }
    }
    
void student :: accept(){
                
        
            int n;
            cout << "Enter the no of records :";
            cin >> n;
                
            
            for(int i = 0; i < n; i++){
                
                student s;   
                cout << "\nEnter PRN: ";
                cin >> s.prn;
                cout << "Enter Name: ";
                cin >> s.name;
                cout << "Enter Address: ";
                cin >> s.add;
                cout << "Enter Percentage: ";
                cin >> s.per;
                
                int loc = s.prn % 10;       // hash function
                
                int originalloc = loc;
                
                while(mykey[loc] != -1){
                    loc = loc % 10 + 1;
                    if(loc == originalloc){
                        cout << "hash table is full..";
                        return;
                    }
                }
                
                mykey[loc] = s.prn;
                H[loc] = s;
            }
    }
                


int main()
{
    
    student s;
   
    s.accept();
    s.table();
    

    return 0;
}