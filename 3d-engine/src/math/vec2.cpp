#include "vector.h"

namespace photon {
	namespace math {
		
		vec2::vec2() {
			x = 0.0;
			y = 0.0;
		}

		vec2::vec2(const float& x, const float& y) {
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

		float vec2::dot(const vec2& other) {
			return x * other.x + y * other.y;
		}

		float vec2::getItem(int i) const {
			if (i == 0) {
				return x;
			}
			else {
				return y;
			}
		}
		void vec2::setItem(int i, float val) {
			if (i == 0) {
				x = val;
			}
			else {
				y = val;
			}
		}


		vec2 operator+(const vec2& left, const vec2& right) {
			vec2 output = left;
			return output.add(right);
		}
		vec2 operator-(const vec2& left, const vec2& right) {
			vec2 output = left;
			return output.subtract(right);
		}
		vec2 operator*(const vec2& left, const vec2& right) {
			vec2 output = left;
			return output.multiply(right);
		}
		vec2 operator/(const vec2& left, const vec2& right) {
			vec2 output = left;
			return output.divide(right);
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