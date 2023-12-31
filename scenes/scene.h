#pragma once

#include <gui/scene_manager.h>

typedef enum {
    MyAppSceneMain,
    MyAppSceneNum,
} MyAppScene;

extern const SceneManagerHandlers app_scene_event_handlers;