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
		float x, y, z, w;
		x = ray.dir.dot(ray.dir);
		y = 2 * ray.dir.dot(ray.org - m_center);
		z=ray.org - m_center).dot(ray.org - m_center) - m_radius * m_radius;
		w = (y * y) - 4 * x * z;

		if (w < 0)
		{
			return false;
		}

		float a, b;

		a = ((-y) + sqrt(w)) / 2 * z;
		b = ((-y) - sqrt(w)) / 2 * z;
		if ((a < Epsilon && b < Epsilon) || (a > ray.t && b > ray.t))
		{
			return false;
		}

		// find the smallest value a
		if (a < b)
		{
			ray.t = a;
		}
		else
		{
			ray.t = b;
		}

		return true;
	}

private:
	Vec3f m_center; ///< Position of the center of the sphere
	float m_radius; ///< Radius of the sphere
};
