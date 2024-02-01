#include "nfVector4.h"
#include "nfMath.h"

namespace nfEngineSDK
{
  const Vector4f Vector4f::kZERO = Vector4f(0.0f, 0.0f, 0.0f, 0.0f);
  const Vector4i Vector4i::kZERO = Vector4i(0, 0, 0, 0);
  const Vector4u Vector4u::kZERO = Vector4u(0u, 0u, 0u, 0u);


  //////////////////////
  //     Vector4f     //
  //////////////////////
  
  float
  Vector4f::dot(const Vector4f& other) const
  {
    return this->x * other.x + this->y * other.y
         + this->z * other.z + this->w * other.w;
  }

  float
  Vector4f::getDistance(const Vector4f& other) const
  {
    Vector4f d = other - *this;
    return Math::sqrt(d.x * d.x + d.y * d.y + d.z * d.z + d.w * d.w);
  }

  float
  Vector4f::getMagnitude() const
  {
    return Math::sqrt(this->x * this->x + this->y * this->y
                    + this->z * this->z + this->w * this->w);
  }
  Vector4f
  Vector4f::getNormalized() const
  {
    return *this / this->getMagnitude();
  }
  Vector4f
  Vector4f::normalize()
  {
    *this = *this / this->getMagnitude();
    return *this;
  }
  Vector4f
  Vector4f::getTruncate(float newSize) const
  {
    Vector4f n = this->getNormalized();
    return n * newSize;
  }
  Vector4f
  Vector4f::truncate(float newSize)
  {
    Vector4f n = this->getNormalized();
    *this = n * newSize;
    return *this;
  }

  Vector4f
  Vector4f::operator+(const Vector4f& other) const
  {
    return Vector4f(this->x + other.x, this->y + other.y,
                    this->z + other.z, this->w + other.w);
  }
  Vector4f
  Vector4f::operator-(const Vector4f& other) const
  {
    return Vector4f(this->x - other.x, this->y - other.y,
                    this->z - other.z, this->w - other.w);
  }
  Vector4f
  Vector4f::operator*(const Vector4f& other) const
  {
    return Vector4f(this->x * other.x, this->y * other.y,
                    this->z * other.z, this->w * other.w);
  }
  Vector4f
  Vector4f::operator/(const Vector4f& other) const
  {
    return Vector4f(this->x / other.x, this->y / other.y,
                    this->z / other.z, this->w / other.w);
  }
  Vector4f
  Vector4f::operator%(const Vector4f& other) const
  {
    return Vector4f(Math::fmod(this->x, other.x),
                    Math::fmod(this->y, other.y),
                    Math::fmod(this->z, other.z),
                    Math::fmod(this->w, other.w));
  }

  Vector4f
  Vector4f::operator+(float other) const
  {
    return Vector4f(this->x + other, this->y + other,
                    this->z + other, this->w + other);
  }
  Vector4f
  Vector4f::operator-(float other) const
  {
    return Vector4f(this->x - other, this->y - other,
                    this->z - other, this->w - other);
  }
  Vector4f
  Vector4f::operator*(float other) const
  {
    return Vector4f(this->x * other, this->y * other,
                    this->z * other, this->w * other);
  }
  Vector4f
  Vector4f::operator/(float other) const
  {
    return Vector4f(this->x / other, this->y / other,
                    this->z / other, this->w / other);
  }
  Vector4f
  Vector4f::operator%(float other) const
  {
    return Vector4f(Math::fmod(this->x, other),
                    Math::fmod(this->y, other),
                    Math::fmod(this->z, other),
                    Math::fmod(this->w, other));
  }

  NF_UTILITIES_EXPORT Vector4f
  operator+(const float& other, const Vector4f& otherV)
  {
    return Vector4f(other + otherV.x, other + otherV.y,
                    other + otherV.z, other + otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4f
  operator-(const float& other, const Vector4f& otherV)
  {
    return Vector4f(other - otherV.x, other - otherV.y,
                    other - otherV.z, other - otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4f
  operator*(const float& other, const Vector4f& otherV)
  {
    return Vector4f(other * otherV.x, other * otherV.y,
                    other * otherV.z, other * otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4f
  operator/(const float& other, const Vector4f& otherV)
  {
    return Vector4f(other / otherV.x, other / otherV.y,
                    other / otherV.z, other / otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4f
  operator%(const float& other, const Vector4f& otherV)
  {
    return Vector4f(Math::fmod(other, otherV.x), Math::fmod(other, otherV.y),
                    Math::fmod(other, otherV.z), Math::fmod(other, otherV.w));
  }

  Vector4f Vector4f::operator-() const
  {
    return Vector4f(-x, -y, -z, -w);
  }

  Vector4f&
  Vector4f::operator=(const Vector4f& other)
  {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
    return *this;
  }

  Vector4f&
  Vector4f::operator+=(const Vector4f& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector4f&
  Vector4f::operator-=(const Vector4f& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector4f&
  Vector4f::operator*=(const Vector4f& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector4f&
  Vector4f::operator/=(const Vector4f& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector4f&
  Vector4f::operator%=(const Vector4f& other)
  {
    *this = *this % other;
    return *this;
  }

  Vector4f&
  Vector4f::operator+=(float other)
  {
    *this = *this + other;
    return *this;
  }
  Vector4f&
  Vector4f::operator-=(float other)
  {
    *this = *this - other;
    return *this;
  }
  Vector4f&
  Vector4f::operator*=(float other)
  {
    *this = *this * other;
    return *this;
  }
  Vector4f&
  Vector4f::operator/=(float other)
  {
    *this = *this / other;
    return *this;
  }
  Vector4f&
  Vector4f::operator%=(float other)
  {
    *this = *this % other;
    return *this;
  }

  bool
  Vector4f::operator==(const Vector4f& other) const
  {
    return (Math::checkEqual(this->x, other.x))
        && (Math::checkEqual(this->y, other.y))
        && (Math::checkEqual(this->z, other.z))
        && (Math::checkEqual(this->w, other.w));
  }
  bool
  Vector4f::operator!=(const Vector4f& other) const
  {
    return !(*this == other);
  }

  Vector4f::operator Vector4i() const
  {
    return Vector4i(static_cast<int32>(x),
                    static_cast<int32>(y),
                    static_cast<int32>(z),
                    static_cast<int32>(w));
  }
  Vector4f::operator Vector4u() const
  {
    return Vector4u(static_cast<uint32>(Math::abs(x)),
                    static_cast<uint32>(Math::abs(y)),
                    static_cast<uint32>(Math::abs(z)),
                    static_cast<uint32>(Math::abs(w)));
  }

  //////////////////////
  //     Vector4i     //
  //////////////////////
  
  int32
  Vector4i::dot(const Vector4i& other) const
  {
    return this->x * other.x + this->y * other.y
         + this->z * other.z + this->w * other.w;
  }

  float
  Vector4i::getDistance(const Vector4i& other) const
  {
    Vector4i d = other - *this;
    return Math::sqrt(static_cast<float>(d.x * d.x)
                    + static_cast<float>(d.y * d.y)
                    + static_cast<float>(d.z * d.z)
                    + static_cast<float>(d.w * d.w));
  }

  float
  Vector4i::getMagnitude() const
  {
    return Math::sqrt(static_cast<float>(this->x * this->x)
                    + static_cast<float>(this->y * this->y)
                    + static_cast<float>(this->z * this->z)
                    + static_cast<float>(this->w * this->w));
  }

  Vector4i
  Vector4i::operator+(const Vector4i& other) const
  {
    return Vector4i(this->x + other.x, this->y + other.y,
                    this->z + other.z, this->w + other.w);
  }
  Vector4i
  Vector4i::operator-(const Vector4i& other) const
  {
    return Vector4i(this->x - other.x, this->y - other.y,
                    this->z - other.z, this->w - other.w);
  }
  Vector4i
  Vector4i::operator*(const Vector4i& other) const
  {
    return Vector4i(this->x * other.x, this->y * other.y,
                    this->z * other.z, this->w * other.w);
  }
  Vector4i
  Vector4i::operator/(const Vector4i& other) const
  {
    return Vector4i(this->x / other.x, this->y / other.y,
                    this->z / other.z, this->w / other.w);
  }
  Vector4i
  Vector4i::operator%(const Vector4i& other) const
  {
    return Vector4i(this->x % other.x, this->y % other.y,
                    this->z % other.z, this->w % other.w);
  }

  Vector4i
  Vector4i::operator+(int32 other) const
  {
    return Vector4i(this->x + other, this->y + other,
                    this->z + other, this->w + other);
  }
  Vector4i
  Vector4i::operator-(int32 other) const
  {
    return Vector4i(this->x - other, this->y - other,
                    this->z - other, this->w - other);
  }
  Vector4i
  Vector4i::operator*(int32 other) const
  {
    return Vector4i(this->x * other, this->y * other,
                    this->z * other, this->w * other);
  }
  Vector4i
  Vector4i::operator/(int32 other) const
  {
    return Vector4i(this->x / other, this->y / other,
                    this->z / other, this->w / other);
  }
  Vector4i
  Vector4i::operator%(int32 other) const
  {
    return Vector4i(this->x % other, this->y % other,
                    this->z % other, this->w % other);
  }

  NF_UTILITIES_EXPORT Vector4i
  operator+(const int32& other, const Vector4i& otherV)
  {
    return Vector4i(other + otherV.x, other + otherV.y,
                    other + otherV.z, other + otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4i
  operator-(const int32& other, const Vector4i& otherV)
  {
    return Vector4i(other - otherV.x, other - otherV.y,
                    other - otherV.z, other - otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4i
  operator*(const int32& other, const Vector4i& otherV)
  {
    return Vector4i(other * otherV.x, other * otherV.y,
                    other * otherV.z, other * otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4i
  operator/(const int32& other, const Vector4i& otherV)
  {
    return Vector4i(other / otherV.x, other / otherV.y,
                    other / otherV.z, other / otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4i
  operator%(const int32& other, const Vector4i& otherV)
  {
    return Vector4i(other % otherV.x, other % otherV.y,
                    other % otherV.z, other % otherV.w);
  }

  Vector4i Vector4i::operator-() const
  {
    return Vector4i(-x, -y, -z, -w);
  }

  Vector4i&
  Vector4i::operator=(const Vector4i& other)
  {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
    return *this;
  }

  Vector4i&
  Vector4i::operator+=(const Vector4i& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector4i&
  Vector4i::operator-=(const Vector4i& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector4i&
  Vector4i::operator*=(const Vector4i& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector4i&
  Vector4i::operator/=(const Vector4i& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector4i&
  Vector4i::operator%=(const Vector4i& other)
  {
    *this = *this % other;
    return *this;
  }

  Vector4i&
  Vector4i::operator+=(int32 other)
  {
    *this = *this + other;
    return *this;
  }
  Vector4i&
  Vector4i::operator-=(int32 other)
  {
    *this = *this - other;
    return *this;
  }
  Vector4i&
  Vector4i::operator*=(int32 other)
  {
    *this = *this * other;
    return *this;
  }
  Vector4i&
  Vector4i::operator/=(int32 other)
  {
    *this = *this / other;
    return *this;
  }
  Vector4i&
  Vector4i::operator%=(int32 other)
  {
    *this = *this % other;
    return *this;
  }

  bool
  Vector4i::operator==(const Vector4i& other) const
  {
    return this->x == other.x && this->y == other.y
        && this->z == other.z && this->w == other.w;
  }
  bool
  Vector4i::operator!=(const Vector4i& other) const
  {
    return !(*this == other);
  }

  Vector4i::operator Vector4f() const
  {
    return Vector4f(static_cast<float>(x),
                    static_cast<float>(y),
                    static_cast<float>(z),
                    static_cast<float>(w));
  }

  Vector4i::operator Vector4u() const
  {
    return Vector4u(static_cast<uint32>(Math::abs(x)),
                    static_cast<uint32>(Math::abs(y)),
                    static_cast<uint32>(Math::abs(z)),
                    static_cast<uint32>(Math::abs(w)));
  }

  //////////////////////
  //     Vector4u     //
  //////////////////////
  
  uint32
  Vector4u::dot(const Vector4u& other) const
  {
    return this->x * other.x + this->y * other.y
         + this->z * other.z + this->w * other.w;
  }
  
  float
  Vector4u::getDistance(const Vector4u& other) const
  {
    Vector4u d = other - *this;
    return Math::sqrt(static_cast<float>(d.x * d.x)
                    + static_cast<float>(d.y * d.y)
                    + static_cast<float>(d.z * d.z)
                    + static_cast<float>(d.w * d.w));
  }

  float
  Vector4u::getMagnitude() const
  {
    return Math::sqrt(static_cast<float>(this->x * this->x)
                    + static_cast<float>(this->y * this->y)
                    + static_cast<float>(this->z * this->z)
                    + static_cast<float>(this->w * this->w));
  }

  Vector4u
  Vector4u::operator+(const Vector4u& other) const
  {
    return Vector4u(this->x + other.x, this->y + other.y,
                   this->z + other.z, this->w + other.w);
  }
  Vector4u
  Vector4u::operator-(const Vector4u& other) const
  {
    return Vector4u(this->x - other.x, this->y - other.y,
                   this->z - other.z, this->w - other.w);
  }
  Vector4u
  Vector4u::operator*(const Vector4u& other) const
  {
    return Vector4u(this->x * other.x, this->y * other.y,
                   this->z * other.z, this->w * other.w);
  }
  Vector4u
  Vector4u::operator/(const Vector4u& other) const
  {
    return Vector4u(this->x / other.x, this->y / other.y,
                   this->z / other.z, this->w / other.w);
  }
  Vector4u
  Vector4u::operator%(const Vector4u& other) const
  {
    return Vector4u(this->x % other.x, this->y % other.y,
                   this->z % other.z, this->w % other.w);
  }

  Vector4u
  Vector4u::operator+(uint32 other) const
  {
    return Vector4u(this->x + other, this->y + other,
                   this->z + other, this->w + other);
  }
  Vector4u
  Vector4u::operator-(uint32 other) const
  {
    return Vector4u(this->x - other, this->y - other,
                   this->z - other, this->w - other);
  }
  Vector4u
  Vector4u::operator*(uint32 other) const
  {
    return Vector4u(this->x * other, this->y * other,
                   this->z * other, this->w * other);
  }
  Vector4u
  Vector4u::operator/(uint32 other) const
  {
    return Vector4u(this->x / other, this->y / other,
                   this->z / other, this->w / other);
  }
  Vector4u
  Vector4u::operator%(uint32 other) const
  {
    return Vector4u(this->x % other, this->y % other,
                   this->z % other, this->w % other);
  }

  NF_UTILITIES_EXPORT Vector4u
  operator+(const uint32& other, const Vector4u& otherV)
  {
    return Vector4u(other + otherV.x, other + otherV.y,
                    other + otherV.z, other + otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4u
  operator-(const uint32& other, const Vector4u& otherV)
  {
    return Vector4u(other - otherV.x, other - otherV.y,
                    other - otherV.z, other - otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4u
  operator*(const uint32& other, const Vector4u& otherV)
  {
    return Vector4u(other * otherV.x, other * otherV.y,
                    other * otherV.z, other * otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4u
  operator/(const uint32& other, const Vector4u& otherV)
  {
    return Vector4u(other / otherV.x, other / otherV.y,
                    other / otherV.z, other / otherV.w);
  }
  NF_UTILITIES_EXPORT Vector4u
  operator%(const uint32& other, const Vector4u& otherV)
  {
    return Vector4u(other % otherV.x, other % otherV.y,
                    other % otherV.z, other % otherV.w);
  }

  Vector4u&
  Vector4u::operator=(const Vector4u& other)
  {
    this->x = other.x;
    this->y = other.y;
    this->z = other.z;
    this->w = other.w;
    return *this;
  }

  Vector4u&
  Vector4u::operator+=(const Vector4u& other)
  {
    *this = *this + other;
    return *this;
  }
  Vector4u&
  Vector4u::operator-=(const Vector4u& other)
  {
    *this = *this - other;
    return *this;
  }
  Vector4u&
  Vector4u::operator*=(const Vector4u& other)
  {
    *this = *this * other;
    return *this;
  }
  Vector4u&
  Vector4u::operator/=(const Vector4u& other)
  {
    *this = *this / other;
    return *this;
  }
  Vector4u&
  Vector4u::operator%=(const Vector4u& other)
  {
    *this = *this % other;
    return *this;
  }

  Vector4u&
  Vector4u::operator+=(uint32 other)
  {
    *this = *this + other;
    return *this;
  }
  Vector4u&
  Vector4u::operator-=(uint32 other)
  {
    *this = *this - other;
    return *this;
  }
  Vector4u&
  Vector4u::operator*=(uint32 other)
  {
    *this = *this * other;
    return *this;
  }
  Vector4u&
  Vector4u::operator/=(uint32 other)
  {
    *this = *this / other;
    return *this;
  }
  Vector4u&
  Vector4u::operator%=(uint32 other)
  {
    *this = *this % other;
    return *this;
  }

  bool
  Vector4u::operator==(const Vector4u& other) const
  {
    return this->x == other.x && this->y == other.y
        && this->z == other.z && this->w == other.w;
  }
  bool
  Vector4u::operator!=(const Vector4u& other) const
  {
    return !(*this == other);
  }
  Vector4u::operator Vector4f() const
  {
    return Vector4f(static_cast<float>(x),
                    static_cast<float>(y),
                    static_cast<float>(z),
                    static_cast<float>(w));
  }
  Vector4u::operator Vector4i() const
  {
    return Vector4i(static_cast<int32>(x),
                    static_cast<int32>(y),
                    static_cast<int32>(z),
                    static_cast<int32>(w));
  }
}