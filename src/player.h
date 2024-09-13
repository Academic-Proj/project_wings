#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_map.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/scene_tree.hpp>
#include <godot_cpp/classes/scene_tree_timer.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot{

class Player : public CharacterBody2D{
    GDCLASS(Player, CharacterBody2D)

private: 
    double movement_speed;
    double acceleration;
    double dash_cooldown;
    int dash_count;
    Vector2 velocity;
    Vector2 direction;
    Input * input;
    bool canDash;

protected:
    static void _bind_methods();
public:
//overrides
    void _ready() override;
    void _physics_process(const double delta) override;
//initializzers
    Player();

//custom methods
void movement(double delta);
void dash();

//sets and gets
    void set_movement_speed(const double p_movement_speed);
    double get_movement_speed() const;
    void set_acceleration(const double p_acceleration);
    double get_acceleration() const;





};


}










#endif