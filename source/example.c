/*---------------------------------------------
 *     modification time: 2016-05-29 09:39:42
 *     mender: Muse
-*---------------------------------------------*/

#include "muselog.h"


static void write_log(Muselog *logger, const char *fmt, ...);


int main(void)
{
    Muselog logger;

    log_start(&logger, "/var/log/muse", LOG_LOCAL1);
    flog(&logger, ERR, "Hello %s", "world");

    log_move(&logger, "Log", 0);
    
    write_log(&logger, "I like %s - %d", "muselog", 10);

    return  -1;
}


void write_log(Muselog *logger, const char *fmt, ...)
{
    va_list ap;

    va_start(ap, fmt);
    vlog(logger, CRIT, fmt, ap);
}
