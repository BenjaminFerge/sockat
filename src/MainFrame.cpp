#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "Editors/HtmlEditor.hpp"
#include "MainFrame.hpp"

using namespace Sockat;

MainFrame::MainFrame(const wxString &title,
                     const wxPoint &pos,
                     const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(
        ID_NewProject, "&New Project\tCtrl-N", "Create a new Sockat project.");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to Sockat!");
}
void MainFrame::onExit(wxCommandEvent &event) { Close(true); }
void MainFrame::onAbout(wxCommandEvent &event)
{
    wxMessageBox(s_aboutMessage, "About Sockat", wxOK | wxICON_INFORMATION);
}
void MainFrame::onNewProject(wxCommandEvent &event)
{
    wxLogMessage("Creating a new Sockat project...");
}
