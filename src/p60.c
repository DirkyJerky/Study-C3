#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>
#include <gdk/gdk.h>

#include "common.h"
#define MAX_BUF 512

GtkWidget *window;
GdkWindow *gdkWindow;
GtkSpinButton *spinButton;
GtkDrawingArea *dArea;
const GdkRGBA colorRed = (GdkRGBA) { 1.0, 80.0/255.0, 80.0/255.0, 1.0 };
const GdkRGBA colorBlue = (GdkRGBA) { 80.0/255.0, 80.0/255.0, 1.0, 1.0 };

gboolean drawRed = FALSE, drawBlue = FALSE;
gdouble redXS;
gdouble redYS;
gdouble redXE;
gdouble redYE;
gdouble blueXS;
gdouble blueYS;
gdouble blueXE;
gdouble blueYE;

gboolean on_drawingarea1_draw(GtkWidget *widget, cairo_t *cr, gpointer user_data) {
    g_debug("on_drawingarea1_draw");

    if(drawRed) {
        g_debug("drawing red (%f, %f) -> (%f, %f)", redXS, redYS, redXE, redYE);
        gdk_cairo_set_source_rgba(cr, &colorRed);
        cairo_move_to(cr, redXS, redYS);
        cairo_line_to(cr, redXE, redYE);
        cairo_set_line_width(cr, gtk_spin_button_get_value_as_int(spinButton));
        cairo_stroke(cr);
    }
    
    if(drawBlue) {
        g_debug("drawing red (%f, %f) -> (%f, %f)", blueXS, blueYS, blueXE, blueYE);
        gdk_cairo_set_source_rgba(cr, &colorBlue);
        cairo_move_to(cr, blueXS, blueYS);
        cairo_line_to(cr, blueXE, blueYE);
        cairo_set_line_width(cr, gtk_spin_button_get_value_as_int(spinButton));
        cairo_stroke(cr);
    }

    return TRUE;
}

gboolean on_drawingarea1_button_press_event(GtkWidget *widget, GdkEvent *gEvent, gpointer user_data) {
    GdkEventButton event = gEvent->button;

    if(event.type != GDK_BUTTON_PRESS) return FALSE;

    g_debug("on_drawingarea1_button_press_event with Button: %d", event.button);

    switch(event.button) {
        case 1: 
            redXS = event.x;
            redYS = event.y;
            g_debug("set red start: (%f, %f)", event.x, event.y);
            break;
        case 3:
            blueXS = event.x;
            blueYS = event.y;
            g_debug("set blue start: (%f, %f)", event.x, event.y);
            break;
        default:
            return FALSE;
    }


    return TRUE;
}

gboolean on_drawingarea1_button_release_event(GtkWidget *widget, GdkEvent *gEvent, gpointer user_data) {
    GdkEventButton event = gEvent->button;

    if(event.type != GDK_BUTTON_RELEASE) return FALSE;

    g_debug("on_drawingarea1_button_release_event with Button: %d", event.button);

    switch(event.button) {
        case 1: 
            redXE = event.x;
            redYE = event.y;
            drawRed = TRUE;
            g_debug("set red end: (%f, %f)", event.x, event.y);
            break;
        case 3:
            blueXE = event.x;
            blueYE = event.y;
            drawBlue = TRUE;
            g_debug("set blue end: (%f, %f)", event.x, event.y);
            break;
        default:
            return FALSE;
    }

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
    int wH, wW; 
    gtk_window_get_size(GTK_WINDOW(window), &wH, &wW);

    
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
