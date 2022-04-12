#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

std::vector<int> z_func(std::string s) {
    std::vector<int> res(s.size());
    for (int i = 1, l = 0, r = 0; i < s.size(); ++i) {
        res[i] = std::max(0, std::min(r - i, res[i - l]));
        while (i + res[i] < s.size() and s[res[i]] == s[i + res[i]]) {
            ++res[i];
        }
        if (i + res[i] > r) {
            l = i;
            r = i + res[i];
        }
    }
    return res;
}

int main() {
    std::string main_stroke, substroke, co_inv;
    std::cin >> substroke >> main_stroke;
    std::string main_inv = main_stroke, sub_inv = substroke;
    std::string concatenated = substroke + '#' + main_stroke;
    std::vector<int> answer;
    std::reverse(sub_inv.begin(), sub_inv.end());
    std::reverse(main_inv.begin(), main_inv.end());
    co_inv = sub_inv + '#' + main_inv;
    std::vector<int> lcp, lcs;
    lcp = z_func(concatenated);
    lcs = z_func(co_inv);

    for (int i = substroke.size() + 1; i < co_inv.size() - substroke.size() + 1; ++i) {
        if (lcp[i] + lcs[lcs.size() - i + 1] >= substroke.size() - 1) {
            answer.push_back(i - substroke.size());
        }
    }

    std::cout << answer.size() << "\n";

    for (auto& i : answer) {
        std::cout << i << " ";
    }
}