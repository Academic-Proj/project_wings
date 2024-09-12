#include "main.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Main::_bind_methods()
{

}

void Main::_ready()
{
    //loads the player scene
    ResourceLoader * ref = ResourceLoader::get_singleton();
    Ref<PackedScene> playerscn = ref->load("res://Player.tscn");
    Player * player = Object::cast_to<Player>(playerscn->instantiate());
    add_child(player);

}