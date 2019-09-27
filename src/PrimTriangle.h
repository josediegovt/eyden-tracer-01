// Triangle Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Triangle Geaometrical Primitive class
 */
class CPrimTriangle : public CPrim{
	private:
		Vec3f m_a;	///< Position of the first vertex
		Vec3f m_b;	///< Position of the second vertex
		Vec3f m_c;	///< Position of the third vertex

	public:

		/**
		 * @brief Constructor
		 * @param a Position of the first vertex
		 * @param b Position of the second vertex
		 * @param c Position of the third vertex
		 */

		CPrimTriangle(Vec3f a, Vec3f b, Vec3f c): CPrim(), m_a(a), m_b(b), m_c(c){}

		virtual ~CPrimTriangle(void) = default;

		virtual bool Intersect(Ray& ray) override{
			float invDet = 1 / det;

			Vec3f tvec = ray.org - v0;

			u = tvec.dot(pvec) * invDet;

			Vec3f qvec = tvec.cross(v0v1);
			v = ray.dir.dot(qvec) * invDet;

			if(v < 0 || u + v > 1){
				return false;
			}

			t = v0v2.dotProduct(qvec) * invDet;

			return true;
		}
};
