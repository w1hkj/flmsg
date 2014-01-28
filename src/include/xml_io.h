#ifndef XML_IO_H
#define XML_IO_H

extern void open_xmlrpc();
extern void close_xmlrpc();
extern void send_new_modem();
extern void *xmlrpc_loop(void *d);
extern pthread_t *xmlrpc_thread;
extern pthread_mutex_t mutex_xmlrpc;
#endif
