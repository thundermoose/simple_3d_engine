#include <main_window/main_window.h>
#include <thundertester/test.h>
#include <cairo/cairo.h>
#include <stdio.h>

struct _main_window_
{
	GtkWidget *window;	
	GtkWidget *drawing_area;
};

static
gboolean draw_on_window(GtkWidget *widget,
			cairo_t *cr,
			gpointer main_window_gpointer);

static
gboolean update_window(GtkWidget *widget,
		       GdkFrameClock *frame_clock,
		       gpointer main_window_gpointer);

main_window_t new_main_window(GtkApplication *application)
{
	main_window_t main_window =
	       	(main_window_t)malloc(sizeof(struct _main_window_));
	main_window->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	main_window->drawing_area = gtk_drawing_area_new();
	gtk_container_add(GTK_CONTAINER(main_window->window),
			  main_window->drawing_area);
	g_signal_connect(main_window->drawing_area,
			 "draw",
			 G_CALLBACK(draw_on_window),
			 (gpointer)(main_window));
	gtk_widget_add_tick_callback(main_window->window, 
				     update_window,
				     main_window,
				     NULL);
	gtk_application_add_window(application,GTK_WINDOW(main_window->window));
	gtk_widget_show_all(main_window->window);
	return main_window;
}

void free_main_window(main_window_t main_window)
{
	free(main_window);
}

static
gboolean draw_on_window(GtkWidget *widget,
			cairo_t *cr,
			gpointer main_window_gpointer)
{
	int height;
	height = gtk_widget_get_allocated_height(widget);
	static int position = 0;
	cairo_set_font_size(cr,12.0);
	cairo_translate(cr,0,position);
	cairo_set_source_rgb(cr,1,1,1);
	cairo_text_path(cr,"Hello World");
	cairo_fill(cr);
	position++;
	position = position % height;
	return TRUE;
}

static
gboolean update_window(GtkWidget *widget,
		       GdkFrameClock *frame_clock,
		       gpointer main_window_gpointer)
{
	main_window_t main_window = (main_window_t)main_window_gpointer;
	gtk_widget_queue_draw(main_window->drawing_area);
	return TRUE;
}

#ifdef TEST
main_window_t open_main_window_main_window = NULL;
void open_main_window_active(GtkApplication *application,
			     gpointer user_data)
{
	open_main_window_main_window = new_main_window(application);
}
#endif

new_test(open_main_window,
	 GtkApplication *open_main_window = 
	 	gtk_application_new("org.thundermoose.simpe_3d_engine",
				    G_APPLICATION_FLAGS_NONE);
	 g_signal_connect(open_main_window,
			  "activate", 
			  G_CALLBACK(open_main_window_active), 
			  NULL);
	 char *arguments="open_main_window";
	 g_application_run(G_APPLICATION(open_main_window),
			   1,&arguments);
	 free_main_window(open_main_window_main_window);
	);
