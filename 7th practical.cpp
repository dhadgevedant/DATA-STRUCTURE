/*problem statement */

#include<iostream>
#include<vector>
using namespace std;

class student{

    private:

            int prn , per;           // prn and roll number
            string name, add;         // name and address
    public :
            student(){
                prn = per = 0;
                name = add = "-";
            }

            static vector<int> key;
            static vector<int> chain;


            void create();
            void display();
            void modify();
            void search();
            void remove();

}H[10];

// Static member definitions
vector<int> student::key(10, -1);
vector<int> student::chain(10, -1);



void student :: create(){
    int n;
    cout <<  "How many record do you want to insert :";
    cin >> n;

    for(int i=0; i< n ; i++){
        student s;

        cout << "Enter the prn number : ";
        cin >> s.prn;
        cout << "Enter the percentage : ";
        cin >> s.per;
        cout << "Enter the name :";
        cin >> s.name;
        cout << "Enter the address :";
        cin >>s.add;

        int loc = s.prn % 10;

        int origonalloc = loc;
        
        while(key[loc] != -1){
            loc = (loc + 1 ) % 10;
           
            if(loc == origonalloc){
                cout << "Hash table is full.";
                break;
            }
        }

        
        if(origonalloc != loc){
            int temp = origonalloc;
            while (chain[temp] != -1){
                temp = chain[temp];
            }
            chain[temp] = loc;
        }
        

        key[loc] = s.prn;
        H[loc] = s;
    }
}

void student :: search(){
    int prn;
    cout<< "Enter the prn no. to search record :";
    cin >> prn;

    int loc = prn % 10;

   while(key[loc] != prn && loc != -1){
    loc = chain[loc];
   }

   if(loc == -1){
        cout << "Record not found." << endl;
        return;
    }

    cout << "\nloc\tprn\tpercentage\tname\taddress\tchain" << endl;
    cout << loc <<"\t" <<key[loc] << "\t" << H[loc].per << "\t" << H[loc].name << "\t" << H[loc].add << "\t" << chain[loc] << endl;
}

void student ::display() {
    cout << "loc\tprn\tpercentage\tname\taddress\tchain" << endl;

    for(int i = 0; i < 10; i++){
        if(key[i] != -1){
                cout << i <<"\t" <<key[i] << "\t" << H[i].per << "\t" << H[i].name << "\t" << H[i].add << "\t" << chain[i] << endl;
        }else{
            cout << i  << "\t" << key[i] <<"\t-\t-\t-\t"<< chain[i] << endl;
        }
    }
}


void student :: remove() {
    int prn;
    cout << "Enter the prn no. to delete record: ";
    cin >> prn;

    int loc = prn % 10;
    int prevLoc = -1;

    // Search for the record
    while (key[loc] != prn && loc != -1) {
        prevLoc = loc;
        loc = chain[loc];
    }

    if (loc == -1) {
        cout << "Record not found." << endl;
        return;
    }

    // Remove the record
    key[loc] = -1;
    H[loc] = student(); // Reset the student object

    // add all next record to its appropriate index;
    if (prevLoc != -1) {
        H[prevLoc] = H[loc];
    }

   H[prevLoc] = student();

    cout << "Record deleted successfully." << endl;
}

int main() {
    student s;
    int choice;

    do {
        cout << "\nMenu:";
        cout << "\n1. Create Records";
        cout << "\n2. Display Records";
        cout << "\n3. Search Record";
        cout << "\n4. Remove Record";
        cout << "\n5. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                s.create();
                break;
            case 2:
                s.display();
                break;
            case 3:
                s.search();
                break;
            case 4:
                s.remove();
                break;
            case 5:
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
