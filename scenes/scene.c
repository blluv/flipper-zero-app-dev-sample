#include "scene.h"

#include "main_scene.h"

void (*const app_scene_on_enter_handlers[])(void*) = {
    main_scene_on_enter,
};

void (*const app_scene_on_exit_handlers[])(void*) = {
    main_scene_on_exit,
};

bool (*const app_scene_on_event_handlers[])(void*, SceneManagerEvent) = {
    main_scene_on_event,
};

const SceneManagerHandlers app_scene_event_handlers = {
    .on_enter_handlers = app_scene_on_enter_handlers,
    .on_exit_handlers = app_scene_on_exit_handlers,
    .on_event_handlers = app_scene_on_event_handlers,
    .scene_num = MyAppSceneNum,
};