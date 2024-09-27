#include "deprecation.hpp"
#include <memory>
#include <string>

namespace rke {
class PimplWithSharedPtr {
public:
  PimplWithSharedPtr(int i);
  PimplWithSharedPtr(std::string &str);

  const std::string &str() const;

private:
  struct Data;
  std::shared_ptr<Data> data_;
};

struct PimplWithSharedPtr::Data {
public:
  QL_DEPRECATED Data(int i);
  Data(std::string &str);

  const std::string &str() const;

private:
  std::string str_;
};
} // namespace rke
