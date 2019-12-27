//
// Created by Mouse on 2019/12/27.
//
#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MaxVnum 50 // 图的顶点数上限
typedef int AdjMatrix[MaxVnum][MaxVnum]; // 可根据权值的类型将 int 替换为 double
typedef struct { // 图的类型定义
    int vexnum, arcnum; // 图的实际顶点数、边数
    AdjMatrix arcs; // 邻接矩阵
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
    for (int i = 0; i < graph.vexnum; ++i) {
        for (int j = 0; j < graph.vexnum; ++j) {
            cin >> graph.arcs[i][j];
        }
    }
}

void dfs(Graph graph, int vex, int *visited) {
    cout << vex << " ";
    visited[vex] = 1; // 标记顶点已被访问
    for (int i = 0; i < graph.vexnum; ++i) {
        if (graph.arcs[vex][i] && !visited[i]) { // 找到邻接且未访问的顶点
            dfs(graph, i, visited);
        }
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

        queue[++queueTail] = i; // 将节点添加到队列中
        while (queueHead < queueTail) { // 遍历队列
            int vex = queue[++queueHead];
            visited[vex] = 1; // 访问顶点
            cout << vex << " ";
            for (int j = 0; j < graph.vexnum; ++j) { // 将当前顶点的邻接顶点添加到队列中
                if (graph.arcs[vex][j] && !visited[j]) queue[++queueTail] = j;
            }
        }
    }
    cout << endl;
    free(queue);
    free(visited);
}