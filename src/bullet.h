#ifndef BULLET_H
#define BULLET_H

#include <godot_cpp/classes/rigid_body2d.hpp>
#include <godot_cpp/classes/marker2d.hpp>
#include <godot_cpp/variant/vector2.hpp>


namespace godot{

class Bullet : public RigidBody2D{
    GDCLASS(Bullet, RigidBody2D)

private:
    double bullet_speed;
    Vector2 impulse;
    Marker2D * spawner;
    Vector2 position;

protected:
    static void _bind_methods();

public:
    Bullet();

    void _ready() override;
    void _physics_process(const double delta) override;

    void set_bullet_speed(const double p_bullet_speed);
    double get_bullet_speed() const;

};
}




#endif