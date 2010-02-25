#ifndef _status_H
#define _status_H

#include <string>

using namespace std;

struct status {
	int		mainX;
	int		mainY;

	bool	compression;
	bool	UTC;

	void saveLastState();
	void loadLastState();
};

extern status progStatus;

#endif
