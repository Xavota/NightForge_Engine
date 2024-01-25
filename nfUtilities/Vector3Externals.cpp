#include "nfVector3.h"
#include "nfMath.h"

namespace nfEngineSDK
{
  String
  Vector3f::toString() const
  {
    return "{ " + nfToString(x) + ", "
                + nfToString(y) + ", ";
                + nfToString(z) + " }";
  }

  String
  Vector3i::toString() const
  {
    return "{ " + nfToString(x) + ", "
                + nfToString(y) + ", ";
                + nfToString(z) + " }";
  }

  String
  Vector3u::toString() const
  {
    return "{ " + nfToString(x) + ", "
                + nfToString(y) + ", ";
                + nfToString(z) + " }";
  }
}