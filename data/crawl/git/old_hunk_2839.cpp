#include "version.h"
#include "sha1-array.h"
#include "gpg-interface.h"

static int feed_object(const unsigned char *sha1, int fd, int negative)
{
