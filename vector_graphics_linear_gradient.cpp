/*************************************************************************/
/*  vg_linear_gradient.cp          	                                     */
/*************************************************************************/

#include "vector_graphics_linear_gradient.h"
#include "core/core_string_names.h"

void VGLinearGradient::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_p1", "p1"), &VGLinearGradient::set_p1);
	ClassDB::bind_method(D_METHOD("get_p1"), &VGLinearGradient::get_p1);

	ClassDB::bind_method(D_METHOD("set_p2", "p2"), &VGLinearGradient::set_p2);
	ClassDB::bind_method(D_METHOD("get_p2"), &VGLinearGradient::get_p2);

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "p1"), "set_p1", "get_p1");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "p2"), "set_p2", "get_p2");
}

VGLinearGradient::VGLinearGradient() {
	p1 = Vector2(0, 0);
	p2 = Vector2(100, 100);
}

void VGLinearGradient::set_p1(const Vector2 &p_p1) {
	p1 = p_p1;
	_change_notify("color");
}

Vector2 VGLinearGradient::get_p1() const {
	return p1;
}

void VGLinearGradient::set_p2(const Vector2 &p_p2) {
	p2 = p_p2;
	_change_notify("color");
}

Vector2 VGLinearGradient::get_p2() const {
	return p2;
}
