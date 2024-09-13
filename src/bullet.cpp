#include "bullet.h"
#include "main.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Bullet::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_bullet_speed", "p_bullet_speed"), &Bullet::set_bullet_speed);
    ClassDB::bind_method(D_METHOD("get_bullet_speed"), &Bullet::get_bullet_speed);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "Bullet speed"), "set_bullet_speed", "get_bullet_speed");
}

Bullet::Bullet()
{
    set_gravity_scale(0);
    bullet_speed = 20;
    time_elapsed = 0;
}

void Bullet::_ready()
{
   
    if(get_parent()->get_parent()->has_node("Bullet_spawner"))
    {

        reparent(get_node<Main>("/root/Main"));
    }
    
}

void Bullet::_process(const double delta)
{
    if(Engine::get_singleton()->is_editor_hint())
    {
        return;
    }
    time_elapsed += delta;
    if(time_elapsed >= 4)
    {
        queue_free();
    }

    
}

void Bullet::set_bullet_speed(const double p_bullet_speed)
{
    bullet_speed = p_bullet_speed;
}

double Bullet::get_bullet_speed() const
{
    return bullet_speed;
}