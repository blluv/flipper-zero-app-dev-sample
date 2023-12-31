#pragma once

#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>

#include <gui/modules/submenu.h>

typedef struct {
    ViewDispatcher* view_dispatcher;
    SceneManager* scene_manager;

    Submenu* mainMenu;
} App;

typedef enum {
    MyAppViewMainMenu,
} MyAppView;