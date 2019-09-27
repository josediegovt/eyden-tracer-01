// Plane Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief The Plane Geaometrical Primitive class
 */
class CPrimPlane : public CPrim{
	private:
		Vec3f m_normal;	///< Point on the plane
		Vec3f m_origin;	///< Normal to the plane

	public:

		/**
		 * @brief Constructor
		 * @param origin Point on the plane
		 * @param normal Normal to the plane
		 */

		CPrimPlane(Vec3f origin, Vec3f normal): CPrim(), m_normal(normal), m_origin(origin){
			normalize(m_normal);
		}

		virtual ~CPrimPlane(void) = default;

		virtual bool Intersect(Ray& ray) override{
			// --- PUT YOUR CODE HERE ---
			float denominator = m_normal.dot(ray.dir);
			if(denominator > Epsilon) {
					Vec3f subtraction = m_origin - ray.org;
					float t = subtraction.dot(m_normal) / denominator;
					if(t >= 0 & t < ray.t){
						return true;
					}
			}
			else{
				return false;
			}
		}

};
