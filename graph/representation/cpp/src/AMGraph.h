/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef THANOS_GRAPH_REPRESENTATION_ADJACENCY_MATRIX_GRAPH_H
#define THANOS_GRAPH_REPRESENTATION_ADJACENCY_MATRIX_GRAPH_H

namespace thanos {

namespace graphs {

// Representing a graph via Adjacency Matrix, VxV, where V is the number of vertices
// Assuming vertex is given by as integer
class AMGraph
{
public:
    explicit AMGraph(const std::size_t v)
        : vertex_count_(v)
    {
        vertices_ = new bool*[vertex_count_];
        for (std::size_t ix = 0; ix < vertex_count_; ++ix) {
            vertices_[ix] = new bool[vertex_count_];
            for (std::size_t jx = 0; jx < vertex_count_; ++jx) {
                vertices_[ix][jx] = 0;
            }
        }
    }

    ~AMGraph()
    {
        for (std::size_t ix = 0; ix < vertex_count_; ++ix) {
            delete [] vertices_[ix];
        }
        delete [] vertices_;
    }

    void AddEdge(const std::size_t from, const std::size_t to)
    {
        if (from > vertex_count_ || to > vertex_count_) return; // better throw an exception
        vertices_[from][to] = true;
    }

    void RemoveEdge(const std::size_t from, const std::size_t to)
    {
        if (from > vertex_count_ || to > vertex_count_) return; // better throw an exception
        vertices_[from][to] = false;
    }

    bool IsAdjacent(const std::size_t from, const std::size_t to) const
    {
        return vertices_[from][to];
    }

    std::size_t Degree(const std::size_t v) const
    {
        std::size_t degree = 0;
        for (std::size_t ix = 0; ix < vertex_count_; ++ix) {
            if (vertices_[v][ix]) {
                ++degree;
            }
        }
        return degree;
    }

    void Print() const
    {
        std::cout << "   ";
        for (std::size_t ix = 0; ix < vertex_count_; ++ix) {
            std::cout << "[" << ix << "]";
        }
        std::cout << std::endl;
        for (std::size_t ix = 0; ix < vertex_count_; ++ix) {
            std::cout << "[" << ix << "]";
            for (std::size_t jx = 0; jx < vertex_count_; ++jx) {
                std::cout << " " << vertices_[ix][jx] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    bool** vertices_;
    std::size_t vertex_count_;
};

} // namespace graphs

} // namespace thanos

#endif // THANOS_GRAPH_REPRESENTATION_ADJACENCY_MATRIX_GRAPH_H
