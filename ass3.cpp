/*
There are flight paths between cities. If there is a flight between city A and city B then there is an edge between the cities. 
The cost of the edge can be the time that flight takes to reach city B from A or the amount of fuel used for the journey.
The node can be represented by airport name or name of the city.
Use adjacency list representation of the graph and adjacency matrix representation of the graph.
Justify the storage representation used.
*/

#include<iostream>
using namespace std;
#include<vector>


class Flight{

public : 
	
	string city[10];
	int size = 50;
	
	vector<vector<int>> mat;
	
	void create();
	void display();	
	
		
	



};

int v; // no. of cities

void Flight :: create(){
	
	
	cout << "Enter the no. of cities : ";
	cin >> v;
	
	cout << "Enter the city names : ";
	for(int i=0; i< v; i++){
		
		cin >> city[i];
	
	}
	
	// Initialize adjacency matrix with zeros
    	
    	mat = vector<vector<int>>(v, vector<int>(v, 0));
	
	for(int i=0; i < v; i++){
	
		for(int j = i + 1; j < v; j++){
			
			
				
			cout << "Enter the fuel cost for the flight from  "<< city[i] << " to " << city[j] << " :";
				
			cin >> mat[i][j];
				
			mat[j][i] = mat[i][j];  // to store the same value both way
				
			
		}
	
	
	}
	
}


void Flight :: display(){

	cout << "\nAdjacency Matrix (Fuel Cost Between Cities):\n";
	
	for(int i=0; i<v;i++){
	
		cout << "\t" <<city[i];
	}
	
	cout << endl;
	 
	for(int i=0; i < v; i++){
	
		cout << city[i] << "\t";
		for(int j = 0; j < v; j++){
		
		
			cout << mat[i][j] << " \t ";
		
		}
		
		cout << endl;
	
	}


}
int main(){


	Flight f;
	
	f.create();
	f.display();




	return 0;
}
