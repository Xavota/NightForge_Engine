#include "nfVector2.h"
#include "nfMath.h"

namespace nfEngineSDK
{
  String
  Vector2f::toString() const
  {
    return "{ " + nfToString(x) + ", "
                + nfToString(y) + " }";
  }

  String
  Vector2i::toString() const
  {
    return "{ " + nfToString(x) + ", "
                + nfToString(y) + " }";
  }

  String
  Vector2u::toString() const
  {
    return "{ " + nfToString(x) + ", "
                + nfToString(y) + " }";
  }
}