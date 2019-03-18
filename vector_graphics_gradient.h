/*************************************************************************/
/*  vg_gradient.h 	                                                     */
/*************************************************************************/

#ifndef VG_GRADIENT_H
#define VG_GRADIENT_H

#include "vector_graphics_paint.h"
#include "scene/resources/gradient.h"

class VGGradient : public VGPaint {
	GDCLASS(VGGradient, VGPaint);

    Vector2 p1;
    Vector2 p2;
    Ref<Gradient> gradient;

    void _gradient_changed();

protected:
	static void _bind_methods();

public:
    VGGradient();

    void set_p1(const Vector2 &p_p1);
    Vector2 get_p1() const;

    void set_p2(const Vector2 &p_p2);
    Vector2 get_p2() const;

    void set_color_ramp(const Ref<Gradient> &p_gradient);
    Ref<Gradient> get_color_ramp() const;
};

#endif // VG_GRADIENT_H
