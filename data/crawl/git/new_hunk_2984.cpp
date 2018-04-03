#include "parse-options.h"
#include "dir.h"
#include "run-command.h"
#include "quote.h"

/**
 * Returns 1 if the file is empty or does not exist, 0 otherwise.
 */
static int is_empty_file(const char *filename)
{
	struct stat st;

	if (stat(filename, &st) < 0) {
		if (errno == ENOENT)
			return 1;
		die_errno(_("could not stat %s"), filename);
	}

	return !st.st_size;
}

/**
 * Like strbuf_getline(), but treats both '\n' and "\r\n" as line terminators.
