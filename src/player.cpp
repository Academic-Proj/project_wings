#include "player.h"

#include <godot_cpp/core/class_db.hpp>


using namespace godot;

void Player::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_movement_speed", "p_movement_speed"), &Player::set_movement_speed);
    ClassDB::bind_method(D_METHOD("get_movement_speed"), &Player::get_movement_speed);
    ClassDB::bind_method(D_METHOD("set_acceleration", "p_acceleration"), &Player::set_acceleration);
    ClassDB::bind_method(D_METHOD("get_acceleration"), &Player::get_acceleration);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "movement_speed"), "set_movement_speed", "get_movement_speed");
    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "acceleration"), "set_acceleration", "get_acceleration");

}

Player::Player()
{
    //changeable by setters
    movement_speed = 800;
    acceleration = 1000;

    dash_count = 3;
    dash_cooldown = 2;
    canDash = true;


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

void Player::_physics_process(const double delta)
{
    //dash cooldown timer
    if(dash_cooldown > 0)
        dash_cooldown -= delta;
    else if(dash_count < 3)
    {
        UtilityFunctions::print("Can Dash!");
        dash_count++;
        dash_cooldown = 2;
    }

    //movement
    movement(delta);
    dash();
    move_and_slide();
    
}

void Player::movement(double delta)
{
    //check for inputs. direction vector gets values (x, y) between -1 to 1
    direction = input->get_vector("Left", "Right", "Up", "Down");
    if(direction != Vector2(0,0))
    {
        //accelerate player until they reach movement speed
        velocity = get_velocity().move_toward(direction * get_movement_speed(), acceleration * delta);
    }
    else
    {
        //slow down player until they stop
        velocity = get_velocity().move_toward(Vector2(0,0), acceleration * delta);
    }
    set_velocity(velocity);
}

void Player::dash()
{
    //check dash directions
    direction = input->get_vector("Left", "Right", "Up", "Down");
    if(input->is_action_just_pressed("Dash") && canDash)
    {
        //checks if velocity is at maximum velocity
        if(velocity != direction * get_movement_speed())
            velocity = direction.normalized() * get_movement_speed();
        else
        {
            velocity = get_velocity() + direction * get_movement_speed();
        }
        dash_count--;
    }
    if(dash_count <= 0)
    {
        UtilityFunctions::print("Can't Dash");
        canDash = false;
    }
    else
        canDash = true;
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

void Player::set_acceleration(const double p_acceleration)
{
    acceleration = p_acceleration;
}
double Player::get_acceleration() const
{
    return acceleration;
}