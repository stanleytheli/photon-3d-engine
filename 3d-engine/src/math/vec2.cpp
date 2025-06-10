#include "vector.h"

namespace photon {
	namespace math {
		
		vec2::vec2() {
			x = 0.0;
			y = 0.0;
		}

		vec2::vec2(const double& x, const double& y) {
			this->x = x;
			this->y = y;
		}

		vec2& vec2::add(const vec2& other) {
			x += other.x;
			y += other.y;
			return *this;
		}

		vec2& vec2::subtract(const vec2& other) {
			x -= other.x;
			y -= other.y;
			return *this;
		}

		vec2& vec2::multiply(const vec2& other) {
			x *= other.x;
			y *= other.y;
			return *this;
		}

		vec2& vec2::divide(const vec2& other) {
			x /= other.x;
			y /= other.y;
			return *this;
		}

		vec2 operator+(const vec2& left, const vec2& right) {
			vec2 output(left.x + right.x, left.y + right.y);
			return output;
		}
		vec2 operator-(const vec2& left, const vec2& right) {
			vec2 output(left.x - right.x, left.y - right.y);
			return output;
		}
		vec2 operator*(const vec2& left, const vec2& right) {
			vec2 output(left.x * right.x, left.y * right.y);
			return output;
		}
		vec2 operator/(const vec2& left, const vec2& right) {
			vec2 output(left.x / right.x, left.y / right.y);
			return output;
		}

		vec2& vec2::operator+=(const vec2& other) { return add(other); }
		vec2& vec2::operator-=(const vec2& other) { return subtract(other); }
		vec2& vec2::operator*=(const vec2& other) { return multiply(other); }
		vec2& vec2::operator/=(const vec2& other) { return divide(other); }

		bool vec2::operator==(const vec2& other) { return (x == other.x) && (y == other.y); }
		bool vec2::operator!=(const vec2& other) { return !(*this == other); }

		std::ostream& operator<<(std::ostream& stream, const vec2& vec) {
			stream << "vec2(" << vec.x << ", " << vec.y << ")";
			return stream;
		}
	}
}