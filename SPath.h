class Dijkstra{
public:
	Dijkstra();
	heap *h1;
	void DijkstraSPaths(graph *G, vertex * S);
	void printOut(vertex *v);
};