#ifndef MAIN_H
#define MAIN_H

#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/marker2d.hpp>

#include "enemy.h"
#include "player.h"

namespace godot{

class Main : public Node{
    GDCLASS(Main, Node)

private:
    double time_elapsed;

    Marker2D * player_spawn;
    Marker2D * enemy_spawn;
    Player * player;
    Enemy * enemy;
    Ref<PackedScene> playerscn;
    Ref<PackedScene> enemyscn;
protected:
    static void _bind_methods();
public:
//override
    void _ready() override;
    void _process(const double delta) override;

};

}







#endif