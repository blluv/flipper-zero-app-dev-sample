#include "main_scene.h"

#include "my_first_app.h"

void main_scene_on_enter(void* context) {
    App* app = context;

    submenu_reset(app->mainMenu);
    submenu_add_item(app->mainMenu, "Menu1", 0, main_scene_menu_callback, app);
    submenu_add_item(app->mainMenu, "Menu2", 1, main_scene_menu_callback, app);
    submenu_add_item(app->mainMenu, "Menu2", 3, main_scene_menu_callback, app);

    view_dispatcher_switch_to_view(app->view_dispatcher, MyAppViewMainMenu);
}

void main_scene_on_exit(void* context) {
    UNUSED(context);
}

bool main_scene_on_event(void* context, SceneManagerEvent event) {
    UNUSED(context);
    UNUSED(event);

    return false;
}

void main_scene_menu_callback(void* context, uint32_t index) {
    UNUSED(context);
    UNUSED(index);
    FURI_LOG_I("MENU", "clicked");
}