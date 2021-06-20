
#ifndef _DESKX_SERVER_
#define _DESKX_SERVER_

#include "DeskX.h"
#include "Server/X11.h"
#include "Server/Actions.h"
#include <stdlib.h>

inline std::string man_text("\033[1mDeskX\033[0m - Program for remote "
"control of a computer in a local network. Server side.\n"
"GitHub: https://github.com/DeskX11/DeskX\n\n"
"Usage: ./dxs [options]\n"
"Options:\n"
"	--port			Connection port\n"
"	--password		Verification secret word without spaces\n"
"	--display		Screen number (:0)\n"
"	--xauth			Path to .Xauthority file\n\n"
"Example:\n"
"	./dxs --port=4431 --password=secret\n");

namespace Global {
	inline TCP		*net;
	inline X11		*x11;
	inline input	args;
}

#endif
