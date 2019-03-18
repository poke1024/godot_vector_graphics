/*************************************************************************/
/*  vg_gradient.cp          	                                             */
/*************************************************************************/

#include "vector_graphics_gradient.h"
#include "core/core_string_names.h"

void VGGradient::_bind_methods() {
	ClassDB::bind_method(D_METHOD("set_p1", "p1"), &VGGradient::set_p1);
	ClassDB::bind_method(D_METHOD("get_p1"), &VGGradient::get_p1);

	ClassDB::bind_method(D_METHOD("set_p2", "p2"), &VGGradient::set_p2);
	ClassDB::bind_method(D_METHOD("get_p2"), &VGGradient::get_p2);

	ClassDB::bind_method(D_METHOD("set_color_ramp", "color_ramp"), &VGGradient::set_color_ramp);
	ClassDB::bind_method(D_METHOD("get_color_ramp"), &VGGradient::get_color_ramp);

	ClassDB::bind_method(D_METHOD("_gradient_changed"), &VGGradient::_gradient_changed);

	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "p1"), "set_p1", "get_p1");
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "p2"), "set_p2", "get_p2");
	ADD_PROPERTY(PropertyInfo(Variant::OBJECT, "color_ramp", PROPERTY_HINT_RESOURCE_TYPE, "Gradient"), "set_color_ramp", "get_color_ramp");
}

VGGradient::VGGradient() {
	p1 = Vector2(0, 0);
	p2 = Vector2(1, 1);
	Ref<Gradient> g;
	g.instance();
	set_color_ramp(g);
}

void VGGradient::_gradient_changed() {
	_change_notify("color");
}

void VGGradient::set_p1(const Vector2 &p_p1) {
	p1 = p_p1;
	_change_notify("color");
}

Vector2 VGGradient::get_p1() const {
	return p1;
}

void VGGradient::set_p2(const Vector2 &p_p2) {
	p2 = p_p2;
	_change_notify("color");
}

Vector2 VGGradient::get_p2() const {
	return p2;
}

void VGGradient::set_color_ramp(const Ref<Gradient> &p_gradient) {
	if (gradient.is_valid()) {
		gradient->disconnect(CoreStringNames::get_singleton()->changed, this, "_gradient_changed");
	}

	gradient = p_gradient;

	if (gradient.is_valid()) {
		gradient->connect(CoreStringNames::get_singleton()->changed, this, "_gradient_changed");
		printf("recv connected\n");
	}

	_change_notify("color");
}

Ref<Gradient> VGGradient::get_color_ramp() const {
    return gradient;
}
