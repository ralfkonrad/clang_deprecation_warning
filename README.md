# clang deprecation warning

`clang-18` shows an unexpected warning when using a deprecated constructor
is used in `std::make_shared<T>(args from deprecated constructor...)` 
when the warning is turned of using `_Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")`.

On the other hand using `std::shared_ptr<T>(new T(args from deprecated constructor...))` does not emit any warning as expected when it off.

Neiter `clang-16` and `clang-17` nor `gcc` on `ubuntu-24.04` and `msvc`
emit a warning.

The same behaviour can be seen with `boost::shared_ptr` instead of `std::shahred_ptr`.