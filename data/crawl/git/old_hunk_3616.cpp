#include "commit.h"
#include "refs.h"
#include "notes-utils.h"
#include "notes-merge.h" /* for create_notes_commit() */

void commit_notes(struct notes_tree *t, const char *msg)
{
