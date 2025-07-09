#pragma once

struct Vector3
{
	float x, y, z;

	Vector3(float x = 0, float y = 0, float z = 0);

	Vector3 operator-(const Vector3& other) const;
	Vector3 operator+(const Vector3& other) const;
	Vector3 operator*(float scalar) const;
	Vector3& operator+=(const Vector3& other);

	Vector3 Normalize() const;
	float Length() const;
	float DistanceTo(const Vector3& other) const;

	static float Dot(const Vector3& a, const Vector3& b);
	static Vector3 Cross(const Vector3& a, const Vector3& b);
	static float Clamp(float value, float min, float max);
	static float RadiansToDegrees(float radians);
};