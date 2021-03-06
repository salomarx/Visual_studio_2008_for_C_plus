// SketcherDoc.h : interface of the CSketcherDoc class
//


#pragma once

#include"Elements.h"
class CSketcherDoc : public CDocument
{
protected: // create from serialization only
	CSketcherDoc();
	DECLARE_DYNCREATE(CSketcherDoc)

// Attributes
public:

// Operations
public:
   void DeleteElement(CElement* pElement); // Delete an element
   unsigned int GetElementType()           // Get the element type
         { return m_Element; }
   COLORREF GetElementColor()              // Get the element color
         { return m_Color; }
   void AddElement(CElement* pElement)     // Add an element to the list
   {
     m_ElementList.AddTail(pElement);
     SetModifiedFlag();                    // Set the modified flag
   }
   POSITION GetListHeadPosition()          // return list head POSITION value
      { return m_ElementList.GetHeadPosition(); }
   CElement* GetNext(POSITION& aPos)       // Return current element pointer
      { return m_ElementList.GetNext(aPos); }
   void SendToBack(CElement* pElement);    // Move an element to the back in the Z-order
   int GetPenWidth()                       // Get the current pen width
      { return m_PenWidth; }
   CSize GetDocSize()
   { return m_DocSize; }                   // Retrieve the document size
  CRect GetDocExtent();                    // Get the bounding rectangle for the whole document

// Overrides
public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);

// Implementation
public:
	virtual ~CSketcherDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()
public:
  afx_msg void OnColorBlack();
public:
  afx_msg void OnColorRed();
public:
  afx_msg void OnColorGreen();
public:
  afx_msg void OnColorBlue();
public:
  afx_msg void OnElementLine();
public:
  afx_msg void OnElementRectangle();
public:
  afx_msg void OnElementCircle();
public:
  afx_msg void OnElementCurve();
protected:
  // Current element type
  unsigned int m_Element;
  COLORREF m_Color;                                 // Current drawing color
  CTypedPtrList<CObList, CElement*> m_ElementList;  // Element list
  int m_PenWidth;                                   // Current pen width
  CSize m_DocSize;                                  // Document size

public:
  afx_msg void OnUpdateColorBlack(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateColorGreen(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateColorRed(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateColorBlue(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateElementLine(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateElementRectangle(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateElementCircle(CCmdUI *pCmdUI);
public:
  afx_msg void OnUpdateElementCurve(CCmdUI *pCmdUI);
public:
  afx_msg void OnPenwidth();
public:
  afx_msg void OnElementText();
public:
  afx_msg void OnUpdateElementText(CCmdUI *pCmdUI);
};


