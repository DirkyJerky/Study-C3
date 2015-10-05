#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

#include "common.h"
#define MAX_BUF 512

GtkWidget *window;
GtkWidget *fileWindow;
GtkWidget *colorWindow;
GtkWidget *checkWindow;
GtkEntry *fileEntry;
GtkToggleButton *checkButton;

void on_selectYes_clicked(GtkButton *button, gpointer data) {
    gtk_toggle_button_set_active(checkButton, TRUE);
}

void on_onFileDialogOK_clicked(GtkButton *button, gpointer data) {
    gchar *uri = gtk_file_chooser_get_uri(GTK_FILE_CHOOSER());
    g_warning(uri);
    gtk_entry_set_text(fileEntry, uri);
}

void on_colorButtonSelect_clicked(GtkButton *button, gpointer data) {
    GdkRGBA *color = malloc(sizeof(GdkRGBA));
    gtk_color_selection_get_current_rgba(
            GTK_COLOR_SELECTION(
                gtk_color_selection_dialog_get_color_selection(
                    GTK_COLOR_SELECTION_DIALOG(colorWindow)
                )
            ), color);

    gtk_widget_override_background_color(window, GTK_STATE_FLAG_NORMAL, color);
}

void on_selectNo_clicked(GtkButton *button, gpointer data) {
    gtk_toggle_button_set_active(checkButton, FALSE);
}

void hideTopLevelOf(GtkWidget *widget) {
    gtk_widget_hide(gtk_widget_get_toplevel(widget));
}

void on_colorButton_clicked(GtkButton *button) {
    gtk_widget_show(colorWindow);
}

void on_checkButton_clicked(GtkButton *button) {
    gtk_widget_show(checkWindow);
}

void on_fileButton_clicked(GtkButton *button) {
    gtk_widget_show(fileWindow);
}

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
    checkButton = GTK_TOGGLE_BUTTON(gtk_builder_get_object(builder, "checkbutton1"));
    colorWindow = GTK_WIDGET(gtk_builder_get_object(builder, "colorselectiondialog1"));
    checkWindow = GTK_WIDGET(gtk_builder_get_object(builder, "checkmarkDialog"));
    fileWindow = GTK_WIDGET(gtk_builder_get_object(builder, "filechooserdialog1"));
    fileEntry = GTK_ENTRY(gtk_builder_get_object(builder, "entry1"));

    gtk_builder_connect_signals(builder, NULL);

    g_object_unref(G_OBJECT(builder));

    gtk_widget_show(window);
    gtk_main();

    return EXIT_SUCCESS;
}
