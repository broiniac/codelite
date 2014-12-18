//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//
// copyright            : (C) 2008 by Eran Ifrah
// file name            : openwindowspanel.h
//
// -------------------------------------------------------------------------
// A
//              _____           _      _     _ _
//             /  __ \         | |    | |   (_) |
//             | /  \/ ___   __| | ___| |    _| |_ ___
//             | |    / _ \ / _  |/ _ \ |   | | __/ _ )
//             | \__/\ (_) | (_| |  __/ |___| | ||  __/
//              \____/\___/ \__,_|\___\_____/_|\__\___|
//
//                                                  F i l e
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
#ifndef __openwindowspanel__
#define __openwindowspanel__

#include "openwindowspanelbase.h"
#include "string_client_data.h"
#include "theme_handler_helper.h"

class LEditor;

class OpenWindowsPanel : public OpenWindowsPanelBase
{
    wxString m_caption;
    wxMenu* m_rclickMenu;
    wxMenu* m_mutliMenu;
    ThemeHandlerHelper* m_themeHelper;

    int EditorItem(const LEditor* editor);
    void DoOpenSelectedItem(int item);
    void DoCloseSelectedItem(int item);
    void DoSaveItem(int item);
    void DoCloseItem(const wxString& filename);
    void DoClearSelections();
    void DoSelectItem(int item);
    void DoSelectItem(const LEditor* editor);
    int DoGetSingleSelection();
    void SortAlphabetically();
    void SortByEditorOrder();

protected:
    virtual void OnItemSelected(wxCommandEvent& event);
    // Handlers for OpenWindowsPanelBase events.
    void OnKeyDown(wxKeyEvent& event);
    void OnItemDClicked(wxCommandEvent& event);
    void OnRightDown(wxMouseEvent& event);
    void OnChar(wxKeyEvent& event);
    void OnSortItems(wxCommandEvent& event);
    void OnSortItemsUpdateUI(wxUpdateUIEvent& event);

    // Handlers for workspace events
    void OnActiveEditorChanged(wxCommandEvent& e);
    void OnEditorClosing(wxCommandEvent& e);
    void OnAllEditorsClosed(wxCommandEvent& e);
    void OnDragEnded(wxAuiNotebookEvent& e);

    void OnListBoxIsDirty(wxCommandEvent& e);
    void OnCloseSelectedFiles(wxCommandEvent& e);
    void OnSaveSelectedFiles(wxCommandEvent& e);
    DECLARE_EVENT_TABLE()

public:
    /** Constructor */
    OpenWindowsPanel(wxWindow* parent, const wxString& caption);
    ~OpenWindowsPanel();
    const wxString& GetCaption() const { return m_caption; }
};

#endif // __openwindowspanel__
