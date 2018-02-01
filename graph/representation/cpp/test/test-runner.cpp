/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include "AMGraph.h"
#include "velograph.h"

// change later to use central runner for all tests
int main()
{
    //thanos::tests::VeloGraphTester::Run();
    //thanos::tests::VeloGraphTester::TestEulerGraphTracing();
    thanos::tests::AMGraphTester::Run();
}
