#include "my_first_app.h"

#include <furi.h>

#include <gui/gui.h>
#include <gui/scene_manager.h>
#include <gui/view_dispatcher.h>

#include <gui/modules/submenu.h>

#include "scenes/scene.h"

bool app_custom_callback(void* context, uint32_t custom_event) {
    furi_assert(context);
    App* app = context;
    return scene_manager_handle_custom_event(app->scene_manager, custom_event);
}

bool app_back_event_callback(void* context) {
    furi_assert(context);
    App* app = context;
    return scene_manager_handle_back_event(app->scene_manager);
}

App* app_alloc() {
    App* app = malloc(sizeof(App));

    app->view_dispatcher = view_dispatcher_alloc();
    app->scene_manager = scene_manager_alloc(&app_scene_event_handlers, app);

    view_dispatcher_enable_queue(app->view_dispatcher);
    view_dispatcher_set_event_callback_context(app->view_dispatcher, app);
    view_dispatcher_set_custom_event_callback(app->view_dispatcher, app_custom_callback);
    view_dispatcher_set_navigation_event_callback(app->view_dispatcher, app_back_event_callback);

    app->mainMenu = submenu_alloc();
    view_dispatcher_add_view(
        app->view_dispatcher, MyAppViewMainMenu, submenu_get_view(app->mainMenu));

    return app;
}

void app_free(App* app) {
    submenu_free(app->mainMenu);

    scene_manager_free(app->scene_manager);
    view_dispatcher_free(app->view_dispatcher);
    free(app);
}

int32_t my_first_app_app(void* p) {
    UNUSED(p);

    Gui* gui = furi_record_open(RECORD_GUI);
    App* app = app_alloc();

    view_dispatcher_attach_to_gui(app->view_dispatcher, gui, ViewDispatcherTypeFullscreen);
    scene_manager_next_scene(app->scene_manager, MyAppSceneMain);
    view_dispatcher_run(app->view_dispatcher);

    app_free(app);
    furi_record_close(RECORD_GUI);

    return 0;
}
