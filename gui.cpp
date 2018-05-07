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
    window = gtk_builder_get_object(builder, "windowMain");
    g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), nullptr);



    // get pointers to the buttons and connect clicked signals
    button = gtk_builder_get_object (builder, "buttonFindEmploye");
    g_signal_connect (button, "clicked", G_CALLBACK (on_buttonFindEmploye_clicked), nullptr);

    button = gtk_builder_get_object (builder, "buttonAddEmploye");
    g_signal_connect (button, "clicked", G_CALLBACK (on_buttonAddEmploye_clicked), nullptr);

    button = gtk_builder_get_object (builder, "buttonFindComputer");
    g_signal_connect (button, "clicked", G_CALLBACK (on_buttonFindComputer_clicked), nullptr);

    button = gtk_builder_get_object (builder, "buttonAddComputer");
    g_signal_connect (button, "clicked", G_CALLBACK (on_buttonAddComputer_clicked), nullptr);

    button = gtk_builder_get_object (builder, "buttonQuit");
    g_signal_connect (button, "clicked", G_CALLBACK (on_buttonQuit_clicked), nullptr);

    // start GTK+ main loop
    gtk_main ();
}


// temporary test function
void GUI::on_buttonFindEmploye_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Find Employe\n");
}

// temporary test function
void GUI::on_buttonAddEmploye_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Add Employe\n");
}

// temporary test function
void GUI::on_buttonFindComputer_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Find Computer\n");
}

// temporary test function
void GUI::on_buttonAddComputer_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Add Computer\n");
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
