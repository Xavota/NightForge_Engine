/************************************************************************/
/**
 * @file nfMath.h
 * @author Mara Castellanos
 * @date 22/01/24
 * @brief This is for replacing the Math library for anything you want.
 *
 * @bug Not bug Known.
 */
/************************************************************************/

#pragma once

#include "nfPrerequisitesUtilities.h"
#include "nfPlatformMath.h"

namespace nfEngineSDK
{
#if NF_PLATFORM == NF_PLATFORM_WIN32 || \
    NF_PLATFORM == NF_PLATFORM_LINUX || \
    NF_PLATFORM == NF_PLATFORM_OSX
  using Math = PlatformMath;
#else
  using Math = PlatformMath;
#endif
}