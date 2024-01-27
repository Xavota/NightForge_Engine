#include "nfVector4.h"
#include "nfStringUtilities.h"

namespace nfEngineSDK
{
  String
  Vector4f::toString() const
  {
    return "{ " + stringUtils::toString(x) + ", "
                + stringUtils::toString(y) + ", "
                + stringUtils::toString(z) + ", "
                + stringUtils::toString(w) + " }";
  }

  String
  Vector4i::toString() const
  {
    return "{ " + stringUtils::toString(x) + ", "
                + stringUtils::toString(y) + ", "
                + stringUtils::toString(z) + ", "
                + stringUtils::toString(w) + " }";
  }

  String
  Vector4u::toString() const
  {
    return "{ " + stringUtils::toString(x) + ", "
                + stringUtils::toString(y) + ", "
                + stringUtils::toString(z) + ", "
                + stringUtils::toString(w) + " }";
  }
}