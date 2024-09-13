#ifndef MAIN_H
#define MAIN_H

#include <godot_cpp/classes/resource_loader.hpp>
#include <godot_cpp/classes/packed_scene.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/classes/node.hpp>

#include "player.h"

namespace godot{

class Main : public Node{
    GDCLASS(Main, Node)

private:

protected:
    static void _bind_methods();
public:
//override
    void _ready() override;

};

}







#endif