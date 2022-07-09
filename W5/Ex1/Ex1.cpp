#include <iostream>
#include "list"
#include "string"
#include "Graph.h"
#include "queue"

int bfs(Graph<char>& g, char c) {
    Vertex<char>* vertex = g.findVertex(c);
    std::vector<Edge<char>> adj = vertex->getadj();
    for (auto it=adj.begin(); it!= adj.end(); it++) (it->getdest())->visited = false;
    std::queue<char> q; // queue of unvisited nodes
    q.push(c);
    g.findVertex(c)->visited = true;
    int count=0;
    while (!q.empty()) { // while there are still unvisited nodes
        char u = q.front();
        q.pop();
        std::vector<Edge<char>> temp = g.findVertex(u)->getadj();
        for (auto e: temp) {
            Vertex<char>* w = e.getdest();
            if (!w->visited) {
                count++;
                q.push(w->getInfo());
                w->visited = true;
            }
        }
    }
    return count;
}


Graph<char> make_graph(std::list<std::string> man){
    Graph<char> g;
    for(auto it=man.begin(); it!=man.end(); ){
        std::string p1 = *it;
        if(++it == man.end()){
            break;
        }
        std::string p2=*(it);
        for(int i=0, j=0; i<p1.length() && j<p2.length(); i++, j++){
            if(p1[i]==p2[j]) continue;
            else{
                if(!g.findVertex(p1[i]))g.addVertex(p1[i]);
                if(!g.findVertex(p2[i]))g.addVertex(p2[j]);
                g.addEdge(p1[i], p2[j], 0.0);
                break;
            }
        }
    }
    return g;
}

std::list<std::string> readIn(){
    char c;
    std::string line;
    std::list<std::string> final;
    while(std::getline(std::cin, line)){
        final.push_back(line);
        if(line=="#"){
            std::getline(std::cin, line);
            c=line[0];
            break;
        }
    }
    for(auto& it: final){
        std::cout << it << std::endl;
    }
    std::cout << "#\n"<<c<<std::endl;
    return final;
}