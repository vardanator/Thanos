/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef THANOS_TEST_GRAPH_TEST_INPUT_H
#define THANOS_TEST_GRAPH_TEST_INPUT_H

#include <iostream>

#include "./../src/velograph.h"

namespace thanos {

namespace tests {

struct VeloGraphTester {
    static void Run() {
        graphs::ConnectedVELOGraph g;

        g.InsertEdge("A", "B");
        g.InsertEdge("B", "C");
        g.Print();

        std::cout << "Tracing from A, path is: " << std::endl;
        auto path = g.Trace("A");
        for (const auto& v : path) {
            std::cout << v << " -> ";
        }
        std::cout << std::endl;
    }

    static void TestEulerGraphTracing() {
        graphs::ConnectedVELOGraph g;

        g.InsertEdge("A", "B");
        g.InsertEdge("B", "A");
        g.InsertEdge("A", "C");
        g.InsertEdge("A", "D");
        g.InsertEdge("D", "A");
        g.InsertEdge("B", "C");
        g.InsertEdge("C", "D");

        std::cout << "Tracing from A, path is: " << std::endl;
        auto path = g.Trace("A");
        for (const auto& v : path) {
            std::cout << v << " -> ";
        }
        std::cout << std::endl;
        g.Print();
    }
};

}
}

#endif // THANOS_TEST_GRAPH_TEST_INPUT_H
