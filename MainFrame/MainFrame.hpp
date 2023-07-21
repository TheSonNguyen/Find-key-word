#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/textctrl.h>
#include <wx/button.h>

class MyFrame : public wxFrame {
public:
    MyFrame(const wxString& title);

private:
    void OnOpen(wxCommandEvent& event);
    void OnSearch(wxCommandEvent& event);

    wxTextCtrl* m_textCtrl;
    wxButton* m_openButton;
    wxButton* m_searchButton;
};

