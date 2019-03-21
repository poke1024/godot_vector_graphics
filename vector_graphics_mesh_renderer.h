/*************************************************************************/
/*  vg_mesh_renderer.h                                                   */
/*************************************************************************/

#ifndef VG_MESH_RENDERER_H
#define VG_MESH_RENDERER_H

#include "vector_graphics_renderer.h"
#include "utils.h"

class VGAbstractMeshRenderer : public VGRenderer {
protected:
    tove::TesselatorRef tesselator;

	static void _bind_methods();

public:
    VGAbstractMeshRenderer();

    const tove::TesselatorRef &get_tesselator() const {
        return tesselator;
    }

    virtual Rect2 render_mesh(Ref<ArrayMesh> &p_mesh, VGPath *p_path);
    virtual Ref<ImageTexture> render_texture(VGPath *p_path);

    virtual bool is_dirty_on_transform_change() const {
        return false;
    }
};

#endif // VG_MESH_RENDERER_H
