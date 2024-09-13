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
        return;
    }

    //loads the player scene
    ResourceLoader * ref = ResourceLoader::get_singleton();
    playerscn = ref->load("res://Player.tscn");
    enemyscn = ref->load("res://enemy.tscn");
    player = Object::cast_to<Player>(playerscn->instantiate());
    enemy = Object::cast_to<Enemy>(enemyscn->instantiate());
    player_spawn = get_node<Marker2D>("Player_spawn");
    enemy_spawn = get_node<Marker2D>("Enemy_spawn");
    player->set_position(player_spawn->get_position());
    enemy->set_position(enemy_spawn->get_position());
    add_child(player);

}

void Main::_process(const double delta)
{
    if(Engine::get_singleton()->is_editor_hint())
    {
        return;
    }
    time_elapsed += delta;
    if(time_elapsed >= 1)
    {
        time_elapsed = 0;
        enemy = Object::cast_to<Enemy>(enemyscn->instantiate());
        enemy->set_position(enemy_spawn->get_position());
        add_child(enemy);
    }
    if(!this->has_node("Player"))
    {
        player = Object::cast_to<Player>(playerscn->instantiate());
        player->set_position(player_spawn->get_position());
        add_child(player);
    }
}