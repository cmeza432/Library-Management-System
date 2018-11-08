#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <gtkmm.h>
#include "library.h"
#include "controller.h"
#include "view.h"

class Main_window : public Gtk::Window
{
public:
  Main_window();
  virtual ~Main_window();

protected:
  void on_list_all_click();
  void on_add_publication_click();
  void on_check_out_click();
  void on_check_in_click();
  void on_list_patron_click();
  void on_add_patron_click();
  void on_help_click();
  void on_exit_click();
private:
  Library library;
};
#endif
