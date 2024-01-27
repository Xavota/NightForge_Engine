#include "nfVector2.h"
#include "nfStringUtilities.h"

namespace nfEngineSDK
{
  String
  Vector2f::toString() const
  {
    return "{ " + stringUtils::toString(x) + ", "
                + stringUtils::toString(y) + " }";
  }

  String
  Vector2i::toString() const
  {
    return "{ " + stringUtils::toString(x) + ", "
                + stringUtils::toString(y) + " }";
  }

  String
  Vector2u::toString() const
  {
    return "{ " + stringUtils::toString(x) + ", "
                + stringUtils::toString(y) + " }";
  }
}