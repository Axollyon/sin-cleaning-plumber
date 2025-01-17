#include "src/game/envfx_snow.h"

const GeoLayout bob_area_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_SWITCH_CASE(4, geo_switch_area),
		GEO_OPEN_NODE(),
			GEO_BRANCH(1, bob_dl_1___Main_Room_geo),
			GEO_BRANCH(1, bob_dl_Left_Room_1_geo),
			GEO_BRANCH(1, bob_dl_Left_Room_3_geo),
			GEO_BRANCH(1, bob_dl_Right_Room_2_geo),
		GEO_CLOSE_NODE(),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_1___Main_Room_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 500, -920, bob_dl_Lights_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -152, 39, 2737, bob_dl_Shelving_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 107, 0, 2735, bob_dl_Shelving_001_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 50, 2549, bob_dl_Shelving_002_mesh),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 0, 0, -7000, bob_dl_Tunnel_Render_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Left_Room_1_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1321, 0, -572, bob_dl_Book_mesh),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 688, 0, -895),
		GEO_OPEN_NODE(),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, -58, 170, 0, bob_dl_Clipping_1_mesh),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 6, 129, 0, bob_dl_Clipping_2_mesh),
			GEO_TRANSLATE_NODE_WITH_DL(LAYER_TRANSPARENT_DECAL, 41, 194, 0, bob_dl_Clipping_3_mesh),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 1198, 0, -451, bob_dl_Cot_mesh),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 1300, 0, -789),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Crate_Render_mesh),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE(LAYER_OPAQUE, 1113, 0, -789),
		GEO_OPEN_NODE(),
			GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_Crate_Render_001_mesh),
		GEO_CLOSE_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 400, 0, -624, bob_dl_Left_Room_1_Mesh_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Left_Room_3_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, 400, 0, 562, bob_dl_Left_Room_3_Mesh_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_dl_Right_Room_2_geo[] = {
	GEO_NODE_START(),
	GEO_OPEN_NODE(),
		GEO_TRANSLATE_NODE_WITH_DL(LAYER_OPAQUE, -400, 0, -31, bob_dl_Right_Room_2_Mesh_mesh),
	GEO_CLOSE_NODE(),
	GEO_RETURN(),
};
const GeoLayout bob_area_2[] = {
	GEO_NODE_SCREEN_AREA(10, SCREEN_WIDTH/2, SCREEN_HEIGHT/2, SCREEN_WIDTH/2, SCREEN_HEIGHT/2),
	GEO_OPEN_NODE(),
		GEO_ZBUFFER(0),
		GEO_OPEN_NODE(),
			GEO_NODE_ORTHO(100.0000),
			GEO_OPEN_NODE(),
				GEO_BACKGROUND_COLOR(0x0001),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_ZBUFFER(1),
		GEO_OPEN_NODE(),
			GEO_CAMERA_FRUSTUM_WITH_FUNC(45.0000, 100, 22000, geo_camera_fov),
			GEO_OPEN_NODE(),
				GEO_CAMERA(CAMERA_MODE_8_DIRECTIONS, 0, 0, 0, 0, -100, 0, geo_camera_main),
				GEO_OPEN_NODE(),
					GEO_BRANCH(1, bob_area_2_geo),
					GEO_RENDER_OBJ(),
					GEO_ASM(ENVFX_MODE_NONE, geo_envfx_main),
				GEO_CLOSE_NODE(),
			GEO_CLOSE_NODE(),
		GEO_CLOSE_NODE(),
		GEO_DISPLAY_LIST(LAYER_OPAQUE, bob_dl_material_revert_render_settings),
		GEO_DISPLAY_LIST(LAYER_TRANSPARENT_DECAL, bob_dl_material_revert_render_settings),
	GEO_CLOSE_NODE(),
	GEO_END(),
};
