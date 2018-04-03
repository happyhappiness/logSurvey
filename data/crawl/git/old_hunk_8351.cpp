#include "cache.h"
#include "pack.h"

void fixup_pack_header_footer(int pack_fd,
			 unsigned char *pack_file_sha1,
