//=====================================================================
//
// crc16 checksum
//
//=====================================================================
#include <string>

using namespace std;

class Ccrc16 {
private:
	unsigned int crcval;
	char ss[5];
public:
	Ccrc16() { crcval = 0xFFFF; }
	~Ccrc16() {};
	void reset() { crcval = 0xFFFF;}
	unsigned int val() {return crcval;}
	string sval() {
		sprintf(ss,"%04X", crcval);
		return ss;
	}
	void update(char c) {
		crcval ^= c;
        for (int i = 0; i < 8; ++i) {
            if (crcval & 1)
                crcval = (crcval >> 1) ^ 0xA001;
            else
                crcval = (crcval >> 1);
        }
	}
	unsigned int crc16(char c) { 
		update(c); 
		return crcval;
	}
	unsigned int crc16(string s) {
		reset();
		for (size_t i = 0; i < s.length(); i++)
			update(s[i]);
		return crcval;
	}
	string scrc16(string s) {
		crc16(s);
		return sval();
	}
};

