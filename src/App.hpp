#pragma once

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#include <wx/wx.h>
#endif

namespace Sockat
{
class App : public wxApp
{
  public:
    virtual bool OnInit();

  private:
    static constexpr char s_title[] = "Sockat";
    static constexpr int s_defaultWidth = 800;
    static constexpr int s_defaultHeight = 600;
};
} // namespace Sockat
