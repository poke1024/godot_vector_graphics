/*************************************************************************/
/*  vg_radial_gradient.h 	                                             */
/*************************************************************************/

#ifndef VG_RADIAL_GRADIENT_H
#define VG_RADIAL_GRADIENT_H

#include "vector_graphics_gradient.h"

class VGRadialGradient : public VGGradient {
	GDCLASS(VGRadialGradient, VGGradient);

    Vector2 center;
    Vector2 focal;
    float radius;

    void _gradient_changed();

protected:
	static void _bind_methods();

public:
    VGRadialGradient();

    void set_center(const Vector2 &p_center);
    Vector2 get_center() const;

    void set_focal(const Vector2 &p_focal);
    Vector2 get_focal() const;

    void set_radius(const float p_radius);
    float get_radius() const;
};

#endif // VG_RADIAL_GRADIENT_H
