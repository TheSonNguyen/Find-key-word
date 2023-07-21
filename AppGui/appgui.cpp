#include <MainFrame.hpp>
#include <wx/wx.h>


class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

bool MyApp::OnInit()
{
    MyFrame* frame = new MyFrame(wxT("Keyword Finder"));
    frame->Show(true);
    return true;
}

wxIMPLEMENT_APP(MyApp);
