#include "nfPlatformMath.h"

namespace nfEngineSDK
{
  const float PlatformMath::kPI = atan(1.0f) * 4;
  const float PlatformMath::kPI_OVER_180 = PlatformMath::kPI / 180.0f;
  const float PlatformMath::k180_OVER_PI = 180 / PlatformMath::kPI;
  const float PlatformMath::k2_PI = PlatformMath::kPI * 2.0f;
  const float PlatformMath::kPI_OVER_2 = PlatformMath::kPI / 2.0f;

  const float PlatformMath::kEuler = std::expf(1);

  const float PlatformMath::kMAX_FLOAT = std::numeric_limits<float>::max();
  const float PlatformMath::kMIN_FLOAT = std::numeric_limits<float>::min();
  const double PlatformMath::kMAX_DOUBLE = std::numeric_limits<double>::max();
  const double PlatformMath::kMIN_DOUBLE = std::numeric_limits<double>::min();
  const long double PlatformMath::kMAX_LONG_DOUBLE = std::numeric_limits<long double>::max();
  const long double PlatformMath::kMIN_LONG_DOUBLE = std::numeric_limits<long double>::min();
  const int32 PlatformMath::kMIN_INT = std::numeric_limits<int32>::min();
  const int32 PlatformMath::kMAX_INT = std::numeric_limits<int32>::max();
  const uint32 PlatformMath::kMAX_UINT = std::numeric_limits<uint32>::max();
}