#include "pimpl_with_shared_ptr.hpp"

namespace rke {
QL_DEPRECATED_DISABLE_WARNING
PimplWithSharedPtr::PimplWithSharedPtr(int i)
    : data_(std::shared_ptr<Data>(new Data(i))) {}
QL_DEPRECATED_ENABLE_WARNING

PimplWithSharedPtr::PimplWithSharedPtr(std::string &str)
    : data_(std::shared_ptr<Data>(new Data(str))) {}

const std::string &PimplWithSharedPtr::str() const { return data_->str(); }

PimplWithSharedPtr::Data::Data(int i) : str_(std::to_string(i)) {}

PimplWithSharedPtr::Data::Data(std::string &str) : str_(std::move(str)) {}

const std::string &PimplWithSharedPtr::Data::str() const { return str_; }
} // namespace rke
