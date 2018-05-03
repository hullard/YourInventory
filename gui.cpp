#include "gui.h"


// set up new window by constructor
GUI::GUI(int argc, char* argv[])
{
    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    gtk_window_set_default_size(GTK_WINDOW(window), SCR_WIDTH, SCR_HEIGHT);

    g_signal_connect(window, "destroy", G_CALLBACK (gtk_main_quit), nullptr);

    gtk_widget_show(window);

    gtk_main();
}

// delete window object by destructor
GUI::~GUI()
{
    delete window;
}
