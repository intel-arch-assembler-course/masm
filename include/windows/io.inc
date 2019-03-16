.NOLIST

;================= PROTO ===============
CharToOemA PROTO :DWORD,:DWORD
CharToOem equ <CharToOemA>
ClearScreen PROTO
CloseHandle PROTO :DWORD; Закрыть файл
CreateFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD,:DWORD
CreateFile equ <CreateFileA>
ExitProcess PROTO :DWORD
GetCommandLineA PROTO 
GetCommandLine equ <GetCommandLineA>
GetConsoleScreenBufferInfo PROTO :DWORD,:DWORD
GetConsoleTitleA PROTO :DWORD,:DWORD
;GetConsoleTitle equ <GetConsoleTitleA>
GetModuleHandleA PROTO :DWORD
GetModuleHandle equ <GetModuleHandleA>
GetStdHandle PROTO :DWORD
GetTickCount PROTO
GetSystemMetrics PROTO :DWORD
GetSystemTime PROTO :DWORD
GlobalAlloc PROTO :DWORD,:DWORD
GlobalFree PROTO :DWORD
GlobalSize PROTO :DWORD
InternetGetConnectedState PROTO :DWORD,:DWORD
nrandom PROTO :DWORD
shell PROTO :DWORD
shell_ex PROTO :DWORD,:DWORD
MessageBoxA PROTO :DWORD,:DWORD,:DWORD,:DWORD
MessageBox equ <MessageBoxA>
MessageBoxIndirectA PROTO :DWORD
MessageBoxIndirect equ <MessageBoxIndirectA>
nseed PROTO :DWORD; Randomize()
SetConsoleCursorPosition PROTO :DWORD,:DWORD
SetConsoleScreenBufferSize PROTO :DWORD,:DWORD
SetConsoleTextAttribute PROTO :DWORD,:DWORD
SetConsoleTitleA PROTO :DWORD
SetConsoleTitle equ <SetConsoleTitleA>
Sleep PROTO :DWORD
fgets PROTO :DWORD,:DWORD,:DWORD
puts PROTO :DWORD
VirtualProtect PROTO :DWORD,:DWORD,:DWORD,:DWORD
URLDownloadToFileA PROTO :DWORD,:DWORD,:DWORD,:DWORD,:DWORD
URLDownloadToFile equ <URLDownloadToFileA>
wait_key PROTO

c_msvcrt typedef PROTO C :VARARG
;externdef _imp__printf:PTR c_msvcrt
externdef printf:PTR c_msvcrt
externdef sprintf:PTR c_msvcrt
;externdef _imp__sprintf:PTR c_msvcrt
;crt_printf  equ <_imp__printf>
crt_printf  equ <printf>
;crt_sprintf equ <_imp__sprintf>
crt_printf  equ <printf>
;fgets equ <_fgetts>
externdef stdin:PTR  c_msvcrt
;======================= const =====================

; --------- Константы цветов ------------------
Black        equ 0h
Blue         equ 1h
Green        equ 2h
Red          equ 4h
Bright       equ 8h
DarkGray     equ Bright
Cyan         equ Blue+Green
Brown        equ Green+Red
Magenta      equ Blue+Red
LightMagenta equ Bright+Blue+Red
LightGray    equ Blue+Green+Red
LightBlue    equ Bright+Blue
LightGreen   equ Bright+Green
LightRed     equ Bright+Red
Yellow       equ Bright+Green+Red
White        equ Bright+Blue+Green+Red
; синонимы цветов
black        equ Black
blue         equ Blue
green        equ Green
red          equ Red
bright       equ Bright
darkgray     equ DarkGray
cyan         equ Cyan
brown        equ Brown
magenta      equ Magenta
lightmagenta equ LightMagenta
lightgray    equ LightGray
lightblue    equ LightBlue
lightgreen   equ LightGreen
lightred     equ LightRed
yellow       equ Yellow
white        equ White
;---------------------------------------
nil          equ dword ptr 0
;---------------------------------------
NULL                 equ 0
GMEM_FIXED           equ 0h
GMEM_ZEROINIT        equ 40h

STD_INPUT_HANDLE     equ -10
STD_OUTPUT_HANDLE    equ -11
STD_ERROR_HANDLE     equ -12

LANG_NEUTRAL         equ 0h
; -------- Message Box ----------
MB_OK                equ 0h
MB_OKCANCEL          equ 1h
MB_ABORTRETRYIGNORE  equ 2h
MB_YESNOCANCEL       equ 3h
MB_YESNO             equ 4h
MB_RETRYCANCEL       equ 5h
MB_CANCELTRYCONTINUE equ 6h
MB_ICONHAND          equ 8h
MB_ICONSTOP          equ 10h
MB_ICONQUESTION      equ 20h
MB_ICONEXCLAMATION   equ 30h
MB_ICONASTERISK      equ 40h
MB_USERICON	     equ 80h
MB_DEFBUTTON1        equ 0h
MB_DEFBUTTON2        equ 100h
MB_DEFBUTTON3        equ 200h
MB_DEFBUTTON4        equ 300h
MB_SYSTEMMODAL       equ 1000h
MB_HELP              equ 4000h
MB_RIGHT             equ 80000h
IDOK                 equ 1
IDCANCEL             equ 2
IDABORT              equ 3
IDRETRY              equ 4
IDIGNORE             equ 5
IDYES                equ 6
IDNO                 equ 7
; ---------- страницы ----------------
PAGE_NOACCESS        equ 1
PAGE_READONLY        equ 2
PAGE_READWRITE       equ 4
PAGE_WRITECOPY       equ 8;  запись в копию страницы
PAGE_EXECUTE         equ 10h
PAGE_EXECUTE_READ    equ 20h
PAGE_EXECUTE_READWRITE equ 40h
PAGE_EXECUTE_WRITECOPY equ 80h;  запись в копию страницы
;----------- Файлы ----------------
GENERIC_READ         equ 80000000h
GENERIC_WRITE        equ 40000000h
GENERIC_EXECUTE      equ 20000000h
GENERIC_ALL          equ 10000000h
CREATE_NEW           equ 1
CREATE_ALWAYS        equ 2; ReWrite существующий
OPEN_EXISTING        equ 3
OPEN_ALWAYS          equ 4; Существует - open, не существует - new
TRUNCATE_EXISTING    equ 5
FILE_ATTRIBUTE_READONLY   equ 1h
FILE_ATTRIBUTE_HIDDEN     equ 2h
FILE_ATTRIBUTE_SYSTEM     equ 4h
FILE_ATTRIBUTE_DIRECTORY  equ 10h
FILE_ATTRIBUTE_ARCHIVE    equ 20h; "обычный" файл
FILE_ATTRIBUTE_NORMAL     equ 80h
FILE_ATTRIBUTE_TEMPORARY  equ 100h
FILE_ATTRIBUTE_COMPRESSED equ 800h

;================= types ===============
COORD struct
  x  dw    ?
  y  dw    ?
COORD ends
;---------------------------------------
SMALL_RECT struct
  Left     dw    ?
  Top      dw    ?
  Right    dw    ?
  Bottom   dw    ?
SMALL_RECT ends
;---------------------------------------
CONSOLE_SCREEN_BUFFER_INFO struct
  dwSize              COORD <>
  dwCursorPosition    COORD <>
  wAttributes         WORD      ?
  srWindow            SMALL_RECT <>
  dwMaximumWindowSize COORD <>
CONSOLE_SCREEN_BUFFER_INFO ends
;---------------------------------------
SystemTime struc
  wYear         dw ?
  wMonth        dw ?
  wDayOfWeek    dw ?
  wDay          dw ?
  wHour         dw ?
  wMinute       dw ?
  wSecond       dw ?
  wMilliseconds dw ?
SystemTime ends
;---------------------------------------

;================= macros ==============

;    purge GLOBAL; ненужный макрос в macros.inc

;---------------------------------------
??SaveReg macro F:=<>
    push eax
    push ecx
    push edx
ifnb <F>
    pushfd
endif
endm
;---------------------------------------
??RestoreReg macro F:=<>
ifnb <F>
    popfd
endif
    pop  edx
    pop  ecx
    pop  eax
endm

;*************************************************
; ??CheckStrToBuf macro x:VARARG
;    Помещает текст в буфер, перекодирует
;    и возвращает его адрес в eax
;*************************************************
??CheckStrToBuf macro x:VARARG
    Local buf,c,n,L1,L2
c   SubStr <x>,1,1
ifidn c,<'>
;c   SubStr <">,1,1
c   textequ <">
endif
.data
n  db 0
ifidn c,<">
buf db x,0
else
buf db 200 dup (0)
.code
    mov  n,0; надо перекодировать
    mov  eax,x
    xor  ecx,ecx
L1: mov  dl,[eax]
    mov  buf[ecx],dl
    inc  eax
    inc  ecx
    cmp  dl,0
    jne  L1
endif
.code
    mov  eax,offset buf
    cmp  ??ConsoleMode,0
    jne  L2;   перекодирование выключено
    cmp  n,0
    jne  L2
    push eax
    invoke CharToOem,eax,eax; Windows to DOS
    mov  n,1; Не надо перекодировать второй раз!
    pop  eax
L2:
endm
;---------------------------------------
     extrn inint_proc@0:proc
;---------------------------------------

;*************************************************
; ??FindESP macro X:Req,pESP
;    pESP:=2222 ESP   in X
;    pESP:=2222 [ESP] in X
;*************************************************
??FindESP macro X:Req,pESP
  local k,p1,p2,n
    k=1 
    p1=0; Позиция [
    p2=0; Позиция ]
    p1=@InStr(1,<X>,<[>)
    p2=@InStr(1,<X>,<]>)
    n=@SizeStr(X)-2
while k LE n
  ifidni @SubStr(X,k,3),<esp>; Поиск esp
    if k GT p1 and k LT p2; [...esp...]
       pESP=3333
    else
       pESP=2222
    endif
    exitm  
  endif
    k=k+1
endm
    endm

;*****************************************
; SetTextAttr macro x=16*фон+буквы
;*****************************************
settextattr equ SetTextAttr
;*****************************************
SetTextAttr macro colors:=<LightGray>; Lightgray светло-серый (стандарт)
    ??SaveReg Flags
    invoke GetStdHandle,STD_OUTPUT_HANDLE; =-11; eax:=OUTPUT_HANDLE
    invoke SetConsoleTextAttribute,eax,colors
    ??RestoreReg Flags
endm

;***********************************************************************
; OutNum macro x:REQ,Wide,tip:=<d>,txt:=<>
;    x=r8,r16,r32,m8,m16,m32,i32
;    Wide=i8 - ширина поля вывода, (<0, - левое выравнивание)
;    tip=d - знаковое, u-беззнаковое,
;          x,X-шестнадцатеричное, b - двоичное
;************************************************************************
OutNum equ outnum
;************************************************************************
OutNum macro x:REQ,Wide,tip:=<d>,txt:=<>
       local n,k,len,fmt,L1,L2,L3,L4,M1,M2,M3,tp,Met
ifnb <txt>
       outstr txt
endif
       ??SaveReg Flags
;------- Проверка type, esp и [esp]
       len=0
if @SizeStr(x) GT 3
  ifidni @SubStr(x,1,4),<type> ;  x=type Y
       len=1111
       goto Met
  endif
endif
       n=@SizeStr(&x)-2
       k=1
while k LE n
 ifidni @SubStr(x,k,3),<esp>;     Поиск esp
       k=(.type &x) and 1000000b
   if k;                          Операнд в стеке
       len=3333
   endif
   if @SizeStr(&x) EQ 3;   x=esp
       len=2222
   endif
       exitm
 endif
       k=k+1
endm

;----------------------------
:Met

;-----------  byte<>sbyte !!!
       tp = type (&x)
if len EQ 1111;            Был outnum type ...;
       mov  eax,(&x)
elseif tp EQ 1 or tp EQ 2
;  Знаковое и беззнаковое расширение до 4 байт
  ifidni <tip>,<d>
       movsx eax,(&x)
  else
       movzx eax,(&x)
  endif
elseif tp NE 8;    ==>     type x EQ 0 or type x EQ 4
       mov eax,x
endif
 
if len EQ 2222;            x=esp
       add eax,16;         коррекция 4*push
endif

if len EQ 3333;            x=[...esp...]
       lea eax,(&x);       адрес операнда-16
; Знаковое и беззнаковое расширение до 4 байт
  if tp EQ 1
    ifidni <tip>,<d>
       movsx eax,byte ptr [eax+16]
    else
       movzx eax,byte ptr [eax+16]
    endif
  elseif tp EQ 2
    ifidni <tip>,<d>
       movsx eax,word ptr [eax+16]
    else
       movzx eax,word ptr [eax+16]
    endif
  elseif tp NE 8;    ==>   type x EQ 0 or type x EQ 4
     mov eax,[eax+16];     коррекция 4*push
  endif
endif

ifidni <tip>,<b>
     xor  ebx,ebx; нет единиц
if tp EQ 8
     mov  ecx,32
     mov  eax,dword ptr x
     mov  edx,dword ptr x+4
M1:  shl  edx,1
     jc   M2
     cmp  ebx,0
     je   M3;      пропуск нулей
     outchar '0'
     jmp  M3
M2:  outchar '1'
     inc  ebx;     была единица
M3:  dec  ecx
     jne  M1
endif
     mov  ecx,32
L1:  shl  eax,1
     jc   L2
     cmp  ebx,0
     je   L3;      пропуск нулей
     outchar '0'
     jmp  L3
L2:  outchar '1'
     inc  ebx;     была единица
L3:  dec  ecx
     jne  L1
     test ebx,ebx
     jne  L4
     outchar '0'
L4:  outchar 'b'
     ??RestoreReg
     exitm
endif 
if tp EQ 8
.data
fmt db "%&Wide&I64&tip&",0
.code
     invoke crt_printf,offset fmt,x
else
.data
fmt db "%&Wide&tip&",0
.code
     invoke crt_printf,offset fmt,eax
endif

ifidni <tip>,<X>
     outchar "h"
endif
     ??RestoreReg Flags
endm
;-----------------------------------------------------------------
OutNumLn equ outnumln
OutNumln equ outnumln
;-----------------------------------------------------------------
outnumln macro x:REQ,Wide,tip:=<d>,txt:=<>
   OutNum x,Wide,tip,txt
   newline
endm

;***************************************************
; Задание (уменьшение) размера буфера окна консоли
;***************************************************
SetScreenSize macro x:=<80>,y:=<25>
    local LnSize,ColSize
.data
LnSize   dw ?
ColSize  dw ?
.code
    mov LnSize,x
    mov ColSize,y
    invoke GetStdHandle,STD_OUTPUT_HANDLE; eax:=OUTPUT_HANDLE
    invoke SetConsoleScreenBufferSize,eax,dword ptr LnSize
endm

;*****************************
; Очистка экрана консоли
;*****************************
Cls equ ClrScr
clrscr equ ClrScr
CLRSCR equ ClrScr
;*************************
ClrScr macro
    ??SaveReg Flags
    call ClearScreen
    ??RestoreReg Flags
endm

;**************************************
;  Переход новую строку <n> раз
;**************************************
NewLine equ newline
Newline equ newline
NEWLINE equ newline
;*********************************
newline macro n:=<1>
repeat n
   outchar 13    
   outchar 10
endm
endm

;**************************
; Выход из программы
;**************************
Exit equ exit
EXIT equ exit
;**********************
exit macro x:=<0>
    cld;           Иначе AVOST
    push x
    call ExitProcess
endm

;**********************************************
; outstr macro x:VARARG
;   Вывод текста x="..." или offset x db "..."
;**********************************************
OutStr equ outstr
OUTSTR equ outstr
;**********************************************
outstr macro x:VARARG
    .code
    ??SaveReg Flags
    ??CheckStrToBuf x
    invoke puts,eax
    ??RestoreReg Flags
endm

;*********************************************** 
; OutStrLn macro x="..." или offset x db "..."
;***********************************************
OutStrLn equ outstrln
OutstrLn equ outstrln
OUTSTRLN equ outstrln
outstrln macro x:VARARG
ifnb <x>
    outstr x
endif
    newline
endm

;***************************************************************************
;   Message Box Cap,Msg = "..." или offset x db "...",buttons
;   Считает, что текст в кодировке Windows
;   style=MB_OK (0h),MB_OKCANCEL (1h),MB_ABORTRETRYIGNORE (2h)
;         MB_YESNOCANCEL (3h),MB_YESNO (4h),MB_RETRYCANCEL (5h)
;         MB_CANCELTRYCONTINUE (6h),
;         MB_TOPMOST (40000h - поверх всех окон)
;         MB_SYSTEMMODAL (1000h - поверх всех окон+фокус ввода)
;
;         MB_ICONSTOP (10h - крест-стоп), MB_ICONQUESTION (20h - ?)
;         MB_ICONEXCLAMATION (30h - !), MB_ICONASTERISK (40h - i в круге)
;         MB_USERICON (80h - без пиктограммы, можно из файла ресурсов)
;         MB_DEFBUTTON1,2,3,4 (0h,100h,200h,300h)
;         MB_HELP (4000h кнопка справки без кода)
;         MB_RIGHT (80000h правое выравнивание текста)
;   Код кнопки=IDOK (1),IDCANCEL или ESC или крестик закрытия окна (2),
;              IDABORT (3),IDRETRY (4),IDIGNORE (5),IDYES (6),IDNO (7)
;              IDTRYAGAIN (10),IDCONTINUE (11)
;******************************************************************************
msgbox equ MsgBox
MSGBOX equ MsgBox
MsgBox macro Cap:=<" ">,Msg:REQ,style:=<MB_OK+MB_ICONASTERISK+MB_SYSTEMMODAL>
    local t1,t2,L,Par1,Par2,c
    ??SaveReg Flags
    ConsoleMode; выключить перекодировку
    ??CheckStrToBuf Cap
    push eax
    ??CheckStrToBuf Msg
    pop  edx; Cap
    invoke MessageBox,NULL,eax,edx,style+MB_SYSTEMMODAL
    ConsoleMode; включить перекодировку
    mov [esp+12],eax;  код возврате в EAX !
    ??RestoreReg Flags
endm

;*************************************
; Заголовок окна консоли
;*************************************
ConsoleTitle macro Title:VARARG
    ??SaveReg Flags
    ??CheckStrToBuf Title
    invoke SetConsoleTitle,eax
    ??RestoreReg Flags
endm

;--------------------------------------------------------------
GetConsoleTitle macro buf:REQ,Len:=<127>
    ??SaveReg
    invoke GetConsoleTitleA,buf,Len
    ??RestoreReg
endm

;*****************************************
; gotoXY macro x,y=i8,r8,r16,m8,m16
;*****************************************
GotoXY equ gotoXY
gotoxy equ gotoXY
GOTOXY equ gotoXY
;*****************************************
gotoXY macro x:REQ,y:REQ
    local s;
.data
s   dw   0; x позиция
    dw   0; y позиция
.code
    ??SaveReg Flags
if type (&x) EQ 1 or type (&x) EQ 2; or len EQ 1 
    movzx eax,x
    mov   s,ax
elseif type (&x) EQ 0
    mov   ax,x
    mov   s,ax
elseif
    echo ------------------------------------------------
    echo ***** Macros GotoXY: Bad operand **** &x& ****
    echo ------------------------------------------------
    .err
    exitm
endif
    dec   s
    and   s,1111111b
.code
if type (&y) EQ 1 or type (&y) EQ 2; or len EQ 1 
    movzx eax,y
    mov   s+2,ax
elseif type (&y) EQ 0
    mov   ax,y
    mov   s+2,ax
elseif
    echo ------------------------------------------------
    echo ***** Macros GotoXY: Bad operand **** &y& ****
    echo ------------------------------------------------
    .err
    exitm
endif
    dec   s+2
    and   s+2,111111b

    invoke GetStdHandle,STD_OUTPUT_HANDLE; eax:=OUTPUT_HANDLE
    invoke SetConsoleCursorPosition,eax,dword ptr s
    ??RestoreReg Flags
endm

;*************************************
; WhereX, WhereY al:=1..80, 1..50
;*************************************
wherex equ WhereX
whereX equ WhereX
WhereX macro
   local pos
.data
pos CONSOLE_SCREEN_BUFFER_INFO <>
.code
   invoke GetStdHandle,STD_OUTPUT_HANDLE
   invoke GetConsoleScreenBufferInfo,eax,offset pos
   mov al,byte ptr pos.dwCursorPosition.x; al=WhereX
   inc al
endm
;---------------------------------------------------------------------------
wherey equ WhereY
whereY equ WhereY
WhereY macro
   local pos
.data
pos CONSOLE_SCREEN_BUFFER_INFO <>
.code
   invoke GetStdHandle,STD_OUTPUT_HANDLE
   invoke GetConsoleScreenBufferInfo,eax,offset pos
   mov al,byte ptr pos.dwCursorPosition.y; al=WhereY
   inc al
endm

;**********************************************************
; InputStr - ввод строки до ENTER, не длиннее Len
;            или до конца строки
;**********************************************************
inputstr equ InputStr
INPUTSTR equ InputStr
InputStr macro Buf:REQ,Len:=<128>,prompt:VARARG
     Local L,M1,M2
ifnb <prompt>
     outstr prompt
endif
     push   ecx
     push   edx
     invoke fgets,Buf,Len,stdin; eax:=Число прочитанных
     pop    edx
     pop    ecx
     push   ebx
     mov    ebx,Buf
     cmp    eax,0
     je     L 
     cmp    byte ptr [ebx+eax-1],10;  CR,LF в буфере
     jne    M1
     sub    eax,2
     jmp    L
M1:  cmp    byte ptr [ebx+eax-1],13;  CR в буфере
     jne    L
     sub    eax,1
L:   mov    byte ptr [ebx+eax],0
     pop    ebx
endm

;**************************************
; pause ["Текст для вывода..."]
;**************************************
do_pause macro message_txt
ifnb <message_txt>    
    outstr message_txt
endif
    ??SaveReg Flags
    ;call wait_key
    ??RestoreReg Flags
    newline
endm

;Pause equ pause
;PAUSE equ pause
;pause equ PAUSE

;********************************************
; inchar macro x=m8,r8,prompt:VARARG
;********************************************
InChar equ inchar
Inchar equ inchar
INCHAR equ inchar
;********************************************
inchar macro x:REQ,prompt:VARARG
    local len,buf,L
ifnb <prompt>
     outstr prompt
endif
    len=0
for i,<al,ah,bl,bh,cl,ch,dl,dh>
 ifidni <i>,<x>
    len=1;                  x=r8
    exitm
 endif
endm
if len NE 1 and type (&x) NE 1
    echo ------------------------------------------------
    echo ***** Macros inchar: Bad operand **** &x& ****
    echo ------------------------------------------------
    .err
    exitm
endif
.data
buf  db 0,0
.code
    ??SaveReg Flags
    ;mov buf+1,0
;    invoke GetStdHandle,STD_INPUT_HANDLE; -10; eax:=INPUT_HANDLE
L: invoke fgets,offset buf,2,stdin; один символ
    cmp buf,0
    je     L
    cmp buf,13;         CR
    je     L
    cmp buf,10;         LF
    je     L
    ??RestoreReg Flags
if len EQ 1;            x=r8
    mov  x,buf
else;                   x=m8, работает и для inchar X[eax]
    push dword ptr (&x)
    push eax
    mov  al,buf
    mov  byte ptr [esp+4],al
    pop  eax
    pop  dword ptr (&x)
endif
endm

;********************************************
; @inchar macro prompt:VARARG
;********************************************
@InChar equ @inchar
@Inchar equ @inchar
@INCHAR equ @inchar
;********************************************
@inchar macro prompt:VARARG
    inchar al,prompt
    exitm <al>
endm

;********************************
;  flush сброс буфера ввода
;********************************
Flush equ flush
FLUSH equ flush
flush macro
    local buf,L
.data
buf  db 0,0
.code
    ??SaveReg Flags
L:  invoke fgets,offset buf,2,stdin; один символ
    cmp buf,10
    jne   L
    ??RestoreReg Flags
endm

;**********************************
;   outchar[ln] x=m8,r8,i8
;**********************************
OutChar equ outchar
OUTCHAR equ outchar
OUTC    equ outchar
;**********************************
outchar macro x:REQ, prompt:VARARG
    local len,buf,L
ifnb <prompt>
     outstr prompt
endif
    len=0
for i,<al,ah,bl,bh,cl,ch,dl,dh>
ifidni <i>,<x>
    len=1
    exitm
endif
endm
if len NE 1 and type (&x) EQ 0; это операнд i8
  if (&x) GT 255 OR (&x) LT 0
    echo -----------------------------------------------
    echo ***** Macros outchar: Big operand **** &x& ****
    echo -----------------------------------------------
    .err
    exitm
  endif  
endif
if len NE 1 and type (&x) NE 1 and type (&x) NE 0
    echo -----------------------------------------------
    echo ***** Macros outchar: Bad operand **** &x& ****
    echo -----------------------------------------------
    .err
    exitm
endif
.data
buf  db 1, 0
.code
    push eax
    mov  al,x
    mov  buf,al
    pop  eax
    outstr offset buf
endm

;********************************************
OutCharln equ outcharln
OutCharLn equ outcharln
OUTCHARLN equ outcharln
OUTCLN    equ outcharln
;********************************************
outcharln macro x:REQ,prompt:VARARG
    outchar x,prompt
    newline
endm

;****************************************
;   DOS x=m8,r8,i8; char Win to DOS
;****************************************
dos equ DOS
@dos equ DOS
@DOS equ DOS
;****************************************
DOS macro x:REQ
    local len,buf
    len=0
for i,<al,ah,bl,bh,cl,ch,dl,dh>
ifidni <i>,<x>
    len=1
    exitm <>
endif
endm
if len NE 1 and type (&x) EQ 0; это операнд i8
  if (&x) GT 255 OR (&x) LT 0
    echo -------------------------------------------------
    echo ***** Macros DOS: Big operand **** &x& ****
    echo -------------------------------------------------
    .err
    exitm <>
  endif  
endif
if len NE 1 and type (&x) NE 1 and type (&x) NE 0
    echo -------------------------------------------------
    echo ***** Macros DOS: Bad operand **** &x& ****
    echo -------------------------------------------------
    .err
    exitm <>
endif
.data
buf  db 0,0
.code
    ??SaveReg Flags
    mov  al,x
    mov  buf,al
    invoke CharToOem,offset buf,offset buf; Windows to DOS
    ??RestoreReg Flags
    mov  al,buf 
    exitm <al>
endm

;***********************************
;   ReadKey txt=:<>; al:=ord(char)
;***********************************
ReadKey equ readkey
READKEY equ readkey
;***********************************
readkey macro txt:=<>
ifnb <txt>
    outstr txt
endif
    push ecx
    push edx
    pushfd
    call wait_key; al:=ord(char)
    popfd
    pop  edx
    pop  ecx
endm
;************************************
;  @ReadKey txt=:<>; al:=ord(char)
;************************************
@ReadKey equ @readkey
@READKEY equ @readkey
;************************************
@readkey macro txt:=<>
     readkey txt
     exitm <al>
endm

;******************************************** 
; outint[ln] macro x:REQ,Wide,txt:=<>
;   x=i32,m8,m16,m32,r8,r16,r32[,Wide=i8]
;******************************************** 
Outint equ outint
OutInt equ outint
OUTINT equ outint
OutI   equ outint
OUTI   equ outint
outi   equ outint
;******************************************** 
outint macro x:REQ,Wide,txt:=<>
    OutNum x,Wide,d,txt
endm
; ---------------------------------
Outintln equ outintln
OutintLn equ outintln
OutIntLn equ outintln
outintLn equ outintln
OUTINTLN equ outintln
OutILn   equ outintln
OutIln   equ outintln
; ---------------------------------
outintln macro x:REQ,Wide,txt:=<>
    outint x,Wide,txt
    newline
endm

;****************************************************
; outword macro x=i32,m8,m16,m32,r8,r16,r32[,Wide=i8]
;****************************************************
OutWord     equ outword
Outword     equ outword
OUTWORD     equ outword
OutUnsigned equ outword
OutU        equ outword
outword macro x:REQ,Wide,txt:=<>
   OutNum x,Wide,u,txt
endm

;******************************************************
; outwordln macro x=i32,m8,m16,m32,r8,r16,r32[,Wide=i8]
;******************************************************
OutWordLn     equ outwordln
OutwordLn     equ outwordln
outwordLn     equ outwordln
OUTWORDLN     equ outwordln
OutUnsignedLn equ outwordln
OutUnsignedln equ outwordln
OutULn        equ outwordln
OutUln        equ outwordln
outwordln macro x:REQ,Wide,txt:=<>
    outword x,Wide,txt
    newline
endm

;**************************************************
; inint[ln] macro x,txt:=<>
;    x=m8,m16,m32,r8,r16,r32   
;    Сначала пропуск всех пробелов и (13,10)
;    затем ввод лексемы целого числа до 
;    первого символа (включительно), не входящего
;    в эту лексему, или до конца строки (13,10)
;**************************************************
Inint equ inint
InInt equ inint
ININT equ inint
;**************************************************
inint macro x:REQ,txt:=<>
     local len,buf
.data
buf dd ?
.code 
ifidni <x>,<sp>
     echo --------------------------
     echo ** BAD Macros: inint SP **
     echo --------------------------
     exitm
endif
ifidni <x>,<esp>
     echo ---------------------------
     echo ** BAD Macros: inint ESP **
     echo ---------------------------
     exitm
endif
ifnb <txt>
     outstr txt
endif
     push eax
     call inint_proc@0; ответ=eax,EFLAGS(CF,ZF,SF)
; Далее флаги не меняются !
     mov  buf,eax
ifidni <x>,<ah>
     pop  eax
     mov  ah,byte ptr buf; inint ah
     exitm
endif
ifidni <x>,<al>
     pop  eax
     mov  al,byte ptr buf; inint al
     exitm
endif
ifidni <x>,<ax>
     pop  eax
     mov  ax,word ptr buf; inint ax
     exitm
endif
ifidni <i>,<eax>
     mov  [esp],eax
     pop  eax
     exitm
endif
     len=0
for i,<bl,bh,cl,ch,dl,dh>
ifidni <i>,<x>
     len=1
     exitm
endif
endm
for i,<bx,cx,dx,di,si,bp>
ifidni <i>,<x>
     len=2
     exitm
endif
endm
for i,<ebx,ecx,edx,edi,esi,ebp>
ifidni <i>,<x>
     len=4
     exitm
endif
endm
if len EQ 1; r8
     mov  x,al
     pop eax
elseif len EQ 2; r16
     mov  x,ax
     pop eax
elseif len EQ 4; r16
     mov  x,eax
     pop eax
elseif type (&x) EQ 1; m8
     pop  eax           ; старое eax
     push dword ptr (&x)
     push eax
     mov  eax,buf  
     mov  byte ptr [esp+4],al
     pop eax
     pop  dword ptr (&x); inint m8[eax] работает !
elseif type (&x) EQ 2; m16
     pop  eax; старое eax
     push dword ptr (&x)
     push eax
     mov  eax,buf  
     mov  word ptr [esp+4],ax
     pop eax
     pop  dword ptr (&x); inint m16[eax] работает !
else                 ; m32
     pop  eax        ; старое eax
     push buf
     pop  x          ;    inint m32[eax] работает !
endif
endm

;***************************
; @inint[ln] macro txt:=<>   
;***************************
@Inint equ @inint
@InInt equ @inint
@ININT equ @inint
;***************************
@inint macro txt:=<>
    inint eax,txt
    exitm <eax>
endm

;*******************************
; inintln macro x:REQ,txt:=<>
; Сначала inint затем flush
;*******************************
InintLn equ inintln
Inintln equ inintln
ININTLN equ inintln
;*******************************
inintln macro x:REQ,txt:=<>
     inint x,txt
     pushfd
     flush
     popfd
endm

;**************************
;  @inintln macro txt:=<>
;**************************
@InintLn equ @inintln
@Inintln equ @inintln
@ININTLN equ @inintln
;**************************
@inintln macro txt:=<>
    inintln eax,txt
    exitm <eax>
endm

;****************************************************
; new macro size=i32 ; min size=16
;*****************************************************
.data
    ??TotalHeapAllocated dd 0
    ??CommonHeapElemSize dd 0
New equ new
NEW equ new
;****************************************************
new macro size:=<16>
    pushfd
    invoke GlobalAlloc,GMEM_FIXED+GMEM_ZEROINIT,size
    add  ??TotalHeapAllocated,size
    mov  ??CommonHeapElemSize,size
    popfd
endm
;****************************************************
; dispose macro ref:req
;****************************************************
Dispose equ dispose
DISPOSE equ dispose
;****************************************************
dispose macro ref:req
    ??SaveReg Flags
    invoke GlobalFree,ref
    mov  eax,??CommonHeapElemSize
    sub  ??TotalHeapAllocated,eax
    ??RestoreReg Flags
endm
;****************************************************
; HeapBlockSize macro ref:req
;****************************************************
heapblocksize equ HeapBlockSize
;****************************************************
HeapBlockSize macro ref:req
    pushfd
    invoke GlobalSize,ref
    popfd
endm

;****************************************************
TotalHeapAllocated macro
    mov eax,??TotalHeapAllocated
endm

;****************************************************
; outdate[ln] macro txt
OutDate equ outdate
OUTDATE equ outdate
;****************************************************
outdate macro txt
   local fmt
ifnb <txt>
   outstr txt
endif
.data
fmt db "%02u.%02u.%u",0
.code
    ??SaveReg Flafs
    invoke GetSystemTime,offset ??sTime
    xor eax,eax
    xor ecx,ecx
    xor edx,edx
    mov ax,??sTime.wDay 
    mov cx,??sTime.wMonth 
    mov dx,??sTime.wYear 
    invoke crt_printf,offset fmt,eax,ecx,edx
    ??RestoreReg Flafs
endm 
;-----------------------------------------------
OutDateln equ outdateln
OutDateLn equ outdateln
OUTDATELN equ outdateln
outdateln macro txt
    outdate txt
    newline
endm

;****************************************************
; outtime[ln] macro txt
OutTime equ outtime
OUTTIME equ outtime
;****************************************************
outtime macro txt
   local fmt,sTime
ifnb <txt>
   outstr txt
endif
.data
fmt db "%02u:%02u:%02u",0
.code
    ??SaveReg Flafs
    invoke GetSystemTime,offset ??sTime
    xor eax,eax
    xor ecx,ecx
    xor edx,edx
    mov ax,??sTime.wHour 
    mov cx,??sTime.wMinute 
    mov dx,??sTime.wSecond 
    invoke crt_printf,offset fmt,eax,ecx,edx
    ??RestoreReg Flafs
endm 
;-----------------------------------------------
OutTimeln equ outtimeln
OutTimeLn equ outtimeln
OUTTIMELN equ outtimeln
outtimeln macro txt
    outtime txt
    newline
endm

;***************************************
; ConsoleMode; выключить перекодировку
;***************************************
.data
  ??ConsoleMode db 0
ConsoleMode macro
    not ??ConsoleMode; не портит EFlags
endm

;**********************************************
; RunExe macro Name:req; Переход на программу 
;**********************************************
RunExe macro Name:req
    ??SaveReg Flags
    ??CheckStrToBuf Name; eax=offset buf
    invoke shell,eax
    ??RestoreReg Flags; может быть NewConsole ?
endm
;------------------------------------
       extrn FreeConsole@0:near,AllocConsole@0:near
NewConsole macro
      call FreeConsole@0
      call AllocConsole@0 
endm

;*************************************
; ChagePageAttr macro Address,NewAttr
;*************************************
ChagePageAttr macro Address,NewAttr
    local oldattr
.data
a dd ?;oldattr
.code
    ??SaveReg Flags
    invoke VirtualProtect,Address,1,NewAttr,offset a
    ??RestoreReg Flags
endm

;******************************************
; Randomize macro
randomize equ Randomize
;******************************************
Randomize macro
    ??SaveReg Flags
    call GetTickCount
    invoke nseed,eax; Randomize
    ??RestoreReg Flags
endm

;******************************************
; @Random macro n:=<0FFFFFFFFh>; n=i32,r32,m32
@random equ @Random
;******************************************
@Random macro n:=<0FFFFFFFFh>
if type n NE 4 and type n NE 0
   .err <** Random: Bad parametr = &n **>
   exitm <eax>
endif
    ??SaveReg Flags
    mov  eax,n
    push eax 
    call nrandom
    mov  [esp+12],eax; eax:=Randon
    ??RestoreReg Flags
    exitm <eax>
endm

;******************************************
; DownloadFile macro URL:Req,FileName:Req
downloadfile equ DownloadFile
;******************************************
DownloadFile macro URL:Req,FileName:Req
   Local lpdwFlags,dwReserved,L,KOH
includelib urlmon.lib
includelib wininet.lib
.data
  lpdwFlags  dd ?
  dwReserved dd 0
.code
    ??SaveReg
    invoke InternetGetConnectedState,offset lpdwFlags,dwReserved
    cmp eax,0; False - нет соединения
    jne L
    outstrln "Нет соединения с Интернетом !"
    jmp KOH
L:
    ??CheckStrToBuf URL
    mov  ebx,eax
    ??CheckStrToBuf FileName
    invoke URLDownloadToFile,0,ebx,eax,0,0
KOH:
    ??RestoreReg
endm

;******************************************
; OutFlafs ; Вывод CF,Of,ZF,SF
;******************************************
OutFlags macro
;---------------------
  OutF macro FL
    pushfd
    mov   eax,1
    j&FL  @F
    mov   eax,0
@@:
    outword eax,-3,"&FL&F="
    popfd
  endm
;---------------------
    ??SaveReg Flags
for i,<C,O,Z,S>
    OutF  i
endm 
    newline
    ??RestoreReg Flags
endm

;***************************
; OpenFile macro Name,Attr
;***************************
OpenFile macro Address,Attr
;   invoke CreateFile
endm

;================= data declaration!!! ===============
.data
??sTime SystemTime <>

;=============== Конец io.inc ========================

.LIST
; Исключение из списка служебных слов
option NoKeyWord: <c name str>


