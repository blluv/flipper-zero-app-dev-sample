#pragma once

#include <stdbool.h>
#include <gui/scene_manager.h>

void main_scene_on_enter(void* context);
void main_scene_on_exit(void* context);
bool main_scene_on_event(void* context, SceneManagerEvent event);

void main_scene_menu_callback(void* context, uint32_t index);