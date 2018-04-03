#include "builtin.h"
#include "utf8.h"

static const char commit_tree_usage[] = "git commit-tree <sha1> [-p <sha1>]* < changelog";

static void new_parent(struct commit *parent, struct commit_list **parents_p)
