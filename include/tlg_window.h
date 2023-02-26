// Main handler for Text graphics (tm).

#include "dvect.h"

typedef struct tlg_window {
    vector data;
    int xy_sum;
    int x;
    int y;
} TWindow;

// Intializer for TWindow.
void TWindow_create(TWindow *tw,int x_size,int y_size) {
    tw->xy_sum = x_size * y_size;
    vector_init(&tw->data);
    vector_resize(&tw->data,tw->xy_sum);

    for (int i = 0;i < tw->xy_sum;i++) {
        vector_add(&tw->data,' ');       
    }
}

// Destroys the TWindow instance.
void TWindow_destroy(TWindow *tw) {
    tw->xy_sum = 0;
    tw->x = 0;
    tw->y = 0;

    vector_free(&tw->data);
}