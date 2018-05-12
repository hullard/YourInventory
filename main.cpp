/* Standard C++ includes */
#include <stdlib.h>
#include <iostream>

#include "sql.h"

#include <gtk/gtk.h>


// GUI handlers
void on_buttonFindEmploye_clicked(GtkWidget *widget, gpointer data);
void on_buttonAddEmploye_clicked(GtkWidget *widget, gpointer data);
void on_buttonFindComputer_clicked(GtkWidget *widget, gpointer data);
void on_buttonAddComputer_clicked(GtkWidget *widget, gpointer data);
void on_buttonQuit_clicked(GtkWidget *widget, gpointer data);


int main(int argc, char* argv[])
{
    // new instance of SQL class to initiate connection
    SQL* Sql = new SQL("inventory", "1234");

    GtkBuilder *builder;
    GObject *window;
    GObject *button;

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


/*
    // insert new entry to "employe" table
    Employe employe1;
    employe1.firstName  = "Janos";
    employe1.lastName   = "Nagy";
    employe1.sex        =  1;

    Sql->addEmploye(employe1);

    // insert new entry to "computer" table
    Computer computer1;
    computer1.name          = "OFFICE01";
    computer1.type          = "desktop";
    computer1.vendor        = "ASUS";
    computer1.cpu           = "Intel Core i5-4570";
    computer1.purchaseDate  = "2017-03-22";
    computer1.warranty      = 3;

    Sql->addComputer(computer1);
*/

    //std::cout << "Two entries added to Inventory" << std::endl;

    return EXIT_SUCCESS;
}

// temporary test function
void on_buttonFindEmploye_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Find Employe\n");
}

// temporary test function
void on_buttonAddEmploye_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Add Employe\n");
}

// temporary test function
void on_buttonFindComputer_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Find Computer\n");
}

// temporary test function
void on_buttonAddComputer_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Add Computer\n");
}

// temporary test function
void on_buttonQuit_clicked(GtkWidget *widget, gpointer data)
{
    g_print("Quit\n");
    gtk_main_quit();
}
