#include "deprecation.hpp"
#include <memory>
#include <string>

namespace rke {
class PimplWithMakeShared {
public:
  PimplWithMakeShared(int i);
  PimplWithMakeShared(std::string &str);

  const std::string &str() const;

private:
  struct Data;
  std::shared_ptr<Data> data_;
};

struct PimplWithMakeShared::Data {
public:
  QL_DEPRECATED Data(int i);
  Data(std::string &str);

  const std::string &str() const;

private:
  std::string str_;
};
} // namespace rke
