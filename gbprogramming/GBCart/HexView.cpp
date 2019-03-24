// HexView.cpp

#include "StdAfx.h"
#include "HexView.h"
#include "GBCartDoc.h"

IMPLEMENT_DYNCREATE(CHexView, CScrollView)

BEGIN_MESSAGE_MAP(CHexView, CScrollView)
    //{{AFX_MSG_MAP(CHexView)
	ON_WM_KEYDOWN()
	ON_WM_SIZING()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP			
END_MESSAGE_MAP()

CHexView::CHexView() : 
    m_dwTotalLines(0), 
    m_dwPageLines(0)
{
	// Schriftart Courier vorbereiten
    VERIFY(m_Font.CreatePointFont(12, "Courier"));
}

void CHexView::OnInitialUpdate()
{
	// Methode der Oberklasse aufrufen
	CScrollView::OnInitialUpdate();

    // Hole Zeiger auf Dokument
    CGBCartDoc * pDoc = (CGBCartDoc *) GetDocument();
    ASSERT_VALID(pDoc);

	// Datei besteht aus so vielen Zeilen
    if(pDoc->m_Size % 16)
	{
        m_dwTotalLines = pDoc->m_Size / 16 + 1;
	}
    else
	{
        m_dwTotalLines = pDoc->m_Size / 16;
	}

	// Gr��e des Dokuments in Pixel setzen
    SetScrollSizes(MM_TEXT, CSize(630, 16 * m_dwTotalLines));
}

void CHexView::OnDraw(CDC* pDC)
{
	CRect rect;

	// Gr��e des Zeichenbereichs ermitteln
	GetClientRect(&rect);

	// Anzahl in Ansicht darstellbarer Zeilen
	if(rect.Height() % 16)
	{
		m_dwPageLines = rect.Height() / 16 + 1;
	}
	else
	{
		m_dwPageLines = rect.Height() / 16;
	}

	// 01-25-2006: prevents garbage being displayed
	if (m_dwTotalLines < m_dwPageLines)
		m_dwPageLines = m_dwTotalLines;

	// Gr��e des Dokuments (in Pixel) erneut setzen
    SetScrollSizes(MM_TEXT, CSize(630, 16 * m_dwTotalLines /* - 1 */),
  		                    CSize(630, 16 * (m_dwPageLines - 1)), CSize(630, 16));

	// Position of Scrollbalken
	m_dwOffset = (GetScrollPos(SB_VERT) & 0xfffffff0);

	// Hole Zeiger auf Dokumentobjekt
	CGBCartDoc* pDoc = (CGBCartDoc *) GetDocument();
	ASSERT_VALID(pDoc);

	// Jede Zeile ausgeben
	for(DWORD dwLine = 0, dwOffset = m_dwOffset; dwLine < m_dwPageLines; dwLine++, dwOffset += 16)
    {
		// Anzahl Zeichen in aktueller Zeile
		DWORD dwCount = 16 < (dwCount = pDoc->m_Size - dwOffset) ? 16 : dwCount;

		CString strLeft, strRight, strFormat;

        for(register DWORD dwChar = 0; dwChar < dwCount; dwChar++)
        {
            // Einzelnes Zeichen hinzuf�gen
            strLeft  += " %02x";
            strRight += "%c";

            // Umwandlung in (hexadezimales) Zeichen
			strLeft .Format(strFormat = strLeft,  BYTE(pDoc->m_Buffer[dwOffset + dwChar]));
            strRight.Format(strFormat = strRight, CHAR(pDoc->m_Buffer[dwOffset + dwChar]));

            // Offset einf�gen
            strFormat.Format("%06x   ", dwOffset);

            // Ausgabezeile zusammenf�gen
            strFormat += strLeft + CString(' ', 49 - 3 * dwChar) + strRight;

			// 01-25-2006: nicer output for '\n', '\r', '\t'
			strFormat.Replace("\r", ".");
			strFormat.Replace("\n", ".");
			strFormat.Replace("\t", ".");
        }

		// Schriftart zur Ausgabe w�hlen
		pDC->SelectObject(m_Font);
		
        // Zeile in Fenster ausgeben
		pDC->TextOut(10, dwOffset, strFormat);
     }
}

void CHexView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	// Fix f�r Fehler Q152252
    if(nSBCode == SB_THUMBTRACK || nSBCode == SB_THUMBPOSITION)
    {
        SCROLLINFO info;

		info.cbSize = sizeof(SCROLLINFO);
        info.fMask  = SIF_TRACKPOS;

		::GetScrollInfo(m_hWnd, SB_VERT, &info);

        nPos = info.nTrackPos;
    }

	// Ansicht wird nur zeilenweise bewegt
	nPos &= 0xfffffff0;

	// Methode der Oberklasse aufrufen
	CScrollView::OnVScroll(nSBCode, nPos, pScrollBar);
}
void CHexView::OnSizing(UINT, LPRECT)
{
	// Scrollbalken neu positionieren
	SetScrollPos(SB_VERT, m_dwOffset);

	// Veranlasse Neuzeichnen der Ansicht
	Invalidate();
}

void CHexView::OnKeyDown(UINT nChar, UINT, UINT)
{
	switch(nChar)
	{
		case VK_PRIOR:
		{
			OnVScroll(SB_PAGEUP, 0, 0);
			break;
		}

		case VK_NEXT:
		{
			OnVScroll(SB_PAGEDOWN, 0, 0);
			break;
		}

		case VK_END:
		{
			OnVScroll(SB_BOTTOM, 0, 0);
			break;
		}

		case VK_HOME:
		{
			OnVScroll(SB_TOP, 0, 0);
			break;
		}

		case VK_UP:
		{
			OnVScroll(SB_LINEUP, 0, 0);
			break;
		}

		case VK_DOWN:
		{
			OnVScroll(SB_LINEDOWN, 0, 0);
			break;
		}
	}
}

void CHexView::OnUpdate(CView* /*pSender*/, LPARAM /*lHint*/, CObject* /*pHint*/){
    Invalidate();
}