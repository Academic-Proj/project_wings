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
    bullet_speed = 20;
}

void Bullet::_ready()
{
    if((get_parent()->get_name().nocasecmp_to("Bullet_spawner")) == 0)
    {
        spawner = Object::cast_to<Marker2D>(get_parent());
        set_global_position(spawner->get_position());
        reparent(get_node<Main>("/root/Main"));
        position = get_position();
    }

}

void Bullet::_physics_process(const double delta)
{
    impulse = Vector2(bullet_speed, 0);
    apply_impulse(impulse, position);

}

void Bullet::set_bullet_speed(const double p_bullet_speed)
{
    bullet_speed = p_bullet_speed;
}

double Bullet::get_bullet_speed() const
{
    return bullet_speed;
}