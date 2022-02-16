#ifndef FLMSG_ARQ_H
#define FLMSG_ARQ_H

#include <string>

#include <FL/Fl_Double_Window.H>

#include "arq.h"

#define SOHCOUNT 10

extern arq  flmsg_arq;

extern Fl_Double_Window *dlgconfig;

extern void init_flmsg_arq();
extern void mainloop(void *);

extern void arqSEND();
extern void cbMenuAbout();
extern void cbMenuConfig();

extern void closeConfig();

extern void abortTransfer();
extern void help_cb();

extern std::string	MyCall;
extern std::string	Logfile;

extern std::string sXfrd;
extern std::string sRcvd;
extern std::string sRtry;
extern std::string sTout;
extern std::string sTo;
extern std::string sFm;
extern std::string sColon;

extern int		exponent;
extern int		txdelay;
extern int		iretries;
extern long		iwaittime;
extern long		itimeout;
extern int		bcnInterval;

// used by xmlrpc interface
extern int			arqstate;
extern bool			sendingfile;
extern bool			rxTextReady;
extern bool			rxARQfile;
extern std::string	txtarqload;

extern void display_payloadtext(std::string outfname, std::string txtarqload);
extern void direct_payload(std::string);
extern void save_this_file_as(std::string, std::string);

extern void send_xml_text(std::string txt);

#endif
