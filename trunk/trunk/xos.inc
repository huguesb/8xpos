
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; memory layout
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; 83p : screwed... go find another OS if you want to store anything
; other 8xp (83pSE, 84p, 84pSE) :
;	* 4 pages for data storage (files) [2, 4, 6, 7]
;	* 3 pages for program execution (code goes to 4000-BFFF [1, 3], dyn data in C000-FFFF [0])
;	* 1 page reserved for OS use [5]
;
;	page 0 layout (shared by OS and apps) :
;		* $C000-$CBFF :  3072 bytes of "static" data (see below, not everything is used by the OS)
;		* $CC00-$FCFF : 12288 bytes of "dynamic" data managed by malloc
;		* $FD00-$FFFF :  1024 bytes of stack space

prgm.start		= $4000

os.sysram		= $C000

os.lcd.mem		= os.sysram
os.lcd.back		= os.lcd.mem + 768

os.console		= os.lcd.back + 768
os.command		= os.console + 216
os.command_buf	= os.command + 129
os.command_mem	= os.command_buf + 4
os.scrap		= os.command_mem + 4

os.flags		= os.scrap + 256

os.contrast		= os.flags + 16

os.prev_key		= os.contrast + 1
os.keymap.normal	= os.prev_key + 1
os.keymap.shift	= os.keymap.normal + 2
os.keymap.alpha	= os.keymap.shift + 2

os.vbuf_addr	= os.keymap.alpha + 2

os.font.con		= os.vbuf_addr + 2
os.font.6x8		= os.font.con + 2
os.font.var		= os.font.6x8 + 2

os.ram_masks	= os.font.var + 2

os.hook.rst08	= os.ram_masks + 2
os.hook.rst10	= os.hook.rst08 + 2
os.hook.rst18	= os.hook.rst10 + 2
os.hook.rst20	= os.hook.rst18 + 2
os.hook.rst28	= os.hook.rst20 + 2
os.hook.rst30	= os.hook.rst28 + 2

os.curpos.col	= os.hook.rst30 + 2
os.curpos.row	= os.curpos.col + 1
os.lrgpos.col	= os.curpos.row + 1
os.lrgpos.row	= os.lrgpos.col + 1

os.aps.timer	= os.lrgpos.row + 1
os.timers		= os.aps.timer + 2

os.im2.isr		= os.timers + 32

os.exception	= os.im2.isr + 2
os.estack		= os.exception + 1
os.savedsp		= os.estack + 2

os.fpstack		= os.savedsp + 2
os.fpprec		= os.fpstack + 2

psp				= os.fpprec + 1		; 16
; Program segment prefix
psp.flags		= psp + 0				;1 Program flags
psp.argc		= psp.flags + 1			;1 Argument count
psp.argv		= psp.argc + 1			;2 Argument list (move with strnext)
psp.stack		= psp.argv + 2			;2 Stack pointer
psp.restart		= psp.stack + 2			;2 Restart vector
psp.ehandler	= psp.restart + 2		;2 Exception vector
psp.interrupt	= psp.ehandler + 2		;2 Interrupt vector
psp.libs		= psp.interrupt + 2		;2 Address of first lib segment 
psp.reserved	= psp.libs + 2			;2 Unused
psp.end			= psp.reserved + 2

os.linkassist.receive	= psp.end
os.linkassist.send		= os.linkassist.receive + 2
os.linkassist.error		= os.linkassist.send + 2

os.silentlink.packet	= os.linkassist.error + 2
os.silentlink.total		= os.silentlink.packet + 2
os.silentlink.check		= os.silentlink.total + 2

os.malloc.start		= os.silentlink.check + 2
os.malloc.mp_start	= os.malloc.start + 2
os.malloc.mp_end	= os.malloc.mp_start + 2

os.dmeminfo			= os.malloc.mp_end + 2
os.fmeminfo			= os.dmeminfo + 4

os.flashwrite.size		= os.fmeminfo + 4
os.flashwrite.source	= os.flashwrite.size + 2
os.flashwrite.dest		= os.flashwrite.source + 3

os.rand_seed		= os.flashwrite.dest + 3

#if os.rand_seed + 2 >= $CC00
!!!
.echo "RAM layout is screwed.\n"
#endif

os.malloc.pool		= $CC00
os.malloc.poolsize	= $3000

os.maxstacksize	= 1024

; file alloc data is placed at the beginning of each storage page
os.falloc.start		= $8000
os.falloc.mp_start	= os.falloc.start + 2
os.falloc.mp_end	= os.falloc.mp_start + 2
os.falloc.split_record		= os.falloc.mp_end + 2
os.falloc.firstnode	= $8010
os.falloc.poolend	= $C000

; os.flags : group 0 -> general status
osf.general		= 0
calc_on				= 0	; 1 = calc is on
aps_on				= 1	; 1 = process APS timer in ISR
debug_on			= 2 ; 1 = debug mode
prgm_running		= 3	; 1 = program is running
im2_isr_rst38		= 4	; 1 = im2 helper runs default system ISR after user ISR
tios_emulation		= 7 ; 1 = TIOS emulation is turned on

; os.flags : group 1 -> filesystem
osf.filesystem	= 1

fmeminfo_dirty		= 3

; os.flags : group 2 -> dynamic memory
osf.dynamicmem	= 2
dmeminfo_dirty		= 0

; os.flags : group 3 -> silent link
osf.silentlink	= 3
silent_wait			= 0
link_dump_on		= 1
proto_dump_on		= 2
silent_abort		= 3
silent_assist		= 7

; os.flags : group 4 -> compat layer
osf.compat		= 4
vbuf_flush			= 0

; os.flags : group 5 -> 
; os.flags : group 6 ->
; os.flags : group 7 ->
; os.flags : group 8 ->
; os.flags : group 9 ->
; os.flags : group 10 ->
; os.flags : group 11 ->
; os.flags : group 12 ->
; os.flags : group 13 ->
; os.flags : group 14 ->
; os.flags : group 15 ->

#define	bitmask(pos)	(1<<(pos))
#define invmask(pos)	~(1<<(pos))

;#define lcd_busy	in a,(lcd_cmd_port)\ and $80\ jr nz, $-4
#define lcd_busy	call $000B
#define range_test(lower,upper,under,over)	cp lower\ jr c, under\ cp upper+1\ jr nc, over
#define	msb(val)	(val)>>8
#define	lsb(val)	(val)&$FF

#define	reset		rst 00h
;#define	deref_hl	rst 08h
;#define	cmp_hlde	rst 10h
;#define	rowread		rst 18h
;#define	offset_hl	rst 20h
#define	bcall(xxxx)	rst 28h \ .dw xxxx
#define	irq			rst 38h

#define offset_hl	add a, l \ ld l, a \ adc a, h \ sub l \ ld h, a
#define offset_de	add a, e \ ld e, a \ adc a, d \ sub e \ ld d, a
#define offset_bc	add a, c \ ld c, a \ adc a, b \ sub e \ ld b, a
#define deref_hl	ld a, (hl) \ inc hl \ ld h, (hl) \ ld l, a
#define cmp_hlde	or a \ sbc hl, de \ add hl, de
#define cmp_hlbc	or a \ sbc hl, bc \ add hl, bc
#define rowread		out (key_port), a \ inc hl \ dec hl \ in a, (key_port)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; file system (headers and such)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

magic.executable	= $23
magic.dynamiclib	= $24

; metadata field types
meta_NAME	=	$01
meta_SIZE	=	$02
meta_NEXT	=	$03
meta_PREV	=	$04

; file_list flags
list_alloc	= 7
list_free	= 6
list_count	= 5
list_total	= 4

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; misc constants
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

ALL_IRQS 			= $1B		; Link port, Timer, ON key
MSG_PANE			= 48		; Lowest screen row of message pane text
CMD_PANE			= 58		; Screen row of command pane text

default.aps_time	= 25000		; About 3 minutes
default.command_mem	= 25		; max number of remembered commands (max 255)
default.contrast	= $EA

; fp constants
FP_ZERO				= 0
FP_ONE				= 1
FP_E				= 2
FP_PI				= 3

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; ports numbers
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; "SE only" means "anything in 83+ family but 83+BE"

link_port		= $00
key_port		= $01
hw_port			= $02
irq_mask_port	= $03
irq_stat_port	= $04

map_bankC_port	= $05	; SE only
map_bankA_port	= $06
map_bankB_port	= $07

la_en_port		= $08	; SE only
la_stat_port	= $09	; SE only
la_in_port		= $0A	; SE only
;la_???			= $0B	; SE only
;la_???			= $0C	; SE only
la_out_port		= $0D	; SE only

;map_???		= $0E	; SE only
;map_???		= $0F	; SE only

lcd_cmd_port	= $10
lcd_data_port	= $11

;???			= $12	; unused
;???			= $13	; unused

flash_lock_port	= $14	; protected
;???			= $15	; unused
flash_exec_port	= $16	; BE only, protected

;???			= $17	; 

md5_regA_port	= $18	; SE only
md5_regB_port	= $19	; SE only
md5_regC_port	= $1A	; SE only
md5_regD_port	= $1B	; SE only
md5_regX_port	= $1C	; SE only
md5_regAC_port	= $1D	; SE only
md5_regS_port	= $1E	; SE only
md5_mode_port	= $1F	; SE only

cpu_speed_port	= $20	; SE only
hw_se_port		= $21	; SE only

; Flash eXecution Limit
fxl_low_port	= $22	; SE only
fxl_high_port	= $23	; SE only

;???			= $24	; unused

;fxl_???		= $25	; protected
;fxl_???		= $26	; protected

; block memory mapping
map_blockC_port	= $27	; SE only : map chunk of mem from page 0 to bank C from $FFFF downwards
map_blockB_port	= $28	; SE only : map chunk of mem from page 1 to bank B from $8000 onwards

; set "auto" delay of LCD I/O depending on CPU speed and enable/disable memory delays
lcd_delay0_port	= $29	; SE only
lcd_delay1_port	= $2A	; SE only
lcd_delay2_port	= $2B	; SE only
lcd_delay3_port	= $2C	; SE only

;???			= $2D

; set "auto" delay of memory I/O depending on CPU speed
mem_delay_port	= $2E	; SE only

; set "wait delay" of LCD I/O depending on CPU speed
lcd_wait_port	= $2F	; SE only

; crystal timers
ct1_on_port		= $30	; SE only
ct1_loop_port	= $31	; SE only
ct1_count_port	= $32	; SE only

ct2_on_port		= $33	; SE only
ct2_loop_port	= $34	; SE only
ct2_count_port	= $35	; SE only

ct3_on_port		= $36	; SE only
ct3_loop_port	= $37	; SE only
ct3_count_port	= $38	; SE only

;???			= $39
;???			= $3A
;???			= $3B	; unused
;???			= $3C	; unused
;???			= $3D	; unused
;???			= $3E	; unused
;???			= $3F	; unused

; clock control
clock_on_port	= $40	; 84 only

; clock write (indirect : need control port write to be copied to read counters)
clock_out0_port	= $41	; 84 only
clock_out1_port	= $42	; 84 only
clock_out2_port	= $43	; 84 only
clock_out3_port	= $44	; 84 only

; clock read
clock_in0_port	= $45	; 84 only
clock_in1_port	= $46	; 84 only
clock_in2_port	= $47	; 84 only
clock_in3_port	= $48	; 84 only

; USB (bits of the mess)
usb_stat_port	= $55	; 84 only
usb_event_port	= $56	; 84 only
usb_irq_port	= $57	; 84 only

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Link I/O
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

RED1_WHITE1	=	%00000000	; "1" = +5V, "0" = 0V
RED0_WHITE1	=	%00000001
RED1_WHITE0	=	%00000010
RED0_WHITE0	=	%00000011
TIMEOUT		=	300

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Link Commands
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Device codes
link_PC		=	$23
link_83P	=	$73

; error codes
link_REXIT	=	$01	; Exit
link_RSKIP	=	$03	; Skip
link_RMEM	=	$03	; Memory

; Command codes
link_VAR	=	$06	; Variable header
link_CTS	=	$09	; Clear to send variable
link_DATA	=	$15	; Data packet
link_VER	=	$2D	; Request version
link_REJ	=	$36	; Rejection
link_ACK	=	$56	; Acknowledgement
link_CHK	=	$5A	; Checksum error
link_RDY	=	$68	; Check ready
link_SCR	=	$6D	; Take screenshot 
link_DEL	=	$88	; Delete variable
link_EOT	=	$92	; End of transmission
link_REQ	=	$A2	; Request variable
link_RTS	=	$C9	; Request to send variable (silent-link)

; variable types for TI link protocol
tReal			= $00 ; Real Number
tRealList		= $01 ; Real List
tMatrix			= $02 ; Matrix
tYvar			= $03 ; Y-Variable
tString			= $04 ; String
tProg			= $05 ; Program
tLockedProg		= $06 ; Edit-locked Program
tPic			= $07 ; Picture
tGDB			= $08 ; GDB
tWindow1		= $0B ; Window Settings (See note below)
tCplx			= $0C ; Complex Number
tCplxList		= $0D ; Complex List
tWindow2		= $0F ; Window Settings (See note below)
tWindow3		= $10 ; Saved Window Settings (See note below)
tTable			= $11 ; Table Setup (See note below)
tBackup			= $13 ; Backup
tGarbage		= $14 ; Used to delete a FLASH application
tAppvar			= $15 ; Application Variable
tGroup			= $17 ; Group Variable (only found on TI83+)
tDirList		= $19 ; Directory (See note below) - only used when requesting a directory
tOS				= $23 ; FLASH Operating System
tApp			= $24 ; FLASH Application
tIDList			= $26 ; ID list
tCert			= $27 ; Get Certificate
tClock			= $29 ; Clock

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Exceptions
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
E_CREATE	=	0
E_LOCATE	=	1
E_LINK		=	2
E_EXIST		=	3
E_MEMORY	=	4
E_CHECKSUM	=	5
E_COMPAT	=	6
E_LAST		=	E_COMPAT

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Key groups and bits for rowread
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
kg_arrows	=	$FE
kb_down		=	0
kb_left		=	1
kb_right	=	2
kb_up		=	3

kg_row1		=	$FD
kb_enter	=	0
kb_plus		=	1
kb_minus	=	2
kb_times	=	3
kb_obelus	=	4
kb_caret	=	5
kb_clear	=	6

kg_row2		=	$FB
kb_chs		=	0
kb_3		=	1
kb_6		=	2
kb_9		=	3
kb_rparen	=	4
kb_tan		=	5
kb_vars		=	6

kg_row3		=	$F7
kb_point	=	0
kb_2		=	1
kb_5		=	2
kb_8		=	3
kb_lparen	=	4
kb_cos		=	5
kb_prgm		=	6
kb_stat		=	7

kg_row4		=	$EF
kb_0		=	0
kb_1		=	1
kb_4		=	2
kb_7		=	3
kb_comma	=	4
kb_sin		=	5
kb_apps		=	6
kb_xt0n		=	7

kg_row5		=	$DF
kb_sto		=	1
kb_ln		=	2
kb_log		=	3
kb_square	=	4
kb_recip	=	5
kb_math		=	6
kb_alpha	=	7

kg_func		=	$BF
kb_f5		=	0
kb_f4		=	1
kb_f3		=	2
kb_f2		=	3
kb_f1		=	4
kb_2nd		=	5
kb_mode		=	6
kb_del		=	7

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Scan codes returned by getkey (equiv TIOS : getcsc)
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
sk_null		=	$00	; No key pressed
sk_down		=	$01
sk_left		=	$02
sk_right	=	$03
sk_up		=	$04
; $05 - $08 not assigned
sk_enter	=	$09
sk_plus		=	$0A
sk_minus	=	$0B
sk_times	=	$0C
sk_obelus	=	$0D
sk_caret	=	$0E
sk_clear	=	$0F
; $10 not assigned
sk_chs		=	$11
sk_3		=	$12
sk_6		=	$13
sk_9		=	$14
sk_rparen	=	$15
sk_tan		=	$16
sk_vars		=	$17
; $18 not assigned
sk_point	=	$19
sk_2		=	$1A
sk_5		=	$1B
sk_8		=	$1C
sk_lparen	=	$1D
sk_cos		=	$1E
sk_prgm		=	$1F
sk_stat		=	$20
sk_0		=	$21
sk_1		=	$22
sk_4		=	$23
sk_7		=	$24
sk_comma	=	$25
sk_sin		=	$26
sk_apps		=	$27
sk_xt0n		=	$28
; $29 not assigned
sk_sto		=	$2A
sk_ln		=	$2B
sk_log		=	$2C
sk_square	=	$2D
sk_recip	=	$2E
sk_math		=	$2F
sk_alpha	=	$30
sk_graph	=	$31
sk_trace	=	$32
sk_zoom		=	$33
sk_window	=	$34
sk_yequ		=	$35
sk_2nd		=	$36
sk_mode		=	$37
sk_del		=	$38

sk_a = sk_math
sk_b = sk_apps
sk_c = sk_prgm
sk_d = sk_recip
sk_e = sk_sin
sk_f = sk_cos
sk_g = sk_tan
sk_h = sk_caret
sk_i = sk_square
sk_j = sk_comma
sk_k = sk_lparen
sk_l = sk_rparen
sk_m = sk_obelus
sk_n = sk_log
sk_o = sk_7
sk_p = sk_8
sk_q = sk_9
sk_r = sk_times
sk_s = sk_ln
sk_t = sk_4
sk_u = sk_5
sk_v = sk_6
sk_w = sk_minus
sk_x = sk_sto
sk_y = sk_1
sk_z = sk_2

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Special getch ASCII codes
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
k_down		=	$01	; DOWN
k_left		=	$02	; LEFT
k_right		=	$03	; RIGHT
k_up		=	$04	; UP
k_xt0n		=	$05	; XT0n
k_del		=	$08	; DEL
k_enter		=	$0A	; ENTER
k_clear		=	$0C	; CLEAR
k_f1		=	$11	; F1
k_f2		=	$12	; F2
k_f3		=	$13	; F3
k_f4		=	$14	; F4
k_f5		=	$15	; F5
k_quit		=	$1B	; MODE
