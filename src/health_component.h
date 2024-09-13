#ifndef HEALTH_COMPONENT_H
#define HEALTH_COMPONENT_H

#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/area2d.hpp>
#include <godot_cpp/variant/utility_functions.hpp>

namespace godot{

class Health : public Node2D{
    GDCLASS(Health, Node2D)

private:
    double max_health;
    double curr_health;

    Area2D * hurtbox;

protected:
    static void _bind_methods();

public:
//initializers
    Health();

//overrides
    void _ready() override;

//sets and gets
    void set_health(const double p_health);
    double get_health() const;
//Custom methods
    void takes_damage(Area2D * area);

};


}








#endif