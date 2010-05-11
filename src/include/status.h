#ifndef _status_H
#define _status_H

#include <string>

using namespace std;

struct status {
	int		mainX;
	int		mainY;

	int		wpl; // words per line in radiogram
	bool	compression;
	bool	UTC;
	int		dtformat;

	void saveLastState();
	void loadLastState();
};

extern status progStatus;

#endif
