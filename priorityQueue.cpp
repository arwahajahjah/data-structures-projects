#include<iostream>
using namespace std;

const int graph_size = 8;
const int stack_size = 10;
struct stack
{
    int top;
    int data[stack_size];
};
void addEdge(int*, int, int, int);
int getEdge(int*, int, int);
void push(stack&, int);
int pop(stack&);
int isEmpty(stack&);
void dfs(int*, int, int);

#define A	0
#define B	1
#define C	2
#define D	3
#define E	4
#define F	5
#define G	6
#define H	7
main()
{
    int* g = new int[graph_size * graph_size];
    for (int i = 0; i < graph_size * graph_size; i++)
        g[i] = 0;
    addEdge(g, A, B, 1);
    addEdge(g, A, C, 1);
    addEdge(g, B, D, 1);
    addEdge(g, C, E, 1);
    addEdge(g, C, F, 1);
    addEdge(g, D, G, 1);
    addEdge(g, D, H, 1);
    dfs(g, A, C);
}

void addEdge(int* g, int from, int to, int value)
{
    *(g + from * graph_size + to) = value;
}

int getEdge(int* g, int from, int to)
{
    return (*(g + from * graph_size + to));
}

void dfs(int* g, int root, int goal)
{
    int node, to;
    stack s;
    s.top = -1;
    push(s, root);
    while (!isEmpty(s))
    {
        node = pop(s);
        cout << node << endl;
        if (node == goal) break;
        for (to = graph_size - 1; to > 0; to--)
            if (getEdge(g, node, to))
                push(s, to);
    }
}

void push(stack& s, int value)
{
    s.top++;
    s.data[s.top] = value;
}

int pop(stack& s)
{
    int value = s.data[s.top];
    s.top--;
    return value;
}

int isEmpty(stack& s)
{
    return(s.top == -1);
}
