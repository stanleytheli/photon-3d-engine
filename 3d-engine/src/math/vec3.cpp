#include "vector.h"

namespace photon {
	namespace math {

		vec3::vec3() {
			x = 0.0;
			y = 0.0;
			z = 0.0;
		}

		vec3::vec3(const double& x, const double& y, const double& z) {
			this->x = x;
			this->y = y;
			this->z = z;
		}

		vec3& vec3::add(const vec3& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			return *this;
		}

		vec3& vec3::subtract(const vec3& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			return *this;
		}

		vec3& vec3::multiply(const vec3& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			return *this;
		}

		vec3& vec3::divide(const vec3& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			return *this;
		}

		vec3 operator+(const vec3& left, const vec3& right) {
			vec3 output(left.x + right.x, left.y + right.y, left.z + right.z);
			return output;
		}
		vec3 operator-(const vec3& left, const vec3& right) {
			vec3 output(left.x - right.x, left.y - right.y, left.z - right.z);
			return output;
		}
		vec3 operator*(const vec3& left, const vec3& right) {
			vec3 output(left.x * right.x, left.y * right.y, left.z * right.z);
			return output;
		}
		vec3 operator/(const vec3& left, const vec3& right) {
			vec3 output(left.x / right.x, left.y / right.y, left.z / right.z);
			return output;
		}

		vec3& vec3::operator+=(const vec3& other) { return add(other); }
		vec3& vec3::operator-=(const vec3& other) { return subtract(other); }
		vec3& vec3::operator*=(const vec3& other) { return multiply(other); }
		vec3& vec3::operator/=(const vec3& other) { return divide(other); }

		bool vec3::operator==(const vec3& other) { return (x == other.x) && (y == other.y) && (z == other.z); }
		bool vec3::operator!=(const vec3& other) { return !(*this == other); }

		std::ostream& operator<<(std::ostream& stream, const vec3& vec) {
			stream << "vec3(" << vec.x << ", " << vec.y << "," << vec.z << ")";
			return stream;
		}
	}
}