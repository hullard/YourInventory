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
    GtkWidget *window;
    const unsigned int SCR_WIDTH = 800;
    const unsigned int SCR_HEIGHT = 600;
};

#endif // GUI_H
