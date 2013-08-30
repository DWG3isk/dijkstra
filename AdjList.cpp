#include "TestSpath.h"
// implement graph using adj list

graph::graph(){
	root = NULL;
	printOnce= false;
}
//finds vertex using name
//preconditon no two vertexs have same name
//post returns vertex
vertex* graph::findVertex(string name){
	vertex* temp = root;
	vertex* location = NULL;

	while(temp != NULL){
		if(name.compare(temp->getName())==0){
			location = temp;
			return location;
		}
		else
			temp = temp->nextV;
	}
	
     return location;
}
// precondion vertex a to vertex b always same distance
//edges to same vertices have same distances
//post returns edge from vertex a to b
// or NULL if not found
edge* graph::findEdge(string a, string b){
	vertex* temp1 = root;
	vertex*temp2 = root;

	while(temp1->nextV!=NULL && temp1->getName().compare(a)!=0){
		temp1=temp1->nextV;
	}
	
	edge* tempE = temp1->edgeList;
	while(tempE->nextE!=NULL){
		if(tempE->getSecondVertex().compare(b))
			return tempE;
		tempE=tempE->nextE;
	}
	return NULL;
	


}
//preconditon 
//post vertex added to end of nextV list
//or root is created
void graph::addVertex(string name){

	vertex* addedVertex = new vertex(name);

	//creating a root vertex to start from
	if(root == NULL){
		root = new vertex(name);
		return;
	}
	
	vertex* temp = root;
	while(temp->nextV != NULL)
		temp = temp->nextV;
	
	temp->nextV = addedVertex;

}
void graph::addEdge(string a, string b, int distance){
	//adds egde a to b
	addEdge2(a,b,distance);
	//adds egde b to a 
	addEdge2(b,a,distance);
	
	
}
//adds both edge forward and back
//a to b and b to a
void graph::addEdge2(string a,string b, int distance){
	vertex* ver1;
	vertex* ver2;

	ver1 = findVertex(a);
	ver2 = findVertex(b);
	
	edge* newEdge = new edge(b, distance);

	//if this is the first edge of the vertex
	if(ver1->edgeList == NULL){
		//its the first element of the list 
		ver1->edgeList = newEdge;
	}
	//otherwise traverse list and add to end
	else{
		edge* temp = ver1->edgeList;
		while(temp->nextE != NULL)
			temp= temp->nextE;

		temp->nextE = newEdge;
	}
	
}
//defaut
vertex::vertex(){
	nextV = NULL;
	edgeList= NULL;
	setParent(NULL);

}
//post sets name rest null
vertex::vertex(string name){
	setName(name);
	nextV = NULL;
	edgeList= NULL;
	setParent(NULL);
}
void vertex::setParent(vertex *v){
	parent=v;
}
void vertex::setName(string name){
	this->name = name;
}
void vertex::setDistance(int distance){
	this->distance = distance;
}
string vertex::getName(){
	return name;
}
int vertex::getDistance(){
	return distance;
}

edge::edge(){

}
//post sets name and second vertex
edge::edge(string b,int distance){
	setDistance(distance);
	setSecondVertex(b);
	nextE = NULL;
}


void edge::setDistance(int distance){
	this->distance = distance;
}
void edge::setSecondVertex(string secondVertex){
	this->secondVertex = secondVertex;
}
int edge::getDistance(){
	return distance;
}
string edge::getSecondVertex(){
	return secondVertex;
}

//prints the graph node then adj nodes and distances 
//for every node
void graph::printGraph(){
     vertex* pTemp = root;
     edge* Temp;
    
	while (pTemp != NULL && printOnce ==false)
     {
          cout << pTemp->getName()<<endl;
          Temp = pTemp->edgeList;
                        
          while (Temp != NULL)
          {
			cout << Temp->getSecondVertex()<< " (" << Temp->getDistance() << ")"<<endl;
			Temp = Temp->nextE;
          }
                        
          cout << endl;
          pTemp = pTemp->nextV;
     }
	printOnce = true;
}
vertex* graph::getRoot(){
	return root;
}
             

