#include "TestSpath.h"

Dijkstra::Dijkstra(){
	
}
//implement Dijkstra's algorithm
void Dijkstra::DijkstraSPaths(graph *G, vertex * S){
	h1 = new heap();
	vertex *temp = G->getRoot();
	while(temp!=NULL){

		temp->setParent(NULL);

		//vertex distance to self is 0
		if(temp == S){
			temp->setDistance(0);
			h1->insert(temp->getDistance(),temp);
		}else{
			//makes distance "infinity"
			temp->setDistance(32767);
			//new node
			h1->insert(temp->getDistance(),temp);
		}
		temp = temp->nextV;
	}
	//not empty
	while(h1->isEmpty() == false){
		vertex *u;
		
		entry *l = h1->removeMin();
		if(l !=NULL){
			u = l->getValue();

		}else{
			//if entry not found exit
			return;
		}
		edge *tempEdgeList = u->edgeList;
		
		while(tempEdgeList!=NULL){

			vertex *z = G->findVertex(tempEdgeList->getSecondVertex());
			int r = u->getDistance() + tempEdgeList->getDistance();
			//distance of second vertex
			if( r < z->getDistance()){
				h1->replaceKey(h1->findEntry(z,z->getDistance()) , r);
				z->setDistance(r);
				z->setParent(u);
			}
			tempEdgeList=tempEdgeList->nextE;
		}
	}
}
//prints out shortest path 
void Dijkstra::printOut(vertex *v){
	vertex *temp = v;
	while(temp->parent!=NULL){

		cout<<temp->getName()<<" ";
		temp= temp->parent;
	}
	cout<<temp->getName()<<" ";
	cout<< v->getDistance()<<endl;
}