#include "tag.h"

static int is_shallow = -1;

int register_shallow(const unsigned char *sha1)
{
