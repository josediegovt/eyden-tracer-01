// Geaometrical Primitives base abstract class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "ray.h"

/**
 * @brief Geometrical Primitives (Prims) base abstract class
 */
class CPrim{
	private:
		Vec3f m_color;
	public:
	/**
	* @brief Constructor
	*/
		CPrim(void) = default;
		CPrim(const CPrim&) = delete;
		virtual ~CPrim(void) = default;
		const CPrim& operator=(const CPrim&) = delete;

		Vec3f getColor(){
			return ncolor;
		}

		void setColor(Vec3f color){
			m_color = color;
		}

	/**
	 * @brief Checks for intersection between ray \b Ray and the primitive
	 * @details If a valid intersection has been found with the primitive,
	 		set Ray::t to the distance to this intersection point (if current t < ray.t)
	 * @param[in,out] ray The ray (Ref. @ref Ray for details)
	 * @retval true If and only if a valid intersection has been found in the interval (epsilon; Ray::t)
	 * @retval false Otherwise
	 */
		virtual bool Intersect(Ray& ray) = 0;
};
