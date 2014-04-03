#ifndef _winx68k_winui_h
#define _winx68k_winui_h

#include "common.h"

extern	BYTE	Debug_Text, Debug_Grp, Debug_Sp;
extern	DWORD	LastClock[4];

#if defined(ANDROID)
#define CUR_DIR_STR "/sdcard/px68k/"
#elif TARGET_OS_IPHONE && TARGET_IPHONE_SIMULATOR == 0
#define CUR_DIR_STR "/var/mobile/px68k/"
#else
#define CUR_DIR_STR "./"
#endif
#define CUR_DIR_SLEN strlen(CUR_DIR_STR)

void WinUI_Init(void);
int WinUI_Menu(int first);
float WinUI_get_vkscale(void);
void send_key(void);

#define WUM_MENU_END 1
#define WUM_EMU_QUIT 2

enum MenuState {ms_key, ms_value, ms_file, ms_hwjoy_set};

#define MFL_MAX 1000

struct menu_flist {
	char name[MFL_MAX][MAX_PATH];
	char type[MFL_MAX];
	char dir[2][MAX_PATH];
	int ptr;
	int num;
	int y;
};

extern char menu_item_key[][15];
extern char menu_items[][15][30];

int WinUI_get_fdd_num(int key);

#ifndef _winx68k_gtkui_h
#define _winx68k_gtkui_h
#endif //winx68k_gtkui_h
#endif //winx68k_winui_h
