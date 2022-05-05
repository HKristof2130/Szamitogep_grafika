#include "scene.h"
#include <obj\load.h>
#include <obj\draw.h>
#include <math.h>

double degree = 0;
//Create the scene for the models
void CreateScene(Scene* scene)
{
    load_model(&(scene->galaxyFloor), "assets/models/galaxyFloor.obj");
    scene->galaxyFloor_texture_id = load_texture("assets/textures/galaxy.jpg");

    load_model(&(scene->galaxy), "assets/models/galaxy.obj");
    scene->galaxy_texture_id = load_texture("assets/textures/galaxy.jpg");

    load_model(&(scene->galaxyRoof), "assets/models/galaxyRoof.obj");
    scene->galaxyRoof_texture_id = load_texture("assets/textures/galaxy.jpg");

    load_model(&(scene->earth), "assets/models/earth.obj");
    scene->earth_texture_id = load_texture("assets/textures/earth.png");

    scene->material.ambient.red = 0.8;
    scene->material.ambient.green = 0.8;
    scene->material.ambient.blue = 0.8;

    scene->material.diffuse.red = 1.0;
    scene->material.diffuse.green = 1.0;
    scene->material.diffuse.blue = 1.0;

    scene->material.specular.red = 0.0;
    scene->material.specular.green = 0.0;
    scene->material.specular.blue = 0.0;

    scene->material.shininess = 0.0;

	scene->world_material.ambient.red = 0.7;
    scene->world_material.ambient.green = 0.7;
    scene->world_material.ambient.blue = 0.7;

    scene->world_material.diffuse.red = 1.0;
    scene->world_material.diffuse.green = 1.0;
    scene->world_material.diffuse.blue = 1.0;

    scene->world_material.specular.red = 0.0;
    scene->world_material.specular.green = 0.0;
    scene->world_material.specular.blue = 0.0;

    scene->world_material.shininess = 0.0;
	scene->light=1.0;

	scene->helppanel_show=false;
	scene->helppanel=load_texture("assets/textures/helppanel.png");

	scene->earth_pos.x = 2;
	scene->earth_pos.y = 0;
	scene->earth_pos.z = 12;

	scene->earth_angle.x = 0;
	scene->earth_angle.y = 0;
	scene->earth_angle.z = 0;
	scene->angle = 0;

}
void SetLights(Scene* scene)
{
    scene->ambient_light[0] = scene->light;
    scene->ambient_light[1] = scene->light;
    scene->ambient_light[2] = scene->light;
    scene->ambient_light[3] = 0.0f;

    scene->diffuse_light[0] = scene->light;
    scene->diffuse_light[1] = scene->light;
    scene->diffuse_light[2] = scene->light;
    scene->diffuse_light[3] = 0.0f;

    scene->specular_light[0] =  1.0f;
    scene->specular_light[1] =  1.0f;
    scene->specular_light[2] =  1.0f;
    scene->specular_light[3] =  0.0f;

    scene->position[0] =  0.0f;
    scene->position[1] =  0.0f;
    scene->position[2] =  4.0f;
    scene->position[3] =  0.0f;

    glLightfv(GL_LIGHT0, GL_AMBIENT, scene->ambient_light);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, scene->diffuse_light);
    glLightfv(GL_LIGHT0, GL_SPECULAR, scene->specular_light);
    glLightfv(GL_LIGHT0, GL_POSITION, scene->position);
}

void SetMaterial(const Material* material)
{
    float ambient_material_color[] = {
        material->ambient.red,
        material->ambient.green,
        material->ambient.blue
    };

    float diffuse_material_color[] = {
        material->diffuse.red,
        material->diffuse.green,
        material->diffuse.blue
    };

    float specular_material_color[] = {
        material->specular.red,
        material->specular.green,
        material->specular.blue
    };

    glMaterialfv(GL_FRONT_AND_BACK, GL_AMBIENT, ambient_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, diffuse_material_color);
    glMaterialfv(GL_FRONT_AND_BACK, GL_SPECULAR, specular_material_color);

    glMaterialfv(GL_FRONT_AND_BACK, GL_SHININESS, &(material->shininess));
}

//Updating the scene in real time
void UpdateScene(Scene* scene,int indicator)
{
    if(indicator == 1 || indicator == 2){
    scene->angle -= 0.05;

    }

    if(indicator == 0 || indicator == 2){
        scene->angle += 0.05;
    }

    if(indicator == 2){
        degree+=0.1;
        double angle = degree_to_radian(degree);
        scene->earth_pos.x = cos(angle) * 2;
        scene->earth_pos.y = sin(angle) * 2;
        scene->earth_pos.z = 12;
    }
}
//Rendering the objects on to the screen
void RenderScene(Scene* scene)
{
    SetMaterial(&(scene->material));
    SetLights(scene);

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->galaxyFloor_texture_id);
    glTranslatef(0, 0, 0);
    draw_model(&(scene->galaxyFloor));
    glPopMatrix();

    //frontgalaxy
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->galaxy_texture_id);
    glRotatef(90, 0, 0, -1);
    glTranslatef(0, 24, 0);
    draw_model(&(scene->galaxy));
    glPopMatrix();

    //rightgalaxy
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->galaxy_texture_id);
    glTranslatef(0, -24, 0);
    draw_model(&(scene->galaxy));
    glPopMatrix();

    //leftgalaxy
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->galaxy_texture_id);
    glTranslatef(0, 24, 0);
    draw_model(&(scene->galaxy));
    glPopMatrix();

    //backgalaxy
    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->galaxy_texture_id);
    glRotatef(90, 0, 0, -1);
    glTranslatef(0, -24, 0);
    draw_model(&(scene->galaxy));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->galaxyRoof_texture_id);
    glTranslatef(0, 0, 24);
    draw_model(&(scene->galaxyRoof));
    glPopMatrix();

    glPushMatrix();
    glBindTexture(GL_TEXTURE_2D, scene->earth_texture_id);
    glTranslatef(scene->earth_pos.x, scene->earth_pos.y, scene->earth_pos.z);
    glRotatef(scene->angle, 0, 0, 1);
    draw_model(&(scene->earth));
    glPopMatrix();

}
