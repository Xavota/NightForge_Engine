#include "nfVector3.h"

#include "nfVector2.h"

//#include "eeStringUtilities.h"

//#include "eeMatrix3.h"
#include "nfMath.h"

namespace nfEngineSDK
{
  const Vector3f Vector3f::kZERO = Vector3f(0.0f, 0.0f, 0.0f);
  const Vector3f Vector3f::kFORWARD = Vector3f(0.0f, 0.0f, 1.0f);
  const Vector3f Vector3f::kRIGHT = Vector3f(1.0f, 0.0f, 0.0f);
  const Vector3f Vector3f::kUP = Vector3f(0.0f, 1.0f, 0.0f);
  
  const Vector3i Vector3i::kZERO = Vector3i(0, 0, 0);
  const Vector3i Vector3i::kFORWARD = Vector3i(0, 0, 1);
  const Vector3i Vector3i::kRIGHT = Vector3i(1, 0, 0);
  const Vector3i Vector3i::kUP = Vector3i(0, 1, 0);
  
  const Vector3u Vector3u::kZERO = Vector3u(0u, 0u, 0u);
  const Vector3u Vector3u::kFORWARD = Vector3u(0u, 0u, 1u);
  const Vector3u Vector3u::kRIGHT = Vector3u(1u, 0u, 0u);
  const Vector3u Vector3u::kUP = Vector3u(0u, 1u, 0u);


  //////////////////////
  //     Vector3f     //
  //////////////////////

  // TODO: Finish this
  Vector3f::Vector3f(const Vector2f& _vec)
  {
  }

  float
  Vector3f::dot(const Vector3f& other) const
  {
    return this->x * other.x + this->y * other.y + this->z * other.z;
  }
  Vector3f
  Vector3f::cross(const Vector3f& other) const
  {
    Vector3f r(this->y * other.z - this->z * other.y,
               this->z * other.x - this->x * other.z,
               this->x * other.y - this->y * other.x);
    return r;
  }

  float
  Vector3f::getDistance(const Vector3f& other) const
  {
    Vector3f d = other - *this;
    return Math::sqrt(d.x * d.x + d.y * d.y + d.z * d.z);
  }

  float
  Vector3f::getMagnitude() const
  {
    return Math::sqrt(this->x * this->x + this->y * this->y + this->z * this->z);
  }
  // TODO: Finish this
  float
  Vector3f::getTheta() const
  {
    return 0.0f;
  }
  void
  Vector3f::setTheta(float theta)
  {
  }
  float
  Vector3f::getPhi() const
  {
    return 0.0f;
  }
  void
  Vector3f::setPhi(float theta)
  {
  }

  Vector3f
  Vector3f::getNormalize() const
  {
    return *this / this->getMagnitude();
  }
  Vector3f
  Vector3f::normalize()
  {
    *this = *this / this->getMagnitude();
    return *this;
  }
  Vector3f
  Vector3f::getTruncate(float newSize) const
  {
    assertm(newSize >= 0.0f, "Size can't be negative for a Vector");
    Vector3f n = this->getNormalize();
    return n * newSize;
  }
  Vector3f
  Vector3f::truncate(float newSize)
  {
    assertm(newSize >= 0.0f, "Size can't be negative for a Vector");
    Vector3f n = this->getNormalize();
    *this = n * newSize;
    return *this;
  }
  
  Vector3f
  Vector3f::operator+(const Vector3f& other) const
  {
    return Vector3f(this->x + other.x, this->y + other.y, this->z + other.z);
  }
  Vector3f
  Vector3f::operator-(const Vector3f& other) const
  {
    return Vector3f(this->x - other.x, this->y - other.y, this->z - other.z);
  }
  Vector3f
  Vector3f::operator*(const Vector3f& other) const
  {
    return Vector3f(this->x * other.x, this->y * other.y, this->z * other.z);
  }
  Vector3f
  Vector3f::operator/(const Vector3f& other) const
  {
    return Vector3f(this->x / other.x, this->y / other.y, this->z / other.z);
  }
  Vector3f
  Vector3f::operator%(const Vector3f& other) const
  {
    return Vector3f(Math::fmod(this->x, other.x),
                    Math::fmod(this->y, other.y),
                    Math::fmod(this->z, other.z));
  }
  Vector3f
  Vector3f::operator+(float other) const
  {
    return Vector3f(this->x + other, this->y + other, this->z + other);
  }
  Vector3f
  Vector3f::operator-(float other) const
  {
    return Vector3f(this->x - other, this->y - other, this->z - other);
  }
  Vector3f
  Vector3f::operator*(float other) const
  {
    return Vector3f(this->x * other, this->y * other, this->z * other);
  }
  Vector3f
  Vector3f::operator/(float other) const
  {
    return Vector3f(this->x / other, this->y / other, this->z / other);
  }
  Vector3f
  Vector3f::operator%(float other) const
  {
    return Vector3f(Math::fmod(this->x, other),
                    Math::fmod(this->y, other),
                    Math::fmod(this->z, other));
  }

  // TODO: Finish this
  NF_UTILITIES_EXPORT
  Vector3f operator+(const float& other, const Vector3f& otherV)
  {
    return Vector3f();
  }
  NF_UTILITIES_EXPORT
  Vector3f operator-(const float& other, const Vector3f& otherV)
  {
    return Vector3f();
  }
  NF_UTILITIES_EXPORT
  Vector3f operator*(const float& other, const Vector3f& otherV)
  {
    return Vector3f();
  }
  NF_UTILITIES_EXPORT
  Vector3f operator/(const float& other, const Vector3f& otherV)
  {
    return Vector3f();
  }
  NF_UTILITIES_EXPORT
  Vector3f operator%(const float& other, const Vector3f& otherV)
  {
    return Vector3f();
  }

  Vector3f Vector3f::operator-() const
  {
    return Vector3f(-x, -y, -z);
  }

  Vector3f&
  Vector3f::operator=(const Vector3f& other)
  {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
  }

  Vector3f&
  Vector3f::operator+=(const Vector3f& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector3f&
  Vector3f::operator-=(const Vector3f& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector3f&
  Vector3f::operator*=(const Vector3f& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector3f&
  Vector3f::operator/=(const Vector3f& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector3f&
  Vector3f::operator%=(const Vector3f& other)
  {
    *this = *this % other;
    return *this;
  }

  Vector3f&
  Vector3f::operator+=(float other)
  {
    *this = *this + other;
    return *this;
  }
  Vector3f&
  Vector3f::operator-=(float other)
  {
    *this = *this - other;
    return *this;
  }
  Vector3f&
  Vector3f::operator*=(float other)
  {
    *this = *this * other;
    return *this;
  }
  Vector3f&
  Vector3f::operator/=(float other)
  {
    *this = *this / other;
    return *this;
  }
  Vector3f&
  Vector3f::operator%=(float other)
  {
    *this = *this % other;
    return *this;
  }

  bool
  Vector3f::operator==(const Vector3f& other) const
  {
    return (Math::checkEqual(this->x, other.x))
        && (Math::checkEqual(this->y, other.y))
        && (Math::checkEqual(this->z, other.z));
  }
  bool
  Vector3f::operator!=(const Vector3f& other) const
  {
    return !(*this == other);
  }

  // TODO: Finish this
  Vector3f::operator Vector3i() const
  {
  }

  Vector3f::operator Vector3u() const
  {
  }

  //////////////////////
  //     Vector3i     //
  //////////////////////

  // TODO: Finish this
  Vector3i::Vector3i(const Vector2i& _vec)
  {
  }

  int32
  Vector3i::dot(const Vector3i& other) const
  {
    return this->x * other.x + this->y * other.y + this->z * other.z;
  }
  Vector3i
  Vector3i::cross(const Vector3i& other) const
  {
    Vector3i r(this->y * other.z - this->z * other.y,
               this->z * other.x - this->x * other.z,
               this->x * other.y - this->y * other.x);
    return r;
  }

  float
  Vector3i::getDistance(const Vector3i& other) const
  {
    Vector3i d = other - *this;
    return Math::sqrt(static_cast<float>(d.x * d.x)
                    + static_cast<float>(d.y * d.y)
                    + static_cast<float>(d.z * d.z));
  }
  float
  Vector3i::getMagnitud() const
  {
    return Math::sqrt(static_cast<float>(this->x * this->x)
                    + static_cast<float>(this->y * this->y)
                    + static_cast<float>(this->z * this->z));
  }
  
  Vector3i
  Vector3i::operator+(const Vector3i& other) const
  {
    return Vector3i(this->x + other.x, this->y + other.y, this->z + other.z);
  }
  Vector3i
  Vector3i::operator-(const Vector3i & other) const
  {
    return Vector3i(this->x - other.x, this->y - other.y, this->z - other.z);
  }
  Vector3i
  Vector3i::operator*(const Vector3i & other) const
  {
    return Vector3i(this->x * other.x, this->y * other.y, this->z * other.z);
  }
  Vector3i
  Vector3i::operator/(const Vector3i & other) const
  {
    return Vector3i(this->x / other.x, this->y / other.y, this->z / other.z);
  }
  Vector3i
  Vector3i::operator%(const Vector3i & other) const
  {
    return Vector3i(this->x % other.x, this->y % other.y, this->z % other.z);
  }

  Vector3i
  Vector3i::operator+(int32 other) const
  {
    return Vector3i(this->x + other, this->y + other, this->z + other);
  }
  Vector3i
  Vector3i::operator-(int32 other) const
  {
    return Vector3i(this->x - other, this->y - other, this->z - other);
  }
  Vector3i
  Vector3i::operator*(int32 other) const
  {
    return Vector3i(this->x * other, this->y * other, this->z * other);
  }
  Vector3i
  Vector3i::operator/(int32 other) const
  {
    return Vector3i(this->x / other, this->y / other, this->z / other);
  }
  Vector3i
  Vector3i::operator%(int32 other) const
  {
    return Vector3i(this->x % other, this->y % other, this->z % other);
  }

  // TODO: Finish this
  NF_UTILITIES_EXPORT Vector3i
  operator+(const float& other, const Vector3i& otherV)
  {
    return Vector3i();
  }
  NF_UTILITIES_EXPORT Vector3i
  operator-(const float& other, const Vector3i& otherV)
  {
    return Vector3i();
  }
  NF_UTILITIES_EXPORT Vector3i
  operator*(const float& other, const Vector3i& otherV)
  {
    return Vector3i();
  }
  NF_UTILITIES_EXPORT Vector3i
  operator/(const float& other, const Vector3i& otherV)
  {
    return Vector3i();
  }
  NF_UTILITIES_EXPORT Vector3i
  operator%(const float& other, const Vector3i& otherV)
  {
    return Vector3i();
  }

  Vector3i Vector3i::operator-() const
  {
    return Vector3i(-x, -y, -z);
  }

  Vector3i&
  Vector3i::operator=(const Vector3i& other)
  {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
  }

  Vector3i&
  Vector3i::operator+=(const Vector3i& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector3i&
  Vector3i::operator-=(const Vector3i& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector3i&
  Vector3i::operator*=(const Vector3i& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector3i&
  Vector3i::operator/=(const Vector3i& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector3i&
  Vector3i::operator%=(const Vector3i& other)
  {
    *this = *this % other;
    return *this;
  }

  Vector3i&
  Vector3i::operator+=(int32 other)
  {
    *this = *this + other;
    return *this;
  }
  Vector3i&
  Vector3i::operator-=(int32 other)
  {
    *this = *this - other;
    return *this;
  }
  Vector3i&
  Vector3i::operator*=(int32 other)
  {
    *this = *this * other;
    return *this;
  }
  Vector3i&
  Vector3i::operator/=(int32 other)
  {
    *this = *this / other;
    return *this;
  }
  Vector3i&
  Vector3i::operator%=(int32 other)
  {
    *this = *this % other;
    return *this;
  }

  bool
  Vector3i::operator==(const Vector3i& other) const
  {
    return this->x == other.x && this->y == other.y && this->z == other.z;
  }
  bool
  Vector3i::operator!=(const Vector3i& other) const
  {
    return !(*this == other);
  }

  // TODO: Finish this
  Vector3i::operator Vector3f() const
  {
  }

  Vector3i::operator Vector3u() const
  {
  }

  //////////////////////
  //     Vector3u     //
  //////////////////////

  // TODO: Finish this
  Vector3u::Vector3u(const Vector2u& _vec)
  {
  }

  // TODO: Finish this
  uint32
  Vector3u::dot(const Vector3u& other) const
  {
    return this->x * other.x + this->y * other.y + this->z * other.z;
  }
  Vector3u
  Vector3u::cross(const Vector3u& other) const
  {
    Vector3u r(this->y * other.z - this->z * other.y,
               this->z * other.x - this->x * other.z,
               this->x * other.y - this->y * other.x);
    return r;
  }

  float
  Vector3u::getDistance(const Vector3u& other) const
  {
    Vector3u d = other - *this;
    return Math::sqrt(static_cast<float>(d.x * d.x)
                    + static_cast<float>(d.y * d.y)
                    + static_cast<float>(d.z * d.z));
  }
  float
  Vector3u::getMagnitud() const
  {
    return Math::sqrt(static_cast<float>(this->x * this->x)
                    + static_cast<float>(this->y * this->y)
                    + static_cast<float>(this->z * this->z));
  }
  
  Vector3u
  Vector3u::operator+(const Vector3u& other) const
  {
    return Vector3u(this->x + other.x, this->y + other.y, this->z + other.z);
  }
  Vector3u
  Vector3u::operator-(const Vector3u& other) const
  {
    return Vector3u(this->x - other.x, this->y - other.y, this->z - other.z);
  }
  Vector3u
  Vector3u::operator*(const Vector3u& other) const
  {
    return Vector3u(this->x * other.x, this->y * other.y, this->z * other.z);
  }
  Vector3u
  Vector3u::operator/(const Vector3u& other) const
  {
    return Vector3u(this->x / other.x, this->y / other.y, this->z / other.z);
  }
  Vector3u
  Vector3u::operator%(const Vector3u& other) const
  {
    return Vector3u(this->x % other.x, this->y % other.y, this->z % other.z);
  }

  Vector3u
  Vector3u::operator+(uint32 other) const
  {
    return Vector3u(this->x + other, this->y + other, this->z + other);
  }
  Vector3u
  Vector3u::operator-(uint32 other) const
  {
    return Vector3u(this->x - other, this->y - other, this->z - other);
  }
  Vector3u
  Vector3u::operator*(uint32 other) const
  {
    return Vector3u(this->x * other, this->y * other, this->z * other);
  }
  Vector3u
  Vector3u::operator/(uint32 other) const
  {
    return Vector3u(this->x / other, this->y / other, this->z / other);
  }
  Vector3u
  Vector3u::operator%(uint32 other) const
  {
    return Vector3u(this->x % other, this->y % other, this->z % other);
  }

  // TODO: Finish this
  NF_UTILITIES_EXPORT Vector3u
  operator+(const float& other, const Vector3u& otherV)
  {
    return Vector3u();
  }
  NF_UTILITIES_EXPORT Vector3u
  operator-(const float& other, const Vector3u& otherV)
  {
    return Vector3u();
  }
  NF_UTILITIES_EXPORT Vector3u
  operator*(const float& other, const Vector3u& otherV)
  {
    return Vector3u();
  }
  NF_UTILITIES_EXPORT Vector3u
  operator/(const float& other, const Vector3u& otherV)
  {
    return Vector3u();
  }
  NF_UTILITIES_EXPORT Vector3u
  operator%(const float& other, const Vector3u& otherV)
  {
    return Vector3u();
  }

  Vector3u&
  Vector3u::operator=(const Vector3u& other)
  {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    return *this;
  }

  Vector3u&
  Vector3u::operator+=(const Vector3u& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector3u&
  Vector3u::operator-=(const Vector3u& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector3u&
  Vector3u::operator*=(const Vector3u& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector3u&
  Vector3u::operator/=(const Vector3u& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector3u&
  Vector3u::operator%=(const Vector3u& other)
  {
    *this = *this % other;
    return *this;
  }

  Vector3u&
  Vector3u::operator+=(uint32 other)
  {
    *this = *this + other;
    return *this;
  }
  Vector3u&
  Vector3u::operator-=(uint32 other)
  {
    *this = *this - other;
    return *this;
  }
  Vector3u&
  Vector3u::operator*=(uint32 other)
  {
    *this = *this * other;
    return *this;
  }
  Vector3u&
  Vector3u::operator/=(uint32 other)
  {
    *this = *this / other;
    return *this;
  }
  Vector3u&
  Vector3u::operator%=(uint32 other)
  {
    *this = *this % other;
    return *this;
  }

  bool
  Vector3u::operator==(const Vector3u& other) const
  {
    return this->x == other.x && this->y == other.y && this->z == other.z;
  }
  bool
  Vector3u::operator!=(const Vector3u& other) const
  {
    return !(*this == other);
  }

  // TODO: Finish this
  Vector3u::operator Vector3f() const
  {
  }
  Vector3u::operator Vector3i() const
  {
  }
}