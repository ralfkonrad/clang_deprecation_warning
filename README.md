# clang deprecation warning

`clang-18` shows an unexpected `deprecated-declarations` warning
when a deprecated constructor is used in
`std::make_shared<T>(args from deprecated constructor...)` 
while the warning is turned of using `_Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")`.

On the other hand using `std::shared_ptr<T>(new T(args from deprecated constructor...))` does not emit any warning as expected when it off.

Neiter `clang-16` and `clang-17` nor `gcc` on `ubuntu-24.04` and `msvc`
emit a warning.

The same behaviour can be seen with `boost::shared_ptr` instead of `std::shahred_ptr`.

Have a look at the [workflow results](https://github.com/ralfkonrad/clang_deprecation_warning/actions).

### Works fine

```cpp
QL_DEPRECATED_DISABLE_WARNING
PimplWithSharedPtr::PimplWithSharedPtr(int i)
    : data_(std::shared_ptr<Data>(new Data(i))) {}
QL_DEPRECATED_ENABLE_WARNING
```

### Fails together with `CMAKE_COMPILE_WARNING_AS_ERROR = ON`
```cpp
QL_DEPRECATED_DISABLE_WARNING
PimplWithMakeShared::PimplWithMakeShared(int i)
    : data_(std::make_shared<Data>(i)) {}
QL_DEPRECATED_ENABLE_WARNING
```

---

### Failure message

```
FAILED: src/CMakeFiles/clang_deprecation_warning.dir/pimpl_with_make_shared.cpp.o
ccache /usr/bin/clang++  -I/home/ralfkonrad/dev/cpp/clang_deprecation_warning/src -O3 -DNDEBUG -std=c++17 -Wall -Wextra -Wpedantic -Werror -MD -MT src/CMakeFiles/clang_deprecation_warning.dir/pimpl_with_make_shared.cpp.o -MF src/CMakeFiles/clang_deprecation_warning.dir/pimpl_with_make_shared.cpp.o.d -o src/CMakeFiles/clang_deprecation_warning.dir/pimpl_with_make_shared.cpp.o -c /home/ralfkonrad/dev/cpp/clang_deprecation_warning/src/pimpl_with_make_shared.cpp
In file included from /home/ralfkonrad/dev/cpp/clang_deprecation_warning/src/pimpl_with_make_shared.cpp:1:
In file included from /home/ralfkonrad/dev/cpp/clang_deprecation_warning/src/pimpl_with_make_shared.hpp:2:
In file included from /usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/memory:66:
In file included from /usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/stl_tempbuf.h:61:
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/stl_construct.h:119:25: error: 'Data' is deprecated [-Werror,-Wdeprecated-declarations]
  119 |       ::new((void*)__p) _Tp(std::forward<_Args>(__args)...);
      |                         ^
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/alloc_traits.h:661:9: note: in instantiation of function template specialization 'std::_Construct<rke::PimplWithMakeShared::Data, int &>' requested here
  661 |         { std::_Construct(__p, std::forward<_Args>(__args)...); }
      |                ^
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/shared_ptr_base.h:604:30: note: in instantiation of function template specialization 'std::allocator_traits<std::allocator<void>>::construct<rke::PimplWithMakeShared::Data, int &>' requested here
  604 |           allocator_traits<_Alloc>::construct(__a, _M_ptr(),
      |                                     ^
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/shared_ptr_base.h:972:6: note: in instantiation of function template specialization 'std::_Sp_counted_ptr_inplace<rke::PimplWithMakeShared::Data, std::allocator<void>, __gnu_cxx::_S_atomic>::_Sp_counted_ptr_inplace<int &>' requested here
  972 |             _Sp_cp_type(__a._M_a, std::forward<_Args>(__args)...);
      |             ^
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/shared_ptr_base.h:1712:14: note: in instantiation of function template specialization 'std::__shared_count<>::__shared_count<rke::PimplWithMakeShared::Data, std::allocator<void>, int &>' requested here
 1712 |         : _M_ptr(), _M_refcount(_M_ptr, __tag, std::forward<_Args>(__args)...)
      |                     ^
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/shared_ptr.h:464:4: note: in instantiation of function template specialization 'std::__shared_ptr<rke::PimplWithMakeShared::Data>::__shared_ptr<std::allocator<void>, int &>' requested here
  464 |         : __shared_ptr<_Tp>(__tag, std::forward<_Args>(__args)...)
      |           ^
/usr/bin/../lib/gcc/x86_64-linux-gnu/13/../../../../include/c++/13/bits/shared_ptr.h:1009:14: note: in instantiation of function template specialization 'std::shared_ptr<rke::PimplWithMakeShared::Data>::shared_ptr<std::allocator<void>, int &>' requested here
 1009 |       return shared_ptr<_Tp>(_Sp_alloc_shared_tag<_Alloc>{__a},
      |              ^
/home/ralfkonrad/dev/cpp/clang_deprecation_warning/src/pimpl_with_make_shared.cpp:6:18: note: in instantiation of function template specialization 'std::make_shared<rke::PimplWithMakeShared::Data, int &>' requested here
    6 |     : data_(std::make_shared<Data>(i)) {}
      |                  ^
/home/ralfkonrad/dev/cpp/clang_deprecation_warning/src/pimpl_with_make_shared.hpp:20:3: note: 'Data' has been explicitly marked deprecated here
   20 |   QL_DEPRECATED Data(int i);
      |   ^
/home/ralfkonrad/dev/cpp/clang_deprecation_warning/src/deprecation.hpp:15:42: note: expanded from macro 'QL_DEPRECATED'
   15 | #    define QL_DEPRECATED __attribute__((deprecated))
      |                                          ^
1 error generated.
```