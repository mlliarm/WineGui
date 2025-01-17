/**
 * Copyright (c) 2020 WineGUI
 *
 * \file    settings_window.h
 * \brief   Settings GTK+ window class
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
 * \class SettingsWindow
 * \brief GTK+ Window class for the settings
 */
class SettingsWindow : public Gtk::Window
{
public:
  // Signals
  sigc::signal<void, Gtk::Window&, Glib::ustring&> directx9; /*!< Install d3dx9 for Direct3D 9 signal */
  sigc::signal<void, Gtk::Window&, Glib::ustring&> vulkan; /*!< Install DXVK for Direct3D 9/10/11 using Vulkan signal */
  sigc::signal<void, Gtk::Window&> liberation_fonts;       /*!< Install Liberation fonts signal */
  sigc::signal<void, Gtk::Window&> corefonts;              /*!< Install Core fonts signal */
  sigc::signal<void, Gtk::Window&, Glib::ustring&> visual_cpp_package; /*!< Install Visual C++ package signal */
  sigc::signal<void, Gtk::Window&, Glib::ustring&> dotnet;             /*!< Install .NET signal */
  sigc::signal<void> uninstaller;                                      /*!< Open Wine Uninstaller signal */
  sigc::signal<void> notepad;                                          /*!< Open Notepad editor signal */
  sigc::signal<void> wordpad;                                          /*!< Open Notepad editor signal */
  sigc::signal<void> iexplore;                                         /*!< Open Notepad editor signal */
  sigc::signal<void> task_manager;                                     /*!< Open Wine Task Manager signal */
  sigc::signal<void> regedit;                                          /*!< Open Wine Registry editor signal */
  sigc::signal<void> explorer;                                         /*!< Open Explorer signal */
  sigc::signal<void> console;                                          /*!< Open Wine Console signal */
  sigc::signal<void> winecfg;                                          /*!< Open Winecfg GUI (fallback) signal */
  sigc::signal<void> winetricks;                                       /*!< Open Winetricks GUI (fallback) signal */

  explicit SettingsWindow(Gtk::Window& parent);
  virtual ~SettingsWindow();

  void Show();
  void SetActiveBottle(BottleItem* bottle);
  void ResetActiveBottle();
  void UpdateInstalled();

protected:
  // Child widgets
  Gtk::Grid settings_grid; /*!< The overall settings GTK grid */

  Gtk::Toolbar first_toolbar;  /*!< 1st row toolbar */
  Gtk::Toolbar second_toolbar; /*!< 2nd row toolbar */
  Gtk::Toolbar third_toolbar;  /*!< 3rd row toolbar */
  Gtk::Toolbar fourth_toolbar; /*!< 4th row toolbar */

  Gtk::Label first_row_label;  /*!< 1st row label */
  Gtk::Label hint_label;       /*!< Extra hint label info for user */
  Gtk::Label second_row_label; /*!< 2nd row label */
  Gtk::Label third_row_label;  /*!< 3rd row label */
  Gtk::Label fourth_row_label; /*!< 4th row label */

  // Buttons First row (Gaming)
  Gtk::ToolButton install_d3dx9_button; /*!< d3dx9 install button */
  Gtk::ToolButton install_dxvk_button;  /*!< DXVK install button */

  // Buttons Second row
  Gtk::ToolButton install_liberation_fonts_button; /*!< Liberation fonts install button */
  Gtk::ToolButton install_core_fonts_button;       /*!< Core fonts install button */
  Gtk::ToolButton install_visual_cpp_button;       /*!< MS Visual C++ Redistributable Package install button */
  Gtk::ToolButton install_dotnet4_button;          /*!< .NET v4.0 install button */
  Gtk::ToolButton install_dotnet452_button;        /*!< .NET v4.5.2 install button */

  // Buttons Third row (supporting tools)
  Gtk::ToolButton wine_uninstall_button;    /*!< Wine Uninstaller button */
  Gtk::ToolButton open_notepad_button;      /*!< Notepad editor button */
  Gtk::ToolButton open_wordpad_button;      /*!< Wordpad editor button */
  Gtk::ToolButton open_iexplore_button;     /*!< Internet Explorer button */
  Gtk::ToolButton wine_task_manager_button; /*!< Wine Task manager button */
  Gtk::ToolButton wine_regedit_button;      /*!< Wine Windows Registry editor button */

  // Buttons Fourth row (fallback tools)
  Gtk::ToolButton explorer_button;     /*!< Explorer button */
  Gtk::ToolButton wine_console_button; /*!< Wine console button */
  Gtk::ToolButton wine_config_button;  /*!< Winecfg button */
  Gtk::ToolButton winetricks_button;   /*!< Winetricks button */

private:
  BottleItem* activeBottle; /*!< Current active bottle */

  bool IsD3DX9Installed();
  bool IsDXVKInstalled();
  bool IsLiberationInstalled();
  bool IsCoreFontsInstalled();
  bool isVisualCppInstalled();
  bool isDotnet4Installed();
  bool isDotnet452Installed();
};
