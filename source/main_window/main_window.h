#ifndef __MAIN_WINDOW__
#define __MAIN_WINDOW__

#include <gtk/gtk.h>

struct _main_window_;
typedef struct _main_window_ *main_window_t;

main_window_t new_main_window(GtkApplication *application);

void free_main_window(main_window_t main_window);

#endif
