#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "App.hpp"
#include "MainFrame.hpp"

using namespace Sockat;

bool App::OnInit()
{
    MainFrame *frame =
        new MainFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
