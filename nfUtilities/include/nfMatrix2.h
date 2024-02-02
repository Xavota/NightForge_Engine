/************************************************************************/
/**
 * @file nfMatrix2.h
 * @author Diego Castellanos
 * @date 01/02/24
 * @brief This file defines the Matrix2 in its 3 forms: floats, int32 and
 *        uint32, as well as its functions, operators and members.
 *        Row major
 *
 * @bug Not bug Known.
 */
/************************************************************************/

#pragma once
#include "nfPrerequisitesUtilities.h"

#ifndef MATRIX2
#define MATRIX2
#endif // !MATRIX2


namespace nfEngineSDK {
  /**
   * @brief
   * Matrix 2x2. Holds 2 rows and 2 columns of floats.
   * Has all the possible operations for matrices.
   * Row major
   */
  class NF_UTILITIES_EXPORT Matrix2
  {
   public:
    /**
     * @brief
     * The default constructor.
     */
    Matrix2() = default;
    /**
     * @brief
     * Custom constructor.
     *
     * @description
     * Takes an array of values to initialize the matrix.
     * Ordered from left to right, up to down.
     *
     * @param src
     * The source from where the data is taken.
     */
    explicit
    Matrix2(float src[4]);
    /**
    * @brief
    * Custom constructor.
    *
    * @description
    * Initializes the matrix with vectors,
    * one for each row.
    *
    * @param r0
    * The first row of the matrix.
    * @param r1
    * The second row of the matrix.
    */
    Matrix2(const Vector2f& r0, const Vector2f& r1);
    /**
     * @brief
     * Custom constructor.
     *
     * @description
     * Initializes the matrix with values. Representing each value in the matrix.
     * Name '_xy'
     * x: row
     * y: column
     *
     * @param _00
     * First row, first column.
     * @param _01
     * First row, second column.
     * @param _10
     * Second row, first column.
     * @param _11
     * Second row, second column.
     */
    FORCEINLINE explicit
    Matrix2(float _00, float _01, float _10, float _11)
    : m_00(_00),
      m_01(_01),
      m_10(_10),
      m_11(_11)
    {}
    /**
     * @brief
     * The destructor.
     *
     * @description
     * Frees allocated memory.
     */
    ~Matrix2() = default;
  
    /**
     * @brief
     * Calculates the determinant of the matrix.
     *
     * @description
     * Returns the determinant of the matrix with its current values.
     *
     * @return
     * The determinant of the matrix.
     */
    float 
    getDeterminant() const;
    /**
     * @brief
     * Calculates the adjoint form of this matrix.
     *
     * @description
     * Returns the adjoint form of this matrix.
     * This form is given by the formula:
     * 
     *     | a b |
     * A = | c d |
     * 
     *          |  d -b |
     * adj(A) = | -c  a |
     *
     * @return
     * The adjoint form of this matrix.
     */
    Matrix2 
    getAdjoint() const;
  
    /**
     * @brief
     * Calculates the transpose of the matrix.
     *
     * @description
     * Returns the transpose of the matrix, inverting rows and columns.
     *
     * @return
     * The transpose of the matrix.
     */
    Matrix2 
    getTranspose() const;
    /**
     * @brief
     * Transpose the matrix.
     *
     * @description
     * Modifies the matrix to its transposed form.
     *
     * @return
     * The transpose of the matrix.
     */
    Matrix2&
    transpose();
    /**
     * @brief
     * Calculates the inverse of the matrix.
     *
     * @description
     * Returns the inverse of the matrix with its current values.
     *
     * @return
     * The inverse of the matrix.
     */
    Matrix2 
    getInverse() const;
    /**
     * @brief
     * Inverse the matrix.
     *
     * @description
     * Modify the matrix to its inverse form with its current values.
     *
     * @return
     * The matrix inverted.
     */
    Matrix2&
    inverse();
  
    /**
     * @brief
     * The operator '+' with other matrix.
     *
     * @description
     * Sums every value with its counterpart on the other matrix.
     *
     * @param other
     * The other matrix to sum.
     *
     * @return
     * The sum of the two matrices.
     */
    Matrix2 
    operator+(const Matrix2& other) const;
    /**
     * @brief
     * The operator '-' with other matrix.
     *
     * @description
     * Subtracts every value with its counterpart on the other matrix.
     *
     * @param other
     * The other matrix to subtract.
     *
     * @return
     * The subtraction of the two matrices.
     */
    Matrix2 
    operator-(const Matrix2& other) const;
    /**
     * @brief
     * The operator '*' with other matrix.
     *
     * @description
     * Multiply the two matrices, rows times columns.
     *
     * @param other
     * The other matrix to multiply.
     *
     * @return
     * The multiplication of the two matrices.
     */
    Matrix2 
    operator*(const Matrix2& other) const;
  
    /**
     * @brief
     * The operator '+' with a number.
     *
     * @description
     * Add each value of the matrix with a number.
     *
     * @param k
     * The value to add.
     *
     * @return
     * The addition of the values of the matrix, plus the number.
     */
    Matrix2 
    operator+(float k) const;
    /**
     * @brief
     * The operator '-' with a number.
     *
     * @description
     * subtract each value of the matrix with a number.
     *
     * @param k
     * The value to subtract.
     *
     * @return
     * The subtraction of the values of the matrix, minus the number.
     */
    Matrix2 
    operator-(float k) const;
    /**
     * @brief
     * The operator '*' with a number.
     *
     * @description
     * Multiply each value of the matrix with a number.
     *
     * @param k
     * The value to multiply.
     *
     * @return
     * The multiplication of the values of the matrix, time the number.
     */
    Matrix2 
    operator*(float k) const;
  
  
    /**
     * @brief
     * The sum of the matrix plus a number.
     *
     * @description
     * Returns a matrix with the sum of every component of
     * the original plus the given number.
     *
     * @param other
     * The number for the operation.
     *
     * @return
     * The sum of the matrix plus the number.
     */
    friend NF_UTILITIES_EXPORT Matrix2
    operator+(const float& k, const Matrix2& mat);
    /**
     * @brief
     * The subtraction of the matrix minus a number.
     *
     * @description
     * Returns a matrix with the subtraction of every component of
     * the original minus the given number.
     *
     * @param other
     * The number for the operation.
     *
     * @return
     * The subtraction of the matrix minus the number.
     */
    friend NF_UTILITIES_EXPORT Matrix2
    operator-(const float& k, const Matrix2& mat);
    /**
     * @brief
     * The multiplication of the matrix times a number.
     *
     * @description
     * Returns a matrix with the multiplication of every component of
     * the original times the given number.
     *
     * @param other
     * The number for the operation.
     *
     * @return
     * The multiplication of the matrix times the number.
     */
    friend NF_UTILITIES_EXPORT Matrix2
    operator*(const float& k, const Matrix2& mat);
  
    /**
     * @brief
     * The operator '=' with other matrix.
     *
     * @description
     * Makes every component of the matrix equal to its counterpart
     * on the other matrix.
     *
     * @param other
     * The matrix to be equal.
     *
     * @return
     * This matrix with its values changed.
     */
    Matrix2&
    operator=(const Matrix2& other);
  
    /**
     * @brief
     * The operator '+=' with other matrix.
     *
     * @description
     * Makes this matrix equal to the sum of it plus the
     * other matrix.
     *
     * @param other
     * The other matrix to sum.
     *
     * @return
     * This matrix with its values changed.
     */
    Matrix2&
    operator+=(const Matrix2& other);
    /**
     * @brief
     * The operator '-=' with other matrix.
     *
     * @description
     * Makes this matrix equal to the subtraction of it minus the
     * other matrix.
     *
     * @param other
     * The other matrix to subtract.
     *
     * @return
     * This matrix with its values changed.
     */
    Matrix2&
    operator-=(const Matrix2& other);
    /**
     * @brief
     * The operator '*=' with other matrix.
     *
     * @description
     * Makes this matrix equal to the multiplication of it times the
     * other matrix.
     *
     * @param other
     * The other matrix to multiply.
     *
     * @return
     * This matrix with its values changed.
     */
    Matrix2&
    operator*=(const Matrix2& other);
  
    /**
     * @brief
     * The operator '+=' with a value.
     *
     * @description
     * Makes this matrix equal to the addition of its components plus a number.
     *
     * @param k
     * The value to add.
     *
     * @return
     * This matrix with its values changed.
     */
    Matrix2&
    operator+=(float k);
    /**
     * @brief
     * The operator '-=' with a value.
     *
     * @description
     * Makes this matrix equal to the subtraction of its components times a
     * number.
     *
     * @param k
     * The value to subtract.
     *
     * @return
     * This matrix with its values changed.
     */
    Matrix2&
    operator-=(float k);
    /**
     * @brief
     * The operator '*=' with a value.
     *
     * @description
     * Makes this matrix equal to the multiplication of its components
     * times the number.
     *
     * @param k
     * The value to multiply.
     *
     * @return
     * This matrix with its values changed.
     */
    Matrix2&
    operator*=(float k);
  
    /**
     * @brief
     * The operator '==' with a value.
     *
     * @description
     * Checks if the two matrices are equal, or really close to be.
     *
     * @param other
     * The other matrix to check.
     *
     * @return
     * True if the two matrices are equal.
     */
    bool 
    operator==(const Matrix2& other);
    /**
     * @brief
     * The operator '!=' with a value.
     *
     * @description
     * Checks if the two matrices are not equal.
     *
     * @param other
     * The other matrix to check.
     *
     * @return
     * True if the two matrices are not equal.
     */
    bool 
    operator!=(const Matrix2& other);
  
   public:
    union
    {
      struct
      {
        /*
         * Component r0c0 of the matrix.
         */
        float m_00;
        /*
         * Component r0c1 of the matrix.
         */
        float m_01;
        /*
         * Component r1c0 of the matrix.
         */
        float m_10;
        /*
         * Component r1c1 of the matrix.
         */
        float m_11;
      };
      /*
       * The entire matrix on an array.
       */
      float m[4];
    };
  
    /*
     * Matrix filled with zeros.
     */
    static const Matrix2 kZERO;
    /*
     * Matrix filled with ones.
     */
    static const Matrix2 kONES;
    /*
     * The identity matrix.
     */
    static const Matrix2 kIDENTITY;
  };
}