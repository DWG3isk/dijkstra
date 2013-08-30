#include "TestSpath.h"

heap::heap(){
	arraySize = 100;
	arrayHeap = new node*[arraySize];
	arrayIndex = 0;
}
//adds a node
void heap::insert(int distance,vertex* v){
	node *addedNode = new node(distance,v);
	int index = arrayIndex;
	
	arrayHeap[arrayIndex] = addedNode;
	arrayIndex++;
	//if array needs resizing
	if(arrayIndex>arraySize)
		resizeArray();

	upheap(index);

}
//removes min from heap
//returns entry
entry* heap::removeMin(){
	entry *min;
	
	arrayIndex--;
	if(arrayIndex>=0){
		min = arrayHeap[0]->getEntry();
		arrayHeap[0] = arrayHeap[arrayIndex];


		int index = 0;

		//while the nodes have children
		while(hasLeftChild(index) || hasRightChild(index)){
			//minimum value
			int min = getCurr(index);
			
			//if left child exists
			if(hasLeftChild(index)){
				//gets min
				if(min >  getLeftChild(index))
					min = getLeftChild(index);
			}
			//if right exists
			if(hasRightChild(index)){
				//gets min
				if(min > getRightChild(index))
					min = getRightChild(index);
			}
			
			//if left exists and is the min
			if(hasLeftChild(index) && min == getLeftChild(index)){
				//swap parent and left
				swap(index, getLeftChildIndex(index));
				index = getLeftChildIndex(index);
			}
			//if right exists and is the min
			else if(hasRightChild(index) && min == getRightChild(index)){
				//swap parent and right
				swap(index, getRightChildIndex(index));
				index = getRightChildIndex(index);
			}
			else{
				break;
			}
		}
		return min;
	}
	arrayIndex++;
	return NULL;
}
//compares two entrys returns true if equal
bool heap::compareEntry(entry* a, entry* b){
	if( a!=NULL && b!=NULL && a->getKey() == b->getKey() && compareVertex(a->getValue(),b->getValue()) == true)
		return true;
	else 
		return false;
}
//compares two vertices returns true if equal
bool heap::compareVertex(vertex* a, vertex* b){
	if(a->getName().compare(b->getName())==0){
		return true;
	}
	else 
		return false;
}
//finds and returns a entry
entry* heap::findEntry(vertex *v, int d){
	int up = 0;
	for(int i = 0; i < arrayIndex; i++){
		if(arrayHeap[i]!=NULL && compareVertex(v, arrayHeap[i]->getEntry()->getValue())  == true && arrayHeap[i]->getEntry()->getKey() == d){
			up = i;
			return  arrayHeap[i]->getEntry();
		}
	}
	upheap(up);
	return NULL;
}
//pre only replace keys with lesser values
//post replaces key ie distance of entry in heap and upheaps
void heap::replaceKey(entry* old,int replacement){
	int up = 0;
	for(int i = 0; i< arrayIndex; i++){
		if(compareEntry(arrayHeap[i]->getEntry(),old) == true){
			arrayHeap[i]->replaceKey(old,replacement);
			up =i;
		}
	}
	
	upheap(up);
}
//swaps two nodes
void heap::swap(int a,int b){
	node* tmp = arrayHeap[a];
	arrayHeap[a] = arrayHeap[b];
	arrayHeap[b] = tmp;

}
//ensures heap remains ordered
void heap::upheap(int index){
	while( getParentIndex(index) >= 0 && (getCurr(index) < getParentVal(index))){
		swap(index, getParentIndex(index));
		index = getParentIndex(index);
	}
}
//returns true if heap is empty
bool heap::isEmpty(){
	root = arrayHeap[0];
	return root == NULL;
}

void heap::resizeArray(){
	arraySize = arraySize*2;
	node ** temp;
	temp = new node*[arraySize];
	for(int i = 0; i <= arrayIndex;i++){
		temp[i] = arrayHeap[i];
	}
	arrayHeap = temp;
}

//helper functions may need to change 
int heap::getLeftChild(int i){
	return arrayHeap[getLeftChildIndex(i)]->getEntry()->getKey();
}
	
int heap::getLeftChildIndex(int i){
	return 2*i+1;
}
	
int heap::getRightChildIndex(int i){
	return 2*i+2;
}
	
bool heap::hasLeftChild(int i){
	return getLeftChildIndex(i) < arrayIndex;
}
	
bool heap::hasRightChild(int i){
	return getRightChildIndex(i) < arrayIndex;
}

int heap::getRightChild(int i){
	return arrayHeap[getRightChildIndex(i)]->getEntry()->getKey();
}

int heap::getParentIndex(int i){
	return (int)((i-1)/2);
}

int heap::getParentVal(int i){
	return arrayHeap[getParentIndex(i)]->getEntry()->getKey();
}

int heap::getCurr(int i){
	return arrayHeap[i]->getEntry()->getKey();
}

node::node(){
	e=NULL;
	leftChild = NULL;
	rightChild = NULL;
}
node::node(int distance, vertex* v){
	e = new entry(distance,v);
	leftChild = NULL;
	rightChild = NULL;
	e->parent = this;
}
node::~node(){
	e->parent = NULL;
	delete e;
}
void node::replaceKey(entry* e,int k){
	e->setkey(k);
}
entry* node::getEntry(){
	return e;
	

}
entry::entry(int key, vertex* value){
	setkey(key);
	setValue(value);

}
entry::~entry(){

}
void entry::setkey(int key){
	cost = key;
}
void entry::setValue(vertex* value){
	this->v = value;
}
int entry::getKey(){
	return cost;
}
vertex* entry::getValue(){
	return v;
}

