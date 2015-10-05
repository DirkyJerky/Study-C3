#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "common.h"
#define MAX_BUF 512

GtkWidget *window;

//void on_close_clicked(GtkWindow* window, gpointer user_data) {
//    gtk_main_quit();
//}
//
//void on_button1_clicked(GtkButton *button, gpointer user_data) {
//    messageWindow("Hello!");
//}
//
//void on_button2_clicked(GtkButton *button, gpointer user_data) {
//    messageWindow("Made on " __DATE__ );
//}
//
//void on_button3_clicked(GtkButton *button, gpointer user_data) {
//    messageWindow("Button!");
//
//}


int main(int argc, char *argv[]) {
    GtkBuilder *builder;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    GError *err = NULL;

    if(gtk_builder_add_from_file(builder, "gladeFiles/LessonEight.glade", &err) == 0) {
	g_error(err->message);
        return EXIT_FAILURE;
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "baseWindow"));

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}
