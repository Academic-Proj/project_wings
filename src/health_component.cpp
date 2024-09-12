#include "health_component.h"
#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Health::_bind_methods()
{
    ClassDB::bind_method(D_METHOD("set_health", "p_health"), &Health::set_health);
    ClassDB::bind_method(D_METHOD("get_health"), &Health::get_health);

    ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "max health"), "set_health", "get_health");
}

Health::Health()
{
    max_health = 10;
    curr_health = max_health;
}

void Health::_ready()
{
    if(get_parent()->has_node("Hurtbox"))
    {
        hurtbox = get_parent()->get_node<Area2D>("Hurtbox");
        hurtbox->connect("area_entered", Callable(this, "takes_damage"));
    }
}

//custom methods
void Health::takes_damage()
{
    
    if(curr_health <= 0)
    {
        UtilityFunctions::print("You died lol\n");
        curr_health = max_health;
    }
    curr_health -= 2;
    UtilityFunctions::print("Health at ", curr_health);
}

//setters and getters
void Health::set_health(const double p_health)
{
    max_health = p_health;
}

double Health::get_health() const
{
    return max_health;
}