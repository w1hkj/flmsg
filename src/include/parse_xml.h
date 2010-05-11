#ifndef XML_H
#define XML_H

#include <string>
#include <list>

using namespace std;

struct TAGS { const char *tag; void (*fp)(size_t &, string);};

extern void parse_ics(string);
extern bool qform_ics_import(string);
extern void qform_ics_export(string);

extern void parse_rg(string);
extern bool qform_rg_import(string);
extern void qform_rg_export(string);

#endif

