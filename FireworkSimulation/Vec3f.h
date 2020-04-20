#pragma once
/*
 * Vec3f class for 3d math
 *
 * Authors: Brian Ploeckelman
 *          Matthew Bayer
 */
#include <iostream>
#include <math.h>


class Vec3f
{
private:
	float _x, _y, _z;

public:
	Vec3f(const float x=0.f, const float y=0.f, const float z=0.f)
		: _x(x), _y(y), _z(z)
	{ }
	Vec3f(const Vec3f& other)
		: _x(other._x)
		, _y(other._y)
		, _z(other._z)
	{ }

	// Component setters (can be chained)
	inline Vec3f& x(const float x) { _x = x; return *this; }
	inline Vec3f& y(const float y) { _y = y; return *this; }
	inline Vec3f& z(const float z) { _z = z; return *this; }
	inline Vec3f& set(const float x, const float y, const float z)
	{
		_x = x;
		_y = y;
		_z = z;
		return *this;
	}

	// Component getters
	inline const float x() const { return _x; }
	inline const float y() const { return _y; }
	inline const float z() const { return _z; }

	// Pointer to float getter (for gl*fv())
	inline const float* v() const { return &_x; }

	// Dot product
	inline float dot(const Vec3f& rhs) const
	{
		return _x * rhs._x 
			 + _y * rhs._y 
			 + _z * rhs._z;
	}

	// Cross product
	inline Vec3f cross(const Vec3f& rhs) const 
	{
		return Vec3f(
			_y * rhs._z - _z * rhs._y, 
			_z * rhs._x - _x * rhs._z, 
			_x * rhs._y - _y * rhs._x );
	}

	// Normalization
	inline Vec3f& normalize() 
	{
		float d = sqrt(_x * _x + _y * _y + _z * _z);
		if( d == 0.f )
			d = 1.f;

		(*this) *= 1.f / d; 

		return *this;
	}

	// Assignment operator
	inline const Vec3f& operator=(const Vec3f& rhs)
	{
		if( this != &rhs ) 
		{
			_x = rhs._x;
			_y = rhs._y;
			_z = rhs._z;
		}
		return *this;
	}

	// Addition assignment 
	inline const Vec3f& operator+=(const Vec3f& rhs)
	{
		_x += rhs._x;
		_y += rhs._y;
		_z += rhs._z;
		return *this;
	}

	// Subtraction assignment 
	inline const Vec3f& operator-=(const Vec3f& rhs)
	{
		_x -= rhs._x;
		_y -= rhs._y;
		_z -= rhs._z;
		return *this;
	}

	// Scalar multiplication assignment 
	inline const Vec3f& operator*=(const float rhs)
	{
		_x *= rhs;
		_y *= rhs;
		_z *= rhs;
		return *this;
	}

	// Equality operator
	inline bool operator==(const Vec3f& other)
	{
		return (this->_x == other._x 
			 && this->_y == other._y
			 && this->_z == other._z);
	}

	//  Inequality operator
	inline bool operator!=(const Vec3f& other)
	{
		return (this->_x != other._x 
			 && this->_y != other._y
			 && this->_z != other._z);
	}

	// Print components to a given ostream (defaults to cout)
	inline void print(std::ostream& out=std::cout) const 
	{
		out << "("  << _x 
			<< ", " << _y 
			<< ", " << _z
			<< ") ";
	}

	// Returns the magnitude of the vector's components
	inline float magnitude() const
	{
		return sqrt(_x * _x + _y * _y + _z * _z);
	}

};

inline float dot(const Vec3f& lhs, const Vec3f& rhs)
{
	return lhs.dot(rhs);
}

inline Vec3f cross(const Vec3f& lhs, const Vec3f& rhs)
{
	return lhs.cross(rhs);
}

inline Vec3f normalize(const Vec3f& v)
{
	Vec3f result(v);
	return result.normalize();
}

inline float magnitude(const Vec3f& v)
{
	return v.magnitude();
}

inline Vec3f operator+(const Vec3f& lhs, const Vec3f& rhs)
{
	Vec3f result(rhs);
	result += lhs;
	return result;
}

inline Vec3f operator-(const Vec3f& lhs, const Vec3f& rhs)
{
	Vec3f result(rhs);
	result -= lhs;
	return result;
}

inline Vec3f operator*(const Vec3f& lhs, const float rhs)
{
	Vec3f result(lhs);
	result *= rhs;
	return result;
}

inline Vec3f operator*(const float lhs, const Vec3f& rhs)
{
	Vec3f result(rhs);
	result *= lhs;
	return result;
}

inline std::ostream& operator<<(std::ostream& out, const Vec3f& rhs)
{
	rhs.print(out);
	return out;
}

inline Vec3f lerp(const float t, const Vec3f& p0, const Vec3f& p1)
{
	return (p0 + t * (p1 - p0));
}
