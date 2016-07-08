/*---------------------------------------------
 *     modification time: 2016-07-08 16:01:13
 *     mender: Muse
-*---------------------------------------------*/

/*---------------------------------------------
 *     file: muselog.h 
 *     creation time: 2016-07-08 16:01:13
 *     author: Muse 
-*---------------------------------------------*/

/*---------------------------------------------
 *       Source file content Four part
 *
 *       Part Zero:  Include
 *       Part One:   Define
 *       Part Two:   Typedef
 *       Part Three: Struct 
 *
 *       Part Three: 
 *
-*---------------------------------------------*/

/*---------------------------------------------
 *             Part Zero: Include
-*---------------------------------------------*/

#include <stdbool.h>
#include <string.h>

#include <errno.h>
#include <time.h>
#include <syslog.h>


/*---------------------------------------------
 *             Part One: Define
-*---------------------------------------------*/

#define DEF_LOGNAME "Muselog"
#define DEF_DIR     "/var/log/"

#define MFILEN_LEN  0x200

#ifdef MDEBUG
#define LOG_OPTION  (LOG_PERROR | LOG_CONS)
#else
#define LOG_OPTION  (LOG_CONS)
#endif


/*---------------------------------------------
 *             Part Two: Typedef
-*---------------------------------------------*/

typedef struct muselog  Muselog;


/*---------------------------------------------
 *             Part Three: Struct
-*---------------------------------------------*/

struct muselog {
    int32_t facility;
};


