// Perspective Camera class
// Written by Sergey Kosov in 2005 for Rendering Competition
#pragma once

#include "ICamera.h"

/**
 * @brief Perspective Camera class
 */
class CCameraPerspective : public ICamera{
	private:
		// input values
		Vec3f m_pos;
		Vec3f m_dir;
		Vec3f m_up;

		// preprocessed values
		float m_focus;
		Vec3f m_xAxis;
		Vec3f m_yAxis;
		Vec3f m_zAxis;
		float m_aspect;
	public:
		/**
		 * @brief Constructor
		 * @param pos Camera origin (center of projection)
		 * @param dir Camera viewing direction
		 * @param up Up-vector
		 * @param angle (Vertical) full opening angle of the viewing frustum (in degrees)
		 * @param resolution The image resolution
		 */
		CCameraPerspective(Vec3f pos, Vec3f dir, Vec3f up, float angle, Size resolution): ICamera(resolution), m_pos(pos), m_dir(dir), m_up(up){
				m_focus = (m_pos * m_dir) * (1/tan(angle/2));
				m_xAxis = normalize(m_up);
				m_yAxis = (normalize(m_dir.cross(m_up));
				m_zAxis = normalize(m_dir);
				m_aspect = getResolution().width / (float) getResolution().height;
		}

		virtual ~CCameraPerspective(void) = default;

		virtual bool InitRay(float x, float y, Ray& ray) override{

			float ndcx = (x + 0.5) / getResolution().width;
			float ndcy = (y + 0.5) / getResolution().height;

			float sscx = (2 * ndcx - 1) * m_aspect;
			float sscy = 2 * ndcy - 1;

			float UnNormalizedD = (sscx * m_xAxis) + (sscy * m_yAxis) + m_focus;
			float dNormalize = normalize(UnNormalizedD);

			ray.dir = dNormalize;
			ray.org = m_pos;
			ray.t = INFINITE;
			return true;
		}

};
