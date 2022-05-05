#ifndef SCENE_H_INCLUDED
#define SCENE_H_INCLUDED

#include "camera.h"
#include "texture.h"
#include <obj/model.h>

typedef struct Scene
{
    Model galaxyFloor;
    Model galaxy;
    Model galaxyRoof;
    Model earth;

    Material material;
	Material world_material;

    GLuint galaxyFloor_texture_id;
    GLuint galaxy_texture_id;
    GLuint galaxyRoof_texture_id;
    GLuint earth_texture_id;

    float ambient_light[4];
    float diffuse_light[4];
    float specular_light[4];
    float position[4];
	float light;
	bool helppanel_show;
	GLuint helppanel;

	vec3 earth_pos;
	vec3 earth_angle;
	float angle;
} Scene;

void CreateScene(Scene* scene);

void SetMaterial(const Material* material);

void UpdateScene(Scene* scene,int indicator);

void RenderScene(Scene* scene);

#endif // SCENE_H_INCLUDED
