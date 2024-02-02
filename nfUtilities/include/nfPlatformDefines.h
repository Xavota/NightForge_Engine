/************************************************************************/
/**
 * @file nfPlatformDefines.h
 * @author Mara Castellanos
 * @date 22/01/24
 * @brief All the defines needed for the Utilities module.
 *
 * @bug Not bug Known.
 */
/************************************************************************/

#pragma once


/************************************************************************/
/**
 * Initial platform/compiler-related stuff to set.
*/
/************************************************************************/
#define NF_PLATFORM_WIN32   1                  //Windows Platform
#define NF_PLATFORM_LINUX   2                  //Linux Platform
#define NF_PLATFORM_OSX     3


#define NF_COMPILER_MSVC    1                  //Visual Studio Compiler
#define NF_COMPILER_GNUC    2                  //GCC Compiler
#define NF_COMPILER_INTEL   3                  //Intel Compiler
#define NF_COMPILER_CLANG   4                  //Clang Compiler

#define NF_ARCHITECTURE_X86_32 1               //Intel x86 32 bits
#define NF_ARCHITECTURE_X86_64 2               //Intel x86 64 bits

#define NF_ENDIAN_LITTLE  1
#define NF_ENDIAN_BIG     2

//Define the actual endian type (little endian for Windows, Linux, Apple and PS4)
#define NF_ENDIAN NF_ENDIAN_LITTLE

#define NF_VERSION_MAJOR    0                 //Engine version major
#define NF_VERSION_MINIOR   0
#define NF_VERSION_PATCH    1
#define NF_VERSION_BUILD    4

//Define if on crate a we want to report warnings on unknown symbols
#define NF_DEBUG_DETAILED_SYMBOLS   1

/************************************************************************/
/**
 * Compiler type and version
 */
 /************************************************************************/

#if defined(__clang__)
#   define NF_COMPILER NF_COMPILER_CLANG
#   define NF_COMP_VER __cland_version__
#   define NF_THREADLOCAL __thread
#   define NF_STDCALL __attribute__((stdcall))
#   define NF_CDECL __attribute__((cdecl))
#   define NF_FALLTHROUHG [[clang::fallthrough]];
#elif defined (__GNUC__) //Check after Cland, as Clang defines this too
#   define NF_COMPILER NF_COMPILER_GNUC
#   define NF_COMP_VER (((__GNUC__)*100)+(__GNUC_MINOR__*10)+__GNUC_PATCHLEVEL__)
#   define NF_THREADLOCAL __thread
#   define NF_STDCALL __attribute__((stdcall))
#   define NF_CDECL __attribute__((cdecl))
#   define NF_FALLTHROUHG __attribute__((fallthrough));
#elif defined (__INTEL_COMPILER)
#   define NF_COMPILER NF_COMPILER_INTEL
#   define NF_COMP_VER __INTEL_COMPILER
#   define NF_STDCALL __stdcall
#   define NF_CDECL __cdecl
#   define NF_FALLTHROUHG 

/**
 * NF_THREADLOCAL define is down below because Intel compiler defines it
 * differently based on platform
 */

 //Check after Clang end Intel, we could be building with either with Vs
#elif defined (_MSC_VER)
#   define NF_COMPILER NF_COMPILER_MSVC
#   define NF_COMP_VER _MSC_VER
#   define NF_THREADLOCAL __declspec
#   define NF_STDCALL __stdcall
#   define NF_CDECL __cdecl
#   define NF_FALLTHROUHG
#   undef __PRETTY_FUNCTION__
#   define __PRETTY_FUNCTION__ __FUNCSIG__
#else
//No know compiler found, send the error to the output (if any)
#   pragma error "No known compuler. "
#endif

/************************************************************************/
/**
 * See if we can use __forceinline or if we need to use __inline instead
 */
 /************************************************************************/
#if NF_COMPILER == NF_COMPILER_MSVC
# if NF_COMP_VER >= 1200
#   define FORCEINLINE __forceinline
#   ifndef RESTRICT 
#     define RESTRICT __restrict
#   endif
# endif
#elif defined (__MINGW32__)
# if !defined (FORCEINLINE)
#   define FORCEINLINE __inline
#   ifndef RESTRICT
#     define RESTRICT
#   endif
# endif
#else
# define FORCEINLINE __inline
# ifndef RESTRICT
#   define RESTRICT __restrict
# endif
#endif

/************************************************************************/
/**
 * Finds the current platform
 */
 /************************************************************************/
#if defined (__WIN32__) || defined (_WIN32)
# define NF_PLATFORM NF_PLATFORM_WIN32
#elif defined (__APPLE_CC__ )
# define NF_PLATFORM NF_PLATFORM_OSX
#elif defined (__ORBIS__)
# define NF_PLATFORM NF_PLATFORM_LINUX
#endif

/************************************************************************/
/**
 * Find the architecture type
 */
 /************************************************************************/
#if defined (__x86_x64__) || defined(_M_X64)    //If this is a x64 compile
# define NF_ARCH_TYPE NF_ARCHITECTURE_X86_64
#else
#  define NF_ARCH_TYPE NF_ARCHITECTURE_X86_32
#endif

/************************************************************************/
/**
 * Memory Alignment macros
 */
 /************************************************************************/
#if NF_COMPILER == NF_COMPILER_MSVC
# define MS_ALIGN(n) __declspec(align(n))
# ifndef GCC_PACK
#   define GCC_PACK(n)
# endif
# ifndef GCC_ALIGN
#   define GCC_ALIGN(n)
# endif
#elif (NF_COMPILER == NF_COMPILER_GNUC)
# define MS_ALIGN(n)
# define GCC_PACK(n)
# define GCC_ALIGN(n) __attribute__( (__aligned__(n)) )
#else
# define MS_ALIGN(n)
# define GCC_PACK(n) __attribute__((packed, aligned(n)))
# define GCC_ALIGN(n) __attribute__( (__aligned__(n)) )
#endif

/************************************************************************/
/**
 * For throw override (deprecated on c++11 but VS does not have handle )
 */
 /************************************************************************/
#if NF_COMPILER == NF_COMPILER_MSVC
# define _NOEXCEPT noexcept
#elif NF_COMPILER == NF_COMPILER_INTEL
# define _NOEXCEPT noexcept
#elif NF_COMPILER == NF_COMPILER_GNUC
# define _NOEXCEPT noexcept
#else
# define _NOEXCEPT
#endif

/************************************************************************/
/**
 * Library export specifics
 */
 /************************************************************************/
#if NF_PLATFORM == NF_PLATFORM_WIN32
# if NF_COMPILER == NF_COMPILER_MSVC
#   if defined( NF_STATIC_lib )
#     define NF_UTILITIES_EXPORT
#   else
#     if defined ( NF_UTILITIES_EXPORTS )
#       define NF_UTILITIES_EXPORT __declspec( dllexport )
#     else
#       define NF_UTILITIES_EXPORT __declspec( dllimport )
#     endif
#   endif
# else //Any other compiler
#   if defined( NF_STATIC_LIB )
#     define NF_UTILITIES_EXPORT
#   else
#     if defined( NF_UTILITIES_EXPORTS )
#       define NF_UTILITIES_EXPORT __attribute__ ((dllexport))
#     else
#       define NF_UTILITIES_EXPORT __attribute__ ((dllimport))
#     endif
#   endif
# endif
# define NF_UTILITIES_HIDDEN
#else
# define NF_UTILITIES_EXPORT __attribute__ ((visibility ("default")))
# define NF_UTILITIES_HIDDEN __attribute__ ((visibility ("hidden")))
#endif

 //DLL export plug ins
#if NF_PLATFORM == NF_PLATFORM_WIN32
# if NF_COMPILER == NF_COMPILER_MSVC
#   define NF_PLUGIN_EXPORT __declspec(dllexport)
# else
#   define NF_PLUGIN_EXPORT __attribute__ ((dllexport))
# endif
#else
#  define NF_PLUGIN_EXPORT __attribute__((visibility("default")))
#endif

/************************************************************************/
/**
 * Window specific Settings
 */
 /************************************************************************/
 //Win32
#if NF_PLATFORM == NF_PLATFORM_WIN32
# if defined(_DEBUG) || defined(DEBUG)
#   define NF_DEBUG_MODE 1
# else
#   define NF_DEBUG_MODE 0
# endif
# if NF_COMPILER == NF_COMPILER_INTEL
#   define NF_THREADLOCAL __declspec(thread)
# endif
#endif //NF_PLATFORM

/************************************************************************/
/**
 * LINUX-Apple specific Settings
 */
 /************************************************************************/

 //
#if NF_PLATFORM == NF_PLATFORM_LINUX || NF_PLATFORM == NF_PLATFORM_OSX

//if we're on debug mode
# if defined(_DEBUG) || defined(DEBUG)
#   define NF_DEBUG_MODE 1
# else
#   define NF_DEBUG_MODE 0
# endif
# if NF_COMPILER == NF_COMPILER_INTEL
#   define NF_THREADLOCAL thread
# endif
#endif //NF_PLATFORM

/************************************************************************/
/**
 * DEfinition of DEbug macros
 */
 /************************************************************************/
#if NF_DEBUG_MODE
# define NF_DEBUG_ONLY(x) x
# define NF_ASSERT(x) assert(x)
#else
# define NF_DEBUG_ONLY(x)
# define NF_ASSERT(x)
#endif

/************************************************************************/
/**
 * Disable some compiler warnings
 */
 /************************************************************************/

 //If we are compiling with VS
#if NF_COMPILER == NF_COMPILER_MSVC

# define _CRT_SECURE_NO_WARNINGS

# pragma warning(disable : 4201)

# pragma warning(disable : 4996)

# pragma warning(disable : 4251)

# pragma warning(disable : 4503)

#endif


// Normal assert but with a message param, to help explain the reason of the
// assertion
#define assertm(exp, msg) assert(((void)msg, exp))