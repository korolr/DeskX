
#ifndef _DESKX_SERVER_
#define _DESKX_SERVER_

#include "DeskX.h"
#include "Server/X11.h"
#include "Server/Actions.h"

inline std::string man_text("\033[1mDeskX\033[0m - Program for remote "
"control of a computer in a local network. Server side.\n\n"
"Usage: ./dxs [options]\n"
"Options (all options are required):\n"
"	--port			Connection port\n"
"	--password		Verification secret word without spaces\n\n"
"Example:\n"
"	./dxs --port=4431 --password=secret\n");

namespace Global {
	inline TCP		*net;
	inline X11		*x11;
	inline input	args;
}

#endif
