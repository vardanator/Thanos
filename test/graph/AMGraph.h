/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef THANOS_TEST_GRAPH_ADJACENCY_MATRIX_GRAPH_H
#define THANOS_TEST_GRAPH_ADJACENCY_MATRIX_GRAPH_H

#include <iostream>

#include "./../../src/graph/representation/cpp/AMGraph.h"

namespace thanos {

namespace tests {

struct AMGraphTester
{
    static void Run()
    {
        thanos::graphs::AMGraph g(10);
        g.AddEdge(1, 4);
        g.AddEdge(2, 3);
        g.AddEdge(1, 1);
        g.AddEdge(6, 8);
        g.Print();
    }
};

} // namespace tests

} // namespace thanos

#endif // THANOS_TEST_GRAPH_ADJACENCY_MATRIX_GRAPH_H
