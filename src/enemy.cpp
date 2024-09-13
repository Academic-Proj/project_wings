#include "enemy.h"


#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Enemy::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_movement_speed", "p_movement_speed"), &Enemy::set_movement_speed);
    ClassDB::bind_method(D_METHOD("get_movement_speed"), &Enemy::get_movement_speed);
    ClassDB::bind_method(D_METHOD("set_acceleration", "p_acceleration"), &Enemy::set_acceleration);
    ClassDB::bind_method(D_METHOD("get_acceleration"), &Enemy::get_acceleration);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movement_speed"), "set_movement_speed", "get_movement_speed");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "acceleration"), "set_acceleration", "get_acceleration");
}

void Enemy::_ready()
{
    if(Engine::get_singleton()->is_editor_hint())
    {
        return;
    }
    player = get_node<Player>("../Player");

}

Enemy::Enemy()
{
    movement_speed = 500;
    acceleration = 500;
}

void Enemy::_physics_process(const double delta)
{
    if(Engine::get_singleton()->is_editor_hint())
    {
        return;
    }

    look_at(player->get_position());
    rotation = this->get_rotation();
    velocity = get_velocity().move_toward(get_movement_speed() * Vector2(1,0).rotated(rotation), acceleration * delta);
    set_velocity(velocity);

    move_and_slide();
}


//setters and getters
void Enemy::set_movement_speed(const double p_movement_speed)
{
    movement_speed = p_movement_speed;
}

double Enemy::get_movement_speed() const
{
    return movement_speed;
}

void Enemy::set_acceleration(const double p_acceleration)
{
    acceleration = p_acceleration;
}
double Enemy::get_acceleration() const
{
    return acceleration;
}
