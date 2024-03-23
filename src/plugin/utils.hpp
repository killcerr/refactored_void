#include <iterator>
namespace tools {
template <typename T>
constexpr bool in(typename T::value_type const& x, T const& c) {
    for (const auto& t : c) {
        if (t == x) return true;
    }
    return false;
}
} // namespace tools
