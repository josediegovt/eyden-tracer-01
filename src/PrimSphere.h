// Sphere Geaometrical Primitive class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "Prim.h"

/**
 * @brief Sphere Geaometrical Primitive class
 */
class CPrimSphere : public CPrim{
	private:
		Vec3f m_center;	///< Position of the center of the sphere
		float m_radius;	///< Radius of the sphere

	public:

		/**
		 * @brief Constructor
		 * @param center Position of the center of the sphere
		 * @param radius Radius of the sphere
		 */

		CPrimSphere(Vec3f center, float radius): CPrim(), m_center(center), m_radius(radius){
		}

		virtual ~CPrimSphere(void) = default;

		virtual bool Intersect(Ray &ray) override {
			Vec3f origin = ray.org;
			Vec3f direction = ray.dir;

			Vec3f v = origin - m_center;

			const float b = 2 * v.dot(d);
			const float c = v.dot(v) - (m_radius*m_radius);
			float delta = b*b - 4 * c;
			// change delta and v names
			if (delta < Epsilon)
					return false;

			const float t1 = (-b - sqrt(delta))/2;
			const float t2 = (-b + sqrt(delta))/2;

			t = (t1 < t2) ? t1 : t2; // get the first intersection only

			return true;
		}
};
