#include<iostream>
#include<vector>
#include<climits>
using namespace std;


class OBST{
    public :
             
        vector<string> product;
        vector<int> p;
        vector<int> q;
        vector<vector<int>> w , c , r;
     
        void accept(); 
        void create_obst();
        void display();
};

void OBST :: accept(){
    int n;
    cout <<"Enter the no. of items :";
    cin >> n;

    product.resize(n);
    p.resize(n);
    q.resize(n+1);

    cout << "Enter the items : ";
    for(int i =0;i <n; i++){
        cin >> product[i];
    }

    cout << " Enter the p probability";
    for(int i =0;i <n;i++){
        cin >> p[i];
    }

    cout << " Enter the q probability";
    for(int i = 0;i <= n;i++){
        cin >> q[i];
    }     
}


void OBST:: create_obst(){

    int n = product.size();

    w.resize(n+1 , vector<int>(n+1));
    c.resize(n+1 , vector<int>(n+1));
    r.resize(n+1 , vector<int>(n+1));


    for (int i = 0; i <= n; i++) {
        w[i][i] = q[i];
        c[i][i] = 0;
        r[i][i] = 0;
    }

    
    for (int l = 1; l <= n; l++) { // l = length of subtree
        for (int i = 0; i <= n - l; i++) {
            int j = i + l;
            w[i][j] = w[i][j - 1] + p[j - 1] + q[j];

            c[i][j] = INT_MAX;  
            for (int k = i + 1; k <= j; k++) {
                int cost = c[i][k - 1] + c[k][j] + w[i][j];
                if (cost < c[i][j]) {
                    c[i][j] = cost;
                    r[i][j] = k;
                }
            }
        }
    }
}
void OBST::display() {
    int n = product.size();
    cout << "\nCost Matrix:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << c[i][j] << "\t";
        }
        cout << endl;
    }

    cout << "\nRoot Matrix:\n";
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            cout << r[i][j] << "\t";
        }
        cout << endl;
    }
}


int main(){

    OBST s;
    s.accept();
    s.create_obst();
    s.display();
    
}
