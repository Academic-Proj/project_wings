#include "main.h"

#include <godot_cpp/core/class_db.hpp>

using namespace godot;

void Main::_bind_methods()
{

}

void Main::_ready()
{
    
    if(Engine::get_singleton()->is_editor_hint())
    {
        set_process_mode(Node::ProcessMode::PROCESS_MODE_PAUSABLE);
    }

    //loads the player scene
    ResourceLoader * ref = ResourceLoader::get_singleton();
    Ref<PackedScene> playerscn = ref->load("res://Player.tscn");
    Player * player = Object::cast_to<Player>(playerscn->instantiate());
    add_child(player);

}