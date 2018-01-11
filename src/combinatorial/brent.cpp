#include <array>
#include <vector>
#include <utility>
#include <iostream>

// using int limits to fewer elements in a sequence
std::pair<int, int> detect_brent_cycle(const std::array<int, 8>& sequence) {
    if (sequence.size() <= 1) return std::make_pair(-1, -1);
    int power = 1;
    int lam = 1;
    int index = 0; // faking f(), e.g. index is f(), f(x0) is index+1, etc.
    int tortoise = sequence[index];
    int hare = sequence[++index];

    while (tortoise != hare && index < sequence.size()) {
        if (power == lam) {
            tortoise = hare;
            power *= 2;
            lam = 0;
        }
        hare = sequence[++index];
        ++lam;
    }
    if (tortoise != hare) return std::make_pair(-1, -1); // checking the non-cyclic sequence case
    // we got 'lam' at this point

    int mu = 0;
    tortoise = sequence[0];
    hare = sequence[lam - 1]; // teleport hare

    int tortoise_index = 0;
    int hare_index = lam - 1;
    while (tortoise != hare && hare_index < sequence.size()) {
        tortoise = sequence[++tortoise_index];
        hare = sequence[++hare_index];
        ++mu;
    }
    if (tortoise != hare) return std::make_pair(-1, -1);
    return std::make_pair(lam, mu);
}

int main() {
    std::array<int, 8> sequence = {2, 0, 6, 3, 1, 6, 3, 1};
    std::pair<int, int> p = detect_brent_cycle(sequence);
    std::cout << "lam == " << p.first << ", mu == " << p.second << std::endl;
}
