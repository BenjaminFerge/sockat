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
};
} // namespace Sockat
