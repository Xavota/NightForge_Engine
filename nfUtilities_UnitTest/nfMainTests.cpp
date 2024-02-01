#include <nfPrerequisitesUtilities.h>

#pragma warning(push)
#pragma warning ( disable: 4389 )
#include <gtest/gtest.h>
#pragma warning(pop)

#include <nfVector2.h>
#include <nfVector3.h>
#include <nfVector4.h>


#include "nfMath.h"

using nfEngineSDK::Math;

using nfEngineSDK::Vector2f;
using nfEngineSDK::Vector2i;
using nfEngineSDK::Vector2u;

using nfEngineSDK::Vector3f;
using nfEngineSDK::Vector3i;
using nfEngineSDK::Vector3u;

using nfEngineSDK::Vector4f;
using nfEngineSDK::Vector4i;
using nfEngineSDK::Vector4u;

TEST(nfUtilities, Basic_Type_Sizes)
{
  EXPECT_EQ(sizeof(nfEngineSDK::int8), 1);
  EXPECT_EQ(sizeof(nfEngineSDK::int16), 2);
  EXPECT_EQ(sizeof(nfEngineSDK::int32), 4);
  EXPECT_EQ(sizeof(nfEngineSDK::int64), 8);

  EXPECT_EQ(sizeof(nfEngineSDK::uint8), 1);
  EXPECT_EQ(sizeof(nfEngineSDK::uint16), 2);
  EXPECT_EQ(sizeof(nfEngineSDK::uint32), 4);
  EXPECT_EQ(sizeof(nfEngineSDK::uint64), 8);

  EXPECT_EQ(sizeof(nfEngineSDK::WCHAR), 2);
  EXPECT_EQ(sizeof(nfEngineSDK::ANSICHAR), 1);
  EXPECT_EQ(sizeof(nfEngineSDK::UNICHAR), 2);
  EXPECT_EQ(sizeof(nfEngineSDK::unchar), 1);

  EXPECT_EQ(sizeof(nfEngineSDK::TYPE_OF_NULL), 4);
#if NF_ARCH_TYPE == NF_ARCHITECTURE_X86_32
  EXPECT_EQ(sizeof(nfEngineSDK::SIZE_T), 4);
#elif NF_ARCH_TYPE == NF_ARCHITECTURE_X86_64
  EXPECT_EQ(sizeof(nfEngineSDK::SIZE_T), 8);
#endif

  EXPECT_EQ(sizeof(nfEngineSDK::Byte), 1);
}

enum class eTestFlags {
  kNone = 0,
  k0001 = 1,
  k0010 = 2,
  k0100 = 4,
  k1000 = 8,

  k0101 = 5,
  k1100 = 12,
};

inline eTestFlags operator|(eTestFlags a, eTestFlags b)
{
  return static_cast<eTestFlags>(static_cast<int>(a) | static_cast<int>(b));
}
inline eTestFlags operator&(eTestFlags a, eTestFlags b)
{
  return static_cast<eTestFlags>(static_cast<int>(a) & static_cast<int>(b));
}

TEST(nfUtilities, Basic_Math)
{
  /// 
  /// Trigonometric
  /// 
  
  /// Basics
  EXPECT_TRUE(Math::checkEqual(Math::cos(1.0f), 0.540302f));
  EXPECT_TRUE(Math::checkEqual(Math::cosd(50.0f), 0.64278760f));
  EXPECT_TRUE(Math::checkEqual(Math::sin(0.5), 0.4794255386042030));
  EXPECT_TRUE(Math::checkEqual(Math::sind(30.0), 0.5));
  EXPECT_TRUE(Math::checkEqual(Math::tan(1.0L),
                               1.5574077246549022305069748074584L));
  EXPECT_TRUE(Math::checkEqual(Math::tand(45.0L), 1.0L));

  /// Complementaries
  EXPECT_TRUE(Math::checkEqual(Math::sec(1.0f), 1.850816f));
  EXPECT_TRUE(Math::checkEqual(Math::secd(50.0f), 1.555724f));
  EXPECT_TRUE(Math::checkEqual(Math::csc(0.5), 2.085829642933));
  EXPECT_TRUE(Math::checkEqual(Math::cscd(30.0), 2.0));
  EXPECT_TRUE(Math::checkEqual(Math::cot(1.0L),
                               0.642092615934330703006420L));
  EXPECT_TRUE(Math::checkEqual(Math::cotd(45.0L), 1.0L));

  /// Inverse basics
  EXPECT_TRUE(Math::checkEqual(Math::acos(-1.0f), Math::kPI));
  EXPECT_TRUE(Math::checkEqual(Math::acosd(0.5f), 60.0f));
  EXPECT_TRUE(Math::checkEqual(Math::asin(1.0), 1.5707963267948966));
  EXPECT_TRUE(Math::checkEqual(Math::asind(0.5), 30.0));
  EXPECT_TRUE(Math::checkEqual(Math::atan(2.0L),
                               1.10714871779409050301706546017853L));
  EXPECT_TRUE(Math::checkEqual(Math::atand(1.0L), 45.0L));
  
  ///// Inverse complementaries
  EXPECT_TRUE(Math::checkEqual(Math::asec(2.0f), 1.04719755f));
  EXPECT_TRUE(Math::checkEqual(Math::asecd(2.0f), 60.0f));
  EXPECT_TRUE(Math::checkEqual(Math::acsc(10.0), 0.1001674211615598));
  EXPECT_TRUE(Math::checkEqual(Math::acscd(2.0), 30.0));
  EXPECT_TRUE(Math::checkEqual(Math::acot(5.0L),
                               0.19739555984988075837004976519479L));
  EXPECT_TRUE(Math::checkEqual(Math::acotd(1.0L), 45.0L));

  /// Conversions
  EXPECT_TRUE(Math::checkEqual(Math::radToDeg(Math::kPI * 2.0f), 360.0f));
  EXPECT_TRUE(Math::checkEqual(Math::degToRad(45.0), Math::kPI / 4.0));


  ///
  /// Arithmetic
  ///

  EXPECT_TRUE(Math::checkEqual(Math::fmod(10.56f, 1.2f), 0.96f));
  EXPECT_TRUE(Math::checkEqual(Math::fmod(5.8f, 2.4f), 1.0f));

  EXPECT_TRUE(Math::checkEqual(Math::sqrt(2.0f), 1.41421356f));
  EXPECT_TRUE(Math::checkEqual(Math::sqrt(9.0f), 3.0f));

  EXPECT_TRUE(Math::checkEqual(Math::sqr(1.5f), 2.25f));
  EXPECT_TRUE(Math::checkEqual(Math::sqr(-2.0f), 4.0f));

  EXPECT_TRUE(Math::checkEqual(Math::pow(1.0f, 0.2f), 1.0f));
  EXPECT_TRUE(Math::checkEqual(Math::pow(4.6f, 0.2f), 1.35691163f));

  EXPECT_TRUE(Math::checkEqual(Math::log2(4.0f), 2.0f));
  EXPECT_TRUE(Math::checkEqual(Math::log2(5.6f), Math::log(5.6f, 2.0f)));

  EXPECT_TRUE(Math::checkEqual(Math::log10(1000.0f), 3.0f));
  EXPECT_TRUE(Math::checkEqual(Math::log10(151.8f), Math::log(151.8f, 10.0f)));

  EXPECT_TRUE(Math::checkEqual(Math::log(Math::kEULER), 1.0f));
  EXPECT_TRUE(Math::checkEqual(Math::log(100.0f, 10.0f), 2.0f));

  EXPECT_TRUE(Math::checkEqual(Math::exp(Math::kEULER), 15.15426224f));
  EXPECT_TRUE(Math::checkEqual(Math::exp(10.0f), 22026.46579481f));

  EXPECT_TRUE(Math::checkEqual(Math::exp2(Math::kEULER), 6.58088599f));
  EXPECT_TRUE(Math::checkEqual(Math::exp2(10.0f), 1024.0f));


  EXPECT_TRUE(Math::checkEqual(Math::round(Math::kEULER), 3.0f));
  EXPECT_TRUE(Math::checkEqual(Math::round(Math::kPI), 3.0f));

  EXPECT_TRUE(Math::checkEqual(Math::floor(Math::k2_PI), 6.0f));
  EXPECT_TRUE(Math::checkEqual(Math::floor(Math::k180_OVER_PI), 57.0f));

  EXPECT_TRUE(Math::checkEqual(Math::ceil(Math::kPI_OVER_180), 1.0f));
  EXPECT_TRUE(Math::checkEqual(Math::ceil(Math::kPI_OVER_2), 2.0f));


  EXPECT_TRUE(Math::checkEqual(Math::abs(2.5f), 2.5f));
  EXPECT_TRUE(Math::checkEqual(Math::abs(-7.6f), 7.6f));

  EXPECT_TRUE(Math::checkEqual(Math::sign(-10.5f), -1.0f));
  EXPECT_TRUE(Math::checkEqual(Math::sign(8.0f), 1.0f));

  EXPECT_TRUE(Math::checkEqual(Math::copysign(-9.5f, 3.0f), 9.5f));
  EXPECT_TRUE(Math::checkEqual(Math::copysign(8.0f, 10.0f), 8.0f));
  EXPECT_TRUE(Math::checkEqual(Math::copysign(7.0f, -5.0f), -7.0f));
  EXPECT_TRUE(Math::checkEqual(Math::copysign(-2.0f, -3.0f), -2.0f));

  EXPECT_TRUE(Math::checkEqual(Math::max(7.0f, -5.0f), 7.0f));
  EXPECT_TRUE(Math::checkEqual(Math::max(-3.0f, -2.0f), -2.0f));

  EXPECT_TRUE(Math::checkEqual(Math::min(7.0f, -5.0f), -5.0f));
  EXPECT_TRUE(Math::checkEqual(Math::min(-3.0f, -2.0f), -3.0f));

  EXPECT_TRUE(Math::checkEqual(Math::maxabs(7.0f, -5.0f), 7.0f));
  EXPECT_TRUE(Math::checkEqual(Math::maxabs(-3.0f, -2.0f), -3.0f));

  EXPECT_TRUE(Math::checkEqual(Math::minabs(7.0f, -5.0f), -5.0f));
  EXPECT_TRUE(Math::checkEqual(Math::minabs(-3.0f, -2.0f), -2.0f));


  EXPECT_FALSE(Math::hasFlag(5, 3));
  EXPECT_TRUE(Math::hasFlag(7, 3));

  auto tf = eTestFlags::k0010 | eTestFlags::k1000;
  EXPECT_TRUE(Math::hasFlag(tf, eTestFlags::k0010));
  EXPECT_TRUE(Math::hasFlag(tf, eTestFlags::k1000));
  EXPECT_FALSE(Math::hasFlag(tf, eTestFlags::k0100));

  tf = eTestFlags::k1100;
  EXPECT_TRUE(Math::hasFlag(tf, eTestFlags::k1000));
  EXPECT_TRUE(Math::hasFlag(tf, eTestFlags::k1100));
  EXPECT_TRUE(Math::hasFlag(tf, eTestFlags::k1100));
}


TEST(nfUtilities, Vector2f_Math) {
  /// Constructors
  const Vector2f ct1 = Vector2f{ 2.0f, 3.0f };
  const Vector2f ct2 = Vector2f{ -1.0f, 4.0f };

  Vector2f vt1 = Vector2f{ 2.0f, -4.0f };
  Vector2f vt2 = Vector2f{ 3.0f, 1.0f };

  EXPECT_TRUE(Math::checkEqual(ct1.x, 2.0f));
  EXPECT_TRUE(Math::checkEqual(ct1.y, 3.0f));

  EXPECT_TRUE(Math::checkEqual(ct2.x, -1.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.y, 4.0f));

  EXPECT_TRUE(Math::checkEqual(vt1.x, 2.0f));
  EXPECT_TRUE(Math::checkEqual(vt1.y, -4.0f));

  EXPECT_TRUE(Math::checkEqual(vt2.x, 3.0f));
  EXPECT_TRUE(Math::checkEqual(vt2.y, 1.0f));

  /// Const functions
  EXPECT_TRUE(Math::checkEqual(ct1.dot(ct2), 10.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.dot(ct1), 10.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.cross(ct2), 11.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.cross(ct1), -11.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 3.16227766f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 3.16227766f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 3.60555128f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 4.12310563f));

  EXPECT_TRUE(Math::checkEqual(ct1.getTheta(), 0.98279372f));
  EXPECT_TRUE(Math::checkEqual(ct2.getTheta(), 1.81577499f));

  EXPECT_TRUE(ct1.getNormalized() == Vector2f(0.55470019f, 0.83205029f));
  EXPECT_TRUE(ct2.getNormalized() == Vector2f(-0.24253562f, 0.97014250f));

  EXPECT_TRUE(ct1.getTruncate(2.0) == Vector2f(1.10940039f, 1.66410058f));
  EXPECT_TRUE(ct2.getTruncate(2.0) == Vector2f(-0.48507125f, 1.94028500f));

  EXPECT_TRUE(ct1 + ct2 == Vector2f(1.0f, 7.0f));
  EXPECT_TRUE(ct1 - ct2 == Vector2f(3.0f, -1.0f));
  EXPECT_TRUE(ct1 * ct2 == Vector2f(-2.0f, 12.0f));
  EXPECT_TRUE(ct1 / ct2 == Vector2f(-2.0f, 0.75f));
  EXPECT_TRUE(ct1 % ct2 == Vector2f(0.0f, 3.0f));

  EXPECT_TRUE(ct1 + 2.0f == Vector2f(4.0f, 5.0f));
  EXPECT_TRUE(ct1 - 2.0f == Vector2f(0.0f, 1.0f));
  EXPECT_TRUE(ct1 * 2.0f == Vector2f(4.0f, 6.0f));
  EXPECT_TRUE(ct1 / 2.0f == Vector2f(1.0f, 1.5f));
  EXPECT_TRUE(ct1 % 2.0f == Vector2f(0.0f, 1.0f));

  EXPECT_TRUE(2.0f + ct2 == Vector2f(1.0f, 6.0f));
  EXPECT_TRUE(2.0f - ct2 == Vector2f(3.0f, -2.0f));
  EXPECT_TRUE(2.0f * ct2 == Vector2f(-2.0f, 8.0f));
  EXPECT_TRUE(2.0f / ct2 == Vector2f(-2.0f, 0.5f));
  EXPECT_TRUE(2.0f % ct2 == Vector2f(0.0f, 2.0f));

  EXPECT_TRUE(-ct1 == Vector2f(-2.0f, -3.0f));
  EXPECT_TRUE(-ct2 == Vector2f(1.0f, -4.0f));

  EXPECT_TRUE(ct1 != Vector2f(-2.0f, -3.0f));
  EXPECT_TRUE(ct2 != Vector2f(1.0f, -4.0f));


  /// Set functions
  vt1.setTheta(Math::kPI / 3.0f);
  EXPECT_TRUE(vt1 == Vector2f(2.23606797f, 3.87298334f));
  vt2.setTheta(Math::kPI / 4.0f);
  EXPECT_TRUE(vt2 == Vector2f(2.23606798f, 2.23606798f));

  vt1.normalize();
  EXPECT_TRUE(vt1 == Vector2f(Math::cosd(60.0f), Math::sind(60.0f)));
  vt2.normalize();
  EXPECT_TRUE(vt2 == Vector2f(Math::cosd(45.0f), Math::sind(45.0f)));

  vt1.truncate(5.0f);
  EXPECT_TRUE(vt1 == Vector2f(Math::cosd(60.0f) * 5.0f, Math::sind(60.0f) * 5.0f));
  vt2.truncate(5.0f);
  EXPECT_TRUE(vt2 == Vector2f(Math::cosd(45.0f) * 5.0f, Math::sind(45.0f) * 5.0f));

  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector2f{ 2.0f, -4.0f };
  vt2 = Vector2f{ 3.0f, 1.5f };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector2f(5.0f, -2.5f));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector2f(2.0f, -4.0f));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector2f(6.0f, -6.0f));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector2f(2.0f, -4.0f));

  vt1 += 3.0f;
  EXPECT_TRUE(vt1 == Vector2f(5.0f, -1.0f));
  vt1 -= 3.0f;
  EXPECT_TRUE(vt1 == Vector2f(2.0f, -4.0f));
  vt2 *= 3.0f;
  EXPECT_TRUE(vt2 == Vector2f(9.0f, 4.5f));
  vt2 /= 3.0f;
  EXPECT_TRUE(vt2 == Vector2f(3.0f, 1.5f));


  /// Externals
  EXPECT_TRUE(static_cast<Vector2i>(vt1) == Vector2i(2, -4));
  EXPECT_TRUE(static_cast<Vector2i>(vt2) == Vector2i(3, 1));

  EXPECT_TRUE(static_cast<Vector2u>(vt1) == Vector2u(2u, 4u));
  EXPECT_TRUE(static_cast<Vector2u>(vt2) == Vector2u(3u, 1u));

  EXPECT_EQ(vt1.toString(2), "{ 2.00, -4.00 }");
  EXPECT_EQ(vt2.toString(2), "{ 3.00, 1.50 }");
}

TEST(nfUtilities, Vector2i_Math) {
  const Vector2i ct1 = Vector2i{ 2, 3 };
  const Vector2i ct2 = Vector2i{ -1, 4 };

  Vector2i vt1 = Vector2i{ 2, -4 };
  Vector2i vt2 = Vector2i{ 3, 1 };

  EXPECT_TRUE(ct1.x == 2);
  EXPECT_TRUE(ct1.y == 3);

  EXPECT_TRUE(ct2.x == -1);
  EXPECT_TRUE(ct2.y == 4);

  EXPECT_TRUE(vt1.x == 2);
  EXPECT_TRUE(vt1.y == -4);

  EXPECT_TRUE(vt2.x == 3);
  EXPECT_TRUE(vt2.y == 1);

  /// Const functions
  EXPECT_TRUE(ct1.dot(ct2) == 10);
  EXPECT_TRUE(ct2.dot(ct1) == 10);

  EXPECT_TRUE(ct1.cross(ct2) == 11);
  EXPECT_TRUE(ct2.cross(ct1) == -11);

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 3.16227766f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 3.16227766f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 3.60555128f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 4.12310563f));

  EXPECT_TRUE(ct1 + ct2 == Vector2i(1, 7));
  EXPECT_TRUE(ct1 - ct2 == Vector2i(3, -1));
  EXPECT_TRUE(ct1 * ct2 == Vector2i(-2, 12));
  EXPECT_TRUE(ct1 / ct2 == Vector2i(-2, 0));
  EXPECT_TRUE(ct1 % ct2 == Vector2i(0, 3));

  EXPECT_TRUE(ct1 + 2 == Vector2i(4, 5));
  EXPECT_TRUE(ct1 - 2 == Vector2i(0, 1));
  EXPECT_TRUE(ct1 * 2 == Vector2i(4, 6));
  EXPECT_TRUE(ct1 / 2 == Vector2i(1, 1));
  EXPECT_TRUE(ct1 % 2 == Vector2i(0, 1));

  EXPECT_TRUE(2 + ct2 == Vector2i(1, 6));
  EXPECT_TRUE(2 - ct2 == Vector2i(3, -2));
  EXPECT_TRUE(2 * ct2 == Vector2i(-2, 8));
  EXPECT_TRUE(2 / ct2 == Vector2i(-2, 0));
  EXPECT_TRUE(2 % ct2 == Vector2i(0, 2));

  EXPECT_TRUE(-ct1 == Vector2i(-2, -3));
  EXPECT_TRUE(-ct2 == Vector2i(1, -4));

  EXPECT_TRUE(ct1 != Vector2i(-2, -3));
  EXPECT_TRUE(ct2 != Vector2i(1, -4));


  /// Set functions
  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector2i{ 2, -4 };
  vt2 = Vector2i{ 3,  1 };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector2i(5, -3));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector2i(2, -4));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector2i(6, -4));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector2i(2, -4));

  vt1 += 3;
  EXPECT_TRUE(vt1 == Vector2i(5, -1));
  vt1 -= 3;
  EXPECT_TRUE(vt1 == Vector2i(2, -4));
  vt2 *= 3;
  EXPECT_TRUE(vt2 == Vector2i(9, 3));
  vt2 /= 3;
  EXPECT_TRUE(vt2 == Vector2i(3, 1));


  /// Externals
  EXPECT_TRUE(static_cast<Vector2f>(vt1) == Vector2f(2.0f, -4.0f));
  EXPECT_TRUE(static_cast<Vector2f>(vt2) == Vector2f(3.0f, 1.0f));

  EXPECT_TRUE(static_cast<Vector2u>(vt1) == Vector2u(2u, 4u));
  EXPECT_TRUE(static_cast<Vector2u>(vt2) == Vector2u(3u, 1u));

  EXPECT_EQ(vt1.toString(), "{ 2, -4 }");
  EXPECT_EQ(vt2.toString(), "{ 3, 1 }");
}

TEST(nfUtilities, Vector2u_Math) {
  const Vector2u ct1 = Vector2u{ 2u, 3u };
  const Vector2u ct2 = Vector2u{ 1u, 4u };

  Vector2u vt1 = Vector2u{ 2u, 4u };
  Vector2u vt2 = Vector2u{ 3u, 1u };

  EXPECT_TRUE(ct1.x == 2u);
  EXPECT_TRUE(ct1.y == 3u);

  EXPECT_TRUE(ct2.x == 1u);
  EXPECT_TRUE(ct2.y == 4u);

  EXPECT_TRUE(vt1.x == 2u);
  EXPECT_TRUE(vt1.y == 4u);

  EXPECT_TRUE(vt2.x == 3u);
  EXPECT_TRUE(vt2.y == 1u);

  /// Const functions
  EXPECT_TRUE(ct1.dot(ct2) == 14u);
  EXPECT_TRUE(ct2.dot(ct1) == 14u);

  EXPECT_TRUE(ct1.cross(ct2) == 5);
  EXPECT_TRUE(ct2.cross(ct1) == -5);

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 1.41421356f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 1.41421356f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 3.60555128f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 4.12310563f));

  EXPECT_TRUE(ct1 + ct2 == Vector2u(3u, 7u));
  EXPECT_TRUE(ct1 - ct2 == Vector2u(1u, 4294967295u)); // -1 in unsigned int32 overflowed
  EXPECT_TRUE(ct1 * ct2 == Vector2u(2u, 12u));
  EXPECT_TRUE(ct1 / ct2 == Vector2u(2u, 0u));
  EXPECT_TRUE(ct1 % ct2 == Vector2u(0u, 3u));

  EXPECT_TRUE(ct1 + 2 == Vector2u(4u, 5u));
  EXPECT_TRUE(ct1 - 2 == Vector2u(0u, 1u));
  EXPECT_TRUE(ct1 * 2 == Vector2u(4u, 6u));
  EXPECT_TRUE(ct1 / 2 == Vector2u(1u, 1u));
  EXPECT_TRUE(ct1 % 2 == Vector2u(0u, 1u));

  EXPECT_TRUE(2 + ct2 == Vector2u(3u, 6u));
  EXPECT_TRUE(2 - ct2 == Vector2u(1u, 4294967294u)); // -2 in unsigned int32 overflowed
  EXPECT_TRUE(2 * ct2 == Vector2u(2u, 8u));
  EXPECT_TRUE(2 / ct2 == Vector2u(2u, 0u));
  EXPECT_TRUE(2 % ct2 == Vector2u(0u, 2u));

  EXPECT_TRUE(ct1 != Vector2u(1u, 1u));
  EXPECT_TRUE(ct2 != Vector2u(2u, 2u));


  /// Set functions
  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector2u{ 2u, 4u };
  vt2 = Vector2u{ 3u, 1u };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector2u(5u, 5u));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector2u(2u, 4u));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector2u(6u, 4u));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector2u(2u, 4u));

  vt1 += 3;
  EXPECT_TRUE(vt1 == Vector2u(5u, 7u));
  vt1 -= 3;
  EXPECT_TRUE(vt1 == Vector2u(2u, 4u));
  vt2 *= 3;
  EXPECT_TRUE(vt2 == Vector2u(9u, 3u));
  vt2 /= 3;
  EXPECT_TRUE(vt2 == Vector2u(3u, 1u));


  /// Externals
  EXPECT_TRUE(static_cast<Vector2f>(vt1) == Vector2f(2.0f, 4.0f));
  EXPECT_TRUE(static_cast<Vector2f>(vt2) == Vector2f(3.0f, 1.0f));

  EXPECT_TRUE(static_cast<Vector2i>(vt1) == Vector2i(2, 4));
  EXPECT_TRUE(static_cast<Vector2i>(vt2) == Vector2i(3, 1));

  EXPECT_EQ(vt1.toString(), "{ 2, 4 }");
  EXPECT_EQ(vt2.toString(), "{ 3, 1 }");
}


TEST(nfUtilities, Vector3f_Math) {
  /// Constructors
  const Vector3f ct1 = Vector3f{ 2.0f, 3.0f, 2.0f };
  const Vector3f ct2 = Vector3f{ -1.0f, 4.0f, 1.0f };

  Vector3f vt1 = Vector3f{ 2.0f, -4.0f, 2.0f };
  Vector3f vt2 = Vector3f{ 3.0f, 1.0f, -3.0f };

  EXPECT_TRUE(Math::checkEqual(ct1.x, 2.0f));
  EXPECT_TRUE(Math::checkEqual(ct1.y, 3.0f));
  EXPECT_TRUE(Math::checkEqual(ct1.z, 2.0f));

  EXPECT_TRUE(Math::checkEqual(ct2.x, -1.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.y, 4.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.z, 1.0f));

  EXPECT_TRUE(Math::checkEqual(vt1.x, 2.0f));
  EXPECT_TRUE(Math::checkEqual(vt1.y, -4.0f));
  EXPECT_TRUE(Math::checkEqual(vt1.z, 2.0f));

  EXPECT_TRUE(Math::checkEqual(vt2.x, 3.0f));
  EXPECT_TRUE(Math::checkEqual(vt2.y, 1.0f));
  EXPECT_TRUE(Math::checkEqual(vt2.z, -3.0f));

  /// Const functions
  EXPECT_TRUE(Math::checkEqual(ct1.dot(ct2), 12.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.dot(ct1), 12.0f));

  EXPECT_TRUE(ct1.cross(ct2) == Vector3f(-5.0f, -4.0f, 11.0f));
  EXPECT_TRUE(ct2.cross(ct1) == -Vector3f(-5.0f, -4.0f, 11.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 3.31662479f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 3.31662479f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 4.12310562f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 4.24264069f));

  EXPECT_TRUE(Math::checkEqual(ct1.getTheta(), Math::degToRad(45.0f)));
  EXPECT_TRUE(Math::checkEqual(ct2.getTheta(), Math::degToRad(135.0f)));

  EXPECT_TRUE(Math::checkEqual(ct1.getPhi(), 0.75596941f));
  EXPECT_TRUE(Math::checkEqual(ct2.getPhi(), 0.33983691f));

  EXPECT_TRUE(Math::checkEqual(ct1.getRadiusCylinder(), 2.82842712f));
  EXPECT_TRUE(Math::checkEqual(ct2.getRadiusCylinder(), 1.41421356f));

  EXPECT_TRUE(ct1.getNormalized() ==
              Vector3f(0.48507125f, 0.72760688f, 0.48507125f));
  EXPECT_TRUE(ct2.getNormalized() ==
              Vector3f(-0.23570226f, 0.94280904f, 0.23570226f));

  EXPECT_TRUE(ct1.getTruncate(2.0) ==
              Vector3f(0.97014250f, 1.45521375f, 0.97014250f));
  EXPECT_TRUE(ct2.getTruncate(2.0) ==
              Vector3f(-0.47140452f, 1.88561801f, 0.47140452f));

  EXPECT_TRUE(ct1 + ct2 == Vector3f(1.0f, 7.0f, 3.0f));
  EXPECT_TRUE(ct1 - ct2 == Vector3f(3.0f, -1.0f, 1.0f));
  EXPECT_TRUE(ct1 * ct2 == Vector3f(-2.0f, 12.0f, 2.0f));
  EXPECT_TRUE(ct1 / ct2 == Vector3f(-2.0f, 0.75f, 2.0f));
  EXPECT_TRUE(ct1 % ct2 == Vector3f(0.0f, 3.0f, 0.0f));

  EXPECT_TRUE(ct1 + 2.0f == Vector3f(4.0f, 5.0f, 4.0f));
  EXPECT_TRUE(ct1 - 2.0f == Vector3f(0.0f, 1.0f, 0.0f));
  EXPECT_TRUE(ct1 * 2.0f == Vector3f(4.0f, 6.0f, 4.0f));
  EXPECT_TRUE(ct1 / 2.0f == Vector3f(1.0f, 1.5f, 1.0f));
  EXPECT_TRUE(ct1 % 2.0f == Vector3f(0.0f, 1.0f, 0.0f));

  EXPECT_TRUE(2.0f + ct2 == Vector3f(1.0f, 6.0f, 3.0f));
  EXPECT_TRUE(2.0f - ct2 == Vector3f(3.0f, -2.0f, 1.0f));
  EXPECT_TRUE(2.0f * ct2 == Vector3f(-2.0f, 8.0f, 2.0f));
  EXPECT_TRUE(2.0f / ct2 == Vector3f(-2.0f, 0.5f, 2.0f));
  EXPECT_TRUE(2.0f % ct2 == Vector3f(0.0f, 2.0f, 0.0f));

  EXPECT_TRUE(-ct1 == Vector3f(-2.0f, -3.0f, -2.0f));
  EXPECT_TRUE(-ct2 == Vector3f(1.0f, -4.0f, -1.0f));

  EXPECT_TRUE(ct1 != Vector3f(-2.0f, -3.0f, -2.0f));
  EXPECT_TRUE(ct2 != Vector3f(1.0f, -4.0f, -1.0f));


  /// Set functions
  vt1.setPhi(Math::degToRad(45.0f));
  EXPECT_TRUE(vt1 == Vector3f(Math::sind(45.0f) * Math::cosd(45.0f),
                              Math::cosd(45.0f),
                              Math::sind(45.0f) * Math::sind(45.0f)) * 
                              vt1.getMagnitude());
  vt2.setPhi(Math::degToRad(30.0f));
  EXPECT_TRUE(vt2 == Vector3f(Math::sind(30.0f) * Math::cosd(315.0f),
                              Math::cosd(30.0f),
                              Math::sind(30.0f) * Math::sind(315.0f)) * 
                              vt2.getMagnitude());

  vt1.setTheta(Math::degToRad(60.0f));
  EXPECT_TRUE(vt1 == Vector3f(Math::sind(45.0f) * Math::cosd(60.0f),
                              Math::cosd(45.0f),
                              Math::sind(45.0f) * Math::sind(60.0f)) * 
                              vt1.getMagnitude());
  vt2.setTheta(Math::degToRad(45.0f));
  EXPECT_TRUE(vt2 == Vector3f(Math::sind(30.0f) * Math::cosd(45.0f),
                              Math::cosd(30.0f),
                              Math::sind(30.0f) * Math::sind(45.0f)) * 
                              vt2.getMagnitude());

  vt1.normalize();
  EXPECT_TRUE(vt1 == Vector3f(Math::sind(45.0f) * Math::cosd(60.0f),
                              Math::cosd(45.0f),
                              Math::sind(45.0f) * Math::sind(60.0f)));
  vt2.normalize();
  EXPECT_TRUE(vt2 == Vector3f(Math::sind(30.0f) * Math::cosd(45.0f),
                              Math::cosd(30.0f),
                              Math::sind(30.0f) * Math::sind(45.0f)));

  vt1.truncate(5.0f);
  EXPECT_TRUE(vt1 == Vector3f(Math::sind(45.0f) * Math::cosd(60.0f),
                              Math::cosd(45.0f),
                              Math::sind(45.0f) * Math::sind(60.0f)) * 5.0f);
  vt2.truncate(5.0f);
  EXPECT_TRUE(vt2 == Vector3f(Math::sind(30.0f) * Math::cosd(45.0f),
                              Math::cosd(30.0f),
                              Math::sind(30.0f) * Math::sind(45.0f)) * 5.0f);

  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector3f{ 2.0f, -4.5f, 2.0f };
  vt2 = Vector3f{ 3.0f, 1.0f, -3.5f };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector3f(5.0f, -3.5f, -1.5f));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector3f(2.0f, -4.5f, 2.0f));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector3f(6.0f, -4.5f, -7.0f));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector3f(2.0f, -4.5f, 2.0f));

  vt1 += 3.0f;
  EXPECT_TRUE(vt1 == Vector3f(5.0f, -1.5f, 5.0f));
  vt1 -= 3.0f;
  EXPECT_TRUE(vt1 == Vector3f(2.0f, -4.5f, 2.0f));
  vt2 *= 3.0f;
  EXPECT_TRUE(vt2 == Vector3f(9.0f, 3.0f, -10.5f));
  vt2 /= 3.0f;
  EXPECT_TRUE(vt2 == Vector3f(3.0f, 1.0f, -3.5f));


  /// Externals
  EXPECT_TRUE(static_cast<Vector3i>(vt1) == Vector3i(2, -4, 2));
  EXPECT_TRUE(static_cast<Vector3i>(vt2) == Vector3i(3, 1, -3));

  EXPECT_TRUE(static_cast<Vector3u>(vt1) == Vector3u(2u, 4u, 2u));
  EXPECT_TRUE(static_cast<Vector3u>(vt2) == Vector3u(3u, 1u, 3u));

  EXPECT_EQ(vt1.toString(2), "{ 2.00, -4.50, 2.00 }");
  EXPECT_EQ(vt2.toString(2), "{ 3.00, 1.00, -3.50 }");
}

TEST(nfUtilities, Vector3i_Math) {
  /// Constructors
  const Vector3i ct1 = Vector3i{ 2, 3, 2 };
  const Vector3i ct2 = Vector3i{ -1, 4, 1 };

  Vector3i vt1 = Vector3i{ 2, -4, 2 };
  Vector3i vt2 = Vector3i{ 3, 1, -3 };

  EXPECT_TRUE(ct1.x == 2);
  EXPECT_TRUE(ct1.y == 3);
  EXPECT_TRUE(ct1.z == 2);

  EXPECT_TRUE(ct2.x == -1);
  EXPECT_TRUE(ct2.y == 4);
  EXPECT_TRUE(ct2.z == 1);

  EXPECT_TRUE(vt1.x == 2);
  EXPECT_TRUE(vt1.y == -4);
  EXPECT_TRUE(vt1.z == 2);

  EXPECT_TRUE(vt2.x == 3);
  EXPECT_TRUE(vt2.y == 1);
  EXPECT_TRUE(vt2.z == -3);

  /// Const functions
  EXPECT_TRUE(ct1.dot(ct2) == 12);
  EXPECT_TRUE(ct2.dot(ct1) == 12);

  EXPECT_TRUE(ct1.cross(ct2) == Vector3i(-5, -4, 11));
  EXPECT_TRUE(ct2.cross(ct1) == -Vector3i(-5, -4, 11));

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 3.31662479f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 3.31662479f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 4.12310562f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 4.24264069f));

  EXPECT_TRUE(ct1 + ct2 == Vector3i(1, 7, 3));
  EXPECT_TRUE(ct1 - ct2 == Vector3i(3, -1, 1));
  EXPECT_TRUE(ct1 * ct2 == Vector3i(-2, 12, 2));
  EXPECT_TRUE(ct1 / ct2 == Vector3i(-2, 0, 2));
  EXPECT_TRUE(ct1 % ct2 == Vector3i(0, 3, 0));

  EXPECT_TRUE(ct1 + 2 == Vector3i(4, 5, 4));
  EXPECT_TRUE(ct1 - 2 == Vector3i(0, 1, 0));
  EXPECT_TRUE(ct1 * 2 == Vector3i(4, 6, 4));
  EXPECT_TRUE(ct1 / 2 == Vector3i(1, 1, 1));
  EXPECT_TRUE(ct1 % 2 == Vector3i(0, 1, 0));

  EXPECT_TRUE(2 + ct2 == Vector3i( 1,  6, 3));
  EXPECT_TRUE(2 - ct2 == Vector3i( 3, -2, 1));
  EXPECT_TRUE(2 * ct2 == Vector3i(-2,  8, 2));
  EXPECT_TRUE(2 / ct2 == Vector3i(-2,  0, 2));
  EXPECT_TRUE(2 % ct2 == Vector3i( 0,  2, 0));

  EXPECT_TRUE(-ct1 == Vector3i(-2, -3, -2));
  EXPECT_TRUE(-ct2 == Vector3i(1, -4, -1));

  EXPECT_TRUE(ct1 != Vector3i(-2, -3, -2));
  EXPECT_TRUE(ct2 != Vector3i(1, -4, -1));


  /// Set functions
  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector3i{ 2, -4, 2 };
  vt2 = Vector3i{ 3, 1, -3 };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector3i(5, -3, -1));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector3i(2, -4, 2));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector3i(6, -4, -6));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector3i(2, -4, 2));

  vt1 += 3;
  EXPECT_TRUE(vt1 == Vector3i(5, -1, 5));
  vt1 -= 3;
  EXPECT_TRUE(vt1 == Vector3i(2, -4, 2));
  vt2 *= 3;
  EXPECT_TRUE(vt2 == Vector3i(9, 3, -9));
  vt2 /= 3;
  EXPECT_TRUE(vt2 == Vector3i(3, 1, -3));


  /// Externals
  EXPECT_TRUE(static_cast<Vector3f>(vt1) == Vector3f(2.0f, -4.0f, 2.0f));
  EXPECT_TRUE(static_cast<Vector3f>(vt2) == Vector3f(3.0f, 1.0f, -3.0f));

  EXPECT_TRUE(static_cast<Vector3u>(vt1) == Vector3u(2u, 4u, 2u));
  EXPECT_TRUE(static_cast<Vector3u>(vt2) == Vector3u(3u, 1u, 3u));

  EXPECT_EQ(vt1.toString(), "{ 2, -4, 2 }");
  EXPECT_EQ(vt2.toString(), "{ 3, 1, -3 }");
}

TEST(nfUtilities, Vector3u_Math) {
  /// Constructors
  const Vector3u ct1 = Vector3u{ 2u, 3u, 2u };
  const Vector3u ct2 = Vector3u{ 1u, 4u, 1u };

  Vector3u vt1 = Vector3u{ 2u, 4u, 2u };
  Vector3u vt2 = Vector3u{ 3u, 1u, 3u };

  EXPECT_TRUE(ct1.x == 2u);
  EXPECT_TRUE(ct1.y == 3u);
  EXPECT_TRUE(ct1.z == 2u);

  EXPECT_TRUE(ct2.x == 1u);
  EXPECT_TRUE(ct2.y == 4u);
  EXPECT_TRUE(ct2.z == 1u);

  EXPECT_TRUE(vt1.x == 2u);
  EXPECT_TRUE(vt1.y == 4u);
  EXPECT_TRUE(vt1.z == 2u);

  EXPECT_TRUE(vt2.x == 3u);
  EXPECT_TRUE(vt2.y == 1u);
  EXPECT_TRUE(vt2.z == 3u);

  /// Const functions
  EXPECT_TRUE(ct1.dot(ct2) == 16u);
  EXPECT_TRUE(ct2.dot(ct1) == 16u);

  EXPECT_TRUE(ct1.cross(ct2) == Vector3i(-5, 0, 5));
  EXPECT_TRUE(ct2.cross(ct1) == -Vector3i(-5, 0, 5));

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 1.73205081f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 1.73205081f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 4.12310562f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 4.24264069f));

  EXPECT_TRUE(ct1 + ct2 == Vector3u(3u, 7u, 3u));
  EXPECT_TRUE(ct1 - ct2 == Vector3u(1u, 4294967295u, 1u)); // -1 in unsigned int32 overflowed
  EXPECT_TRUE(ct1 * ct2 == Vector3u(2u, 12u, 2u));
  EXPECT_TRUE(ct1 / ct2 == Vector3u(2u, 0u, 2u));
  EXPECT_TRUE(ct1 % ct2 == Vector3u(0u, 3u, 0u));

  EXPECT_TRUE(ct1 + 2u == Vector3u(4u, 5u, 4u));
  EXPECT_TRUE(ct1 - 2u == Vector3u(0u, 1u, 0u));
  EXPECT_TRUE(ct1 * 2u == Vector3u(4u, 6u, 4u));
  EXPECT_TRUE(ct1 / 2u == Vector3u(1u, 1u, 1u));
  EXPECT_TRUE(ct1 % 2u == Vector3u(0u, 1u, 0u));

  EXPECT_TRUE(2u + ct2 == Vector3u(3u, 6u, 3u));
  EXPECT_TRUE(2u - ct2 == Vector3u(1u, 4294967294u, 1u)); // -2 in unsigned int32 overflowed
  EXPECT_TRUE(2u * ct2 == Vector3u(2u, 8u, 2u));
  EXPECT_TRUE(2u / ct2 == Vector3u(2u, 0u, 2u));
  EXPECT_TRUE(2u % ct2 == Vector3u(0u, 2u, 0u));

  EXPECT_TRUE(ct1 != Vector3u(1u, 1u, 1u));
  EXPECT_TRUE(ct2 != Vector3u(2u, 2u, 2u));


  /// Set functions
  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector3u{ 2u, 4u, 2u };
  vt2 = Vector3u{ 3u, 1u, 3u };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector3u(5u, 5u, 5u));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector3u(2u, 4u, 2u));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector3u(6u, 4u, 6u));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector3u(2u, 4u, 2u));

  vt1 += 3;
  EXPECT_TRUE(vt1 == Vector3u(5u, 7u, 5u));
  vt1 -= 3;
  EXPECT_TRUE(vt1 == Vector3u(2u, 4u, 2u));
  vt2 *= 3;
  EXPECT_TRUE(vt2 == Vector3u(9u, 3u, 9u));
  vt2 /= 3;
  EXPECT_TRUE(vt2 == Vector3u(3u, 1u, 3u));


  /// Externals
  EXPECT_TRUE(static_cast<Vector3f>(ct1) == Vector3f(2.0f, 3.0f, 2.0f));
  EXPECT_TRUE(static_cast<Vector3f>(ct2) == Vector3f(1.0f, 4.0f, 1.0f));

  EXPECT_TRUE(static_cast<Vector3u>(vt1) == Vector3u(2u, 4u, 2u));
  EXPECT_TRUE(static_cast<Vector3u>(vt2) == Vector3u(3u, 1u, 3u));

  EXPECT_EQ(vt1.toString(), "{ 2, 4, 2 }");
  EXPECT_EQ(vt2.toString(), "{ 3, 1, 3 }");
}


TEST(nfUtilities, Vector4f_Math) {
  /// Constructors
  const Vector4f ct1 = Vector4f{ 2.0f, 3.0f, 2.0f, 0.0f };
  const Vector4f ct2 = Vector4f{ -1.0f, 4.0f, 1.0f, -3.0f };

  Vector4f vt1 = Vector4f{ 1.0f, -2.0f, 3.0f, 4.0f };
  Vector4f vt2 = Vector4f{ 4.0f, 3.0f, 2.0f, -1.0f };

  EXPECT_TRUE(Math::checkEqual(ct1.x, 2.0f));
  EXPECT_TRUE(Math::checkEqual(ct1.y, 3.0f));
  EXPECT_TRUE(Math::checkEqual(ct1.z, 2.0f));
  EXPECT_TRUE(Math::checkEqual(ct1.w, 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct2.x, -1.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.y, 4.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.z, 1.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.w, -3.0f));

  EXPECT_TRUE(Math::checkEqual(vt1.x, 1.0f));
  EXPECT_TRUE(Math::checkEqual(vt1.y, -2.0f));
  EXPECT_TRUE(Math::checkEqual(vt1.z, 3.0f));
  EXPECT_TRUE(Math::checkEqual(vt1.w, 4.0f));

  EXPECT_TRUE(Math::checkEqual(vt2.x, 4.0f));
  EXPECT_TRUE(Math::checkEqual(vt2.y, 3.0f));
  EXPECT_TRUE(Math::checkEqual(vt2.z, 2.0f));
  EXPECT_TRUE(Math::checkEqual(vt2.w, -1.0f));

  /// Const functions
  EXPECT_TRUE(Math::checkEqual(ct1.dot(ct2), 12.0f));
  EXPECT_TRUE(Math::checkEqual(ct2.dot(ct1), 12.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 4.47213595f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 4.47213595f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 4.12310562f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 5.19615242f));

  EXPECT_TRUE(ct1.getNormalized() ==
              Vector4f(0.48507125f, 0.72760688f, 0.48507125f, 0.0f));
  EXPECT_TRUE(ct2.getNormalized() ==
              Vector4f(-0.19245009f, 0.76980036f, 0.19245009f, -0.57735027f));

  EXPECT_TRUE(ct1.getTruncate(2.0) ==
              Vector4f(0.48507125f, 0.72760688f, 0.48507125f, 0.0f) * 2.0f);
  EXPECT_TRUE(ct2.getTruncate(2.0) ==
             Vector4f(-0.19245009f, 0.76980036f, 0.19245009f, -0.57735027f) * 2.0f);

  EXPECT_TRUE(ct1 + ct2 == Vector4f(1.0f, 7.0f, 3.0f, -3.0f));
  EXPECT_TRUE(ct1 - ct2 == Vector4f(3.0f, -1.0f, 1.0f, 3.0f));
  EXPECT_TRUE(ct1 * ct2 == Vector4f(-2.0f, 12.0f, 2.0f, 0.0f));
  EXPECT_TRUE(ct1 / ct2 == Vector4f(-2.0f, 0.75f, 2.0f, 0.0f));
  EXPECT_TRUE(ct1 % ct2 == Vector4f(0.0f, 3.0f, 0.0f, 0.0f));

  EXPECT_TRUE(ct1 + 2.0f == Vector4f(4.0f, 5.0f, 4.0f, 2.0f));
  EXPECT_TRUE(ct1 - 2.0f == Vector4f(0.0f, 1.0f, 0.0f, -2.0f));
  EXPECT_TRUE(ct1 * 2.0f == Vector4f(4.0f, 6.0f, 4.0f, 0.0f));
  EXPECT_TRUE(ct1 / 2.0f == Vector4f(1.0f, 1.5f, 1.0f, 0.0f));
  EXPECT_TRUE(ct1 % 2.0f == Vector4f(0.0f, 1.0f, 0.0f, 0.0f));

  EXPECT_TRUE(2.0f + ct2 == Vector4f(1.0f, 6.0f, 3.0f, -1.0f));
  EXPECT_TRUE(2.0f - ct2 == Vector4f(3.0f, -2.0f, 1.0f, 5.0f));
  EXPECT_TRUE(2.0f * ct2 == Vector4f(-2.0f, 8.0f, 2.0f, -6.0f));
  EXPECT_TRUE(2.0f / ct2 == Vector4f(-2.0f, 0.5f, 2.0f, -0.66666666f));
  EXPECT_TRUE(2.0f % ct2 == Vector4f(0.0f, 2.0f, 0.0f, 2.0f));

  EXPECT_TRUE(-ct1 == Vector4f(-2.0f, -3.0f, -2.0f, 0.0f));
  EXPECT_TRUE(-ct2 == Vector4f(1.0f, -4.0f, -1.0f, 3.0f));

  EXPECT_TRUE(ct1 != Vector4f(-2.0f, -3.0f, -2.0f, 0.0f));
  EXPECT_TRUE(ct2 != Vector4f(1.0f, -4.0f, -1.0f, 3.0f));


  /// Set functions
  vt1.normalize();
  EXPECT_TRUE(vt1 ==
              Vector4f(0.18257419f, -0.36514837f, 0.54772256f, 0.73029674f));
  vt2.normalize();
  EXPECT_TRUE(vt2 ==
              Vector4f(0.73029674f, 0.54772256f, 0.36514837f, -0.18257419f));

  vt1.truncate(5.0f);
  EXPECT_TRUE(vt1 ==
              Vector4f(0.18257419f, -0.36514837f, 0.54772256f, 0.73029674f) * 5.0f);
  vt2.truncate(5.0f);
  EXPECT_TRUE(vt2 ==
              Vector4f(0.73029674f, 0.54772256f, 0.36514837f, -0.18257419f) * 5.0f);

  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector4f{ -1.5f, 2.0f, 3.5f, 4.0f };
  vt2 = Vector4f{ 4.0f, -3.0f, 2.5f, 1.0f };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector4f(2.5f, -1.0f, 6.0f, 5.0f));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector4f(-1.5f, 2.0f, 3.5f, 4.0f));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector4f(-6.0f, -6.0f, 8.75f, 4.0f));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector4f(-1.5f, 2.0f, 3.5f, 4.0f));

  vt1 += 3.0f;
  EXPECT_TRUE(vt1 == Vector4f(1.5f, 5.0f, 6.5f, 7.0f));
  vt1 -= 3.0f;
  EXPECT_TRUE(vt1 == Vector4f(-1.5f, 2.0f, 3.5f, 4.0f));
  vt2 *= 3.0f;
  EXPECT_TRUE(vt2 == Vector4f(12.0f, -9.0f, 7.5f, 3.0f));
  vt2 /= 3.0f;
  EXPECT_TRUE(vt2 == Vector4f(4.0f, -3.0f, 2.5f, 1.0f));


  /// Externals
  EXPECT_TRUE(static_cast<Vector4i>(vt1) == Vector4i(-1, 2, 3, 4));
  EXPECT_TRUE(static_cast<Vector4i>(vt2) == Vector4i(4, -3, 2, 1));

  EXPECT_TRUE(static_cast<Vector4u>(vt1) == Vector4u(1u, 2u, 3u, 4u));
  EXPECT_TRUE(static_cast<Vector4u>(vt2) == Vector4u(4u, 3u, 2u, 1u));

  EXPECT_EQ(vt1.toString(2), "{ -1.50, 2.00, 3.50, 4.00 }");
  EXPECT_EQ(vt2.toString(2), "{ 4.00, -3.00, 2.50, 1.00 }");
}

TEST(nfUtilities, Vector4i_Math) {
  /// Constructors
  const Vector4i ct1 = Vector4i{ 2, 3, 2, 0 };
  const Vector4i ct2 = Vector4i{ -1, 4, 1, -3 };

  Vector4i vt1 = Vector4i{ 1, -2, 3, 4 };
  Vector4i vt2 = Vector4i{ 4, 3, 2, -1 };

  EXPECT_TRUE(ct1.x ==  2);
  EXPECT_TRUE(ct1.y ==  3);
  EXPECT_TRUE(ct1.z ==  2);
  EXPECT_TRUE(ct1.w ==  0);

  EXPECT_TRUE(ct2.x == -1);
  EXPECT_TRUE(ct2.y ==  4);
  EXPECT_TRUE(ct2.z ==  1);
  EXPECT_TRUE(ct2.w == -3);

  EXPECT_TRUE(vt1.x ==  1);
  EXPECT_TRUE(vt1.y == -2);
  EXPECT_TRUE(vt1.z ==  3);
  EXPECT_TRUE(vt1.w ==  4);

  EXPECT_TRUE(vt2.x ==  4);
  EXPECT_TRUE(vt2.y ==  3);
  EXPECT_TRUE(vt2.z ==  2);
  EXPECT_TRUE(vt2.w == -1);

  /// Const functions
  EXPECT_TRUE(ct1.dot(ct2) == 12);
  EXPECT_TRUE(ct2.dot(ct1) == 12);

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 4.47213595f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 4.47213595f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 4.12310562f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 5.19615242f));

  EXPECT_TRUE(ct1 + ct2 == Vector4i(1, 7, 3, -3));
  EXPECT_TRUE(ct1 - ct2 == Vector4i(3, -1, 1, 3));
  EXPECT_TRUE(ct1 * ct2 == Vector4i(-2, 12, 2, 0));
  EXPECT_TRUE(ct1 / ct2 == Vector4i(-2, 0, 2, 0));
  EXPECT_TRUE(ct1 % ct2 == Vector4i(0, 3, 0, 0));

  EXPECT_TRUE(ct1 + 2 == Vector4i(4, 5, 4, 2));
  EXPECT_TRUE(ct1 - 2 == Vector4i(0, 1, 0, -2));
  EXPECT_TRUE(ct1 * 2 == Vector4i(4, 6, 4, 0));
  EXPECT_TRUE(ct1 / 2 == Vector4i(1, 1, 1, 0));
  EXPECT_TRUE(ct1 % 2 == Vector4i(0, 1, 0, 0));

  EXPECT_TRUE(2 + ct2 == Vector4i(1, 6, 3, -1));
  EXPECT_TRUE(2 - ct2 == Vector4i(3, -2, 1, 5));
  EXPECT_TRUE(2 * ct2 == Vector4i(-2, 8, 2, -6));
  EXPECT_TRUE(2 / ct2 == Vector4i(-2, 0, 2, 0));
  EXPECT_TRUE(2 % ct2 == Vector4i(0, 2, 0, 2));

  EXPECT_TRUE(-ct1 == Vector4i(-2, -3, -2, 0));
  EXPECT_TRUE(-ct2 == Vector4i(1, -4, -1, 3));

  EXPECT_TRUE(ct1 != Vector4i(-2, -3, -2, 0));
  EXPECT_TRUE(ct2 != Vector4i(1, -4, -1, 3));


  /// Set functions
  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector4i{ -1,  2, 3, 4 };
  vt2 = Vector4i{  4, -3, 2, 1 };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector4i(3, -1, 5, 5));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector4i(-1, 2, 3, 4));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector4i(-4, -6, 6, 4));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector4i(-1, 2, 3, 4));

  vt1 += 3;
  EXPECT_TRUE(vt1 == Vector4i(2, 5, 6, 7));
  vt1 -= 3;
  EXPECT_TRUE(vt1 == Vector4i(-1, 2, 3, 4));
  vt2 *= 3;
  EXPECT_TRUE(vt2 == Vector4i(12, -9, 6, 3));
  vt2 /= 3;
  EXPECT_TRUE(vt2 == Vector4i(4, -3, 2, 1));


  /// Externals
  EXPECT_TRUE(static_cast<Vector4f>(vt1) == Vector4i(-1.0f, 2.0f, 3.0f, 4.0f));
  EXPECT_TRUE(static_cast<Vector4f>(vt2) == Vector4i(4.0f, -3.0f, 2.0f, 1.0f));

  EXPECT_TRUE(static_cast<Vector4u>(vt1) == Vector4u(1u, 2u, 3u, 4u));
  EXPECT_TRUE(static_cast<Vector4u>(vt2) == Vector4u(4u, 3u, 2u, 1u));

  EXPECT_EQ(vt1.toString(), "{ -1, 2, 3, 4 }");
  EXPECT_EQ(vt2.toString(), "{ 4, -3, 2, 1 }");
}

TEST(nfUtilities, Vector4u_Math) {
  /// Constructors
  const Vector4u ct1 = Vector4u{ 2u, 3u, 2u, 0u };
  const Vector4u ct2 = Vector4u{ 1u, 4u, 1u, 3u };

  Vector4u vt1 = Vector4u{ 1u, 2u, 3u, 4u };
  Vector4u vt2 = Vector4u{ 4u, 3u, 2u, 1u };

  EXPECT_TRUE(ct1.x == 2u);
  EXPECT_TRUE(ct1.y == 3u);
  EXPECT_TRUE(ct1.z == 2u);
  EXPECT_TRUE(ct1.w == 0u);

  EXPECT_TRUE(ct2.x == 1u);
  EXPECT_TRUE(ct2.y == 4u);
  EXPECT_TRUE(ct2.z == 1u);
  EXPECT_TRUE(ct2.w == 3u);

  EXPECT_TRUE(vt1.x == 1u);
  EXPECT_TRUE(vt1.y == 2u);
  EXPECT_TRUE(vt1.z == 3u);
  EXPECT_TRUE(vt1.w == 4u);

  EXPECT_TRUE(vt2.x == 4u);
  EXPECT_TRUE(vt2.y == 3u);
  EXPECT_TRUE(vt2.z == 2u);
  EXPECT_TRUE(vt2.w == 1u);

  /// Const functions
  EXPECT_TRUE(ct1.dot(ct2) == 16u);
  EXPECT_TRUE(ct2.dot(ct1) == 16u);

  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct2), 3.46410162f));
  EXPECT_TRUE(Math::checkEqual(ct2.getDistance(ct1), 3.46410162f));
  EXPECT_TRUE(Math::checkEqual(ct1.getDistance(ct1), 0.0f));

  EXPECT_TRUE(Math::checkEqual(ct1.getMagnitude(), 4.12310562f));
  EXPECT_TRUE(Math::checkEqual(ct2.getMagnitude(), 5.19615242f));

  //const Vector4u ct1 = Vector4u{ 2u, 3u, 2u, 0u };
  //const Vector4u ct2 = Vector4u{ 1u, 4u, 1u, 3u };
  EXPECT_TRUE(ct1 + ct2 == Vector4u(3u, 7u, 3u, 3u));
  EXPECT_TRUE(ct1 - ct2 == Vector4u(1u, 4294967295u, 1u, 4294967293u));
  EXPECT_TRUE(ct1 * ct2 == Vector4u(2u, 12u, 2u, 0u));
  EXPECT_TRUE(ct1 / ct2 == Vector4u(2u, 0u, 2u, 0u));
  EXPECT_TRUE(ct1 % ct2 == Vector4u(0u, 3u, 0u, 0u));

  EXPECT_TRUE(ct1 + 2 == Vector4u(4u, 5u, 4u, 2u));
  EXPECT_TRUE(ct1 - 2 == Vector4u(0u, 1u, 0u, 4294967294u));
  EXPECT_TRUE(ct1 * 2 == Vector4u(4u, 6u, 4u, 0u));
  EXPECT_TRUE(ct1 / 2 == Vector4u(1u, 1u, 1u, 0u));
  EXPECT_TRUE(ct1 % 2 == Vector4u(0u, 1u, 0u, 0u));

  EXPECT_TRUE(2 + ct2 == Vector4u(3u, 6u, 3u, 5u));
  EXPECT_TRUE(2 - ct2 == Vector4u(1u, 4294967294u, 1u, 4294967295u));
  EXPECT_TRUE(2 * ct2 == Vector4u(2u, 8u, 2u, 6u));
  EXPECT_TRUE(2 / ct2 == Vector4u(2u, 0u, 2u, 0u));
  EXPECT_TRUE(2 % ct2 == Vector4u(0u, 2u, 0u, 2u));

  EXPECT_TRUE(ct1 != Vector4u(1u, 1u, 1u, 1u));
  EXPECT_TRUE(ct2 != Vector4u(2u, 2u, 2u, 2u));


  /// Set functions
  vt1 = vt2;
  EXPECT_TRUE(vt1 == vt2);

  vt1 = Vector4u{ 1u, 2u, 3u, 4u };
  vt2 = Vector4u{ 4u, 3u, 2u, 1u };

  vt1 += vt2;
  EXPECT_TRUE(vt1 == Vector4u(5u, 5u, 5u, 5u));
  vt1 -= vt2;
  EXPECT_TRUE(vt1 == Vector4u(1u, 2u, 3u, 4u));
  vt1 *= vt2;
  EXPECT_TRUE(vt1 == Vector4u(4u, 6u, 6u, 4u));
  vt1 /= vt2;
  EXPECT_TRUE(vt1 == Vector4u(1u, 2u, 3u, 4u));

  vt1 += 3;
  EXPECT_TRUE(vt1 == Vector4u(4u, 5u, 6u, 7u));
  vt1 -= 3;
  EXPECT_TRUE(vt1 == Vector4u(1u, 2u, 3u, 4u));
  vt2 *= 3;
  EXPECT_TRUE(vt2 == Vector4u(12u, 9u, 6u, 3u));
  vt2 /= 3;
  EXPECT_TRUE(vt2 == Vector4u(4u, 3u, 2u, 1u));


  /// Externals
  EXPECT_TRUE(static_cast<Vector4f>(vt1) == Vector4u(1.0f, 2.0f, 3.0f, 4.0f));
  EXPECT_TRUE(static_cast<Vector4f>(vt2) == Vector4u(4.0f, 3.0f, 2.0f, 1.0f));

  EXPECT_TRUE(static_cast<Vector4i>(vt1) == Vector4i(1, 2, 3, 4));
  EXPECT_TRUE(static_cast<Vector4i>(vt2) == Vector4i(4, 3, 2, 1));

  EXPECT_EQ(vt1.toString(), "{ 1, 2, 3, 4 }");
  EXPECT_EQ(vt2.toString(), "{ 4, 3, 2, 1 }");
}

int main(int argc, char** argv) {
  int stop;
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  std::cin >> stop;
  return 0;
}