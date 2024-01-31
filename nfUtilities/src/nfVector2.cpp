#include "nfVector2.h"
#include "nfMath.h"

namespace nfEngineSDK
{
  const Vector2f Vector2f::kZERO = Vector2f(0.0f, 0.0f);
  const Vector2f Vector2f::kRIGHT = Vector2f(1.0f, 0.0f);
  const Vector2f Vector2f::kUP = Vector2f(0.0f, 1.0f);
  const Vector2i Vector2i::kZERO = Vector2i(0, 0);
  const Vector2i Vector2i::kRIGHT = Vector2i(1, 0);
  const Vector2i Vector2i::kUP = Vector2i(0, 1);
  const Vector2u Vector2u::kZERO = Vector2u(0u, 0u);
  const Vector2u Vector2u::kRIGHT = Vector2u(1u, 0u);
  const Vector2u Vector2u::kUP = Vector2u(0u, 1u);
  
  
  //////////////////////
  //     Vector2f     //
  //////////////////////
  
  float
  Vector2f::dot(const Vector2f& other) const
  {
    return this->x * other.x + this->y * other.y;
  }
  float
  Vector2f::cross(const Vector2f& other) const
  {
    return this->x * other.y - this->y * other.x;
  }

  float
  Vector2f::getDistance(const Vector2f& other) const
  {
    Vector2f d = other - *this;
    return Math::sqrt(d.x * d.x + d.y * d.y);
  }
  
  float
  Vector2f::getMagnitude() const
  {
    return Math::sqrt(this->x * this->x + this->y * this->y);
  }
  float
  Vector2f::getTheta() const
  {
    return Math::atan2(this->y, this->x);
  }
  void
  Vector2f::setTheta(float theta)
  {
    float m = this->getMagnitude();
    *this = Vector2f(Math::cos(theta), Math::sin(theta)) * m;
  }
  Vector2f
  Vector2f::getNormalized() const
  {
    return *this / this->getMagnitude();
  }
  Vector2f
  Vector2f::normalize()
  {
    *this /= this->getMagnitude();
    return *this;
  }
  Vector2f
  Vector2f::getTruncate(float newSize) const
  {
    assertm(newSize >= 0.0f, "Size can't be negative for a Vector");
    Vector2f n = this->getNormalized();
    return n * newSize;
  }
  Vector2f
  Vector2f::truncate(float newSize)
  {
    assertm(newSize >= 0.0f, "Size can't be negative for a Vector");
    Vector2f n = this->getNormalized();
    *this = n * newSize;
    return *this;
  }
  
  Vector2f
  Vector2f::operator+(const Vector2f& other) const
  {
    return Vector2f(this->x + other.x, this->y + other.y);
  }
  Vector2f
  Vector2f::operator-(const Vector2f& other) const
  {
    return Vector2f(this->x - other.x, this->y - other.y);
  }
  Vector2f
  Vector2f::operator*(const Vector2f& other) const
  {
    return Vector2f(this->x * other.x, this->y * other.y);
  }
  Vector2f
  Vector2f::operator/(const Vector2f& other) const
  {
    return Vector2f(this->x / other.x, this->y / other.y);
  }
  Vector2f
  Vector2f::operator%(const Vector2f& other) const
  {
    return Vector2f(Math::fmod(this->x, other.x),
                    Math::fmod(this->y, other.y));
  }
  
  Vector2f
  Vector2f::operator+(float other) const
  {
    return Vector2f(this->x + other, this->y + other);
  }
  Vector2f
  Vector2f::operator-(float other) const
  {
    return Vector2f(this->x - other, this->y - other);
  }
  Vector2f
  Vector2f::operator*(float other) const
  {
    return Vector2f(this->x * other, this->y * other);
  }
  Vector2f
  Vector2f::operator/(float other) const
  {
    return Vector2f(this->x / other, this->y / other);
  }
  Vector2f
  Vector2f::operator%(float other) const
  {
    return Vector2f(Math::fmod(this->x, other),
                    Math::fmod(this->y, other));
  }
  
  NF_UTILITIES_EXPORT Vector2f
  operator+(const float& other, const Vector2f& otherV)
  {
    return Vector2f(other + otherV.x, other + otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2f
  operator-(const float& other, const Vector2f& otherV)
  {
    return Vector2f(other - otherV.x, other - otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2f
  operator*(const float& other, const Vector2f& otherV)
  {
    return Vector2f(other * otherV.x, other * otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2f
  operator/(const float& other, const Vector2f& otherV)
  {
    return Vector2f(other / otherV.x, other / otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2f
  operator%(const float& other, const Vector2f& otherV)
  {
    return Vector2f(Math::fmod(other, otherV.x),
                    Math::fmod(other, otherV.y));
  }
  
  Vector2f
  Vector2f::operator-() const
  {
    return Vector2f(-x, -y);
  }
  
  Vector2f&
  Vector2f::operator=(const Vector2f& other)
  {
    this->x = other.x;
    this->y = other.y;
    return *this;
  }
  
  Vector2f&
  Vector2f::operator+=(const Vector2f& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector2f&
  Vector2f::operator-=(const Vector2f& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector2f&
  Vector2f::operator*=(const Vector2f& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector2f&
  Vector2f::operator/=(const Vector2f& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector2f&
  Vector2f::operator%=(const Vector2f& other)
  {
    *this = *this % other;
    return *this;
  }
  
  Vector2f&
  Vector2f::operator+=(float other)
  {
    *this = *this + other;
    return *this;
  }
  Vector2f&
  Vector2f::operator-=(float other)
  {
    *this = *this - other;
    return *this;
  }
  Vector2f&
  Vector2f::operator*=(float other)
  {
    *this = *this * other;
    return *this;
  }
  Vector2f&
  Vector2f::operator/=(float other)
  {
    *this = *this / other;
    return *this;
  }
  Vector2f&
  Vector2f::operator%=(float other)
  {
    *this = *this % other;
    return *this;
  }
  
  bool
  Vector2f::operator==(const Vector2f& other) const
  {
    return Math::checkEqual(this->x, other.x)
        && Math::checkEqual(this->y, other.y);
  }
  bool
  Vector2f::operator!=(const Vector2f& other) const
  {
    return !(*this == other);
  }

  Vector2f::operator Vector2i() const {
    return Vector2i(static_cast<int32>(x), static_cast<int32>(y));
  }
  Vector2f::operator Vector2u() const {
    return Vector2u(static_cast<uint32>(Math::abs(x)),
                    static_cast<uint32>(Math::abs(y)));
  }
  
  //////////////////////
  //     Vector2i     //
  //////////////////////
  
  int
  Vector2i::dot(const Vector2i& other) const
  {
    return this->x * other.x + this->y * other.y;
  }
  int
  Vector2i::cross(const Vector2i& other) const
  {
    return this->x * other.y - this->y * other.x;
  }

  float
  Vector2i::getDistance(const Vector2i& other) const
  {
    Vector2i d = other - *this;
    return Math::sqrt(static_cast<float>(d.x * d.x)
                    + static_cast<float>(d.y * d.y));
  }
  float
  Vector2i::getMagnitude() const
  {
    return Math::sqrt(static_cast<float>(this->x * this->x)
                    + static_cast<float>(this->y * this->y));
  }

  Vector2i
  Vector2i::operator+(const Vector2i& other) const
  {
    return Vector2i(this->x + other.x, this->y + other.y);
  }
  Vector2i
  Vector2i::operator-(const Vector2i& other) const
  {
    return Vector2i(this->x - other.x, this->y - other.y);
  }
  Vector2i
  Vector2i::operator*(const Vector2i& other) const
  {
    return Vector2i(this->x * other.x, this->y * other.y);
  }
  Vector2i
  Vector2i::operator/(const Vector2i& other) const
  {
    return Vector2i(this->x / other.x, this->y / other.y);
  }
  Vector2i
  Vector2i::operator%(const Vector2i& other) const
  {
    return Vector2i(this->x % other.x, this->y % other.y);
  }

  Vector2i
  Vector2i::operator+(int32 other) const
  {
    return Vector2i(this->x + other, this->y + other);
  }
  Vector2i
  Vector2i::operator-(int32 other) const
  {
    return Vector2i(this->x - other, this->y - other);
  }
  Vector2i
  Vector2i::operator*(int32 other) const
  {
    return Vector2i(this->x * other, this->y * other);
  }
  Vector2i
  Vector2i::operator/(int32 other) const
  {
    return Vector2i(this->x / other, this->y / other);
  }
  Vector2i
  Vector2i::operator%(int32 other) const
  {
    return Vector2i(this->x % other, this->y % other);
  }
  
  NF_UTILITIES_EXPORT Vector2i
  operator+(const int32& other, const Vector2i& otherV)
  {
    return Vector2i(other + otherV.x, other + otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2i
  operator-(const int32& other, const Vector2i& otherV)
  {
    return Vector2i(other - otherV.x, other - otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2i
  operator*(const int32& other, const Vector2i& otherV)
  {
    return Vector2i(other * otherV.x, other * otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2i
  operator/(const int32& other, const Vector2i& otherV)
  {
    return Vector2i(other / otherV.x, other / otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2i
  operator%(const int32& other, const Vector2i& otherV)
  {
    return Vector2i(other % otherV.x, other % otherV.y);
  }

  Vector2i
  Vector2i::operator-() const
  {
    return Vector2i(-x, -y);
  }

  Vector2i&
  Vector2i::operator=(const Vector2i& other)
  {
    this->x = other.x;
    this->y = other.y;
    return *this;
  }

  Vector2i&
  Vector2i::operator+=(const Vector2i& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector2i&
  Vector2i::operator-=(const Vector2i& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector2i&
  Vector2i::operator*=(const Vector2i& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector2i&
  Vector2i::operator/=(const Vector2i& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector2i&
  Vector2i::operator%=(const Vector2i& other)
  {
    *this = *this % other;
    return *this;
  }

  Vector2i&
  Vector2i::operator+=(int32 other)
  {
    *this = *this + other;
    return *this;
  }
  Vector2i&
  Vector2i::operator-=(int32 other)
  {
    *this = *this - other;
    return *this;
  }
  Vector2i&
  Vector2i::operator*=(int32 other)
  {
    *this = *this * other;
    return *this;
  }
  Vector2i&
  Vector2i::operator/=(int32 other)
  {
    *this = *this / other;
    return *this;
  }
  Vector2i&
  Vector2i::operator%=(int32 other)
  {
    *this = *this % other;
    return *this;
  }

  bool
  Vector2i::operator==(const Vector2i& other) const
  {
    return this->x == other.x && this->y == other.y;
  }
  bool
  Vector2i::operator!=(const Vector2i& other) const
  {
    return !(*this == other);
  }

  Vector2i::operator Vector2f() const {
    return Vector2f(static_cast<float>(x), static_cast<float>(y));
  }
  Vector2i::operator Vector2u() const {
    return Vector2u(static_cast<uint32>(x), static_cast<uint32>(y));
  }
  
  //////////////////////
  //     Vector2u     //
  //////////////////////
  
  uint32
  Vector2u::dot(const Vector2u& other) const
  {
    return this->x * other.x + this->y * other.y;
  }
  uint32
  Vector2u::cross(const Vector2u& other) const
  {
    return this->x * other.y - this->y * other.x;
  }

  float
  Vector2u::getDistance(const Vector2u& other) const
  {
    Vector2u d = other - *this;
    return Math::sqrt(static_cast<float>(d.x * d.x)
                    + static_cast<float>(d.y * d.y));
  }
  float
  Vector2u::getMagnitud() const
  {
    return Math::sqrt(static_cast<float>(this->x * this->x)
                    + static_cast<float>(this->y * this->y));
  }

  Vector2u
  Vector2u::operator+(const Vector2u& other) const
  {
    return Vector2u(this->x + other.x, this->y + other.y);
  }
  Vector2u
  Vector2u::operator-(const Vector2u & other) const
  {
    return Vector2u(this->x - other.x, this->y - other.y);
  }
  Vector2u
  Vector2u::operator*(const Vector2u & other) const
  {
    return Vector2u(this->x * other.x, this->y * other.y);
  }
  Vector2u
  Vector2u::operator/(const Vector2u & other) const
  {
    return Vector2u(this->x / other.x, this->y / other.y);
  }
  Vector2u
  Vector2u::operator%(const Vector2u & other) const
  {
    return Vector2u(this->x % other.x, this->y % other.y);
  }

  Vector2u
  Vector2u::operator+(uint32 other) const
  {
    return Vector2u(this->x + other, this->y + other);
  }
  Vector2u
  Vector2u::operator-(uint32 other) const
  {
    return Vector2u(this->x - other, this->y - other);
  }
  Vector2u
  Vector2u::operator*(uint32 other) const
  {
    return Vector2u(this->x * other, this->y * other);
  }
  Vector2u
  Vector2u::operator/(uint32 other) const
  {
    return Vector2u(this->x / other, this->y / other);
  }
  Vector2u
  Vector2u::operator%(uint32 other) const
  {
    return Vector2u(this->x % other, this->y % other);
  }

  NF_UTILITIES_EXPORT Vector2u
  operator+(const uint32& other, const Vector2u& otherV)
  {
    return Vector2u(other + otherV.x, other + otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2u
  operator-(const uint32& other, const Vector2u& otherV)
  {
    return Vector2u(other - otherV.x, other - otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2u
  operator*(const uint32& other, const Vector2u& otherV)
  {
    return Vector2u(other * otherV.x, other * otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2u
  operator/(const uint32& other, const Vector2u& otherV)
  {
    return Vector2u(other / otherV.x, other / otherV.y);
  }
  NF_UTILITIES_EXPORT Vector2u
  operator%(const uint32& other, const Vector2u& otherV)
  {
    return Vector2u(other % otherV.x, other % otherV.y);
  }

  Vector2u&
  Vector2u::operator=(const Vector2u& other)
  {
    this->x = other.x;
    this->y = other.y;
    return *this;
  }

  Vector2u&
  Vector2u::operator+=(const Vector2u& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector2u&
  Vector2u::operator-=(const Vector2u& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector2u&
  Vector2u::operator*=(const Vector2u& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector2u&
  Vector2u::operator/=(const Vector2u& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector2u&
  Vector2u::operator%=(const Vector2u& other)
  {
    *this = *this % other;
    return *this;
  }

  Vector2u&
  Vector2u::operator+=(uint32 other)
  {
    *this = *this + other;
    return *this;
  }
  Vector2u&
  Vector2u::operator-=(uint32 other)
  {
    *this = *this - other;
    return *this;
  }
  Vector2u&
  Vector2u::operator*=(uint32 other)
  {
    *this = *this * other;
    return *this;
  }
  Vector2u&
  Vector2u::operator/=(uint32 other)
  {
    *this = *this / other;
    return *this;
  }
  Vector2u&
  Vector2u::operator%=(uint32 other)
  {
    *this = *this % other;
    return *this;
  }

  bool
  Vector2u::operator==(const Vector2u& other) const
  {
    return this->x == other.x && this->y == other.y;
  }
  bool
  Vector2u::operator!=(const Vector2u& other) const
  {
    return !(*this == other);
  }

  Vector2u::operator Vector2f() const {
    return Vector2f(static_cast<float>(x), static_cast<float>(y));
  }
  Vector2u::operator Vector2i() const {
    return Vector2i(static_cast<int32>(x), static_cast<int32>(y));
  }
}