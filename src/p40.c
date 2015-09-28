#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "common.h"
#define MAX_BUF 512

void messageWindow(const gchar*);
void gtk_builder_add_callback_symbol(GtkBuilder*, const char*, GCallback);

GtkWidget *window;

void on_close_clicked(GtkWindow* window, gpointer user_data) {
    gtk_main_quit();
}

void on_button1_clicked(GtkButton *button, gpointer user_data) {
    messageWindow("Hello!");
}

void on_button2_clicked(GtkButton *button, gpointer user_data) {
    messageWindow("Made on " __DATE__ );
}

void on_button3_clicked(GtkButton *button, gpointer user_data) {
    messageWindow("Button!");

}

void messageWindow(const char *message) {
        GtkWidget *dialog;

        /* log to terminal window */
        g_warning (message);

        /* create an error message dialog and display modally to the user */
        dialog = gtk_message_dialog_new (GTK_WINDOW(window),
                                         GTK_DIALOG_MODAL | GTK_DIALOG_DESTROY_WITH_PARENT,
                                         GTK_MESSAGE_ERROR,
                                         GTK_BUTTONS_OK,
                                         message);

        gtk_window_set_title (GTK_WINDOW (dialog), "Message!");
        gtk_dialog_run (GTK_DIALOG (dialog));
        gtk_widget_destroy (dialog);
}


int main(int argc, char *argv[]) {
    GtkBuilder *builder;

    gtk_init(&argc, &argv);

    builder = gtk_builder_new();

    GError *err = NULL;

    if(gtk_builder_add_from_file(builder, "gladeFiles/LessonFour.glade", &err) == 0) {
	g_error(err->message);
        return EXIT_FAILURE;
    }

    window = GTK_WIDGET(gtk_builder_get_object(builder, "baseWindow"));

    CONSIG(on_close_clicked);
    CONSIG(on_button1_clicked);
    CONSIG(on_button2_clicked);
    CONSIG(on_button3_clicked);
    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}
