#include "diffcore.h"
#include "revision.h"
#include "cache-tree.h"
#include "unpack-trees.h"
#include "refs.h"

/*
 * diff-files
 */

/*
 * Has the work tree entity been removed?
 *
