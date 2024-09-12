#ifndef ANCHOR_H
#define ANCHOR_H

#include "bullet.h"
#include <godot_cpp/classes/node2d.hpp>
#include <godot_cpp/classes/input.hpp>
#include <godot_cpp/classes/input_map.hpp>
#include <godot_cpp/classes/rigid_body2d.hpp>
#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/marker2d.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include <godot_cpp/variant/transform2d.hpp>



namespace godot{

class Anchor : public Node2D{
    GDCLASS(Anchor, Node2D)

private:
    Input * input;
    double rotation;
    Vector2 impulse;
    Ref<PackedScene> bulletscn;
    Bullet * bullet;
    Marker2D * spawner;


protected:
    static void _bind_methods();
public:
    void _ready() override;
    void _process(const double delta) override;

    void shoot();
};
}





#endif