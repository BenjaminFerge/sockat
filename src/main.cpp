#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "App.hpp"
#include "MainFrame.hpp"

using namespace Sockat;

wxBEGIN_EVENT_TABLE(MainFrame, wxFrame)
EVT_MENU(ID_NewProject, MainFrame::onNewProject)
EVT_MENU(wxID_EXIT, MainFrame::onExit)
EVT_MENU(wxID_ABOUT, MainFrame::onAbout)
wxEND_EVENT_TABLE()
wxIMPLEMENT_APP(App);
