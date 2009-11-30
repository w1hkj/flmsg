#ifndef WRAP_H
#define WRAP_H

#include <string.h>
#include <string>

using namespace std;

extern void export_wrapfile(string, string, string, bool with_ext);
extern bool import_wrapfile(string fname, string &efname, string &text);

#endif
