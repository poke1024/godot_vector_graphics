/*************************************************************************/
/*  utils.h     	                                                     */
/*************************************************************************/

#ifndef VG_UTILS_H
#define VG_UTILS_H

#include <stdint.h>
#include "core/class_db.h"
#include "scene/2d/mesh_instance_2d.h"

#include "tove2d/src/cpp/graphics.h"
#include "tove2d/src/cpp/path.h"
#include "tove2d/src/cpp/subpath.h"
#include "tove2d/src/cpp/paint.h"

inline Rect2 tove_bounds_to_rect2(const float *bounds) {
	return Rect2(bounds[0], bounds[1],  bounds[2] - bounds[0], bounds[3] - bounds[1]);
}

tove::PathRef new_transformed_path(const tove::PathRef &p_tove_path, const Transform2D &p_transform);

void copy_mesh(Ref<ArrayMesh> &p_mesh, tove::MeshRef &p_tove_mesh);

#endif // VG_UTILS_H
