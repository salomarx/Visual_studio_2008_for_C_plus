// SketcherDoc.cpp : implementation of the CSketcherDoc class
//

#include "stdafx.h"
#include "Sketcher.h"
#include "PenDialog.h"

#include "SketcherDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CSketcherDoc

IMPLEMENT_DYNCREATE(CSketcherDoc, CDocument)

BEGIN_MESSAGE_MAP(CSketcherDoc, CDocument)
  ON_COMMAND(ID_COLOR_BLACK, &CSketcherDoc::OnColorBlack)
  ON_COMMAND(ID_COLOR_RED, &CSketcherDoc::OnColorRed)
  ON_COMMAND(ID_COLOR_GREEN, &CSketcherDoc::OnColorGreen)
  ON_COMMAND(ID_COLOR_BLUE, &CSketcherDoc::OnColorBlue)
  ON_COMMAND(ID_ELEMENT_LINE, &CSketcherDoc::OnElementLine)
  ON_COMMAND(ID_ELEMENT_RECTANGLE, &CSketcherDoc::OnElementRectangle)
  ON_COMMAND(ID_ELEMENT_CIRCLE, &CSketcherDoc::OnElementCircle)
  ON_COMMAND(ID_ELEMENT_CURVE, &CSketcherDoc::OnElementCurve)
  ON_UPDATE_COMMAND_UI(ID_COLOR_BLACK, &CSketcherDoc::OnUpdateColorBlack)
  ON_UPDATE_COMMAND_UI(ID_COLOR_RED, &CSketcherDoc::OnUpdateColorRed)
  ON_UPDATE_COMMAND_UI(ID_COLOR_GREEN, &CSketcherDoc::OnUpdateColorGreen)
  ON_UPDATE_COMMAND_UI(ID_COLOR_BLUE, &CSketcherDoc::OnUpdateColorBlue)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_LINE, &CSketcherDoc::OnUpdateElementLine)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_RECTANGLE, &CSketcherDoc::OnUpdateElementRectangle)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_CIRCLE, &CSketcherDoc::OnUpdateElementCircle)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_CURVE, &CSketcherDoc::OnUpdateElementCurve)
  ON_COMMAND(ID_PENWIDTH, &CSketcherDoc::OnPenwidth)
  ON_COMMAND(ID_ELEMENT_TEXT, &CSketcherDoc::OnElementText)
  ON_UPDATE_COMMAND_UI(ID_ELEMENT_TEXT, &CSketcherDoc::OnUpdateElementText)
END_MESSAGE_MAP()


// CSketcherDoc construction/destruction

CSketcherDoc::CSketcherDoc()
: m_Element(LINE)
, m_Color(BLACK)
,m_PenWidth(0)                        // 1 pixel pen
,m_DocSize(CSize(3000,3000))
{
	// TODO: add one-time construction code here

}

CSketcherDoc::~CSketcherDoc()
{
   // Get the position at the head of the list
   POSITION aPosition = m_ElementList.GetHeadPosition();

   // Now delete the element pointed to by each list entry
   while(aPosition)
      delete m_ElementList.GetNext(aPosition);

   m_ElementList.RemoveAll();   // Finally delete all pointers
}

BOOL CSketcherDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}




// CSketcherDoc serialization

void CSketcherDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}


// CSketcherDoc diagnostics

#ifdef _DEBUG
void CSketcherDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CSketcherDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CSketcherDoc commands

void CSketcherDoc::OnColorBlack()
{
     m_Color = BLACK;          // Set the drawing color to black
}

void CSketcherDoc::OnColorRed()
{
     m_Color = RED;          // Set the drawing color to red
}

void CSketcherDoc::OnColorGreen()
{
     m_Color = GREEN;          // Set the drawing color to green
}

void CSketcherDoc::OnColorBlue()
{
     m_Color = BLUE;          // Set the drawing color to blue
}

void CSketcherDoc::OnElementLine()
{
     m_Element = LINE;         // Set element type as a line
}

void CSketcherDoc::OnElementRectangle()
{
     m_Element = RECTANGLE;         // Set element type as a rectangle
}

void CSketcherDoc::OnElementCircle()
{
     m_Element = CIRCLE;         // Set element type as a circle
}

void CSketcherDoc::OnElementCurve()
{
     m_Element = CURVE;         // Set element type as a curve
}

void CSketcherDoc::OnUpdateColorBlack(CCmdUI *pCmdUI)
{
   // Set menu item Checked if the current color is black
   pCmdUI->SetCheck(m_Color==BLACK);
}

void CSketcherDoc::OnUpdateColorRed(CCmdUI *pCmdUI)
{
   // Set menu item Checked if the current color is red
   pCmdUI->SetCheck(m_Color==RED);
}

void CSketcherDoc::OnUpdateColorGreen(CCmdUI *pCmdUI)
{
     // Set menu item Checked if the current color is green
   pCmdUI->SetCheck(m_Color==GREEN);

}

void CSketcherDoc::OnUpdateColorBlue(CCmdUI *pCmdUI)
{
   // Set menu item Checked if the current color is blue
   pCmdUI->SetCheck(m_Color==BLUE);
}

void CSketcherDoc::OnUpdateElementLine(CCmdUI *pCmdUI)
{
     // Set Checked if the current element is a circle
   pCmdUI->SetCheck(m_Element==LINE);
}

void CSketcherDoc::OnUpdateElementRectangle(CCmdUI *pCmdUI)
{
   // Set Checked if the current element is a rectangle
   pCmdUI->SetCheck(m_Element==RECTANGLE);
}

void CSketcherDoc::OnUpdateElementCircle(CCmdUI *pCmdUI)
{
   // Set Checked if the current element is a circle
   pCmdUI->SetCheck(m_Element==CIRCLE);
}

void CSketcherDoc::OnUpdateElementCurve(CCmdUI *pCmdUI)
{
   // Set Checked if the current element is a curve
   pCmdUI->SetCheck(m_Element==CURVE);
}

void CSketcherDoc::DeleteElement(CElement* pElement)
{
  if(pElement)
  {
    // If the element pointer is valid,
    // find the pointer in the list and delete it
    POSITION aPosition = m_ElementList.Find(pElement);
    m_ElementList.RemoveAt(aPosition);
    delete pElement;                   // Delete the element from the heap
  }
}

void CSketcherDoc::SendToBack(CElement* pElement)
{
  if(pElement)
  {
    // If the element pointer is valid,
    // find the pointer in the list and remove the element
    POSITION aPosition = m_ElementList.Find(pElement);
    m_ElementList.RemoveAt(aPosition);

    m_ElementList.AddTail(pElement);  // Put it back to the end of the list
  }
} 

void CSketcherDoc::OnPenwidth()
{
   CPenDialog aDlg;                    // Create a local dialog object

   // Set the pen width in the dialog to that stored in the document
   aDlg.m_PenWidth = m_PenWidth;

   // Display the dialog as modal
   // When closed with OK, get the pen width
   if(aDlg.DoModal() == IDOK)
      m_PenWidth = aDlg.m_PenWidth;
}

void CSketcherDoc::OnElementText()
{
  m_Element = TEXT;
}

void CSketcherDoc::OnUpdateElementText(CCmdUI *pCmdUI)
{
  // Set checked if the current element is text
  pCmdUI->SetCheck(m_Element == TEXT);
}
