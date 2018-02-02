/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#ifndef THANOS_SORTING_SELECTION_SORT_H
#define THANOS_SORTING_SELECTION_SORT_H

#include <vector>

namespace thanos {
namespace sorting {

struct SelectionSortFactory
{
public:
    template <typename T>
    void SortVector(std::vector<T>& vec)
    {
        
    }
};

} // namespace sorting
} // namespace thanos

#endif // THANOS_SORTING_SELECTION_SORT_H
