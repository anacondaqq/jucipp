#include "juci.h"

Window::Window() :
  window_box_(Gtk::ORIENTATION_VERTICAL),
  menu_(keybindings_) {
  set_title("juCi++");
  set_default_size(600, 600);
  add(window_box_);
  keybindings_.action_group()->add(Gtk::Action::create("FileQuit",
                  Gtk::Stock::QUIT),
          [this]() {
              OnSystemQuit();
          });

  add_accel_group(keybindings_.ui_manager()->get_accel_group());
  window_box_.pack_start(menu_.view(), Gtk::PACK_SHRINK);
  window_box_.pack_start(source().view());
  show_all_children();
}

Source::Controller& Window::source() {
  return source_;
}

void Window::OnSystemQuit() {
  hide();
}
