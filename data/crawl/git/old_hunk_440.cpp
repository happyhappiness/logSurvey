	revs->limited = 1;
}

int handle_revision_arg(const char *arg_, struct rev_info *revs, int flags, unsigned revarg_opt)
{
	struct object_context oc;
	char *dotdot;
	char *mark;
	struct object *object;
	unsigned char sha1[20];
