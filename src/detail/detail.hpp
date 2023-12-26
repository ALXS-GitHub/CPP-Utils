#ifndef UTILS_DETAIL_DETAIL_HPP
#define UTILS_DETAIL_DETAIL_HPP
#include <iostream>
#include <type_traits>
#include <vector>
#include <map>
#include <iomanip>
#include <list>
#include <unordered_map>
#include <deque>
#include <forward_list>
#include <array>
#include <set>
#include <unordered_set>
#include <string>
#include <tuple>
#include <variant>
#include <optional>
#include <any>

using namespace std;

namespace utils {
    // & detail nested namespace (for internal use only)
    namespace detail {
        template <typename T>
        struct is_string_like : std::false_type
        {
        };

        template <typename CharT, typename Traits, typename Alloc>
        struct is_string_like<std::basic_string<CharT, Traits, Alloc>> : std::true_type
        {
        };

        template <typename CharT, typename Traits>
        struct is_string_like<std::basic_string_view<CharT, Traits>> : std::true_type
        {
        };

        template <typename CharT>
        struct is_string_like<std::basic_string<CharT>> : std::true_type
        {
        };

        template <typename CharT>
        struct is_string_like<std::basic_string_view<CharT>> : std::true_type
        {
        };

        template <typename CharT>
        struct is_string_like<CharT *> : std::true_type
        {
        };

        template <typename CharT>
        struct is_string_like<const CharT *> : std::true_type
        {
        };

        // µ is_vector_like
        template <typename T>
        struct is_vector_like : std::false_type
        {
        };

        template <typename T, typename Alloc>
        struct is_vector_like<std::vector<T, Alloc>> : std::true_type
        {
        };

        template <typename T, typename Alloc>
        struct is_vector_like<std::deque<T, Alloc>> : std::true_type
        {
        };

        template <typename T, std::size_t N>
        struct is_vector_like<std::array<T, N>> : std::true_type
        {
        };

        // µ is_list_like

        template <typename T>
        struct is_list_like : std::false_type
        {
        };

        template <typename T, typename Alloc>
        struct is_list_like<std::list<T, Alloc>> : std::true_type
        {
        };

        template <typename T, typename Alloc>
        struct is_list_like<std::forward_list<T, Alloc>> : std::true_type
        {
        };

        // µ is_map_like

        template <typename T>
        struct is_map_like : std::false_type
        {
        };

        template <typename Key, typename T, typename Compare, typename Alloc>
        struct is_map_like<std::map<Key, T, Compare, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename T, typename Compare, typename Alloc>
        struct is_map_like<std::multimap<Key, T, Compare, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename T, typename Hash, typename Pred, typename Alloc>
        struct is_map_like<std::unordered_map<Key, T, Hash, Pred, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename T, typename Hash, typename Pred, typename Alloc>
        struct is_map_like<std::unordered_multimap<Key, T, Hash, Pred, Alloc>> : std::true_type
        {
        };

        // µ is_set_like

        template <typename T>
        struct is_set_like : std::false_type
        {
        };

        template <typename Key, typename Compare, typename Alloc>
        struct is_set_like<std::set<Key, Compare, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename Compare, typename Alloc>
        struct is_set_like<std::multiset<Key, Compare, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename Hash, typename Pred, typename Alloc>
        struct is_set_like<std::unordered_set<Key, Hash, Pred, Alloc>> : std::true_type
        {
        };

        template <typename Key, typename Hash, typename Pred, typename Alloc>
        struct is_set_like<std::unordered_multiset<Key, Hash, Pred, Alloc>> : std::true_type
        {
        };

        // µ is_tuple_like

        template <typename T>
        struct is_tuple_like : std::false_type
        {
        };

        template <typename... Args>
        struct is_tuple_like<std::tuple<Args...>> : std::true_type
        {
        };

        template <typename... Args>
        struct is_tuple_like<std::pair<Args...>> : std::true_type
        {
        };

        template <typename... Args>
        struct is_tuple_like<std::variant<Args...>> : std::true_type
        {
        };

        template <typename... Args>
        struct is_tuple_like<std::optional<Args...>> : std::true_type
        {
        };

        // µ is_variant_like

        template <typename T>
        struct is_variant_like : std::false_type
        {
        };

        template <typename... Args>
        struct is_variant_like<std::variant<Args...>> : std::true_type
        {
        };

        // µ is_optional_like

        template <typename T>
        struct is_optional_like : std::false_type
        {
        };

        template <typename... Args>
        struct is_optional_like<std::optional<Args...>> : std::true_type
        {
        };

        // µ is_any_like

        template <typename T>
        struct is_any_like : std::false_type
        {
        };

        template <>
        struct is_any_like<std::any> : std::true_type
        {
        };
    } // namespace detail
}

#endif // UTILS_DETAIL_DETAIL_HPP