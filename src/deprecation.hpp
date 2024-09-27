/* Copied from
 * https://github.com/lballabio/QuantLib/blob/1af4f821508e1975f607fca24da5e00e59185a11/ql/qldefines.hpp#L190-L219
 */

// emit warning when using deprecated features
// clang-format off
#if defined(_MSC_VER)       // Microsoft Visual C++
#    define QL_DEPRECATED __declspec(deprecated)
#    define QL_DEPRECATED_DISABLE_WARNING \
        __pragma(warning(push))           \
        __pragma(warning(disable : 4996))
#    define QL_DEPRECATED_ENABLE_WARNING \
        __pragma(warning(pop))
#elif defined(__clang__)
#    define QL_DEPRECATED __attribute__((deprecated))
#    define QL_DEPRECATED_DISABLE_WARNING                                 \
        _Pragma("clang diagnostic push")                                  \
        _Pragma("clang diagnostic ignored \"-Wdeprecated-declarations\"")
#    define QL_DEPRECATED_ENABLE_WARNING \
        _Pragma("clang diagnostic pop")
#elif defined(__GNUC__)
#    define QL_DEPRECATED __attribute__((deprecated))
#    define QL_DEPRECATED_DISABLE_WARNING                               \
        _Pragma("GCC diagnostic push")                                  \
        _Pragma("GCC diagnostic ignored \"-Wdeprecated-declarations\"")
#    define QL_DEPRECATED_ENABLE_WARNING \
        _Pragma("GCC diagnostic pop")
#else
// we don't know how to enable it, just define the macros away
#    define QL_DEPRECATED
#    define QL_DEPRECATED_DISABLE_WARNING
#    define QL_DEPRECATED_ENABLE_WARNING
#endif
// clang-format on
