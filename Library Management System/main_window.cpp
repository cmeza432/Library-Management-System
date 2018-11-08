#include "main_window.h"
#include "controller.h"
#include "library.h"
#include "view.h"
#include <gtkmm.h>

//Library library;

Main_window::Main_window()
{
  set_default_size(400, 200);
  Gtk::Box *vbox = Gtk::manage(new Gtk::Box(Gtk::ORIENTATION_VERTICAL, 0));
  add(*vbox);

  ///// M E N U /////
  Gtk::MenuBar *menubar = Gtk::manage(new Gtk::MenuBar());
  vbox->pack_start(*menubar, Gtk::PACK_SHRINK, 0);

  ///// F I L E /////
  Gtk::MenuItem *menuitem_file = Gtk::manage(new Gtk::MenuItem("_File", true));
  menubar->append(*menuitem_file);
  Gtk::Menu *filemenu = Gtk::manage(new Gtk::Menu());
  menuitem_file->set_submenu(*filemenu);

  ///// Q U I T /////
  Gtk::MenuItem *menuitem_quit = Gtk::manage(new Gtk::MenuItem("_Quit", true));
  menuitem_quit->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_exit_click));
  filemenu->append(*menuitem_quit);


  ///// P U B L I C A T I O N /////
  Gtk::MenuItem *menuitem_publication = Gtk::manage(new Gtk::MenuItem("_Publication", true));
  menubar->append(*menuitem_publication);
  Gtk::Menu *publicationmenu = Gtk::manage(new Gtk::Menu());
  menuitem_publication->set_submenu(*publicationmenu);

  ///// L I S T //////
  Gtk::MenuItem *menuitem_list = Gtk::manage(new Gtk::MenuItem("_List", true));
  menuitem_list->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_all_click));
  publicationmenu->append(*menuitem_list);

  ///// A D D /////
  Gtk::MenuItem *menuitem_add = Gtk::manage(new Gtk::MenuItem("_Add", true));
  menuitem_add->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_publication_click));
  publicationmenu->append(*menuitem_add);

  ///// C H E C K O U T //////
  Gtk::MenuItem *menuitem_checkout = Gtk::manage(new Gtk::MenuItem("_Check Out", true));
  menuitem_checkout->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_check_out_click));
  publicationmenu->append(*menuitem_checkout);

  ///// C H E C K I N /////
  Gtk::MenuItem *menuitem_checkin = Gtk::manage(new Gtk::MenuItem("_Check In", true));
  menuitem_checkin->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_check_in_click));
  publicationmenu->append(*menuitem_checkin);

  ///// P A T R O N /////
  Gtk::MenuItem *menuitem_patron = Gtk::manage(new Gtk::MenuItem("_Patron", true));
  menubar->append(*menuitem_patron);
  Gtk::Menu *patronmenu = Gtk::manage(new Gtk::Menu());
  menuitem_patron->set_submenu(*patronmenu);

  ///// L I S T   P A T R O N /////
  Gtk::MenuItem *menuitem_list_p = Gtk::manage(new Gtk::MenuItem("_List", true));
  menuitem_list_p->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_list_patron_click));
  patronmenu->append(*menuitem_list_p);

  ///// A D D   P A T R O N /////
  Gtk::MenuItem *menuitem_addpatron = Gtk::manage(new Gtk::MenuItem("_Add", true));
  menuitem_addpatron->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_add_patron_click));
  patronmenu->append(*menuitem_addpatron);

  ///// H E L P /////
  Gtk::MenuItem *menuitem_help = Gtk::manage(new Gtk::MenuItem("_Help", true));
  menubar->append(*menuitem_help);
  Gtk::Menu *helpmenu = Gtk::manage(new Gtk::Menu());
  menuitem_help->set_submenu(*helpmenu);

  ///// A B O U T /////
  Gtk::MenuItem *menuitem_about = Gtk::manage(new Gtk::MenuItem("_About", true));
  menuitem_about->signal_activate().connect(sigc::mem_fun(*this, &Main_window::on_help_click));
  helpmenu->append(*menuitem_about);

  vbox->show_all();
}

Main_window::~Main_window()
{
}

// Exit function
void Main_window::on_exit_click()
{
  hide();
}

//Goes to add publication controller call
void Main_window::on_add_publication_click()
{
  Controller controller(library);
  controller.execute_cmd(1);
}

//List all publications
void Main_window::on_list_all_click()
{
  Controller controller(library);
  controller.execute_cmd(2);
}

// Checks out publication
void Main_window::on_check_out_click()
{
  Controller controller(library);
  controller.execute_cmd(3);
}

//Checks in publication
void Main_window::on_check_in_click()
{
  Controller controller(library);
  controller.execute_cmd(4);
}

// List all the patrons
void Main_window::on_list_patron_click()
{
  Controller controller(library);
  controller.execute_cmd(6);
}

// Adds a patron
void Main_window::on_add_patron_click()
{
  Controller controller(library);
  controller.execute_cmd(5);
}

// Help function
void Main_window::on_help_click()
{
  Controller controller(library);
  controller.execute_cmd(9);
}
