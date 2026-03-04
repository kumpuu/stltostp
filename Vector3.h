#pragma once
/*Copyright(c) 2026, kumpu, slugdev
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met :
1. Redistributions of source code must retain the above copyright
notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright
notice, this list of conditions and the following disclaimer in the
documentation and/or other materials provided with the distribution.
3. All advertising materials mentioning features or use of this software
must display the following acknowledgement :
This product includes software developed by slugdev.
4. Neither the name of the slugdev nor the
names of its contributors may be used to endorse or promote products
derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY SLUGDEV ''AS IS'' AND ANY
EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED.IN NO EVENT SHALL SLUGDEV BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/


#include <math.h>

struct Vector3
{
	union {
		struct { double x, y, z; };
		double data[3];
	};

	Vector3() : data{ 0.0, 0.0, 0.0 } {}
	Vector3(double x, double y, double z) : data{ x, y, z } {}

	void Vector3::operator+=(const Vector3& rhs) {
		for (int i = 0; i < 3; i++)
			this->data[i] += rhs.data[i];
	}

	Vector3 operator+(const Vector3& rhs) const {
		Vector3 res(*this);
		res += rhs;
		return res;
	}

	void Vector3::operator-=(const Vector3& rhs) {
		for (int i = 0; i < 3; i++)
			this->data[i] -= rhs.data[i];
	}

	Vector3 operator-(const Vector3& rhs) const {
		Vector3 res(*this);
		res -= rhs;
		return res;
	}

	void Vector3::operator*=(const double& rhs) {
		for (int i = 0; i < 3; i++)
			this->data[i] *= rhs;
	}

	Vector3 operator*(const double& rhs) const {
		Vector3 res(*this);
		res *= rhs;
		return res;
	}

	void Vector3::operator/=(const double& rhs) {
		for (int i = 0; i < 3; i++)
			this->data[i] /= rhs;
	}

	Vector3 operator/(const double& rhs) const {
		Vector3 res(*this);
		res /= rhs;
		return res;
	}

	double Vector3::operator*(const Vector3& rhs) const {
		double res = 0;
		for (int i = 0; i < 3; i++)
			res += this->data[i] * rhs.data[i];

		return res;
	}

	Vector3 cross(const Vector3& rhs) const {
		return Vector3(y * rhs.z - z * rhs.y,
			z * rhs.x - x * rhs.z,
			x * rhs.y - y * rhs.x);
	}

	double len()
	{
		return sqrt(x * x + y * y + z * z);
	}

	void normalize() {
		(*this) /= this->len();
	}
};
