#ifndef GUI_H
#define GUI_H

#include <gtk/gtk.h>

class GUI
{
public:
    GUI(int argc, char* argv[]);

    virtual ~GUI();

protected:

private:
    GtkBuilder* builder;
    GObject* window;
    GObject* button;

    static void on_buttonNewEntry_clicked(GtkWidget *widget, gpointer data);
    static void on_buttonNewQuery_clicked(GtkWidget *widget, gpointer data);
    static void on_buttonQuit_clicked(GtkWidget *widget, gpointer data);
};

#endif // GUI_H
