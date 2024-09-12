#include "anchor.h"
#include "bullet.h"

using namespace godot;

void Anchor::_bind_methods()
{

}

void Anchor::_ready()
{
    InputMap * map = InputMap::get_singleton();
    input = Input::get_singleton();
    map->load_from_project_settings();

    ResourceLoader * bullet_loader = ResourceLoader::get_singleton();
    bulletscn = bullet_loader->load("res://Bullet.tscn");

    if(this->has_node("Bullet_spawner"))
    {
        spawner = get_node<Marker2D>("Bullet_spawner");
    }
    
}

void Anchor::_process(const double delta)
{
    look_at(get_global_mouse_position());
    rotation = get_rotation();
    if(input->is_action_just_pressed("Shoot"))
    {
        shoot();
    }

}

void Anchor::shoot()
{
    bullet = Object::cast_to<Bullet>(bulletscn->instantiate());
    impulse = Vector2(bullet->get_bullet_speed(), 0);
    bullet->apply_impulse(impulse.rotated(rotation), get_position());
    if(spawner!= NULL)
    {
        spawner->add_child(bullet);
    }
}
