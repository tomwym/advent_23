#include <string_view>
#include <iostream>
#include <ranges>

#include "01"


consteval std::string_view trim_newline(const std::string_view sv) {
    if (sv.back() == '\n')
        return std::string_view{ sv.begin(), sv.end() - 1 };
    else
        return sv;
}

consteval int pow(int val, int n) {
    if (n == 0) {
        return 1;
    }
    return val * pow(val, n - 1);
}


consteval int sum(const std::string_view sv, const int order, const int add) {
    if (sv.size() == 0) {
        return add;
    }
    else {
        const auto local_sum{ (static_cast<int>(sv.back()) - '0') * pow(10, order) };
        return sum(std::string_view{ sv.begin(), sv.end() - 1 }, order + 1, add + local_sum);
    }
}

consteval int strview_to_size(const std::string_view sv) {
    if (sv.size() == 0 || sv == "\n") {
        return 0;
    }
    else {
        const auto s{ sum(trim_newline(sv), 0, 0)
    };
        return s;
    }
}

consteval int split_string(const std::string_view sv, const int sum)
{
    if (sv.length() == 0) {
        return sum;
    }
    for (int idx{ 0 }; const auto & c : sv) {
        if (c == '\n') {
            ++idx;
            return
                split_string(
                    std::string_view{
                        sv.begin() + idx,
                        sv.end()
                    },
                    sum + strview_to_size(std::string_view{ sv.begin(), sv.begin() + idx })
                );
        }
        ++idx;
    }
    return sum + strview_to_size(sv);
}

// return index of elf
consteval std::tuple<int, int> split_block(const std::string_view sv, const int previous_score, const int previous_elf, const int current) {
    if (sv.size() == 0 || sv.size() == 1) {
        return { previous_elf, previous_score };
    }
    for (int idx{ 0 }; const auto & c : sv) {
        if (c == '\n' && (idx != (sv.size()-1)) && *(sv.begin() + idx + 1) == '\n') {
            const auto block_score{
                split_string(
                    std::string_view{ sv.begin(), sv.begin() + idx },
                    0
                )
            };
            return
                split_block(
                    std::string_view{
                        sv.begin() + idx + 2,
                        sv.end()
                    },
                    std::max(previous_score, block_score),
                    std::max(previous_score, block_score) == previous_score ? previous_elf : current + 1,
                    current+1
                );
        }
        ++idx;
    }
    const auto block_score{
        split_string(
            sv,
            0
        )
    };
    return {
        std::max(previous_score, block_score) == previous_score ? previous_elf : current + 1,
        std::max(previous_score, block_score)
    };
}

int main() {
    constexpr auto tup{ split_block(data, 0, 0, 0) };

    return 0;
}