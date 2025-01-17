/**
 * Copyright (c) 2020 WineGUI
 *
 * \file    edit_window.h
 * \brief   Edit GTK+ window class
 * \author  Melroy van den Berg <webmaster1989@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as
 * published by the Free Software Foundation, either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#pragma once

#include <gtkmm.h>

using std::string;

// Forward declaration
class BottleItem;

/**
 * \class EditWindow
 * \brief GTK+ Window class for the settings
 */
class EditWindow : public Gtk::Window
{
public:
  explicit EditWindow(Gtk::Window& parent);
  virtual ~EditWindow();

  void Show();
  void SetActiveBottle(BottleItem* bottle);
  void ResetActiveBottle();

protected:
  // Child widgets
  Gtk::Grid settings_grid;

  Gtk::Label label;

  Gtk::ToolButton save_button;   /*!< save button */
  Gtk::ToolButton delete_button; /*!< delete button */

  // Buttons second row
  Gtk::ToolButton wine_config_button; /*!< Winecfg button */

private:
  BottleItem* activeBottle; /*!< Current active bottle */
};
