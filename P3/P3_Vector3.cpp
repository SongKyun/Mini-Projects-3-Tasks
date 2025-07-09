#include <cmath>

#include "P3_Vector3.h"

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

Vector3 Vector3::operator-(const Vector3& other) const
{
	return Vector3(x - other.x, y - other.y, z - other.z);
}

Vector3 Vector3::operator+(const Vector3& other) const
{
	return Vector3(x + other.x, y + other.y, z + other.z);
}

// 스칼라 곱셈
Vector3 Vector3::operator*(float scalar) const
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x += other.x; y += other.y; z += other.z;
	return *this;
}

// 벡터 정규화
Vector3 Vector3::Normalize() const
{
	float len = Length();
	if (len == 0) return Vector3();
	return Vector3(x / len, y / len, z / len);
}

// 벡터 길이
float Vector3::Length() const
{
	return std::sqrt(x * x + y * y + z * z);
}

// 두 벡터 간 거리
float Vector3::DistanceTo(const Vector3& other) const
{
	return (*this - other).Length();
}

// 내적 : 방향 유사도 판별
float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// 외적 : 회전 방향 구분
Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

// 각도 제한
float Vector3::Clamp(float value, float min, float max)
{
	if (value < min) return min;
	if (value > max) return max;
	return value;
}

// 단위 변환(라디안->도)
float Vector3::RadiansToDegrees(float radians)
{
	return radians * (180.0f / 3.14159265358979323846f);
}