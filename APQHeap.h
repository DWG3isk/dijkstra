

class node{
public:
	node();
	node(int distance, vertex* v);
	~node();
	node* leftChild;
	node* rightChild;
	void replaceKey(entry *e, int key);
	entry* getEntry();
private:
	entry* e;
};
class entry{
public:
	node* parent;
	entry(int key,vertex* value);
	~entry();
	int getKey();
	void setkey(int key);
	vertex* getValue();
	void setValue(vertex* value);
	entry* getEntry();

private:
	//key:
	unsigned int cost;
	// value: 
	vertex* v;
};
class heap{
public:
	int arraySize;
	int arrayIndex;
	node ** arrayHeap;

	heap();
	~heap();
	node* root;
	entry* removeMin();
	void insert(int distance,vertex* v);
	void upheap(int index);
	void downheap();
	bool isEmpty();
	void resizeArray();
	void swap(int a,int b);
	void replaceKey(entry* old,int replacement);
	bool compareVertex(vertex* a, vertex* b);
	bool compareEntry(entry* a, entry* b);
	entry* findEntry(vertex* v,int d);

	int getLeftChild(int i);
	int getLeftChildIndex(int i);
	int getRightChildIndex(int i);
	bool hasLeftChild(int i);
	bool hasRightChild(int i);
	int getRightChild(int i);
	int getParentIndex(int i);
	int getParentVal(int i);
	int getCurr(int i);
	
};