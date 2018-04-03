/*
 * Copyright (C) 2005 Junio C Hamano
 */
#include "cache.h"
#include "diff.h"
#include "diffcore.h"

static unsigned int contains(struct diff_filespec *one,
			     const char *needle, unsigned long len,
