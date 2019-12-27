//
// Created by Mouse on 2019/12/27.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MaxVnum 50 // 图的顶点数上限
typedef char VertexType; // 如果结点的名字较长，可在 VertexType 后面加上[128]
typedef struct ArcNode { // 表结点
    int adjvex;
    double weight;
    struct ArcNode *nextarc;
} ArcNode;
typedef struct { // 头结点
    VertexType data;
    ArcNode *firstarc;
} AdjList[MaxVnum];
typedef struct { // 图的类型定义
    int vexnum, arcnum; // 实际的顶点数、边数
    AdjList vertices;
} Graph;

Graph graph;

void initialize();

void dfs();

void bfs();

int main() {
    initialize();
    dfs();
    bfs();
    return 0;
}

void initialize() {
    cin >> graph.vexnum >> graph.arcnum;
    for (int i = 0; i < graph.vexnum; ++i) graph.vertices[i].firstarc = nullptr;
    for (int i = 0; i < graph.arcnum; ++i) {
        int vex;
        ArcNode *node = (ArcNode *) malloc(sizeof(ArcNode));
        cin >> vex >> node->adjvex >> node->weight;
        node->nextarc = graph.vertices[vex].firstarc;
        graph.vertices[vex].firstarc = node;
    }
}

void dfs(Graph graph, int vex, int *visited) {
    cout << vex << " ";
    visited[vex] = 1; // 标记顶点已被访问
    ArcNode *node = graph.vertices[vex].firstarc;
    while (node != nullptr) {
        if (!visited[node->adjvex]) { // 找到邻接且未访问的顶点
            dfs(graph, node->adjvex, visited);
        }
        node = node->nextarc;
    }
}

void dfs() {
    int *visited = (int *) malloc(sizeof(int) * graph.vexnum);
    for (int i = 0; i < graph.vexnum; ++i) visited[i] = 0;
    for (int i = 0; i < graph.vexnum; ++i) { // 遍历顶点
        if (!visited[i]) { // 如果顶点未访问
            dfs(graph, i, visited);
        }
    }
    cout << endl;
    free(visited);
}

void bfs() {
    int *visited = (int *) malloc(sizeof(int) * graph.vexnum);
    for (int i = 0; i < graph.vexnum; ++i) visited[i] = 0;
    int *queue = (int *) malloc(sizeof(int) * graph.vexnum);
    int queueHead = -1, queueTail = -1;
    for (int i = 0; i < graph.vexnum; ++i) {
        if (visited[i]) continue; // 节点已访问，进入下一次迭代

        visited[i] = 1; // 访问顶点
        queue[++queueTail] = i; // 将节点添加到队列中
        while (queueHead < queueTail) { // 遍历队列
            int vex = queue[++queueHead];
            cout << vex << " ";
            ArcNode *node = graph.vertices[vex].firstarc;
            while (node != nullptr) {
                if (!visited[node->adjvex]) { // 将当前顶点的邻接顶点添加到队列中
                    visited[node->adjvex] = 1; // 访问顶点
                    queue[++queueTail] = node->adjvex;
                }
                node = node->nextarc;
            }
        }
    }
    cout << endl;
    free(queue);
    free(visited);
}