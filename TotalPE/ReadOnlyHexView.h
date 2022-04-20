#pragma once

#include "View.h"
#include "SimpleHexControl.h"
#include "MemoryBuffer.h"

class CReadOnlyHexView : public CView<CReadOnlyHexView> {
public:
	using CView::CView;

	void SetData(std::vector<uint8_t> const& data);

	BEGIN_MSG_MAP(CreadOnlyHexView)
		MESSAGE_HANDLER(WM_CREATE, OnCreate)
		CHAIN_MSG_MAP(CView<CReadOnlyHexView>)
	END_MSG_MAP()

	LRESULT OnCreate(UINT /*uMsg*/, WPARAM /*wParam*/, LPARAM /*lParam*/, BOOL& /*bHandled*/);

private:
	CHexControl m_Hex;
	MemoryBuffer m_data;
	int m_DataSize{ 1 };
	int m_BytesPerLine{ 32 };
};
