#pragma once

#include <iostream>

namespace photon {
	namespace math {

		struct vec2 {
			double x, y;

			vec2();
			vec2(const double& x, const double& y);

			vec2& add(const vec2& other);
			vec2& subtract(const vec2& other);
			vec2& multiply(const vec2& other);
			vec2& divide(const vec2& other);

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

			vec3& add(const vec3& other);
			vec3& subtract(const vec3& other);
			vec3& multiply(const vec3& other);
			vec3& divide(const vec3& other);

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


	}
}
