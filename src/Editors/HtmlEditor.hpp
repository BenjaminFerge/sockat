#include <wx/stc/stc.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

enum { MARGIN_LINE_NUMBERS };

class HtmlEditor : public wxDialog
{
  public:
    void onClose(wxCloseEvent &evt);
    HtmlEditor(wxWindow *parent, wxString source);
};
