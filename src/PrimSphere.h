#pragma once

#include "Prim.h"

/**
 * @brief Sphere Geaometrical Primitive class
 */
class CPrimSphere : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param center Position of the center of the sphere
	 * @param radius Radius of the sphere
	 */
	CPrimSphere(Vec3f center, float radius)
		: CPrim(), m_center(center), m_radius(radius)
	{
	}
	virtual ~CPrimSphere(void) = default;

	virtual bool Intersect(Ray &ray) override
	{
		// --- PUT YOUR CODE HERE ---
		float x, y, z;
		x = ray.dir.dot(ray.dir);
		y = 2 * ray.dir.dot(ray.org - m_center);
		z = (ray.org - m_center).dot(ray.org - m_center) - m_radius * m_radius;

		float testValue = y * y - (4 * x * z);
		if (testValue < 0)
		{
			return false;
		}

		float t = ((-y) + sqrt(testValue)) / x;

		if (t < Epsilon || t > ray.t)
		{
			return false;
		}

		ray.t = t;
		return true;
	}

private:
	Vec3f m_center; ///< Position of the center of the sphere
	float m_radius; ///< Radius of the sphere
};
