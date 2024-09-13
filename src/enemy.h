#ifndef ENEMY_H
#define ENEMY_H

#include "player.h"
#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/vector2.hpp>

namespace godot{

class Enemy : public CharacterBody2D{
    GDCLASS(Enemy, CharacterBody2D)

private:
    double rotation;
    double movement_speed;
    double acceleration;
    Vector2 velocity;
    Player * player;

public:
    //overrides
    void _ready() override;
    void _physics_process(const double delta) override;

    Enemy();

    void set_movement_speed(const double p_movement_speed);
    double get_movement_speed() const;
    void set_acceleration(const double p_acceleration);
    double get_acceleration() const;

protected:
    static void _bind_methods();


};

}











#endif