#include "controller.h"
#include "main_window.h"
#include "view.h"
#include "library.h"
#include "publication.h"
#include "patron.h"
#include "genre.h"
#include "media.h"
#include "age.h"
#include "dialogs.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char *argv[]) {
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "edu.uta.cse1325.main");

  // Instance a window
  Main_window win;

  // Set the window title
  win.set_title("Library Management System");

  // Show the window and return when its closed or hidden
  return app->run(win);
}
