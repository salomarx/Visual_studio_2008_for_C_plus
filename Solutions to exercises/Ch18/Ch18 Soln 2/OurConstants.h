//Definitions of constants

#pragma once

   // Element type definitions
   // Each type value must be unique
   const unsigned int LINE = 101U;
   const unsigned int RECTANGLE = 102U;
   const unsigned int CIRCLE = 103U;
   const unsigned int CURVE = 104U;
   const unsigned int TEXT = 105U;
   ///////////////////////////////////

   // Color values for drawing
   const COLORREF BLACK = RGB(0,0,0);
   const COLORREF RED = RGB(255,0,0);
   const COLORREF GREEN = RGB(0,255,0);
   const COLORREF BLUE = RGB(0,0,255);
   const COLORREF SELECT_COLOR = RGB(255,0,180);
   ///////////////////////////////////

   // Program version number for use in serialization
   const UINT VERSION_NUMBER = 1;

