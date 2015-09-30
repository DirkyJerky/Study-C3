#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

#include "common.h"
#define MAX_BUF 512

GtkWidget *window;
GdkWindow *gdkWindow;
GdkPixbuf *pixbuf;
GtkSpinButton *spinButton;
GtkDrawingArea *dArea;
cairo_surface_t *scr;

gboolean on_drawingarea1_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    gdk_cairo_set_source_pixbuf(cr, pixbuf, 0, 0);
    cairo_paint(cr);

    g_debug("on_drawingarea1_draw");
    return TRUE;
}

gboolean on_drawingarea1_button_press_event(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    g_debug("on_drawingarea1_button_press_event");
    return TRUE;
}

gboolean on_drawingarea1_button_release_event(GtkWidget *widget, GdkEvent *event, gpointer user_data) {
    g_debug("on_drawingarea1_button_release_event");
    return TRUE;
}

void setupBuilder() {
    GtkBuilder *builder;
    builder = gtk_builder_new();

    GError *err = NULL;
    if(gtk_builder_add_from_file(builder, "gladeFiles/LessonSix.glade", &err) == 0) {
        g_critical(err->message);
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    spinButton = GTK_SPIN_BUTTON(gtk_builder_get_object(builder, "spinbutton1"));
    dArea = GTK_DRAWING_AREA(gtk_builder_get_object(builder, "drawingarea1"));

    gtk_builder_connect_signals(builder, NULL);
    g_object_unref(builder);
}

void setupObjects() {
    // Value = gtk_spin_button_get_value_as_int(spinButton)

    gdkWindow = gtk_widget_get_window(GTK_WIDGET(window));
    cr = gdk_cairo_create(gdkWindow);
    int wH, wW; 
    gtk_window_get_size(GTK_WINDOW(window), &wH, &wW);
    pixbuf = gdk_pixbuf_new(GDK_COLORSPACE_RGB, FALSE, 8, wH, wW);

    GdkRGBA red = NULL;
    gdk_rgba_parse(&red, "red");


    
}

int main(int argc, char *argv[]) {
    g_log_set_fatal_mask("all", G_LOG_LEVEL_CRITICAL);
    gtk_init(&argc, &argv);

    setupBuilder();

    setupObjects();

    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}
