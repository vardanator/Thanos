/**
 * Copyright (c) 2018, Vardan Grigoryan (vardanator)
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#include <string>

#ifndef THANOS_SORTING_KEY_INDEXED_COUNTING_STRING_SORT_H
#define THANOS_SORTING_KEY_INDEXED_COUNTING_STRING_SORT_H

namespace thanos {
namespace sorting {

// T should have Key() member function
template <typename T, int Radix>
class KeyIndexedCountingStringSorter
{
public:
    // Will change later to template template in order to get any container
    // Or will change to use iterators
    void Sort(std::vector<T>& vec)
    {
        std::vector<int> count(Radix + 1, 0);
        std::vector<T> aux(vec.size());

        for (std::size_t ix = 0; ix < vec.size(); ++ix) {
            count[vec[ix].Key() + 1]++;
        }
        for (std::size_t rx = 0; rx < Radix; ++rx) {
            count[rx + 1] = count[rx];
        }

        for (std::size_t ix = 0; ix < vec.size(); ++ix) {
            aux[count[vec[ix].Key()]++] = vec[ix];
        }
        for (std::size_t ix = 0; ix < vec.size(); ++ix) {
            vec[ix] = aux[ix];
        }
    }
};

} // namespace sorting
} // namespace thanos

#endif // THANOS_SORTING_KEY_INDEXED_COUNTING_STRING_SORT_H
