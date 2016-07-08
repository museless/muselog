/*---------------------------------------------
 *     modification time: 2016-07-08 16:03:45
 *     mender: Muse
-*---------------------------------------------*/

/*---------------------------------------------
 *     file: muselog.c
 *     creation time: 2016-07-08 16:03:45
 *     author: Muse
-*---------------------------------------------*/

/*---------------------------------------------
 *        Source file content Five part
 *
 *       Part Zero:  Include
 *       Part One:   Define 
 *       Part Two:   Local data
 *       Part Three: Local function
 *
 *       Part Four:  Log control
 *
-*---------------------------------------------*/

/*---------------------------------------------
 *             Part Zero: Include
-*---------------------------------------------*/

#include "muselog.h"


/*---------------------------------------------
 *          Part Four: Log control
 *
 *          1. log_start
 *          2. log
 *          3. vlog
 *          4. log_move
 *
-*---------------------------------------------*/

/*-----log_start-----*/
bool log_start(Muselog *log, int facility)
{
    if (!log) {
        errno = EINVAL;
        return  false;
    }

    log->facility = facility;

    openlog(NULL, LOG_OPTION, LOG_USER);

    return  true;
}


/*-----log_move-----*/
bool log_move(const char *log, const char *dir, const char *name)
{
    if (!log || !dir || !name) {
        errno = EINVAL;
        return  false;
    }

    char    buffer[MFILEN_LEN];

    snprintf(buffer, MFILEN_LEN - 1, "%s%s", 
        (dir) ? dir : DEF_DIR, (name) ? name : DEF_LOGNAME);

    int32_t out = open(buffer, O_RDONLY);
    int32_t in = open(log, O_WRONLY); 

    if (out == -1 || in == -1)
        return  false;

    struct stat stats;

    if (fstat(out, &stats) == -1)
        return  false;

    if (sendfile(out, in, NULL, stats.st_size) == -1)
        return  false;

    close(out);
    close(in);

    if (truncate(buffer, 0) == -1)
        return  false;

    return  true;
}   

