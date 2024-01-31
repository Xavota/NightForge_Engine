#include <nfPrerequisitesUtilities.h>

#pragma warning(push)
#pragma warning ( disable: 4389 )
#include <gtest/gtest.h>
#pragma warning(pop)

#include <nfVector2.h>


#include "nfMath.h"

using nfEngineSDK::Math;

using nfEngineSDK::Vector2f;
using nfEngineSDK::Vector2i;
using nfEngineSDK::Vector2u;

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

TEST(nfUtilities, Vector2_Math) {
  ///
  /// Vector2f
  ///

  const Vector2f ct1 = Vector2f{ 2.0f, 3.0f };
  const Vector2f ct2 = Vector2f{ -1.0f, 4.0f };

  Vector2f vt1 = Vector2f{ 2.0f, -4.0f };
  Vector2f vt2 = Vector2f{ 3.0f, 1.0f };

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

  auto t = static_cast<Vector2u>(vt1);
  EXPECT_TRUE(static_cast<Vector2u>(vt1) == Vector2u(2, 4));
  EXPECT_TRUE(static_cast<Vector2u>(vt2) == Vector2u(3, 1));

  EXPECT_EQ(vt1.toString(2), "{ 2.00, -4.00 }");
  EXPECT_EQ(vt2.toString(2), "{ 3.00, 1.50 }");
}

int main(int argc, char** argv) {
  int stop;
  ::testing::InitGoogleTest(&argc, argv);
  RUN_ALL_TESTS();
  std::cin >> stop;
  return 0;
}