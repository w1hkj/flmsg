// ----------------------------------------------------------------------------
// Copyright (C) 2014
//              David Freese, W1HKJ
//
// This file is part of flmsg
//
// flrig is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// (at your option) any later version.
//
// flrig is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
// ----------------------------------------------------------------------------

#ifndef XML_IO_H
#define XML_IO_H
extern std::string get_io_mode(void);
extern void enable_arq(void);
extern void open_xmlrpc();
extern void close_xmlrpc();
extern void send_new_modem();
extern void *xmlrpc_loop(void *d);
extern pthread_t *xmlrpc_thread;
extern pthread_mutex_t mutex_xmlrpc;
#endif
