#include <string>
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "App.hpp"
#include "MainFrame.hpp"

using namespace Sockat;

constexpr char App::s_title[];

bool App::OnInit()
{
    MainFrame *frame =
        new MainFrame(s_title, wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
