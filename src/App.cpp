#include <string>
#include <wx/gdicmn.h>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "App.hpp"
#include "MainFrame.hpp"

using namespace Sockat;

bool App::OnInit()
{
    MainFrame *frame = new MainFrame(
        s_title, wxDefaultPosition, wxSize(s_defaultWidth, s_defaultHeight));
    frame->Show(true);
    return true;
}
