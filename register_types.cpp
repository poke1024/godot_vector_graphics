/*************************************************************************/
/*  register_types.cpp                                                   */
/*************************************************************************/

#include "register_types.h"
#include "resource_format_loader_svg.h"
#include "vector_graphics_path.h"
#include "vector_graphics_paint.h"
#include "vector_graphics_color.h"
#include "vector_graphics_gradient.h"
#include "vector_graphics_renderer.h"
#include "vector_graphics_texture_renderer.h"
#include "vector_graphics_adaptive_renderer.h"

#ifdef TOOLS_ENABLED
#include "vector_graphics_editor_plugin.h"
#endif

#if GDTOVE_SVG_RFL
static ResourceFormatLoaderSVG *svg_loader = NULL;
#endif

#ifdef TOOLS_ENABLED
static void editor_init_callback() {
	EditorNode *editor = EditorNode::get_singleton();
	editor->add_editor_plugin(memnew(VGEditorPlugin(editor)));
}
#endif

void register_vector_graphics_types() {
#if GDTOVE_SVG_RFL
	svg_loader = memnew(ResourceFormatLoaderSVG);
	ResourceLoader::add_resource_format_loader(svg_loader);
#endif

	ClassDB::register_class<VGPath>();
	ClassDB::register_class<VGPaint>();
	ClassDB::register_class<VGColor>();
	ClassDB::register_class<VGGradient>();

	ClassDB::register_class<VGRenderer>();
	ClassDB::register_class<VGTextureRenderer>();
	ClassDB::register_class<VGAdaptiveRenderer>();

#ifdef TOOLS_ENABLED
	EditorNode::add_init_callback(editor_init_callback);
#endif
}

void unregister_vector_graphics_types() {
}
