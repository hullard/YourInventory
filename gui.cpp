#include "gui.h"

// set up new window by constructor
GUI::GUI(int argc, char* argv[])
{
    // set up GTK+, type system, connection to Xorg
    gtk_init(&argc, &argv);

    // Construct a GtkBuilder instance and load our UI description (created by Glade)
    builder = gtk_builder_new();
    gtk_builder_add_from_file(builder, "builder.ui", nullptr);

    // Connect signal handlers to the constructed widgets
    window = gtk_builder_get_object(builder, "window");
    g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), nullptr);

    // get pointers to the buttons and connect clicked signals
    button = gtk_builder_get_object (builder, "buttonNewEntry");
    g_signal_connect (button, "clicked", G_CALLBACK (on_buttonNewEntry_clicked), nullptr);

    button = gtk_builder_get_object (builder, "buttonNewQuery");
    g_signal_connect (button, "clicked", G_CALLBACK (on_buttonNewQuery_clicked), nullptr);

    button = gtk_builder_get_object (builder, "buttonQuit");
    g_signal_connect (button, "clicked", G_CALLBACK (on_buttonQuit_clicked), nullptr);

    // start GTK+ main loop
    gtk_main ();
}


// temporary test function
void GUI::on_buttonNewEntry_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Add new Entry\n");
}

// temporary test function
void GUI::on_buttonNewQuery_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Run new query\n");
}

// temporary test function
void GUI::on_buttonQuit_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Quit\n");
    gtk_main_quit();
}


// delete window object by destructor
GUI::~GUI()
{
    delete button;
    delete window;
    delete builder;
}
