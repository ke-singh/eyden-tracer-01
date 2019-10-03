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
		// --- PUT YOUR CODE HERE ---
		Vec3f aa, bb, cc, p;
		aa = (m_b - ray.org).cross(m_a - ray.org);
		bb = (m_c - ray.org).cross(m_b - ray.org);
		cc = (m_a - ray.org).cross(m_c - ray.org);

		float s_area = aa.dot(ray.dir) + bb.dot(ray.dir) + cc.dot(ray.dir);
		float X = aa.dot(ray.dir) / s_area;
		float Y = bb.dot(ray.dir) / s_area;
		float Z = cc.dot(ray.dir) / s_area;

		if (X < 0 || Y < 0 || Z < 0)
		{
			return false;
		}
		p = X * m_a + Y * m_b + Z * m_c;
		float t = p[0] / ray.dir[0];
		if (t < Epsilon || t > ray.t)
			return false;
		ray.t = t;
		return true;
	}

private:
	Vec3f m_a; ///< Position of the first vertex
	Vec3f m_b; ///< Position of the second vertex
	Vec3f m_c; ///< Position of the third vertex
};
