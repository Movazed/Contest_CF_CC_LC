#include <bits/stdc++.h>
using namespace std;

#define FAST_IO std::ios_base::sync_with_stdio(false); std::cin.tie(NULL);
#define VEC std::vector
#define SET std::set
#define QUEUE std::queue
#define PUSH_IT push
#define PUSH_BACK push_back
#define INSERT insert
#define GET_ID(x, y) ((x) * 101 + (y))
#define READ_INPUT(val) std::cin >> val
#define PRINT_OUTPUT(val) std::cout << val 
#define MAIN int main()
#define BEGIN {
#define END }
#define MAX_NODES 10201
#define PROCESS_SEGMENT(x1, y1, x2, y2, id1, id2) std::cin >> x1 >> y1 >> x2 >> y2; id1 = GET_ID(x1, y1); id2 = GET_ID(x2, y2);
#define ADD_UNDIRECTED_EDGE(u, v) BEGIN adj[u].PUSH_BACK(v); adj[v].PUSH_BACK(u); END
#define MARK_SEEN(node) seen[node] = true
#define IS_SEEN(node) (seen[node])
#define IS_INVALID_FOR_CYCLE(node) (adj[node].size() != 2)
#define INCREMENT(var) var++

VEC<int> adj[MAX_NODES];
bool seen[MAX_NODES] = {false};

MAIN
BEGIN
    FAST_IO

    int n;
    READ_INPUT(n);

    SET<int> points;
    int iter = 0;
    while (iter < n)
    BEGIN
        int x_1, y_1, x_2, y_2, id_1, id_2;
        PROCESS_SEGMENT(x_1, y_1, x_2, y_2, id_1, id_2);
        ADD_UNDIRECTED_EDGE(id_1, id_2);
        points.INSERT(id_1);
        points.INSERT(id_2);
        INCREMENT(iter);
    END

    int shape_counter = 0;
    auto point_iterator = points.begin();
    while (point_iterator != points.end())
    BEGIN
        int current_point = *point_iterator;

        if (!IS_SEEN(current_point))
        BEGIN
            bool is_a_shape = true;
            QUEUE<int> task_q;
            task_q.PUSH_IT(current_point);
            MARK_SEEN(current_point);

            while (!task_q.empty())
            BEGIN
                int u_node = task_q.front();
                task_q.pop();

                is_a_shape = IS_INVALID_FOR_CYCLE(u_node) ? false : is_a_shape;

                auto neighbor_iterator = adj[u_node].begin();
                while (neighbor_iterator != adj[u_node].end())
                BEGIN
                    int v_node = *neighbor_iterator;
                    if (!IS_SEEN(v_node))
                    BEGIN
                        MARK_SEEN(v_node);
                        task_q.PUSH_IT(v_node);
                    END
                    INCREMENT(neighbor_iterator);
                END
            END

            shape_counter += (is_a_shape ? 1 : 0);
        END

        INCREMENT(point_iterator);
    END

    PRINT_OUTPUT(shape_counter);

    return 0;
END