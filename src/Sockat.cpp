#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif
#include "MainFrame.hpp"
#include "Sockat.hpp"

bool Sockat::OnInit()
{
    MainFrame *frame =
        new MainFrame("Hello World", wxPoint(50, 50), wxSize(450, 340));
    frame->Show(true);
    return true;
}
