#include <furi.h>
#include <gui/gui.h>
#include <input/input.h>
#include <stdlib.h>

#define BARCODE_STARTING_POS 16
#define BARCODE_HEIGHT 50
#define BARCODE_Y_START 3
#define BARCODE_TEXT_OFFSET 9

typedef enum {
    EventTypeTick,
    EventTypeKey,
} EventType;

typedef struct {
    EventType type;
    InputEvent input;
} PluginEvent;

typedef struct {
    int barcodeNumeral[12];
    int editingIndex;
    bool editingMode;
} PluginState;

void number_0(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #0 on left is OOOIIOI
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "0");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 3, BARCODE_HEIGHT); //OOO
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 3, BARCODE_Y_START, 2, BARCODE_HEIGHT); //II
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 5, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 6, BARCODE_Y_START, 1, BARCODE_HEIGHT); //I
}
void number_1(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #1 on left is OOIIOOI
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "1");

    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 2, BARCODE_HEIGHT); //OO
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 2, BARCODE_Y_START, 2, BARCODE_HEIGHT); //II
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 4, BARCODE_Y_START, 2, BARCODE_HEIGHT); //OO
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 6, BARCODE_Y_START, 1, BARCODE_HEIGHT); //I
}
void number_2(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #2 on left is OOIOOII
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "2");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 2, BARCODE_HEIGHT); //OO
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 2, BARCODE_Y_START, 1, BARCODE_HEIGHT); //I
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 3, BARCODE_Y_START, 2, BARCODE_HEIGHT); //OO
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 5, BARCODE_Y_START, 2, BARCODE_HEIGHT); //II
}
void number_3(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #3 on left is OIIIIOI
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "3");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 1, BARCODE_Y_START, 4, BARCODE_HEIGHT); //IIII
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 5, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 6, BARCODE_Y_START, 1, BARCODE_HEIGHT); //I
}
void number_4(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #4 on left is OIOOOII
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "4");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 1, BARCODE_Y_START, 1, BARCODE_HEIGHT); //I
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 2, BARCODE_Y_START, 3, BARCODE_HEIGHT); //OOO
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 5, BARCODE_Y_START, 2, BARCODE_HEIGHT); //II
}
void number_5(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #5 on left is OIIOOOI
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "5");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 1, BARCODE_Y_START, 2, BARCODE_HEIGHT); //II
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 3, BARCODE_Y_START, 3, BARCODE_HEIGHT); //OOO
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 6, BARCODE_Y_START, 1, BARCODE_HEIGHT); //I
}
void number_6(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #6 on left is OIOIIII
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "6");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 1, BARCODE_Y_START, 1, BARCODE_HEIGHT); //I
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 2, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 3, BARCODE_Y_START, 4, BARCODE_HEIGHT); //IIII
}
void number_7(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #7 on left is OIIIOII
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "7");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 1, BARCODE_Y_START, 3, BARCODE_HEIGHT); //III
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 4, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 5, BARCODE_Y_START, 2, BARCODE_HEIGHT); //II
}
void number_8(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #8 on left is OIIOIII
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "8");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 1, BARCODE_Y_START, 2, BARCODE_HEIGHT); //II
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 3, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 4, BARCODE_Y_START, 3, BARCODE_HEIGHT); //III
}
void number_9(
    Canvas* canvas,
    bool rightHand,
    int startingPosition) { //UPC Code for #9 on left is OOOIOII
    canvas_set_color(canvas, ColorBlack);
    canvas_draw_str(
        canvas, startingPosition, BARCODE_Y_START + BARCODE_HEIGHT + BARCODE_TEXT_OFFSET, "9");
    if(rightHand) {
        canvas_set_color(canvas, ColorBlack);
    } else {
        canvas_set_color(canvas, ColorWhite);
    }
    canvas_draw_box(canvas, startingPosition, BARCODE_Y_START, 3, BARCODE_HEIGHT); //OOO
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 3, BARCODE_Y_START, 1, BARCODE_HEIGHT); //I
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 4, BARCODE_Y_START, 1, BARCODE_HEIGHT); //O
    canvas_invert_color(canvas);
    canvas_draw_box(canvas, startingPosition + 5, BARCODE_Y_START, 2, BARCODE_HEIGHT); //II
}

static void render_callback(Canvas* const canvas, void* ctx) {
    const PluginState* plugin_state = acquire_mutex((ValueMutex*)ctx, 25);
    if(plugin_state == NULL) {
        return;
    }

    //I originally had all of these values being generated at runtime by math, but that kept giving me trouble.
    int editingMarkerPosition[12] = {
        19,
        26,
        33,
        40,
        47,
        54,
        66,
        73,
        80,
        87,
        94,
        101,
    };

    canvas_set_color(canvas, ColorBlack);
    canvas_draw_box(canvas, BARCODE_STARTING_POS, BARCODE_Y_START, 1, BARCODE_HEIGHT + 2);
    //canvas_draw_box(canvas, BARCODE_STARTING_POS + 1, 1, 1, 50); //left blank on purpose
    canvas_draw_box(
        canvas, (BARCODE_STARTING_POS + 2), BARCODE_Y_START, 1, BARCODE_HEIGHT + 2); //start saftey
    for(int index = 0; index < 12; index++) {
        bool isOnRight = false;
        if(index >= 6) {
            isOnRight = true;
        }
        switch(plugin_state->barcodeNumeral[index]) {
        case 0:
            number_0(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 1:
            number_1(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 2:
            number_2(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 3:
            number_3(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 4:
            number_4(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 5:
            number_5(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 6:
            number_6(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 7:
            number_7(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 8:
            number_8(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        case 9:
            number_9(canvas, isOnRight, editingMarkerPosition[index]);
            break;
        }
    }

    canvas_set_color(canvas, ColorBlack);
    //canvas_draw_box(canvas, BARCODE_STARTING_POS + 45, BARCODE_Y_START, 1, BARCODE_HEIGHT);
    canvas_draw_box(canvas, BARCODE_STARTING_POS + 46, BARCODE_Y_START, 1, BARCODE_HEIGHT + 2);
    //canvas_draw_box(canvas, BARCODE_STARTING_POS + 47, BARCODE_Y_START, 1, BARCODE_HEIGHT);
    canvas_draw_box(canvas, BARCODE_STARTING_POS + 48, BARCODE_Y_START, 1, BARCODE_HEIGHT + 2);
    //canvas_draw_box(canvas, BARCODE_STARTING_POS + 49, BARCODE_Y_START, 1, BARCODE_HEIGHT);


    if(plugin_state->editingMode) {
        canvas_set_color(canvas, ColorBlack);
        canvas_draw_box(
            canvas,
            editingMarkerPosition[plugin_state->editingIndex],
            63,
            7,
            1); //draw editing cursor
    }

    canvas_set_color(canvas, ColorBlack);
    canvas_draw_box(canvas, BARCODE_STARTING_POS + 92, BARCODE_Y_START, 1, BARCODE_HEIGHT + 2);
    //canvas_draw_box(canvas, 14, 1, 1, 50); //left blank on purpose
    canvas_draw_box(
        canvas,
        (BARCODE_STARTING_POS + 2) + 92,
        BARCODE_Y_START,
        1,
        BARCODE_HEIGHT + 2); //end safety


    release_mutex((ValueMutex*)ctx, plugin_state);
}

static void input_callback(InputEvent* input_event, osMessageQueueId_t event_queue) {
    furi_assert(event_queue);

    PluginEvent event = {.type = EventTypeKey, .input = *input_event};
    osMessageQueuePut(event_queue, &event, 0, osWaitForever);
}

static void barcode_generator_state_init(PluginState* const plugin_state) {
    int i;
    for(i = 0; i < 12; ++i) {
        if(i > 9) {
            plugin_state->barcodeNumeral[i] = i - 10;
        } else if(i < 10) {
            plugin_state->barcodeNumeral[i] = i;
        }
    }
    plugin_state->editingIndex = 0;
    plugin_state->editingMode = false;
}

int32_t barcode_generator_app(void* p) {
    UNUSED(p);
    //testing
    osMessageQueueId_t event_queue = osMessageQueueNew(8, sizeof(PluginEvent), NULL);

    PluginState* plugin_state = malloc(sizeof(PluginState));
    barcode_generator_state_init(plugin_state);
    ValueMutex state_mutex;
    if(!init_mutex(&state_mutex, plugin_state, sizeof(PluginState))) {
        FURI_LOG_E("barcode_generator", "cannot create mutex\r\n");
        free(plugin_state);
        return 255;
    }

    // Set system callbacks
    ViewPort* view_port = view_port_alloc();
    view_port_draw_callback_set(view_port, render_callback, &state_mutex);
    view_port_input_callback_set(view_port, input_callback, event_queue);

    // Open GUI and register view_port
    Gui* gui = furi_record_open("gui");
    gui_add_view_port(gui, view_port, GuiLayerFullscreen);

    PluginEvent event;
    for(bool processing = true; processing;) {
        osStatus_t event_status = osMessageQueueGet(event_queue, &event, NULL, 100);
        PluginState* plugin_state = (PluginState*)acquire_mutex_block(&state_mutex);

        if(event_status == osOK) {
            // press events
            if(event.type == EventTypeKey) {
                if((event.input.type == InputTypePress) || (event.input.type == InputTypeRepeat)) {
                    switch(event.input.key) {
                    case InputKeyUp:
                        if(plugin_state->editingMode) {
                            plugin_state->barcodeNumeral[plugin_state->editingIndex]++;
                        }
                        if(plugin_state->barcodeNumeral[plugin_state->editingIndex] > 9) {
                            plugin_state->barcodeNumeral[plugin_state->editingIndex] = 0;
                        }
                        break;
                    case InputKeyDown:
                        if(plugin_state->editingMode) {
                            plugin_state->barcodeNumeral[plugin_state->editingIndex]--;
                        }
                        if(plugin_state->barcodeNumeral[plugin_state->editingIndex] < 0) {
                            plugin_state->barcodeNumeral[plugin_state->editingIndex] = 9;
                        }
                        break;
                    case InputKeyRight:
                        if(plugin_state->editingMode) {
                            plugin_state->editingIndex++;
                        }
                        if(plugin_state->editingIndex >= 12) {
                            plugin_state->editingIndex = 0;
                        }
                        break;
                    case InputKeyLeft:
                        if(plugin_state->editingMode) {
                            plugin_state->editingIndex--;
                        }
                        if(plugin_state->editingIndex < 0) {
                            plugin_state->editingIndex = 11;
                        }
                        break;
                    case InputKeyOk:
                        if(plugin_state->editingMode == true) {
                            plugin_state->editingMode = false;
                        } else {
                            plugin_state->editingMode = true;
                        }
                        break;
                    case InputKeyBack:
                        processing = false;
                        break;
                    }
                }
            }
        } else {
            FURI_LOG_D("barcode_generator", "osMessageQueue: event timeout");
            // event timeout
        }

        view_port_update(view_port);
        release_mutex(&state_mutex, plugin_state);
    }

    view_port_enabled_set(view_port, false);
    gui_remove_view_port(gui, view_port);
    furi_record_close("gui");
    view_port_free(view_port);
    osMessageQueueDelete(event_queue);

    return 0;
}