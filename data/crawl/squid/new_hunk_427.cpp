
#include "squid.h"
#include "crypt_md5.h"
#include "helpers/defines.h"
#include "rfc1738.h"

#include <unordered_map>
#if HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#if HAVE_CRYPT_H
#include <crypt.h>
#endif

typedef std::unordered_map<std::string, std::string> usermap_t;
usermap_t usermap;

static void
read_passwd_file(const char *passwdfile)
{
    FILE *f;
    char buf[HELPER_INPUT_BUFFER];
    char *user;
    char *passwd;

    usermap.clear();
    //TODO: change to c++ streams
    f = fopen(passwdfile, "r");
    if (NULL == f) {
        fprintf(stderr, "FATAL: %s: %s\n", passwdfile, xstrerror());
