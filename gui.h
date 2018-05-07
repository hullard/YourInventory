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

    // handlers connected to clicked signals
    static void on_buttonFindEmploye_clicked(GtkWidget *widget, gpointer data);
    static void on_buttonAddEmploye_clicked(GtkWidget *widget, gpointer data);
    static void on_buttonFindComputer_clicked(GtkWidget *widget, gpointer data);
    static void on_buttonAddComputer_clicked(GtkWidget *widget, gpointer data);
    static void on_buttonQuit_clicked(GtkWidget *widget, gpointer data);

    //void connectSignals();

};

#endif // GUI_H
