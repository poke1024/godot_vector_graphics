/*************************************************************************/
/*  vg_linear_gradient.h 	                                             */
/*************************************************************************/

#ifndef VG_LINEAR_GRADIENT_H
#define VG_LINEAR_GRADIENT_H

#include "vector_graphics_gradient.h"

class VGLinearGradient : public VGGradient {
	GDCLASS(VGLinearGradient, VGGradient);

    Vector2 p1;
    Vector2 p2;

protected:
	static void _bind_methods();

public:
    VGLinearGradient();

    void set_p1(const Vector2 &p_p1);
    Vector2 get_p1() const;

    void set_p2(const Vector2 &p_p2);
    Vector2 get_p2() const;
};

#endif // VG_LINEAR_GRADIENT_H
