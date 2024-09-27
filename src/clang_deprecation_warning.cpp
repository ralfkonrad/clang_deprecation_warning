#include "pimpl_with_make_shared.hpp"
#include "pimpl_with_shared_ptr.hpp"
#include <iostream>

int main() {
  auto pimplWithMakeShared = rke::PimplWithMakeShared(41);
  std::cout << "Hello make_shared '" << pimplWithMakeShared.str() << "'."
            << std::endl;

  auto pimplWithSharedPtr = rke::PimplWithSharedPtr(42);
  std::cout << "Hello shared_ptr '" << pimplWithSharedPtr.str() << "'."
            << std::endl;
}
