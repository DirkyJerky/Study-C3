#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include <gtk/gtk.h>

#include "common.h"
#define MAX_BUF 512

GtkLabel *clockLabel;
GtkLabel *countLabel;
GtkEntry *intervalEntry;

void updateClock();

void on_timerSwitch_active_notify(GObject *obj, GParamSpec *pspec, gpointer data) {
    GtkSwitch *toggleSwitch = GTK_SWITCH(obj);
    switch(gtk_switch_get_active(toggleSwitch)) {
        case TRUE:
            updateClock();
            ;;
        case FALSE:
            updateClock();
            ;;
    }
}

void updateClock() {
    gchar *buffer = calloc(9, sizeof(char));
    time_t theTime = time(NULL);
    strftime(buffer, 9, "%T", localtime(&theTime));
    gtk_label_set_text(clockLabel, buffer);
}

int main(int argc, char *argv[]) {
    GtkBuilder *builder;
    GtkWidget *window;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    GError *err = NULL;

    if(gtk_builder_add_from_file(builder, "gladeFiles/LessonSeven.glade", &err) == 0) {
        g_error(err->message);
        return EXIT_FAILURE;
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "window1"));
    clockLabel = GTK_LABEL(gtk_builder_get_object(builder, "clockLabel"));
    countLabel = GTK_LABEL(gtk_builder_get_object(builder, "countLabel"));
    intervalEntry = GTK_ENTRY(gtk_builder_get_object(builder, "intervalEntry"));

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}
