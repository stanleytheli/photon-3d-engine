#include "vector.h"

namespace photon {
	namespace math {

		vec4::vec4() {
			x = 0.0;
			y = 0.0;
			z = 0.0;
			w = 0.0;
		}

		vec4::vec4(const float& x, const float& y, const float& z, const float& w) {
			this->x = x;
			this->y = y;
			this->z = z;
			this->w = w;
		}

		vec4& vec4::add(const vec4& other) {
			x += other.x;
			y += other.y;
			z += other.z;
			w += other.w;
			return *this;
		}

		vec4& vec4::subtract(const vec4& other) {
			x -= other.x;
			y -= other.y;
			z -= other.z;
			w -= other.w;
			return *this;
		}

		vec4& vec4::multiply(const vec4& other) {
			x *= other.x;
			y *= other.y;
			z *= other.z;
			w *= other.w;
			return *this;
		}

		vec4& vec4::divide(const vec4& other) {
			x /= other.x;
			y /= other.y;
			z /= other.z;
			w /= other.w;
			return *this;
		}

		float vec4::dot(const vec4& other) const {
			return x * other.x + y * other.y + z * other.z + w * other.w;
		}

		float vec4::getItem(int i) const {
			if (i == 0) {
				return x;
			}
			else if (i == 1) {
				return y;
			}
			else if (i == 2) {
				return z;
			}
			else {
				return w;
			}
		}
		void vec4::setItem(int i, float val) {
			if (i == 0) {
				x = val;
			}
			else if (i == 1) {
				y = val;
			}
			else if (i == 2) {
				z = val;
			}
			else {
				w = val;
			}
		}

		vec4 operator+(const vec4& left, const vec4& right) {
			vec4 output = left;
			return output.add(right);
		}
		vec4 operator-(const vec4& left, const vec4& right) {
			vec4 output = left;
			return output.subtract(right);
		}
		vec4 operator*(const vec4& left, const vec4& right) {
			vec4 output = left;
			return output.multiply(right);
		}
		vec4 operator/(const vec4& left, const vec4& right) {
			vec4 output = left;
			return output.divide(right);
		}

		vec4& vec4::operator+=(const vec4& other) { return add(other); }
		vec4& vec4::operator-=(const vec4& other) { return subtract(other); }
		vec4& vec4::operator*=(const vec4& other) { return multiply(other); }
		vec4& vec4::operator/=(const vec4& other) { return divide(other); }

		bool vec4::operator==(const vec4& other) { return (x == other.x) && (y == other.y) && (z == other.z); }
		bool vec4::operator!=(const vec4& other) { return !(*this == other); }


		float vec4::magnitude() const { return sqrt(x * x + y * y + z * z + w * w); }
		vec4 vec4::normalized() const {
			vec4 output = *this;
			output.divide(magnitude());
			return output;
		}
		vec4& vec4::multiply(const float scale) {
			x *= scale;
			y *= scale;
			z *= scale;
			w *= scale;
			return *this;
		}
		vec4& vec4::divide(const float scale) {
			x /= scale;
			y /= scale;
			z /= scale;
			w /= scale;
			return *this;
		}
		vec4 operator*(const vec4& left, const float scale) {
			vec4 output = left;
			return output.multiply(scale);
		}
		vec4 operator/(const vec4& left, const float scale) {
			vec4 output = left;
			return output.divide(scale);
		}
		vec4& vec4::operator*=(const float scale) {
			return multiply(scale);
		}
		vec4& vec4::operator/=(const float scale) {
			return divide(scale);
		}

		std::ostream& operator<<(std::ostream& stream, const vec4& vec) {
			stream << "vec4(" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << ")";
			return stream;
		}
	}
}