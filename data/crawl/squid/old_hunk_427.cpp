
#include "squid.h"
#include "crypt_md5.h"
#include "hash.h"
#include "helpers/defines.h"
#include "rfc1738.h"
#include "util.h"

#include <cerrno>
#include <cstring>
#if HAVE_UNISTD_H
#include <unistd.h>
#endif
#if HAVE_SYS_STAT_H
#include <sys/stat.h>
#endif
#if HAVE_CRYPT_H
#include <crypt.h>
#endif

static hash_table *hash = NULL;
static HASHFREE my_free;

typedef struct _user_data {
    /* first two items must be same as hash_link */
    char *user;
    struct _user_data *next;
    char *passwd;
} user_data;

static void
my_free(void *p)
{
    user_data *u = static_cast<user_data*>(p);
    xfree(u->user);
    xfree(u->passwd);
    xfree(u);
}

static void
read_passwd_file(const char *passwdfile)
{
    FILE *f;
    char buf[HELPER_INPUT_BUFFER];
    user_data *u;
    char *user;
    char *passwd;
    if (hash != NULL) {
        hashFreeItems(hash, my_free);
        hashFreeMemory(hash);
    }
    /* initial setup */
    hash = hash_create((HASHCMP *) strcmp, 7921, hash_string);
    if (NULL == hash) {
        fprintf(stderr, "FATAL: Cannot create hash table\n");
        exit(1);
    }
    f = fopen(passwdfile, "r");
    if (NULL == f) {
        fprintf(stderr, "FATAL: %s: %s\n", passwdfile, xstrerror());
