#ifndef STD_EXPERIMENTAL_BITS_CAN_REQUIRE_H
#define STD_EXPERIMENTAL_BITS_CAN_REQUIRE_H

#include <type_traits>
#include <tuple>
#include <utility>

namespace std {
namespace experimental {
inline namespace executors_v1 {
namespace execution {
namespace can_require_impl {

template<class Executor, class Properties, class = std::void_t<>>
struct eval : std::false_type {};

template<class Executor, class... Properties>
struct eval<Executor, std::tuple<Properties...>,
  std::void_t<decltype(
    ::std::experimental::executors_v1::execution::require(std::declval<Executor>(), std::declval<Properties>()...)
  )>> : std::true_type {};

} // namespace can_require_impl

template<class Executor, class... Properties>
struct can_require : can_require_impl::eval<Executor, std::tuple<Properties...>> {};

} // namespace execution
} // inline namespace executors_v1
} // namespace experimental
} // namespace std

#endif // STD_EXPERIMENTAL_BITS_CAN_REQUIRE_H
