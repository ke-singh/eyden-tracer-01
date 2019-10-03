#pragma once

#include "Prim.h"

/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim
{
public:
	/**
	 * @brief Constructor
	 * @param a Position of the first vertex
	 * @param b Position of the second vertex
	 * @param c Position of the third vertex
	 */
	CPrimTriangle(Vec3f a, Vec3f b, Vec3f c)
		: CPrim(), m_a(a), m_b(b), m_c(c)
	{
	}
	virtual ~CPrimTriangle(void) = default;

	virtual bool Intersect(Ray &ray) override
	{
		Vec3f nab, nbc, nca, normal;
		float sum, l1, l2, l3, d1, d2, t;

		nab = (v_y - ray.org).cross(v_x - ray.org);
		nbc = (v_z - ray.org).cross(v_y - ray.org);
		nca = (v_x - ray.org).cross(v_z - ray.org);

		sum = nab.dot(ray.dir) + nbc.dot(ray.dir) + nca.dot(ray.dir);
		l1 = nab.dot(ray.dir) / sum;
		l2 = nbc.dot(ray.dir) / sum;
		l3 = nca.dot(ray.dir) / sum;

		if (l1 < 0 || l2 < 0 || l3 < 0)
			return false;
		normal = (v_y - v_x).cross(v_z - v_x);
		d1 = -normal.dot(ray.org - v_x);
		d2 = normal.dot(ray.dir);
		if (d2 == 0)
		{
			return false;
		}
		else
		{
			t = d1 / d2;
		}
		if (t < Epsilon || t > ray.t)
		{
			return false;
		}
		ray.t = t;
		return true;
	}

private:
	Vec3f m_a; ///< Position of the first vertex
	Vec3f m_b; ///< Position of the second vertex
	Vec3f m_c; ///< Position of the third vertex
};
