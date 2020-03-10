#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

class MainFrame : public wxFrame
{
  public:
    MainFrame(const wxString &title, const wxPoint &pos, const wxSize &size);

  private:
    void onNewProject(wxCommandEvent &event);
    void onExit(wxCommandEvent &event);
    void onAbout(wxCommandEvent &event);
    wxDECLARE_EVENT_TABLE();
    static constexpr char s_aboutMessage[] = "About message...";
};
enum { ID_NewProject = 1 };
