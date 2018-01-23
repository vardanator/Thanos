/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef THANOS_GRAPH_STRUCTURE_REPRESENTATION_VELOGRAPH_H
#define THANOS_GRAPH_STRUCTURE_REPRESENTATION_VELOGRAPH_H

#include <map>
#include <vector>
#include <iostream>
#include <unordered_map>

namespace thanos {

namespace graphs {

// A representation of a graph with both vertex and edge tables
// Vertex table is a hashtable of edges (mapped by label)
// Edge table is a structure with 4 fields
// VELO = Vertex Edge Label Only (e.g. no vertex payloads)

class ConnectedVELOGraph {
public:
    struct Edge {
        Edge(const std::string& f, const std::string& t)
            : from(f)
            , to(t)
            , used(false)
            , next(nullptr)
        {}
        std::string ToString() {
            return (from + " - " + to + " [used:" + (used ? "true" : "false") + "]");
        }

        std::string from;
        std::string to;
        bool used;
        Edge* next;
    };

    ConnectedVELOGraph() {}
    ~ConnectedVELOGraph() {
        vertices_.clear();
        for (std::size_t ix = 0; ix < edges_.size(); ++ix) {
            delete edges_[ix];
        }
    }

public:
    void InsertEdge(const std::string& from, const std::string& to) {
        Edge* e = new Edge(from, to);
        InsertVertexEdge_(from, e);
        InsertVertexEdge_(to, e);
        edges_.push_back(e);
    }

public:
    void Print() {
        for (auto elem : edges_) {
            std::cout << elem->ToString() << std::endl;
        }
    }

    std::vector<std::string> Trace(const std::string& v) {
        std::vector<std::string> path;
        Edge* e = vertices_[v];
        while (e != nullptr) {
            if (e->used) {
                e = e->next;
            } else {
                e->used = true;
                path.push_back(e->from);
                path.push_back(e->to);
                e = vertices_[e->to];
            }
        }
        return path;
    }

private:
    void InsertVertexEdge_(const std::string& label, Edge* e) {
        if (vertices_.count(label) == 0) {
            vertices_[label] = e;
        } else {
            vertices_[label]->next = e;
        }
    }

private:
    std::unordered_map<std::string, Edge*> vertices_;
    std::vector<Edge*> edges_;
};

}
}

#endif // THANOS_GRAPH_STRUCTURE_REPRESENTATION_VELOGRAPH_H
