/*---------------------------------------------
 *     modification time: 2016-05-29 09:39:42
 *     mender: Muse
-*---------------------------------------------*/

#include "muselog.h"
#include "muselogmsg.h"
#include <errno.h>


int main(void)
{
    Muselog messageLog;

    log_start(&messageLog, "/var/log/muse", LOG_LOCAL1);
    errno = EINVAL;
    setmsg(LM1, "fuck", 10);

    return  -1;
}


