#pragma once

#include <iostream>

namespace photon {
	namespace math {

		struct vec2 {
			double x, y;

			vec2();
			vec2(const double& x, const double& y);

			// Adds the given vector to this vector
			vec2& add(const vec2& other);
			// Subtracts the given vector from this vector
			vec2& subtract(const vec2& other);
			// Multiplies this vector with the given vector, element-by-element
			vec2& multiply(const vec2& other);
			// Divides this vector by the given vector, element-by-element
			vec2& divide(const vec2& other);

			// Returns the value of (this vector) dot (other vector)
			double dot(const vec2& other);

			double getItem(int i) const;
			void setItem(int i, double val);

			friend vec2 operator+(const vec2& left, const vec2& right);
			friend vec2 operator-(const vec2& left, const vec2& right);
			friend vec2 operator*(const vec2& left, const vec2& right);
			friend vec2 operator/(const vec2& left, const vec2& right);

			vec2& operator+=(const vec2& other);
			vec2& operator-=(const vec2& other);
			vec2& operator*=(const vec2& other);
			vec2& operator/=(const vec2& other);

			bool operator==(const vec2& other);
			bool operator!=(const vec2& other);
		
			friend std::ostream& operator<<(std::ostream& stream, const vec2& vec);
		};

		struct vec3 {
			double x, y, z;

			vec3();
			vec3(const double& x, const double& y, const double& z);

			// Adds the given vector to this vector			
			vec3& add(const vec3& other);
			// Subtracts the given vector from this vector
			vec3& subtract(const vec3& other);
			// Multiplies this vector with the given vector, element-by-element
			vec3& multiply(const vec3& other);
			// Divides this vector by the given vector, element-by-element
			vec3& divide(const vec3& other);
			
			// Returns the value of (this vector) dot (given vector)
			double dot(const vec3& other);
			// Returns the result of (this vector) cross (given vector)
			vec3 cross(const vec3& other);

			double getItem(int i) const;
			void setItem(int i, double val);

			friend vec3 operator+(const vec3& left, const vec3& right);
			friend vec3 operator-(const vec3& left, const vec3& right);
			friend vec3 operator*(const vec3& left, const vec3& right);
			friend vec3 operator/(const vec3& left, const vec3& right);

			vec3& operator+=(const vec3& other);
			vec3& operator-=(const vec3& other);
			vec3& operator*=(const vec3& other);
			vec3& operator/=(const vec3& other);

			bool operator==(const vec3& other);
			bool operator!=(const vec3& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vec);
		};

		struct vec4 {
			double x, y, z, w;

			vec4();
			vec4(const double& x, const double& y, const double& z, const double& w);

			// Adds the given vector to this vector			
			vec4& add(const vec4& other);
			// Subtracts the given vector from this vector
			vec4& subtract(const vec4& other);
			// Multiplies this vector with the given vector, element-by-element
			vec4& multiply(const vec4& other);
			// Divides this vector by the given vector, element-by-element
			vec4& divide(const vec4& other);

			// Returns the value of (this vector) dot (given vector)
			double dot(const vec4& other);

			double getItem(int i) const;
			void setItem(int i, double val);

			friend vec4 operator+(const vec4& left, const vec4& right);
			friend vec4 operator-(const vec4& left, const vec4& right);
			friend vec4 operator*(const vec4& left, const vec4& right);
			friend vec4 operator/(const vec4& left, const vec4& right);

			vec4& operator+=(const vec4& other);
			vec4& operator-=(const vec4& other);
			vec4& operator*=(const vec4& other);
			vec4& operator/=(const vec4& other);

			bool operator==(const vec4& other);
			bool operator!=(const vec4& other);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vec);
		};


	}
}
