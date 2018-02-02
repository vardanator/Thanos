/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef THANOS_SORTING_TEST_INSERTION_SORT_H
#define THANOS_SORTING_TEST_INSERTION_SORT_H

#include <iostream>

#include "./../src/insertion_sort.h"

namespace thanos {
namespace tests {

struct InsertionSortTester
{
public:
    static void Run()
    {
        int arr[] = {4, 5, 2, -1, 9, 13, -13, 20, 0, -2, 45, 3};
        std::vector<int> vec(arr, arr + 12); // will use above array in future needs

        std::cout << "Before insertion sort: " << std::endl;
        for (auto elem : vec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;

        thanos::sorting::InsertionSortFactory f;
        f.SortVector<int>(vec);

        std::cout << "After insertion sort: " << std::endl;
        for (auto elem : vec) {
            std::cout << elem << " ";
        }
        std::cout << std::endl;
    }
};

} // namespace tests
} // namespace thanos

#endif // THANOS_SORTING_TEST_INSERTION_SORT_H
