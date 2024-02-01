#include "nfVector3.h"
#include "nfStringUtilities.h"

namespace nfEngineSDK
{
  String
  Vector3f::toString(int decimals) const
  {
    return "{ " + stringUtils::toString(x, decimals) + ", "
                + stringUtils::toString(y, decimals) + ", "
                + stringUtils::toString(z, decimals) + " }";
  }

  String
  Vector3i::toString() const
  {
    return "{ " + stringUtils::toString(x) + ", "
                + stringUtils::toString(y) + ", "
                + stringUtils::toString(z) + " }";
  }

  String
  Vector3u::toString() const
  {
    return "{ " + stringUtils::toString(x) + ", "
                + stringUtils::toString(y) + ", "
                + stringUtils::toString(z) + " }";
  }
}