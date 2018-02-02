/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef THANOS_SORTING_INSERTION_SORT_H
#define THANOS_SORTING_INSERTION_SORT_H

#include <vector>

namespace thanos {
namespace sorting {

struct InsertionSortFactory
{
public:
    template <typename T>
    void SortVector(std::vector<T>& vec)
    {
        for (int ix = 1; ix < vec.size(); ++ix) {
            T item = vec[ix];
            int jx = ix - 1;
            while (jx >= 0 && vec[jx] > item) {
                vec[jx + 1] = vec[jx];
                --jx;
            }
            vec[jx + 1] = item;
        }
    }
};

} // namespace sorting
} // namespace thanos

#endif // THANOS_SORTING_INSERTION_SORT_H
