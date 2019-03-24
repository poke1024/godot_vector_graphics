/*************************************************************************/
/*  vg_texture_renderer.h                                                */
/*************************************************************************/

#ifndef VG_TEXTURE_RENDERER_H
#define VG_TEXTURE_RENDERER_H

#include "vector_graphics_renderer.h"
#include "utils.h"

class VGSpriteRenderer : public VGRenderer {
	GDCLASS(VGSpriteRenderer, VGRenderer);

    float quality;

protected:
	static void _bind_methods();

public:
    VGSpriteRenderer();

    virtual bool prefer_sprite() const {
        return true;
    }

    float get_quality();
    void set_quality(float p_quality);

    virtual Rect2 render_mesh(Ref<ArrayMesh> &p_mesh, Ref<Material> &r_material, Ref<Texture> &r_texture, VGPath *p_path, bool p_hq);
    virtual Ref<ImageTexture> render_texture(VGPath *p_path, bool p_hq);

    virtual bool is_dirty_on_transform_change() const {
        return true;
    }
};

#endif // VG_TEXTURE_RENDERER_H
