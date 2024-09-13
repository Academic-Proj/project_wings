#ifndef PLAYER_H
#define PLAYER_H

#include <godot_cpp/classes/character_body2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_map.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/vector2.hpp>

namespace godot{

class Player : public CharacterBody2D{
    GDCLASS(Player, CharacterBody2D)

private: 
    double movement_speed;
    Vector2 velocity;
    Vector2 direction;
    Input * input;

protected:
    static void _bind_methods();
public:
//overrides
    void _ready() override;
    void _physics_process(double delta) override;
//initializzers
    Player();

//custom methods
void movement();

//sets and gets
    void set_movement_speed(const double p_movement_speed);
    double get_movement_speed() const;





};


}










#endif