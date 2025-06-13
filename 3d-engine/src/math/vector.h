#pragma once

#include <iostream>

namespace photon {
	namespace math {

		struct vec2 {
			float x, y;

			vec2();
			vec2(const float& x, const float& y);

			// Adds the given vector to this vector
			vec2& add(const vec2& other);
			// Subtracts the given vector from this vector
			vec2& subtract(const vec2& other);
			// Multiplies this vector with the given vector, element-by-element
			vec2& multiply(const vec2& other);
			// Divides this vector by the given vector, element-by-element
			vec2& divide(const vec2& other);

			// Returns the value of (this vector) dot (other vector)
			float dot(const vec2& other);

			float getItem(int i) const;
			void setItem(int i, float val);

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

			// Get the magnitude = sqrt(v dot v) of this vector
			float magnitude();
			// Get a normalized copy of this vector
			vec2 normalized();
			// Multiplies this vector by a scalar
			vec2& multiply(const float scale);
			// Divides this vector by a scalar
			vec2& divide(const float scale);
			friend vec2 operator*(const vec2& left, const float scale);
			friend vec2 operator/(const vec2& left, const float scale);
			vec2& operator*=(const float scale);
			vec2& operator/=(const float scale);

			friend std::ostream& operator<<(std::ostream& stream, const vec2& vec);
		};

		struct vec3 {
			float x, y, z;

			vec3();
			vec3(const float& x, const float& y, const float& z);

			// Adds the given vector to this vector			
			vec3& add(const vec3& other);
			// Subtracts the given vector from this vector
			vec3& subtract(const vec3& other);
			// Multiplies this vector with the given vector, element-by-element
			vec3& multiply(const vec3& other);
			// Divides this vector by the given vector, element-by-element
			vec3& divide(const vec3& other);
			
			// Returns the value of (this vector) dot (given vector)
			float dot(const vec3& other);
			// Returns the result of (this vector) cross (given vector)
			vec3 cross(const vec3& other);

			float getItem(int i) const;
			void setItem(int i, float val);

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

			// Get the magnitude = sqrt(v dot v) of this vector
			float magnitude();
			// Get a normalized copy of this vector
			vec3 normalized();
			// Multiplies this vector by a scalar
			vec3& multiply(const float scale);
			// Divides this vector by a scalar
			vec3& divide(const float scale);
			friend vec3 operator*(const vec3& left, const float scale);
			friend vec3 operator/(const vec3& left, const float scale);
			vec3& operator*=(const float scale);
			vec3& operator/=(const float scale);

			friend std::ostream& operator<<(std::ostream& stream, const vec3& vec);
		};

		struct vec4 {
			float x, y, z, w;

			vec4();
			vec4(const float& x, const float& y, const float& z, const float& w);

			// Adds the given vector to this vector			
			vec4& add(const vec4& other);
			// Subtracts the given vector from this vector
			vec4& subtract(const vec4& other);
			// Multiplies this vector with the given vector, element-by-element
			vec4& multiply(const vec4& other);
			// Divides this vector by the given vector, element-by-element
			vec4& divide(const vec4& other);

			// Returns the value of (this vector) dot (given vector)
			float dot(const vec4& other);

			float getItem(int i) const;
			void setItem(int i, float val);

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

			// Get the magnitude = sqrt(v dot v) of this vector
			float magnitude();
			// Get a normalized copy of this vector
			vec4 normalized();
			// Multiplies this vector by a scalar
			vec4& multiply(const float scale);
			// Divides this vector by a scalar
			vec4& divide(const float scale);
			friend vec4 operator*(const vec4& left, const float scale);
			friend vec4 operator/(const vec4& left, const float scale);
			vec4& operator*=(const float scale);
			vec4& operator/=(const float scale);

			friend std::ostream& operator<<(std::ostream& stream, const vec4& vec);
		};


	}
}
