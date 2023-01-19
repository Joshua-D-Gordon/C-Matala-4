# include <stdio.h>
# include "graph.h"

int main()
{
    //making empty graph with 0 nodes, 0 edges, NULL node linked list, NULL edge linked list
    struct Graph g = {0, 0, NULL, NULL};
    //pointer to graph
    struct Graph *graph_ptr = &g;

    //char runner for scanner
    char ch;
    scanf("%c",&ch);
    //while ch is not EOF or '\n'
    while (ch != EOF && ch != '\n')
    {
        //switch Case for all: A,B,D,S,T
        switch (ch)
        {
        case 'A':
        {
            //if graph exsits delete current graph
            if (graph_ptr->nodes_num > 0)
            {
                delete_graph(graph_ptr);
            }
            
            //initilize new graph
            init_graph(graph_ptr, &ch);

            break;
        }
        case 'B':
        {
            //scan node to add
            int nodeToAdd;
            scanf(" %d",&nodeToAdd);
            //add node
            add_node(nodeToAdd, graph_ptr);

            //connect node to dest node (in pairs of weights and dest point)
            int dest, w;
            while (scanf(" %d %d", &dest, &w) == 2)
            {
                connect(nodeToAdd, dest, w, graph_ptr);
            }
            scanf("%c",&ch);

            break;
        }
        case 'D':
        {   //scan node num to remove
            int nodeToRemove;
            scanf(" %d",&nodeToRemove);
            //remove node
            remove_node(nodeToRemove ,graph_ptr);
            scanf("%c",&ch);

            break;
        }
        case 'S':
        {
            int start, end, ans;
            ans = -1;
            //find shortest path
            if (scanf(" %d %d", &start, &end) == 2)
                ans = shortest_path(start, end, graph_ptr);
            //ans is -1 if no path
            if (ans == 0)
                ans = -1;
            printf("Dijsktra shortest path: %d \n", ans);
            scanf("%c",&ch);

            break;
        }
        case 'T':
        {
            int ans = -1;
            //the sales man problem answer
            ans = TSP(graph_ptr, &ch);
            printf("TSP shortest path: %d \n", ans);
            scanf("%c",&ch);

            break;
        }
        case 'P':
        {
            print_graph(graph_ptr);
            scanf("%c",&ch);

            break;
        }
        case ' ':
        {   //if space scan next input
            scanf("%c",&ch);
            break;
        }
        default:
            break;
        }
    }
    //free graph function
    free_graph(graph_ptr);
    return 0;
}
