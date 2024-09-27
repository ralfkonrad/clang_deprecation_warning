#include "pimpl_with_make_shared.hpp"

namespace rke {
QL_DEPRECATED_DISABLE_WARNING
PimplWithMakeShared::PimplWithMakeShared(int i)
    : data_(std::make_shared<Data>(i)) {}
QL_DEPRECATED_ENABLE_WARNING

PimplWithMakeShared::PimplWithMakeShared(std::string &str)
    : data_(std::make_shared<Data>(str)) {}

const std::string &PimplWithMakeShared::str() const { return data_->str(); }

PimplWithMakeShared::Data::Data(int i) : str_(std::to_string(i)) {}

PimplWithMakeShared::Data::Data(std::string &str) : str_(std::move(str)) {}

const std::string &PimplWithMakeShared::Data::str() const { return str_; }
} // namespace rke
