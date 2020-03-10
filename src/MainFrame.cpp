#include <wx/stc/stc.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

#include "MainFrame.hpp"
/** Not really needed here since this example uses a single margin */
enum { MARGIN_LINE_NUMBERS };

class SourceViewDialog : public wxDialog
{
  public:
    void onClose(wxCloseEvent &evt) { EndModal(GetReturnCode()); }

    SourceViewDialog(wxWindow *parent, wxString source)
        : wxDialog(parent,
                   wxID_ANY,
                   "Source Code",
                   wxDefaultPosition,
                   wxSize(700, 500),
                   wxDEFAULT_DIALOG_STYLE | wxRESIZE_BORDER)
    {
        wxStyledTextCtrl *text = new wxStyledTextCtrl(this, wxID_ANY);

        text->SetMarginWidth(MARGIN_LINE_NUMBERS, 50);
        text->StyleSetForeground(wxSTC_STYLE_LINENUMBER, wxColour(75, 75, 75));
        text->StyleSetBackground(wxSTC_STYLE_LINENUMBER,
                                 wxColour(220, 220, 220));
        text->SetMarginType(MARGIN_LINE_NUMBERS, wxSTC_MARGIN_NUMBER);

        text->SetWrapMode(wxSTC_WRAP_WORD);

        text->SetText(source);

        text->StyleClearAll();
        text->SetLexer(wxSTC_LEX_HTML);
        text->StyleSetForeground(wxSTC_H_DOUBLESTRING, wxColour(255, 0, 0));
        text->StyleSetForeground(wxSTC_H_SINGLESTRING, wxColour(255, 0, 0));
        text->StyleSetForeground(wxSTC_H_ENTITY, wxColour(255, 0, 0));
        text->StyleSetForeground(wxSTC_H_TAG, wxColour(0, 150, 0));
        text->StyleSetForeground(wxSTC_H_TAGUNKNOWN, wxColour(0, 150, 0));
        text->StyleSetForeground(wxSTC_H_ATTRIBUTE, wxColour(0, 0, 150));
        text->StyleSetForeground(wxSTC_H_ATTRIBUTEUNKNOWN, wxColour(0, 0, 150));
        text->StyleSetForeground(wxSTC_H_COMMENT, wxColour(150, 150, 150));

        wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
        sizer->Add(text, 1, wxEXPAND);
        SetSizer(sizer);

        Connect(wxEVT_CLOSE_WINDOW,
                wxCloseEventHandler(SourceViewDialog::onClose),
                NULL,
                this);
    }
};

MainFrame::MainFrame(const wxString &title,
                     const wxPoint &pos,
                     const wxSize &size)
    : wxFrame(NULL, wxID_ANY, title, pos, size)
{
    SourceViewDialog sourceView(this->GetMainWindowOfCompositeControl(), "");
    sourceView.ShowModal();
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello,
                     "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    SetMenuBar(menuBar);
    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets!");
}
void MainFrame::OnExit(wxCommandEvent &event) { Close(true); }
void MainFrame::OnAbout(wxCommandEvent &event)
{
    wxMessageBox("This is a wxWidgets' Hello world sample",
                 "About Hello World",
                 wxOK | wxICON_INFORMATION);
}
void MainFrame::OnHello(wxCommandEvent &event)
{
    wxLogMessage("Hello world from wxWidgets!");
}
