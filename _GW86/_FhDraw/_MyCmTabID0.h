//_GW86_FhDraw_CmTaskID0.h
//Gao-Wei Chang, 211121, 210911, 210831, 200603, 171007.
#pragma once
#include "_MyGraphID0.h"
#define CM_PATT TA_PATT
#define CM_LINE TA_PATT+ID_LINE
#define CM_RECT TA_PATT+ID_RECT
#define CM_ELLIP TA_PATT+ID_ELLIP
#define CM_FRECT TA_PATT+ID_FRECT
#define CM_FELLIP TA_PATT+ID_FELLIP
#define CM_DARR ID_DARR
#define CM_SINE ID_SINE

#define CM_TLINE CM_LINE+ID_TMR
#define CM_TRECT CM_RECT+ID_TMR
#define CM_TELLIP CM_ELLIP+ID_TMR
#define CM_TDARR TA_DARR
#define CM_TSINE TA_SINE
#define CM_TMOFF 10000
#define CM_TMSETUP 10001
#define CM_COORD 11000
#define CM_ACCOFF 12000
#define CM_ACCON 12001

#define CM_NONE 0
#define ERR_OPCSET -1
#define ERR_OPC -2
#define ERR_OPDS -3
#define CM_HELP -2  //?

#define NO_FIELDS 5
#define NO_DIV 3
#define NO_FIELD1 3
#define NO_FIELD2 3

namespace GW86 {
namespace FhDraw {
using namespace System;
//using namespace System::Windows::Forms;
public ref class MyCmTab0 {
public: static array< System::String^>^ szOpcSet = {
	"line", "rect", "ellip", "frect", "fellip",
	"darr", "sine", "tline", "trect", "tellip",
	"tdarr", "tsine", "tmoff", "tmsetup", "coord",
	"accoff", "accon"
};
public: static array<System::Int32>^ idOpcSet = {
	CM_LINE, CM_RECT, CM_ELLIP, CM_FRECT, CM_FELLIP,
	CM_DARR, CM_SINE, CM_TLINE, CM_TRECT, CM_TELLIP,
	CM_TDARR, CM_TSINE, CM_TMOFF, CM_TMSETUP, CM_COORD,
	CM_ACCOFF, CM_ACCON
};
};

} }
