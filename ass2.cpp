#include <iostream>
using namespace std;

class RRS {
public:
    int price, id;
    string name, add, con;
    RRS *left, *right;

    void create();
    void insert(RRS*, RRS*);
    void displayAllRecords(RRS*);
    void displayAc(RRS*);
    void displayNonAc(RRS*);
    void searchByPrice(RRS*, int);
    void modifyRecord(RRS*, int);
}*root = nullptr;

int totalPrice = 0;

void RRS::create() {

    if (root == nullptr) {
        root = new RRS;  
        root->price = 1500;
        root->id = -1;
        root->name = "";
        root->add = "";
        root->con = "";
        root->left = root->right = nullptr;
    }

    int ch;
    do {
        RRS* next = new RRS;
        next->left = next->right = nullptr;

        cout << "Enter passenger details (Name Address ID Contact Price): ";
        cin >> next->name >> next->add >> next->id >> next->con >> next->price;
        totalPrice += next->price;
        
        insert(root, next); 

        cout << "Enter 1 to add another passenger, 0 to stop: ";
        cin >> ch;
    } while (ch != 0);
}

void RRS::insert(RRS* root, RRS* next) {
    if (root == nullptr) return; 

    if (next->price < root->price) {
        if (root->left == nullptr) {
            root->left = next;
        } else {
            insert(root->left, next);
        }
    } else {
        if (root->right == nullptr) {
            root->right = next;
        } else {
            insert(root->right, next);
        }
    }
}


void RRS::displayAllRecords(RRS* root) {
    if (root == nullptr) return;

    displayAllRecords(root->left);
    cout << root->name << "\t" << root->id << "\t" << root->price << "\t" << root->add << "\t" << root->con << endl;
    displayAllRecords(root->right);
}


void RRS::displayAc(RRS* root) {
    if (root == nullptr) return;
    
    displayAc(root->left);
    if (root->price > 1500) {  
        cout << root->name << "\t" << root->id << "\t" << root->price << "\t" << root->add << "\t" << root->con << endl;
    }
    displayAc(root->right);
}



void RRS::displayNonAc(RRS* root) {
    if (root == nullptr) return;

    displayNonAc(root->left);
    if (root->price <= 1500) {  
        cout << root->name << "\t" << root->id << "\t" << root->price << "\t" << root->add << "\t" << root->con << endl;
    }
    displayNonAc(root->right);
}

void RRS::searchByPrice(RRS* root, int price) {
    if (root == nullptr) return;
    
    searchByPrice(root->left, price); 

    if (root->price == price) {  
        cout << root->name << "\t" << root->id << "\t" << root->price << "\t" << root->add << "\t" << root->con << endl;
    }
    
    searchByPrice(root->right, price);
}



void RRS::modifyRecord(RRS* root, int price) {
    if (root == nullptr) return;
    
    modifyRecord(root->left, price);

    if (root->price == price) {
        cout << "Enter new details (name, address, contact): ";
        cin >> root->name >> root->add >> root->con;
    }
    
    modifyRecord(root->right, price);
}






int main() {
    int choice;
    do {
        cout << "\n===== Railway Reservation System =====" << endl;
        cout << "0. Exit\n1. Accept passenger details\n2. Display all records\n3. Display AC passenger list\n4. Display Non-AC passenger list\n5. Display total price\n6. Search passenger by price\n7. Modify record\nEnter choice: ";
        cin >> choice;

        switch (choice) {
        
            case 0:
                return 0;
                
            case 1:
                if (root == nullptr) root = new RRS();
                root->create();
                break;
                
            case 2:
            
                cout << "Name\tID\tPrice\tAddress\tContact" << endl;
                root->displayAllRecords(root);
                break;
                
            case 3:
            
                cout << "AC Passengers:\n";
                cout << "Name\tID\tPrice\tAddress\tContact" << endl;
                root->displayAc(root);
                break;
                
            case 4:
            
                cout << "Non-AC Passengers:\n";
                cout << "Name\tID\tPrice\tAddress\tContact" << endl;
                root->displayNonAc(root);
                break;
                
            case 5:
            
                cout << "Total Price: " << totalPrice << endl;
                break;
                
            case 6 :
           	
            	int pprice;
            	cout << "Enter the price to find passanger : "<<endl;
            	cin >> pprice;
            	cout << "Name\tID\tPrice\tAddress\tContact" << endl;
            	root->searchByPrice(root , pprice);
            	break;
            case 7 : 
            	
            	int p;
            	cout << "Enter the price to find passanger : "<<endl;
            	cin >> p;
            	cout << "Name\tID\tPrice\tAddress\tContact" << endl;
            	root->modifyRecord(root , p);
            	break;
            	
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 0);

    return 0;
}

