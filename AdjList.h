//required libaries 
#include <iostream>
#include <string>
using namespace std;



//graph class
//graphs are collection of vertexs connected by edges
class graph{
private:
	//a starting point to add and search from
	vertex *root;
	
public:
	graph();
	//looks to see if vertex allready exists
	//and finds vertex to append edge to
	vertex* findVertex(string name);
	edge* findEdge(string a, string b);

	//adds vertex
	void addVertex(string name);
	//adds edge from a to b
	void addEdge(string a, string b, int distance);
	void addEdge2(string a, string b, int distance);

	bool isEmpty();

	//for testing 
	void printGraph();
	bool printOnce;
	vertex* getRoot();
};
//vertex class
//contains name of airports

class vertex{
public:
	void setParent(vertex* v);
	vertex* parent;
	vertex();
	vertex(string name);
	vertex* nextV;
	void setName(string name);
	string getName();
	edge* edgeList;
	//for shortest path holds distance to 1st vertex
	int getDistance();
	void setDistance(int distance);
	//get entry associated to vertex
	entry* getEntry();
private:
	string name;
	int distance;
};
//edge class
//flight routes contains distance between airports
class edge{
public:
	edge();
	edge(string b,int distance);

	edge* nextE;
	void setDistance(int distance);
	int getDistance();

	void setSecondVertex(string secondVertex);
	string getSecondVertex();
	bool marked;
private:
	int distance;
	string secondVertex;
};

