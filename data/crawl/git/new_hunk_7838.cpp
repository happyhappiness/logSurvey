
const char *commit_type = "commit";

static struct commit *check_commit(struct object *obj,
				   const unsigned char *sha1,
				   int quiet)
