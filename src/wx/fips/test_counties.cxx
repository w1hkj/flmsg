#include <stdio.h>
#include <stdlib.h>

#include "severe_wx_strings.cxx"

string state;

int main (int args, char *argv[])
{
	size_t p1, p2;
	string state_counties;
	if (args == 2) {
		state = argv[1];
		if (state.length() < 2) return 4;
		for (int i = 0; i < 2; i++) state[i] = toupper(state[i]);
		string st = "";
		for (size_t n = 0; n < sizeof(states) / sizeof(string); n++) {
			if (states[n].find(state) == 0) {
				st = states[n];
				break;
			}
		}
		if (st.empty()) {
			printf("%s not valid state abbreviation\n", state.c_str());
			return 2;
		}
		st.erase(0,3);
		state.append(",");
		p1 = counties.find(state);
		p2 = counties.rfind(state);
		if (p1 == string::npos || p2 == string::npos) {
			printf("not found\n");
			return 1;
		}
		state_counties = counties.substr(p1 + 3, p2 - p1 - 3);
		size_t p4 = 0;
		int num = 0;
		while ((p4 = state_counties.find(',',p4 + 1)) != string::npos) {
			num++;
			state_counties[p4] = '\n';
		}
		printf("%s has %d entries\n%s\n\n",
			st.c_str(), num,
			state_counties.c_str());
		return 0;
	}
	size_t p3;
	string st;
	for (size_t n = 0; n < sizeof(states) / sizeof(string); n++) {
		st = states[n];
		p3 = st.find(',');
		p1 = counties.find(st.substr(0, p3));
		p2 = counties.rfind(st.substr(0, p3));
		if (p1 == string::npos || p2 == string::npos) {
			printf("%s not found\n", st.c_str());
		} else {
			state_counties = counties.substr(p1 + 3, p2 - p1 - 3);
			size_t p4 = 0;
			int num = 0;
			while ((p4 = state_counties.find(',',p4 + 1)) != string::npos) {
				num++;
				state_counties[p4] = '\n';
			}
			printf("# %d, %s has %d entries\n%s\n\n", n + 1,
				st.substr(p3 + 1).c_str(), num,
				state_counties.c_str());
		}
	}
}
