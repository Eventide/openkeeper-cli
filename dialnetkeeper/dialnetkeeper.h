#ifndef __DIANETKEEPER_H
#define __DIANETKEEPER_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>
#include <time.h>

#ifndef BUF_SIZE
#define BUF_SIZE (512)
#endif /* BUF_SIZE */

void get_user_message( int argc, char *argv[], char *user, char *radius );
void get_real_user_name( const char *src, const char *radius, char *dst );

#endif /* __DIANETKEEPER_H */ 
