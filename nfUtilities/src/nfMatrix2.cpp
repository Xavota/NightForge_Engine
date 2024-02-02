#include "nfMatrix2.h"

#include "nfMath.h"

#include "nfVector2.h"

namespace nfEngineSDK {
  const Matrix2 Matrix2::kZERO = Matrix2(0.0f, 0.0f, 0.0f, 0.0f);
  const Matrix2 Matrix2::kONES = Matrix2(1.0f, 1.0f, 1.0f, 1.0f);
  const Matrix2 Matrix2::kIDENTITY = Matrix2(1.0f, 0.0f, 0.0f, 1.0f);
  
  
  Matrix2::Matrix2(float src[4])
  {
    memcpy(m, src, sizeof(float) * 4);
  }

  Matrix2::Matrix2(const Vector2f& r0, const Vector2f& r1)
    : m_00(r0.x), m_01(r0.y), m_10(r1.x), m_11(r1.y) {}
  
  float 
  Matrix2::getDeterminant() const
  {
    return m_00 * m_11 - m_01 * m_10;
  }
  Matrix2
  Matrix2::getAdjoint() const
  {
    return Matrix2(m_11, -m_01, -m_10, m_00);
  }
  
  Matrix2
  Matrix2::getTranspose() const
  {
    return Matrix2(m_00, m_10, m_01, m_11);
  }
  Matrix2&
  Matrix2::transpose()
  {
    /// Basically just changes 01 with 10, since 00 and 11 stay the same.
    float temp = m_01;
    m_01 = m_10;
    m_10 = temp;
    return *this;
  }
  Matrix2
  Matrix2::getInverse() const
  {
    Matrix2 adj = getAdjoint();
    /// TODO: LOG A WARNING IF getDeterminant() RETURNS 0
    float det = getDeterminant();
    return adj * (1.0f / det);
  }
  Matrix2&
  Matrix2::inverse()
  {
    *this = getInverse();
    return *this;
  }
  
  Matrix2 
  Matrix2::operator+(const Matrix2& other) const
  {
    return Matrix2(this->m_00 + other.m_00, this->m_01 + other.m_01,
                   this->m_10 + other.m_10, this->m_11 + other.m_11);
  }
  Matrix2 
  Matrix2::operator-(const Matrix2& other) const
  {
    return Matrix2(this->m_00 - other.m_00, this->m_01 - other.m_01,
                   this->m_10 - other.m_10, this->m_11 - other.m_11);
  }
  Matrix2 
  Matrix2::operator*(const Matrix2& other) const
  {
    return Matrix2(this->m_00 * other.m_00 + this->m_01 * other.m_10,
                   this->m_00 * other.m_01 + this->m_01 * other.m_11,
                   this->m_10 * other.m_00 + this->m_11 * other.m_10,
                   this->m_10 * other.m_01 + this->m_11 * other.m_11);
  }
  
  Matrix2
  Matrix2::operator+(float k) const
  {
    return Matrix2(this->m_00 + k, this->m_01 + k,
                   this->m_10 + k, this->m_11 + k);
  }
  Matrix2
  Matrix2::operator-(float k) const
  {
    return Matrix2(this->m_00 - k, this->m_01 - k,
                   this->m_10 - k, this->m_11 - k);
  }
  Matrix2 
  Matrix2::operator*(float k) const
  {
    return Matrix2(this->m_00 * k, this->m_01 * k,
                   this->m_10 * k, this->m_11 * k);
  }
  
  NF_UTILITIES_EXPORT Matrix2
  operator+(const float& k, const Matrix2& mat)
  {
    return Matrix2(k + mat.m_00, k + mat.m_01,
                   k + mat.m_10, k + mat.m_11);
  }
  NF_UTILITIES_EXPORT Matrix2
  operator-(const float& k, const Matrix2& mat)
  {
    return Matrix2(k - mat.m_00, k - mat.m_01,
                   k - mat.m_10, k - mat.m_11);
  }
  NF_UTILITIES_EXPORT Matrix2
  operator*(const float& k, const Matrix2& mat)
  {
    return Matrix2(k * mat.m_00, k * mat.m_01,
                   k * mat.m_10, k * mat.m_11);
  }
  
  Matrix2&
  Matrix2::operator=(const Matrix2& other)
  {
    this->m_00 = other.m_00;
    this->m_01 = other.m_01;
    this->m_10 = other.m_10;
    this->m_11 = other.m_11;
    return *this;
  }
  
  Matrix2&
  Matrix2::operator+=(const Matrix2& other)
  {
    *this = *this + other;
    return *this;
  }
  Matrix2&
  Matrix2::operator-=(const Matrix2& other)
  {
    *this = *this - other;
    return *this;
  }
  Matrix2&
  Matrix2::operator*=(const Matrix2& other)
  {
    *this = *this * other;
    return *this;
  }
  
  Matrix2&
  Matrix2::operator+=(float k)
  {
    *this = *this + k;
    return *this;
  }
  Matrix2&
  Matrix2::operator-=(float k)
  {
    *this = *this - k;
    return *this;
  }
  Matrix2&
  Matrix2::operator*=(float k)
  {
    *this = *this * k;
    return *this;
  }
  
  bool 
  Matrix2::operator==(const Matrix2& other)
  {
    for (int32 i = 0; i < 4; ++i) {
      if (!Math::checkEqual(this->m[i], other.m[i])) {
        return false;
      }
    }
    return true;
  }
  bool 
  Matrix2::operator!=(const Matrix2& other)
  {
    for (int32 i = 0; i < 4; ++i) {
      if (Math::checkEqual(this->m[i], other.m[i])) {
        return false;
      }
    }
    return true;
  }
}