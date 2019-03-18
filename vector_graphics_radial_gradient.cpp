/*************************************************************************/
/*  vg_radial_gradient.cp          	                                     */
/*************************************************************************/

#include "vector_graphics_radial_gradient.h"
#include "core/core_string_names.h"

void VGRadialGradient::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_center", "center"), &VGRadialGradient::set_center);
	ClassDB::bind_method(D_METHOD("get_center"), &VGRadialGradient::get_center);

	ClassDB::bind_method(D_METHOD("set_focal", "focal"), &VGRadialGradient::set_focal);
	ClassDB::bind_method(D_METHOD("get_focal"), &VGRadialGradient::get_focal);

	ClassDB::bind_method(D_METHOD("set_radius", "radius"), &VGRadialGradient::set_radius);
	ClassDB::bind_method(D_METHOD("get_radius"), &VGRadialGradient::get_radius);

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "center"), "set_center", "get_center");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "focal"), "set_focal", "get_focal");
	ADD_PROPERTY(PropertyInfo(Variant::REAL, "radius"), "set_radius", "get_radius");
}

VGRadialGradient::VGRadialGradient() {
	center = Vector2(50, 50);
	focal = Vector2(0, 0);
	radius = 200;
}

void VGRadialGradient::set_center(const Vector2 &p_center) {
	center = p_center;
	_change_notify("color");
}

Vector2 VGRadialGradient::get_center() const {
	return center;
}

void VGRadialGradient::set_focal(const Vector2 &p_focal) {
	focal = p_focal;
	_change_notify("color");
}

Vector2 VGRadialGradient::get_focal() const {
	return focal;
}

void VGRadialGradient::set_radius(const float p_radius) {
	radius = p_radius;
	_change_notify("color");
}

float VGRadialGradient::get_radius() const {
	return radius;
}
