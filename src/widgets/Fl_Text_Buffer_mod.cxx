#include <config.h>

#if FLMSG_FLTK_API_MAJOR == 1 && FLMSG_FLTK_API_MINOR < 3
#  include "Fl_Text_Buffer_mod_1_1.cxx"
#elif FLMSG_FLTK_API_MAJOR == 1 && FLMSG_FLTK_API_MINOR == 3
#  include "Fl_Text_Buffer_mod_1_3.cxx"
#endif
