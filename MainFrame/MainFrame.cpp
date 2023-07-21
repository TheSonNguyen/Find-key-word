#include <wx/wx.h>
#include <wx/filedlg.h>
#include <wx/textctrl.h>
#include <wx/button.h>
#include <wx/tokenzr.h>
#include "MainFrame.hpp"

MyFrame::MyFrame(const wxString& title)
    : wxFrame(NULL, wxID_ANY, title, wxDefaultPosition, wxSize(500, 300))
{
    wxPanel* panel = new wxPanel(this, wxID_ANY);

    m_textCtrl = new wxTextCtrl(panel, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, wxTE_MULTILINE | wxTE_READONLY);
    m_openButton = new wxButton(panel, wxID_ANY, wxT("Open File"));
    m_searchButton = new wxButton(panel, wxID_ANY, wxT("Search"));

    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(m_textCtrl, 1, wxEXPAND | wxALL, 5);
    sizer->Add(m_openButton, 0, wxALL, 5);
    sizer->Add(m_searchButton, 0, wxALL, 5);

    panel->SetSizer(sizer);

    m_openButton->Bind(wxEVT_BUTTON, &MyFrame::OnOpen, this);
    m_searchButton->Bind(wxEVT_BUTTON, &MyFrame::OnSearch, this);
}

void MyFrame::OnOpen(wxCommandEvent& event)
{
    wxFileDialog openFileDialog(this, wxT("Open File"), wxEmptyString, wxEmptyString, wxT("Text files (*.txt)|*.txt"), wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (openFileDialog.ShowModal() == wxID_CANCEL)
        return;

    wxString path = openFileDialog.GetPath();
    m_textCtrl->LoadFile(path);
}

void MyFrame::OnSearch(wxCommandEvent& event)
{
    wxString keyword = wxT("monsters");  // Replace with the desired keyword/Chúng ta sẽ tìm cụm "monsters" này trong
    wxString text = m_textCtrl->GetValue();

    wxStringTokenizer tokenizer(text, wxT("\n"));
    while (tokenizer.HasMoreTokens()) {
        wxString line = tokenizer.GetNextToken();
        if (line.Contains(keyword))
            wxLogMessage(line);
    }
}

