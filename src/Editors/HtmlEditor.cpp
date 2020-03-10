#include "HtmlEditor.hpp"
#include <wx/stc/stc.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

void HtmlEditor::onClose(wxCloseEvent &evt) { EndModal(GetReturnCode()); }

HtmlEditor::HtmlEditor(wxWindow *parent, wxString source)
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
    text->StyleSetBackground(wxSTC_STYLE_LINENUMBER, wxColour(220, 220, 220));
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
            wxCloseEventHandler(HtmlEditor::onClose),
            NULL,
            this);
}
