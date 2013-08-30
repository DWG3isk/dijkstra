//parse input file 
//main
#include "TestSpath.h"

void print(graph *G1){
	G1->printGraph();
}


int main()
{	
	ifstream inFile;
	string filename;
	string line;
	//new graph
	graph *G1 = new graph();
	Dijkstra *D1 = new Dijkstra();
	//now just parse file run program
	cout<<"enter filename" <<endl;
	cin>>filename;
	
	inFile.open(filename);
	if(inFile.good()){
		while(!inFile.eof()){
			getline(inFile,line);
		
			istringstream iss(line);
		  
			string ver1;
			iss >> ver1;
			   
			if(ver1.compare("findfare")!=0){
				string ver2;
				iss >> ver2;

				int distance;
				iss >> distance;

				if(G1->findVertex(ver1)==NULL)
					G1->addVertex(ver1);
				if(G1->findVertex(ver2)==NULL)
					G1->addVertex(ver2);

				G1->addEdge(ver1,ver2,distance);
			}else{
				print(G1);
				string to;
				iss >> to;
				string from;
				iss >> from;
				D1->DijkstraSPaths(G1,G1->findVertex(from));
				D1->printOut(G1->findVertex(to));

			}
		}
		print(G1);
	}else{
		cout<<"file not found";
	}
	system("pause");
	return 0;
}
