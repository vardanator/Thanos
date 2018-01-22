/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef THANOS_TEST_GRAPH_TEST_INPUT_H
#define THANOS_TEST_GRAPH_TEST_INPUT_H

#include <iostream>

#include "./../../src/graph/representation/cpp/velograph.h"

namespace thanos {

namespace tests {

struct GraphInputTester {
    static void Run() {
        graphs::ConnectedVELOGraph g;

        /*
        Having graph:
         A - B
         B - A
         B - C
         B - D
         C - B
         C - D
         D - C
         D - B
        */


        g.InsertEdge("A", "B");
        g.InsertEdge("B", "A");
        g.InsertEdge("B", "C");
        g.InsertEdge("C", "B");

        g.Print();
    }
};

}
}

#endif // THANOS_TEST_GRAPH_TEST_INPUT_H
