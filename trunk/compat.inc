
ramStart             =  8000h
appData              =  8000h
ramCode              =  8100h
ramCodeEnd           =  822Fh
baseAppBrTab         =  8230h
bootTemp             =  8251h
appSearchPage        =  82A3h
tempSwapArea         =  82A5h
appID                =  838Dh
ramReturnData        =  83EDh
arcInfo              =  83EEh
savedArcInfo         =  8406h
appInfo              =  8432h
appBank_jump         =  843Ch
appPage              =  843Eh
kbdScanCode          =  843Fh
kbdKey               =  8444h
kbdGetKy             =  8445h
keyExtend            =  8446h
contrast             =  8447h
apdSubTimer          =  8448h
apdTimer             =  8449h
curTime              =  844Ah
curRow               =  844Bh
curCol               =  844Ch
curOffset            =  844Dh
curUnder             =  844Eh
curY                 =  844Fh
curType              =  8450h
curXRow              =  8451h
prevDData            =  8452h
lFont_record         =  845Ah
sFont_record         =  8462h
tokVarPtr            =  846Ah
tokLen               =  846Ch
indicMem             =  846Eh
indicCounter         =  8476h
indicBusy            =  8477h
OP1                  =  8478h
OP1M                 =  847Ah
OP2                  =  8483h
OP2M                 =  8485h
OP2EXT               =  848Ch
OP3                  =  848Eh
OP3M                 =  8490h
OP4                  =  8499h
OP4M                 =  849Bh
OP5                  =  84A4h
OP5M                 =  84A6h
OP6                  =  84AFh
OP6M                 =  84B1h
OP6EXT               =  84B8h
progToEdit           =  84BFh
nameBuff             =  84C7h
equ_edit_save        =  84D2h
iMathPtr1            =  84D3h
iMathPtr2            =  84D5h
iMathPtr3            =  84D7h
iMathPtr4            =  84D9h
iMathPtr5            =  84DBh
chkDelPtr1           =  84DDh
chkDelPtr2           =  84DFh
insDelPtr            =  84E1h
upDownPtr            =  84E3h
fOutDat              =  84E5h
asm_data_ptr1        =  84EBh
asm_data_ptr2        =  84EDh
asm_sym_ptr1         =  84EFh
asm_sym_ptr2         =  84F1h
asm_ram              =  84F3h
asm_ind_call         =  8507h
textShadow           =  8508h
textShadCur          =  8588h
textShadTop          =  858Ah
textShadAlph         =  858Bh
textShadIns          =  858Ch
cxMain               =  858Dh
cxPPutAway           =  858Fh
cxPutAway            =  8591h
cxRedisp             =  8593h
cxErrorEP            =  8595h
cxSizeWind           =  8597h
cxPage               =  8599h
cxCurApp             =  859Ah
cxPrev               =  859Bh
monQH                =  85AAh
monQT                =  85ABh
monQueue             =  85ACh
onSP                 =  85BCh
promptRow            =  85C0h
promptCol            =  85C1h
promptIns            =  85C2h
promptShift          =  85C3h
promptRet            =  85C4h
promptValid          =  85C6h
promptTop            =  85C8h
promptCursor         =  85CAh
promptTail           =  85CCh
promptBtm            =  85CEh
varType              =  85D0h
varCurrent           =  85D1h
varClass             =  85D9h
menuActive           =  85DCh
menuAppDepth         =  85DDh
MenuCurrent          =  85DEh
ProgCurrent          =  85E8h
userMenuSA           =  85FEh
ioPrompt             =  865Fh
dImageWidth          =  8660h
RectFillPHeight      =  8660h
RectFillPWidth       =  8661h
RectFillPattern      =  8662h
ioFlag               =  8670h
sndRecState          =  8672h
ioErrState           =  8673h
header               =  8674h
ioData               =  867Dh
ioNewData            =  8689h
bakHeader            =  868Bh
penCol               =  86D7h
penRow               =  86D8h
rclQueue             =  86D9h
rclQueueEnd          =  86DBh
errNo                =  86DDh
errSP                =  86DEh
errOffset            =  86E0h
saveSScreen          =  86ECh
bstCounter           =  89EEh
flags                =  89F0h
statVars             =  8A3Ah
anovaf_vars          =  8C17h
infVars              =  8C4Dh
curGStyle            =  8D17h
curGY                =  8D18h
curGX                =  8D19h
curGY2               =  8D1Ah
curGX2               =  8D1Bh
freeSaveY            =  8D1Ch
freeSaveX            =  8D1Dh
XOffset              =  8DA1h
YOffset              =  8DA2h
lcdTallP             =  8DA3h
pixWideP             =  8DA4h
pixWide_m_1          =  8DA5h
pixWide_m_2          =  8DA6h
lastEntryPTR         =  8DA7h
lastEntryStk         =  8DA9h
numLastEntries       =  8E29h
currLastEntry        =  8E2Ah
curInc               =  8E67h
uXmin                =  8E7Eh
uXmax                =  8E87h
uXscl                =  8E90h
uYmin                =  8E99h
uYmax                =  8EA2h
uYscl                =  8EABh
uThetMin             =  8EB4h
uThetMax             =  8EBDh
uThetStep            =  8EC6h
uTmin                =  8ECFh
uTmax                =  8ED8h
uTStep               =  8EE1h
uPlotStart           =  8EEAh
unMax                =  8EF3h
uu0                  =  8EFCh
uv0                  =  8F05h
unMin                =  8F0Eh
uu02                 =  8F17h
uv02                 =  8F20h
uw0                  =  8F29h
uPlotStep            =  8F32h
uXres                =  8F3Bh
uw02                 =  8F44h
Xmin                 =  8F50h
Xmax                 =  8F59h
Xscl                 =  8F62h
Ymin                 =  8F6Bh
Ymax                 =  8F74h
Yscl                 =  8F7Dh
ThetaMin             =  8F86h
ThetaMax             =  8F8Fh
ThetaStep            =  8F98h
TminPar              =  8FA1h
TmaxPar              =  8FAAh
Tstep                =  8FB3h
PlotStart            =  8FBCh
nMax                 =  8FC5h
u0                   =  8FCEh
v0                   =  8FD7h
nMin                 =  8FE0h
u02                  =  8FE9h
v02                  =  8FF2h
w0                   =  8FFBh
PlotStep             =  9004h
XresO                =  900Dh
w02                  =  9016h
un1                  =  901Fh
un2                  =  9028h
vn1                  =  9031h
vn2                  =  903Ah
wn1                  =  9043h
wn2                  =  904Ch
fin_N                =  9055h
fin_I                =  905Eh
fin_PV               =  9067h
fin_PMT              =  9070h
fin_FV               =  9079h
fin_PY               =  9082h
fin_CY               =  908Bh
cal_N                =  9094h
cal_I                =  909Dh
cal_PV               =  90A6h
cal_PMT              =  90AFh
cal_FV               =  90B8h
cal_PY               =  90C1h
smallEditRAM         =  90D3h
XFact                =  913Fh
YFact                =  9148h
Xres_int             =  9151h
deltaX               =  9152h
deltaY               =  915Bh
shortX               =  9164h
shortY               =  916Dh
lower                =  9176h
upper                =  917Fh
XOutSym              =  918Ch
XOutDat              =  918Eh
YOutSym              =  9190h
YOutDat              =  9192h
inputSym             =  9194h
inputDat             =  9196h
prevData             =  9198h
TblMin               =  92B3h
TblStep              =  92BCh
P1Type		     =  92C9h
SavX1List	     =  92CAh
SavY1List	     =  92CFh
SavF1List	     =  92D4h
P1FrqOnOff	     =  92D9h
P2Type		     =  92DAh
SavX2List	     =  92DBh
SavY2List	     =  92E0h
SavF2List	     =  92E5h
P2FrqOnOff	     =  92EAh
P3Type		     =  92EBh	
SavX3List	     =  92ECh
SavY3List	     =  92F1h
SavF3List	     =  92F6h
P3FrqOnOff	     =  92FBh
plotSScreen          =  9340h
seed1                =  9640h
seed2                =  9649h
cmdShadow            =  966Eh
cmdShadCur           =  96EEh
cmdShadAlph          =  96F0h
cmdShadIns           =  96F1h
cmdCursor            =  96F2h
editTop              =  96F4h
editCursor           =  96F6h
editTail             =  96F8h
editBtm              =  96FAh
editSym              =  9706h
editDat              =  9708h
winTop               =  97A5h
winBtm               =  97A6h
winLeftEdge          =  97A7h
winLeft              =  97A8h
winAbove             =  97AAh
winRow               =  97ACh
winCol               =  97AEh
fmtDigits            =  97B0h
fmtString            =  97B1h
fmtConv              =  97F2h
fmtLeft              =  9804h
fmtIndex             =  9806h
fmtMatSym            =  9808h
fmtMatMem            =  980Ah
EQS                  =  980Ch
tSymPtr1             =  9818h
tSymPtr2             =  981Ah
chkDelPtr3           =  981Ch
chkDelPtr4           =  981Eh
tempMem              =  9820h
fpBase               =  9822h
FPS                  =  9824h
OPBase               =  9826h
OPS                  =  9828h
pTempCnt             =  982Ah
cleanTmp             =  982Ch
pTemp                =  982Eh
progPtr              =  9830h
newDataPtr           =  9832h
pagedCount           =  9834h
pagedPN              =  9835h
pagedGetPtr          =  9836h
pagedPutPtr          =  9838h
pagedBuf             =  983Ah
appErr1              =  984Dh
appErr2              =  985Ah
flashByte1           =  9867h
flashByte2           =  9868h
freeArcBlock         =  9869h
arcPage              =  986Bh
arcPtr               =  986Ch
appRawKeyHandle      =  9870h
appBackUpScreen      =  9872h
customHeight         =  9B72h
localLanguage        =  9B73h
cursorHookPtr        =  9B7Ch
rawKeyHookPtr        =  9B84h
getKeyHookPtr        =  9B88h
fontHookPtr          =  9B9Ch
restartClr           =  9BD0h
localTokStr          =  9D65h
keyForStr            =  9D76h
keyToStrRam          =  9D77h
sedMonSp             =  9D88h
bpSave               =  9D8Ah
userMem              =  9D95h
symTable             =  0FE66h

;
;======================================================================
;           System and State Flags
;======================================================================
;

trigFlags	=  0		;Trigonometry mode settings
trigDeg 	=    2	; 1=degrees, 0=radians

kbdFlags	=  0		;Keyboard scan
kbdSCR		=    3	; 1=scan code ready
kbdKeyPress	=    4	; 1=key has been pressed

doneFlags	=  0		;display "Done"
donePrgm	=    5	; 1=display "Done" after prgm

ioDelFlag	=  0
inDelete	=    0	;1 = DELETE SCREEN 

;----------------------------------------------------------------------
editFlags	=  1
editOpen	=    2	; 1=edit buffer is open

monFlags	=  1		;monitor flags
monAbandon	=    4	; 1=don't start any long process
				; in put away (#715)
;----------------------------------------------------------------------
plotFlags	=  2		;plot generation flags
plotTrace	=  0
plotLoc 	=    1	; 0=bkup & display, 1=display only
plotDisp	=    2	; 1=plot is in display, 0=text in display


grfModeFlags	=  2		;graph mode settings
grfFuncM	=    4	; 1=function graph
grfPolarM	=    5	; 1=polar graph
grfParamM	=    6	; 1=parametric graph
grfRecurM       =    7        ; 1=RECURSION graph

graphFlags	=  3
graphDraw	=    0	; 0=graph is valid, 1=redraw graph

grfDBFlags	=  4
grfDot		=    0	; 0=line, 1=dot
grfSimul	=    1	; 0=sequential, 1=simultaneous
grfGrid 	=    2	; 0=no grid, 1=grid
grfPolar	=    3	; 0=rectangular, 1=polar coordinates
grfNoCoord	=    4	; 0=display coordinates, 1=off
grfNoAxis	=    5	; 0=axis, 1=no axis
grfLabel	=    6	; 0=off, 1=axis label

textFlags	=  5		;Text output flags
textEraseBelow	=    1	; 1=erase line below small char
textScrolled	=    2	; 1=screen scrolled
textInverse	=    3	; 1=display inverse bit-map
textInsMode	=    4	; 0=overstrike, 1=insert mode

ParsFlag2	=  7		;PARSER flags
numOP1		=    0	; 1=RESULT IN OP1, 0=NO RESULT

newDispF        =  8		;Derivative mode flags
preClrForMode   =    0	; 1=HELP BLINK ON MODE SCREEN

apdFlags	=  8		;Automatic power-down
apdAble 	=    2	; 1=APD enabled
apdRunning	=    3	; 1=APD clock running


web_err_mask    =  60h

onFlags 	=  9		;on key flags
onRunning	=  3		; 1 = calculator is running
onInterrupt	=    4	; 1=on key interrupt request

statFlags	=  9		;statistics flags
statsValid	=    6	; 1=stats are valid
statANSDISP	=  7		; 1=display stat results


fmtFlags	=  10		;numeric format flags
fmtExponent	=    0	; 1=show exponent, 0=no exponent
fmtEng		=    1	; 1=engineering notion, 0=scientific
fmtHex		=    2	; 1=hexadecimal
fmtOct		=    3	; 1=octal
fmtBin		=    4	; 1=binary
;
numMode         =  10
fmtReal         =    5
fmtRect         =    6
fmtPolar        =    7

realMode        =    5
rectMode        =    6
polarMode       =    7
;					;   if Hex and Oct both = 1
;					;   then Bin=0 means >Frac
;					;	 Bin=1 means >DMS
fmtBaseMask     =  00011100B		; mask to base flags
fmtBaseShift    =  2			; offset to base flags
;
;       CHECK IF THESE ARE USED BY NUMFORM,
;
;               =  6
;               =  7

fmtOverride	=  11		;copy of fmtFlags with conversion override

fmtEditFlags	=  12		;numeric editing flags
fmtEdit 	=    0	; 1=format number for editing

curFlags	=  12		;Cursor
curAble 	=    2	; 1=cursor flash is enabled
curOn		=    3	; 1=cursor is showing
curLock 	=    4	; 1=cursor is locked off

appFlags	=  13		;application flags
appWantIntrpt	=    0		; 1=want ON key interrupts
appTextSave	=    1		; 1=save characters in textShadow
appAutoScroll	=    2		; 1=auto-scroll text on last line
appMenus	=    3		; 1=process keys that bring up menus
					; 0=check Lock menu flag
appLockMenus	=    4		; 1=ignore menu keys
					; 0=switch to home screen and bring up menu
appCurGraphic	=    5		; 1=graphic cursor
appCurWord	=    6		; 1=text cursor covers entire word
appExit 	=    7		; 1=application handles [EXIT] key itself

appWantIntrptF	=	1<<appWantIntrpt
appTextSaveF	=	1<<appTextSave
appAutoScrollF	=	1<<appAutoScroll
appMenusF	=	1<<appMenus
appLockMenusF	=	1<<appLockMenus
appCurGraphicF	=	1<<appCurGraphic
appCurWordF	=	1<<appCurWord
appExitF	=	1<<appExit


seqFlags        =  15              ; Sequential Graph flags
webMode         =    0             ; 0 = NORMAL SEQ MODE, 1 = WEB MODE
webVert         =    1             ;
sequv           =    2             ; U vs V
seqvw           =    3             ; V vs W
sequw           =    4             ; U vs W


promptFlags	=  17		;prompt line flags
promptEdit	=    0	; 1=editing in prompt buffer

indicFlags	=  18		;Indicator flags
indicRun	=    0	; 1=run indicator ON
indicInUse	=    1	; indicator save area in use=1, free=0
indicOnly	=    2	; interrupt handler only checks run indicator

shiftFlags	=  18		;[2nd] and [ALPHA] flags
shift2nd	=    3	; 1=[2nd] has been pressed
shiftAlpha	=    4	; 1=[ALPHA] has been pressed
shiftLwrAlph	=    5	; 1=lower case, 0=upper case
shiftALock	=    6	; 1=alpha lock has been pressed
shiftKeepAlph	=    7	; 1=cannot cancel alpha shift


tblFlags        =  19		;table flags.
autoFill        =    4	; 1=prompt, 0=fillAuto
autoCalc        =    5	; 1=prompt, 0=CalcAuto
reTable         =    6	; 0=table is ok, 1=must recompute table.

sGrFlags	=  20
grfSplit        =    0	; 1=Split Graph, 0=Normal
vertSplit       =    1	; 1=Vertical (left-right) Split
grfSChanged     =    2	; 1=Graph just changed Split <-> normal
grfSplitOverride =   3	; 1 = ignore graph split flag if set
write_on_graph  =    4	; 1 = TEXT OR = WRITING TO GRAPH SCREEN
g_style_active  =    5	; 1 = GRAPH STYLES ARE ENABLED, USE THEM
cmp_mod_box     =    6	; 1 = DOING MOD BOX PLOT COMPUTATION
textWrite       =    7	; 1 = Small font writes to buffer
							; 0 = Small font writes to display
;

newIndicFlags   =  21
extraIndic      =    0
saIndic         =    1

newFlags2	    =  22
noRestores	    =  5

smartFlags      =  23
;
;----------------------------------------------------------------------
; Note: Fix these Equates if smartFlags are moved                            
;----------------------------------------------------------------------
;
smarter_mask    =  3
smarter_test    =  1
smartGraph      =  0
smartGraph_inv  =  1                                                 

more_Flags	= 26

No_Del_Stat	= 2
;----------------------------------------------------------------------
;           Available for ASM programming
;----------------------------------------------------------------------

asm_Flag1       =  33          ; ASM CODING
asm_Flag2       =  34          ; ASM CODING
asm_Flag3       =  35          ; ASM CODING

;----------------------------------------------------------------------
;
getSendFlg	=  36
comFailed	=  1	      ; 1 = Get/Send Communication Failed
;
appLwrCaseFlag  =  36
lwrCaseActive   =  3
;
apiFlg3		=  42 
;
apiFlg4		=  43
fullScrnDraw	=    2	; DRAW INTO LAST ROW/COL OF SCREEN

groupFlags	=  38
inGroup		=  1		;1 = IN GROUP CONTEXT


xapFlag0        =  46      ; external app flags
xapFlag1        =  47
xapFlag2        =  48
xapFlag3        =  49

fontFlags	=  50
fracDrawLFont	=    2
fracTallLFont	=    3
customFont	=    7  

plotFlag3	=  60  
bufferOnly	=    0
useFastCirc	=    4

DBKeyFlags      =     61              ;dbus keyboard flags
;Modifier         =     0..3          ;Reserved for LSNibble of Modifiers
repeatMost        =     4             ;set if repeat normal keys
haveDBKey         =     5             ;set if have DBus key
keyDefaultsF      =     6             ;set if don't use system default keys.
HWLinkErrF        =     7             ;have a SE Hardware Link error.

;
varTypeMask	=  1FH             
varGraphRef	=    6
