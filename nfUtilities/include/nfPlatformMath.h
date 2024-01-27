/************************************************************************/
/**
 * @file nfPlatformMath.h
 * @author Mara Castellanos
 * @date 22/01/24
 * @brief All math that will be needed on the engine. Wraps all the
 *        math functions so that the only changes made will be in here,
 *        if needed.
 *
 * @bug Not bug Known.
 */
/************************************************************************/

#pragma once

#include "nfPrerequisitesUtilities.h"

namespace nfEngineSDK {
  /**
   * @brief
   * All math that will be needed on the engine. Wraps all the 
   * math functions so that the only changes made will be in here,
   * if needed.
   */
  class NF_UTILITIES_EXPORT PlatformMath
  {
  public:
    PlatformMath() = default;
    ~PlatformMath() = default;
  
    /***************************************************************************/
    /*                                                                         */
    /*                              Trigonometric                              */
    /*                                                                         */
    /***************************************************************************/
    
    /**
     * @brief
     * The cosine function.
     *
     * @description
     * Returns the cosine operation for the angle passed, in radians.
     *
     * @param _radian
     * The angle for the function in radians.
     *
     * @return
     * The result of the cosine function.
     */
    template<typename T>
    static FORCEINLINE T
    cos(const T& _radian);
    /**
     * @brief
     * The cosine function for degrees.
     *
     * @description
     * Returns the cosine operation for the angle passed, in degrees.
     *
     * @param _radian
     * The angle for the function in degrees.
     *
     * @return
     * The result of the cosine function.
     */
    template<typename T>
    static FORCEINLINE T
    cosd(const T& _degree);
    /**
     * @brief
     * The sine function.
     *
     * @description
     * Returns the sine operation for the angle passed, in radians.
     *
     * @param _radian
     * The angle for the function in radians.
     *
     * @return
     * The result of the sine function.
     */
    template<typename T>
    static FORCEINLINE T
    sin(const T& _radian);
    /**
     * @brief
     * The sine function for degrees.
     *
     * @description
     * Returns the sine operation for the angle passed, in degrees.
     *
     * @param _radian
     * The angle for the function in degrees.
     *
     * @return
     * The result of the sine function.
     */
    template<typename T>
    static FORCEINLINE T
    sind(const T& _degree);
    /**
     * @brief
     * The tangent function.
     *
     * @description
     * Returns the tangent operation for the angle passed, in radians.
     *
     * @param _radian
     * The angle for the function in radians.
     *
     * @return
     * The result of the tangent function.
     */
    template<typename T>
    static FORCEINLINE T
    tan(const T& _radian);
    /**
     * @brief
     * The tangent function for degrees.
     *
     * @description
     * Returns the tangent operation for the angle passed, in degrees.
     *
     * @param _radian
     * The angle for the function in degrees.
     *
     * @return
     * The result of the tangent function.
     */
    template<typename T>
    static FORCEINLINE T
    tand(const T& _degree);
    /**
     * @brief
     * The secant function.
     *
     * @description
     * Returns the secant operation for the angle passed, in radians.
     *
     * @param _radian
     * The angle for the function in radians.
     *
     * @return
     * The result of the secant function.
     */
    template<typename T>
    static FORCEINLINE T
    sec(const T& _radian);
    /**
     * @brief
     * The secant function for degrees.
     *
     * @description
     * Returns the secant operation for the angle passed, in degrees.
     *
     * @param _radian
     * The angle for the function in degrees.
     *
     * @return
     * The result of the secant function.
     */
    template<typename T>
    static FORCEINLINE T
    secd(const T& _degree);
    /**
     * @brief
     * The cosecant function.
     *
     * @description
     * Returns the cosecant operation for the angle passed, in radians.
     *
     * @param _radian
     * The angle for the function in radians.
     *
     * @return
     * The result of the cosecant function.
     */
    template<typename T>
    static FORCEINLINE T
    csc(const T& _radian);
    /**
     * @brief
     * The cosecant function for degrees.
     *
     * @description
     * Returns the cosecant operation for the angle passed, in degrees.
     *
     * @param _radian
     * The angle for the function in degrees.
     *
     * @return
     * The result of the cosecant function.
     */
    template<typename T>
    static FORCEINLINE T
    cscd(const T& _degree);
    /**
     * @brief
     * The cotangent function.
     *
     * @description
     * Returns the cotangent operation for the angle passed, in radians.
     *
     * @param _radian
     * The angle for the function in radians.
     *
     * @return
     * The result of the cotangent function.
     */
    template<typename T>
    static FORCEINLINE T
    cot(const T& _radian);
    /**
     * @brief
     * The cotangent function for degrees.
     *
     * @description
     * Returns the cotangent operation for the angle passed, in degrees.
     *
     * @param _radian
     * The angle for the function in degrees.
     *
     * @return
     * The result of the cotangent function.
     */
    template<typename T>
    static FORCEINLINE T
    cotd(const T& _degree);
  
    /**
     * @brief
     * The arccosine function.
     *
     * @description
     * Returns the arccosine operation for the value passed, in radians.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arccosine function.
     */
    template<typename T>
    static FORCEINLINE T
    acos(const T& _value);
    /**
     * @brief
     * The arccosine function, for degrees.
     *
     * @description
     * Returns the arccosine operation for the value passed, in degrees.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arccosine function.
     */
    template<typename T>
    static FORCEINLINE T
    acosd(const T& _value);
    /**
     * @brief
     * The arcsine function.
     *
     * @description
     * Returns the arcsine operation for the value passed, in radians.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arcsine function.
     */
    template<typename T>
    static FORCEINLINE T
    asin(const T& _value);
    /**
     * @brief
     * The arcsine function, for degrees.
     *
     * @description
     * Returns the arcsine operation for the value passed, in degrees.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arcsine function.
     */
    template<typename T>
    static FORCEINLINE T
    asind(const T& _value);
    /**
     * @brief
     * The arctangent function.
     *
     * @description
     * Returns the arctangent operation for the value passed, in radians.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arctangent function.
     */
    template<typename T>
    static FORCEINLINE T
    atan(const T& _value);
    /**
     * @brief
     * The arctangent2 function.
     *
     * @description
     * Returns the arctangent operation for the values passed, using the signs
     * of arguments to correctly determine quadrant. The value is assumed as 
     * Y / X
     *
     * @param Y
     * The y component of the right triangle.
     * @param X
     * The x component of the right triangle.
     *
     * @return
     * The result of the arctangent2 function.
     */
    template<typename T>
    static FORCEINLINE T
    atan2(const T& Y, const T& X);
    /**
     * @brief
     * The arctangent function, for degrees.
     *
     * @description
     * Returns the arctangent operation for the value passed, in degrees.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arctangent function.
     */
    template<typename T>
    static FORCEINLINE T
    atand(const T& _value);
    /**
     * @brief
     * The arcsecant function.
     *
     * @description
     * Returns the arcsecant operation for the value passed, in radians.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arcsecant function.
     */
    template<typename T>
    static FORCEINLINE T
    asec(const T& _value);
    /**
     * @brief
     * The arcsecant function, for degrees.
     *
     * @description
     * Returns the arcsecant operation for the value passed, in degrees.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arcsecant function.
     */
    template<typename T>
    static FORCEINLINE T
    asecd(const T& _value);
    /**
     * @brief
     * The arccosecant function.
     *
     * @description
     * Returns the arccosecant operation for the value passed, in radians.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arccosecant function.
     */
    template<typename T>
    static FORCEINLINE T
    acsc(const T& _value);
    /**
     * @brief
     * The arccosecant function, for degrees.
     *
     * @description
     * Returns the arccosecant operation for the value passed, in degrees.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arccosecant function.
     */
    template<typename T>
    static FORCEINLINE T
    acscd(const T& _value);
    /**
     * @brief
     * The arccotangent function.
     *
     * @description
     * Returns the arccotangent operation for the value passed, in radians.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arccotangent function.
     */
    template<typename T>
    static FORCEINLINE T
    acot(const T& _value);
    /**
     * @brief
     * The arccotangent function, for degrees.
     *
     * @description
     * Returns the arccotangent operation for the value passed, in degrees.
     *
     * @param _value
     * The value for the function.
     *
     * @return
     * The result of the arccotangent function.
     */
    template<typename T>
    static FORCEINLINE T
    acotd(const T& _value);
  
    /**
     * @brief
     * Transforms radians to degrees.
     *
     * @description
     * Gets radians and transforms them into degrees.
     *
     * @param _radian
     * The radians to transform.
     *
     * @return
     * The degrees result.
     */
    template<typename T>
    static FORCEINLINE T
    radToDeg(const T& _radian);
    /**
     * @brief
     * Transforms degrees to radians.
     *
     * @description
     * Gets degrees and transforms them into radians.
     *
     * @param _degree
     * The degree to transform.
     *
     * @return
     * The radians result.
     */
    template<typename T>
    static FORCEINLINE T
    degToRad(const T& _degree);
  
    /***************************************************************************/
    /*                                                                         */
    /*                               Arithmetic                                */
    /*                                                                         */
    /***************************************************************************/
  
    /**
     * @brief
     * The module operation, for floats.
     *
     * @description
     * The residue of the division between left and right values.
     *
     * @param _lval
     * The value who's gonna be divided.
     * @param _rval
     * The value who's gonna divide.
     *
     * @return
     * The result of the module.
     */
    template<typename T>
    static FORCEINLINE T
    fmod(const T& _lval, const T& _rval);
    /**
     * @brief
     * The square root operation.
     *
     * @description
     * Returns the square root of the value.
     *
     * @param _val
     * The value for the square root.
     *
     * @return
     * The result of the square root.
     */
    template<typename T>
    static FORCEINLINE T
    sqrt(T _val);
    /**
     * @brief
     * The power operation.
     *
     * @description
     * Returns the power of a number to its exponent.
     *
     * @param _base
     * The number to be powered.
     * @param _power
     * The exponent of the base.
     *
     * @return
     * The result of the power operation.
     */
    template<typename T>
    static FORCEINLINE T
    pow(T _base, T _power);
    /**
     * @brief
     * The logarithmic operation base 2.
     *
     * @description
     * Returns the logarithm of a number with a base of 2.
     *
     * @param _value
     * The number to be log.
     *
     * @return
     * The result of the logarithmic operation.
     */
    template<typename T>
    static FORCEINLINE T
    log2(T _value);
    /**
     * @brief
     * The logarithmic operation base 10.
     *
     * @description
     * Returns the logarithm of a number with a base of 10.
     *
     * @param _value
     * The number to be log.
     *
     * @return
     * The result of the logarithmic operation.
     */
    template<typename T>
    static FORCEINLINE T
    log10(T _value);
    /**
     * @brief
     * The natural logarithmic operation.
     *
     * @description
     * Returns the logarithm of a number with a base of e.
     *
     * @param _value
     * The number to be log.
     *
     * @return
     * The result of the logarithmic operation.
     */
    template<typename T>
    static FORCEINLINE T
    log(T _value);
    /**
     * @brief
     * The logarithmic operation.
     *
     * @description
     * Returns the logarithm of a number with a base.
     *
     * @param _value
     * The number to be log.
     * @param _base
     * The base of the log.
     *
     * @return
     * The result of the logarithmic operation.
     */
    template<typename T>
    static FORCEINLINE T
    log(T _value, T _base = kEULER);
    /**
     * @brief
     * The exponential function.
     *
     * @description
     * Calculates the exponential value of a floating-point argument x, with
     * the formula e^x (e = kEULER).
     *
     * @param _value
     * The number to be exponentiated.
     *
     * @return
     * The result of the exponential.
     */
    template<typename T>
    static FORCEINLINE T
    exp(T _value);
  
    /**
     * @brief
     * Rounds a value.
     *
     * @description
     * Returns the number passed, but rounded to the nearest
     * integer.
     *
     * @param _val
     * The number to be rounded.
     *
     * @return
     * The number rounded.
     */
    template<typename T>
    static FORCEINLINE T
    round(T _val);
    /**
     * @brief
     * Rounds a value.
     *
     * @description
     * Returns the number passed, but rounded to the integer
     * below.
     *
     * @param _val
     * The number to be rounded.
     *
     * @return
     * The number rounded.
     */
    template<typename T>
    static FORCEINLINE T
    floor(T _val);
    /**
     * @brief
     * Rounds a value.
     *
     * @description
     * Returns the number passed, but rounded to the integer
     * above.
     *
     * @param _val
     * The number to be rounded.
     *
     * @return
     * The number rounded.
     */
    template<typename T>
    static FORCEINLINE T
    ceil(T _val);
  
    /**
     * @brief
     * The absolute value.
     *
     * @description
     * Returns the absolute value of the number passed.
     *
     * @param _val
     * The number to know its absolute.
     *
     * @return
     * The absolute value.
     */
    template<typename T>
    static FORCEINLINE T
    abs(T _val);
    /**
     * @brief
     * The sign of a value.
     *
     * @description
     * Returns the sign of the number passed as a 1.0f or -1.0f.
     *
     * @param _val
     * The number to know its sing.
     *
     * @return
     * The sign value.
     */
    template<typename T>
    static FORCEINLINE T
    sign(T _val);
    /**
     * @brief
     * Returns a number with a needed sign.
     *
     * @description
     * Composes a floating point value with the magnitude of mag and the sign of
     * sign.
     *
     * @param _mag
     * The number to apply the sign.
     * @param _sgn
     * The number to get the sign.
     *
     * @return
     * The absolute value.
     */
    template<typename T>
    static FORCEINLINE T
    copysign(T _mag, T _sgn);
  
    /**
     * @brief
     * The maximum value.
     *
     * @description
     * Returns the maximum value between the first and the second value.
     *
     * @param _val1
     * The first number to check.
     * @param _val2
     * The second number to check.
     *
     * @return
     * The maximum value between the first and the second value.
     */
    template<typename T>
    static FORCEINLINE T
    max(const T& _val1, const T& _val2);
    /**
     * @brief
     * The minimum value.
     *
     * @description
     * Returns the minimum value between the first and the second value.
     *
     * @param _val1
     * The first number to check.
     * @param _val2
     * The second number to check.
     *
     * @return
     * The minimum value between the first and the second value.
     */
    template<typename T>
    static FORCEINLINE T
    min(const T& _val1, const T& _val2);

    /**
     * @brief
     * Check if two floats are nearly equal.
     *
     * @description
     * Check if two floats are nearly equal, given a gap value.
     *
     * @param _val1
     * The first number to check.
     * @param _val2
     * The second number to check.
     * @param maxRelativeDiff
     * The maximum relative difference. This is a small number, that will get
     * scaled relative to the max number between _val1 and _val2, to check for
     * their relative difference, since floating point error gets bigger with
     * bigger numbers and vice versa.
     *
     * @return
     * If the two floats differ by less than the value of the relative
     * difference.
     */
    static FORCEINLINE bool
    checkEqual(float _val1,
               float _val2,
               float maxRelativeDiff = FLT_EPSILON * 5.0f);
    /**
     * @brief
     * Check if two double are nearly equal.
     *
     * @description
     * Check if two double are nearly equal, given a gap value.
     *
     * @param _val1
     * The first number to check.
     * @param _val2
     * The second number to check.
     * @param maxRelativeDiff
     * The maximum relative difference. This is a small number, that will get
     * scaled relative to the max number between _val1 and _val2, to check for
     * their relative difference, since floating point error gets bigger with
     * bigger numbers and vice versa.
     *
     * @return
     * If the two double differ by less than the value of the relative
     * difference.
     */
    static FORCEINLINE bool
    checkEqual(double _val1,
               double _val2,
               double maxRelativeDiff = DBL_EPSILON * 5.0f);
    /**
     * @brief
     * Check if two long double are nearly equal.
     *
     * @description
     * Check if two long double are nearly equal, given a gap value.
     *
     * @param _val1
     * The first number to check.
     * @param _val2
     * The second number to check.
     * @param maxRelativeDiff
     * The maximum relative difference. This is a small number, that will get
     * scaled relative to the max number between _val1 and _val2, to check for
     * their relative difference, since floating point error gets bigger with
     * bigger numbers and vice versa.
     *
     * @return
     * If the two long double differ by less than the value of the relative
     * difference.
     */
    static FORCEINLINE bool
    checkEqual(long double _val1,
               long double _val2,
               long double maxRelativeDiff = LDBL_EPSILON * 5.0f);
    /**
     * @brief
     * Check if the value has the flag.
     *
     * @description
     * Check if the value has the 1's bits of the flag.
     *
     * @param _val
     * The value to check.
     * @param _flag
     * The flag to check the 1's bits.
     *
     * @return
     * If the value has the 1's bits of the flag.
     */
    template<typename V, typename F>
    static FORCEINLINE bool
    hasFlag(const V& _val, const F& _flag);
  
    /***************************************************************************/
    /*                                                                         */
    /*                                Geometry                                 */
    /*                                                                         */
    /***************************************************************************/
  
    ///**
    // * @brief
    // * Distance between a point and a plane.
    // *
    // * @description
    // * Returns the shortest distance between a point and a plane.
    // *
    // * @param p
    // * The plane in the space.
    // * @param X
    // * The point to check distance.
    // *
    // * @return
    // * The shortest distance between a point and a plane.
    // */
    //static float
    //planeDistance(const Plane& p, const Vector3f& point);
    ///**
    // * @brief
    // * Check the position of the sphere with respect to the plane.
    // *
    // * @description
    // * Returns true if the sphere is on the opposite side of the normal
    // * of the plane and it's not touching it.
    // *
    // * @param s
    // * The sphere to check position.
    // * @param p
    // * The plane in the space.
    // *
    // * @return
    // * The shortest distance between a point and a plane.
    // */
    //static bool
    //sphereInsidePlane(const Sphere& s, const Plane& p);
    ///**
    // * @brief
    // * Intersection between a sphere and a plane.
    // *
    // * @description
    // * Returns true if the plane intersects the sphere.
    // *
    // * @param s
    // * The sphere to check.
    // * @param p
    // * The plane to check.
    // *
    // * @return
    // * True if the plane intersects the sphere.
    // */
    //static bool
    //sphereIntersectsPlane(const Sphere& s, const Plane& p);
    ///**
    // * @brief
    // * Check if the sphere is inside the box.
    // *
    // * @description
    // * Returns true if the sphere is inside the box with out touching
    // * its walls.
    // *
    // * @param s
    // * The sphere to check position.
    // * @param b
    // * The box in the space.
    // *
    // * @return
    // * True if the sphere is inside the box with out touching
    // * its walls.
    // */
    //static bool
    //sphereInsideBox(const Sphere& s, const BoxAAB& b);
    ///**
    // * @brief
    // * Intersection between a sphere and a plane.
    // *
    // * @description
    // * Returns true if the plane intersects the sphere, and returns
    // * the point and radius of the intersecting circle between the
    // * sphere and the plane.
    // *
    // * @param s
    // * The sphere to check.
    // * @param p
    // * The plane to check.
    // * @param point
    // * The point on the center of the intersection.
    // * @param radius
    // * The radius of the circle of the intersection area.
    // *
    // * @return
    // * True if the plane intersects the sphere.
    // */
    //static bool
    //sphereIntersectsPlanePoint(const Sphere& s, 
    //                           const Plane& p, 
    //                           Vector3f* point, 
    //                           float* radius);
    ///**
    // * @brief
    // * Intersection between a sphere and a box.
    // *
    // * @description
    // * Returns true if the sphere intersects the box, but it isn't inside.
    // *
    // * @param s
    // * The sphere to check.
    // * @param b
    // * The box to check.
    // *
    // * @return
    // * True if the sphere intersects the box, but it isn't inside.
    // */
    //static bool
    //sphereIntersectsBox(const Sphere& s, const BoxAAB& b);
    //
    ///**
    // * @brief
    // * Intersection between a plane and a point.
    // *
    // * @description
    // * Returns true if the point is on the plane.
    // *
    // * @param _plane
    // * The plane to check.
    // * @param _point
    // * The point to check.
    // *
    // * @return
    // * True if the point is on the plane.
    // */
    //static bool 
    //intersectionPlanePoint(const Plane& _plane, const Vector3f& _point);
    ///**
    // * @brief
    // * Intersection between a two planes.
    // *
    // * @description
    // * Returns true if the first plane intersects the second.
    // *
    // * @param _plane1
    // * The first plane to check.
    // * @param _plane2
    // * The second plane to check.
    // *
    // * @return
    // * True if the first plane intersects the second.
    // */
    //static bool
    //intersectionPlanePlane(const Plane& _plane1, const Plane& _plane2);
    ///**
    // * @brief
    // * Intersection between a sphere and a point.
    // *
    // * @description
    // * Returns true if the point is inside the sphere.
    // *
    // * @param _sphere
    // * The sphere to check.
    // * @param _point
    // * The point to check.
    // *
    // * @return
    // * True if the point is inside the sphere.
    // */
    //static bool
    //intersectionSpherePoint(const Sphere& _sphere, const Vector3f& _point);
    ///**
    // * @brief
    // * Intersection between a sphere and a plane.
    // *
    // * @description
    // * Returns true if the plane intersects the sphere.
    // *
    // * @param _sphere
    // * The sphere to check.
    // * @param _plane
    // * The plane to check.
    // *
    // * @return
    // * True if the plane intersects the sphere.
    // */
    //static bool
    //intersectionSpherePlane(const Sphere& _sphere, const Plane& _plane);
    ///**
    // * @brief
    // * Intersection between a two spheres.
    // *
    // * @description
    // * Returns true if the first sphere intersects the second.
    // *
    // * @param _sphere1
    // * The first sphere to check.
    // * @param _sphere2
    // * The second sphere to check.
    // *
    // * @return
    // * True if the first sphere intersects the second.
    // */
    //static bool
    //intersectionSphereSphere(const Sphere& _sphere1, const Sphere& _sphere2);
    ///**
    // * @brief
    // * Intersection between a box and a point.
    // *
    // * @description
    // * Returns true if the point is in the box.
    // *
    // * @param _box
    // * The box to check.
    // * @param _point
    // * The point to check.
    // *
    // * @return
    // * True if the point is in the box.
    // */
    //static bool
    //intersectionBoxPoint(const BoxAAB& _box, const Vector3f& _point);
    ///**
    // * @brief
    // * Intersection between a box and a plane.
    // *
    // * @description
    // * Returns true if the plane intersects the box.
    // *
    // * @param _box
    // * The box to check.
    // * @param _plane
    // * The plane to check.
    // *
    // * @return
    // * True if the plane intersects the box.
    // */
    //static bool
    //intersectionBoxPlane(const BoxAAB& _box, const Plane& _plane);
    ///**
    // * @brief
    // * Intersection between a box and a sphere.
    // *
    // * @description
    // * Returns true if the sphere intersects the box.
    // *
    // * @param _box
    // * The box to check.
    // * @param _sphere
    // * The sphere to check.
    // *
    // * @return
    // * True if the sphere intersects the box.
    // */
    //static bool
    //intersectionBoxSphere(const BoxAAB& _box, const Sphere& _sphere);
    ///**
    // * @brief
    // * Intersection between two boxes.
    // *
    // * @description
    // * Returns true if the first box intersects the second.
    // *
    // * @param _box1
    // * The first box to check.
    // * @param _box2
    // * The second box to check.
    // *
    // * @return
    // * True if the first box intersects the second.
    // */
    //static bool
    //intersectionBoxBox(const BoxAAB& _box1, const BoxAAB& _box2);
    ///**
    // * @brief
    // * Intersection between a capsule and a point.
    // *
    // * @description
    // * Returns true if the point is in the capsule.
    // *
    // * @param _capsule
    // * The capsule to check.
    // * @param _point
    // * The point to check.
    // *
    // * @return
    // * True if the point is in the capsule.
    // */
    //static bool
    //intersectionCapsulePoint(const Capsule& _capsule, const Vector3f& _point);
    ///**
    // * @brief
    // * Intersection between a capsule and a plane.
    // *
    // * @description
    // * Returns true if the plane intersects the capsule.
    // *
    // * @param _capsule
    // * The capsule to check.
    // * @param _plane
    // * The plane to check.
    // *
    // * @return
    // * True if the plane intersects the capsule.
    // */
    //static bool
    //intersectionCapsulePlane(const Capsule& _capsule, const Plane& _plane);
    ///**
    // * @brief
    // * Intersection between a capsule and a sphere.
    // *
    // * @description
    // * Returns true if the sphere intersects the capsule.
    // *
    // * @param _capsule
    // * The capsule to check.
    // * @param _sphere
    // * The sphere to check.
    // *
    // * @return
    // * True if the sphere intersects the capsule.
    // */
    //static bool
    //intersectionCapsuleSphere(const Capsule& _capsule, const Sphere& _sphere);
    ///**
    // * @brief
    // * Intersection between a capsule and a box.
    // *
    // * @description
    // * Returns true if the box intersects the capsule.
    // *
    // * @param _capsule
    // * The capsule to check.
    // * @param _box
    // * The box to check.
    // *
    // * @return
    // * True if the box intersects the capsule.
    // */
    ////static bool
    ////intersectionCapsuleBox(const Capsule& _capsule, const BoxAAB& _box);
    ///**
    // * @brief
    // * Intersection between two capsules.
    // *
    // * @description
    // * Returns true if the first capsule intersects the second.
    // *
    // * @param _capsule1
    // * The first capsule to check.
    // * @param _capsule2
    // * The second capsule to check.
    // *
    // * @return
    // * True if the first capsule intersects the second.
    // */
    //static bool
    //intersectionCapsuleCapsule(const Capsule& _capsule1, const Capsule& _capsule2);
    ///**
    // * @brief
    // * Intersection between a rectangle and a 2D point.
    // *
    // * @description
    // * Returns true if the point is in the rectangle.
    // *
    // * @param _rectangle
    // * The rectangle to check.
    // * @param _point2D
    // * The point to check.
    // *
    // * @return
    // * True if the point is in the rectangle.
    // */
    //static bool
    //intersectionRectanglePoint2D(const Rectangle& _rectangle, const Vector2f& _point2D);
    ///**
    // * @brief
    // * Intersection between two rectangles.
    // *
    // * @description
    // * Returns true if the first rectangle intersects the second.
    // *
    // * @param _rectangle1
    // * The first rectangle to check.
    // * @param _rectangle2
    // * The second rectangle to check.
    // *
    // * @return
    // * True if the first rectangle intersects the second.
    // */
    //static bool
    //intersectionRectangleRectangle(const Rectangle& _rectangle1, const Rectangle& _rectangle2);
  
    /***************************************************************************/
    /*                                                                         */
    /*                               Constants                                 */
    /*                                                                         */
    /***************************************************************************/
  
    /**
     * @brief
     * The approximate value of pi.
     */
    static const float kPI;
    /**
     * @brief
     * Pi divided by 180.
     */
    static const float kPI_OVER_180;
    /**
     * @brief
     * 180 divided by pi.
     */
    static const float k180_OVER_PI;
    /**
     * @brief
     * Pi times 2.
     */
    static const float k2_PI;
    /**
     * @brief
     * Pi over 2.
     */
    static const float kPI_OVER_2;
  
    /**
     * @brief
     * The value of e.
     */
    static const float kEULER;
  
    /**
     * @brief
     * The maximum float possible.
     */
    static const float kMAX_FLOAT;
    /**
     * @brief
     * The minimum float possible.
     */
    static const float kMIN_FLOAT;
    /**
     * @brief
     * The maximum double possible.
     */
    static const double kMAX_DOUBLE;
    /**
     * @brief
     * The minimum long double possible.
     */
    static const long double kMIN_LONG_DOUBLE;
    /**
     * @brief
     * The maximum long double possible.
     */
    static const long double kMAX_LONG_DOUBLE;
    /**
     * @brief
     * The minimum double possible.
     */
    static const double kMIN_DOUBLE;
    /**
     * @brief
     * The minimum integer of 32 bits possible.
     */
    static const int32 kMIN_INT;
    /**
     * @brief
     * The maximum integer of 32 bits possible.
     */
    static const int32 kMAX_INT;
    /**
     * @brief
     * The maximum integer of 32 bits possible.
     */
    static const uint32 kMAX_UINT;
  };
  
  
  template<typename T>
  FORCEINLINE T
  PlatformMath::cos(const T& _radian)
  {
    return std::cos(_radian);
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::cosd(const T& _degree)
  {
    return std::cos(degToRad(_degree));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::sin(const T& _radian)
  {
    return std::sin(_radian);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::sind(const T& _degree)
  {
    return std::sin(degToRad(_degree));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::tan(const T& _radian)
  {
    return std::tan(_radian);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::tand(const T& _degree)
  {
    return std::tan(degToRad(_degree));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::sec(const T& _radian)
  {
    return 1 / cos(_radian);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::secd(const T& _degree)
  {
    return 1 / cos(degToRad(_degree));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::csc(const T& _radian)
  {
    return 1 / sin(_radian);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::cscd(const T& _degree)
  {
    return 1 / sin(degToRad(_degree));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::cot(const T& _radian)
  {
    return 1 / tan(_radian);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::cotd(const T& _degree)
  {
    return 1 / tan(degToRad(_degree));
  }
  
  template<typename T>
  FORCEINLINE T 
  PlatformMath::acos(const T& _value)
  {
    return std::acos(_value);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::acosd(const T& _value)
  {
    return degToRad(std::acos(_value));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::asin(const T& _value)
  {
    return std::asin(_value);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::asind(const T& _value)
  {
    return degToRad(std::asin(_value));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::atan(const T& _value)
  {
    return std::atan(_value);
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::atan2(const T& Y, const T& X)
  {
    return std::atan2(Y, X);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::atand(const T& _value)
  {
    return degToRad(std::atan(_value));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::asec(const T& _value)
  {
    return acos(1 / _value);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::asecd(const T& _value)
  {
    return degToRad(acos(1 / _value));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::acsc(const T& _value)
  {
    return asin(1 / _value);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::acscd(const T& _value)
  {
    return degToRad(asin(1 / _value));
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::acot(const T& _value)
  {
    return atan(1 / _value);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::acotd(const T& _value)
  {
    return degToRad(atan(1 / _value));
  }
  
  template<typename T>
  FORCEINLINE T 
  PlatformMath::radToDeg(const T& _radian)
  {
    return _radian * k180_OVER_PI;
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::degToRad(const T& _degree)
  {
    return _degree * kPI_OVER_180;
  }
  
  template<typename T>
  FORCEINLINE T 
  PlatformMath::fmod(const T& _lval, const T& _rval)
  {
    return _lval - floor(_lval / _rval) * _rval;
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::sqrt(T _val)
  {
    return std::sqrt(_val);
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::pow(T _base, T _power)
  {
    return std::pow(_base, _power);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::log2(T _value)
  {
    return std::log2(_value);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::log10(T _value)
  {
    return std::log10(_value);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::log(T _value)
  {
    return std::log(_value);
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::log(T _value, T _base)
  {
    return std::log(_value) / std::log(_base);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::exp(T _value)
  {
    return T();
  }
  
  template<typename T>
  FORCEINLINE T 
  PlatformMath::round(T _val)
  {
    return std::round(_val);
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::floor(T _val)
  {
    return std::floor(_val);
  }
  template<typename T>
  FORCEINLINE T 
  PlatformMath::ceil(T _val)
  {
    return std::ceil(_val);
  }
  
  template<typename T>
  FORCEINLINE T 
  PlatformMath::abs(T _val)
  {
    return std::abs(_val);
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::sign(T _val)
  {
    return abs(_val) / _val;
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::copysign(T _mag, T _sgn)
  {
    return abs(_mag) * sign(_sgn);
  }
  
  template<typename T>
  FORCEINLINE T
  PlatformMath::max(const T& _val1, const T& _val2)
  {
    return _val1 > _val2 ? _val1 : _val2;
  }
  template<typename T>
  FORCEINLINE T
  PlatformMath::min(const T& _val1, const T& _val2)
  {
    return _val1 < _val2 ? _val1 : _val2;
  }
  
  FORCEINLINE bool
  PlatformMath::checkEqual(float _val1,
                           float _val2,
                           float maxRelativeDiff)
  {
    float diff = fabs(_val1 - _val2);

    _val1 = fabs(_val1);
    _val2 = fabs(_val2);
    float largest = (_val2 > _val1) ? _val2 : _val1;

    return diff <= largest * maxRelativeDiff;
  }
  FORCEINLINE bool
  PlatformMath::checkEqual(double _val1,
                           double _val2,
                           double maxRelativeDiff)
  {
    double diff = fabs(_val1 - _val2);

    _val1 = fabs(_val1);
    _val2 = fabs(_val2);
    double largest = (_val2 > _val1) ? _val2 : _val1;

    return diff <= largest * maxRelativeDiff;
  }
  FORCEINLINE bool
  PlatformMath::checkEqual(long double _val1,
                           long double _val2,
                           long double maxRelativeDiff)
  {
    long double diff = fabs(_val1 - _val2);

    _val1 = fabs(_val1);
    _val2 = fabs(_val2);
    long double largest = (_val2 > _val1) ? _val2 : _val1;

    return diff <= largest * maxRelativeDiff;
  }
  
  template<typename V, typename F>
  FORCEINLINE bool
  PlatformMath::hasFlag(const V& _val, const F& _flag)
  {
    return (_val & _flag) == _flag;
  }
}