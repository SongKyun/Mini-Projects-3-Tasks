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

// ��Į�� ����
Vector3 Vector3::operator*(float scalar) const
{
	return Vector3(x * scalar, y * scalar, z * scalar);
}

Vector3& Vector3::operator+=(const Vector3& other)
{
	x += other.x; y += other.y; z += other.z;
	return *this;
}

// ���� ����ȭ
Vector3 Vector3::Normalize() const
{
	float len = Length();
	if (len == 0) return Vector3();
	return Vector3(x / len, y / len, z / len);
}

// ���� ����
float Vector3::Length() const
{
	return std::sqrt(x * x + y * y + z * z);
}

// �� ���� �� �Ÿ�
float Vector3::DistanceTo(const Vector3& other) const
{
	return (*this - other).Length();
}

// ���� : ���� ���絵 �Ǻ�
float Vector3::Dot(const Vector3& a, const Vector3& b)
{
	return a.x * b.x + a.y * b.y + a.z * b.z;
}

// ���� : ȸ�� ���� ����
Vector3 Vector3::Cross(const Vector3& a, const Vector3& b)
{
	return Vector3(
		a.y * b.z - a.z * b.y,
		a.z * b.x - a.x * b.z,
		a.x * b.y - a.y * b.x
	);
}

// ���� ����
float Vector3::Clamp(float value, float min, float max)
{
	if (value < min) return min;
	if (value > max) return max;
	return value;
}

// ���� ��ȯ(����->��)
float Vector3::RadiansToDegrees(float radians)
{
	return radians * (180.0f / 3.14159265358979323846f);
}