
#ifndef _DESKX_SERVER_ACTIONS_H_
#define _DESKX_SERVER_ACTIONS_H_

class Actions {
private:
	static bool work;

	static bool ProtsSync(uint16_t &, uint16_t &);
	static bool SendHeaders(uint8_t, bool);

	static void ScreenUDP(uint16_t);
	static void EventsUDP(uint16_t);
	static void EventsTCP(uint16_t);
	static void ScreenTCP(void);

public:
	static void StartStream(uint8_t, bool, bool, bool);
};

#endif
