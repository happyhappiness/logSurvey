#include "patch-ids.h"

int commit_patch_id(struct commit *commit, struct diff_options *options,
		    unsigned char *sha1, int diff_header_only)
{
	if (commit->parents)
		diff_tree_sha1(commit->parents->item->object.oid.hash,
			       commit->object.oid.hash, "", options);
	else
		diff_root_tree_sha1(commit->object.oid.hash, "", options);
	diffcore_std(options);
	return diff_flush_patch_id(options, sha1, diff_header_only);
}

/*
 * When we cannot load the full patch-id for both commits for whatever
 * reason, the function returns -1 (i.e. return error(...)). Despite
 * the "cmp" in the name of this function, the caller only cares about
 * the return value being zero (a and b are equivalent) or non-zero (a
 * and b are different), and returning non-zero would keep both in the
 * result, even if they actually were equivalent, in order to err on
 * the side of safety.  The actual value being negative does not have
 * any significance; only that it is non-zero matters.
 */
static int patch_id_cmp(struct patch_id *a,
			struct patch_id *b,
			struct diff_options *opt)
{
	if (is_null_sha1(a->patch_id) &&
	    commit_patch_id(a->commit, opt, a->patch_id, 0))
		return error("Could not get patch ID for %s",
			oid_to_hex(&a->commit->object.oid));
	if (is_null_sha1(b->patch_id) &&
	    commit_patch_id(b->commit, opt, b->patch_id, 0))
		return error("Could not get patch ID for %s",
			oid_to_hex(&b->commit->object.oid));
	return hashcmp(a->patch_id, b->patch_id);
}

