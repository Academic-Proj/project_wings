#include "player.h"

#include <godot_cpp/core/class_db.hpp>


using namespace godot;

void Player::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_movement_speed", "p_movement_speed"), &Player::set_movement_speed);
    ClassDB::bind_method(D_METHOD("get_movement_speed"), &Player::get_movement_speed);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movement_speed"), "set_movement_speed", "get_movement_speed");

}

Player::Player()
{
    //changeable by setters
    movement_speed = 2;

}

void Player::_ready()
{
    if(Engine::get_singleton()->is_editor_hint())
    {
        set_process_mode(Node::ProcessMode::PROCESS_MODE_PAUSABLE);
    }
    //prepare input maps
    input = Input::get_singleton();
    InputMap * inputmap = InputMap::get_singleton();
    inputmap->load_from_project_settings();

}

void Player::_physics_process(double delta)
{
    //player movement with input
    
    movement();
    move_and_slide();
    
}

void Player::movement()
{
    direction = input->get_vector("Left", "Right", "Up", "Down");
    velocity = direction * get_movement_speed();
    set_velocity(velocity);
}

//setters and getters
void Player::set_movement_speed(const double p_movement_speed)
{
    movement_speed = p_movement_speed;
}

double Player::get_movement_speed() const
{
    return movement_speed;
}