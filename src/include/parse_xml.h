#ifndef XML_H
#define XML_H

#include <string>
#include <list>

using namespace std;

struct TAGS { const char *tag; void (*fp)(size_t &, string);};

void parse_xml( string );

#endif

