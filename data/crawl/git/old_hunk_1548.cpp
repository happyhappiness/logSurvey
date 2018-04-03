#include "patch-ids.h"

int commit_patch_id(struct commit *commit, struct diff_options *options,
		    unsigned char *sha1)
{
	if (commit->parents)
		diff_tree_sha1(commit->parents->item->object.oid.hash,
			       commit->object.oid.hash, "", options);
	else
		diff_root_tree_sha1(commit->object.oid.hash, "", options);
	diffcore_std(options);
	return diff_flush_patch_id(options, sha1, 0);
}

static int patch_id_cmp(struct patch_id *a,
			struct patch_id *b,
			void *keydata)
{
	return hashcmp(a->patch_id, b->patch_id);
}

