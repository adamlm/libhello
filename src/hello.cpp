#include <fmt/core.h>

#include "libhello/hello.hpp"

namespace hello {

    auto say_hello()

    noexcept -> void {
    fmt::print("Hello!\n");
}

} // namespace hello
