{
	if (!branch)
		return error_buf(err, _("HEAD does not point to a branch"));
	if (!branch->merge || !branch->merge[0] || !branch->merge[0]->dst) {
		if (!ref_exists(branch->refname))
			return error_buf(err, _("no such branch: '%s'"),
					 branch->name);
		if (!branch->merge)
			return error_buf(err,
					 _("no upstream configured for branch '%s'"),
					 branch->name);
		return error_buf(err,
				 _("upstream branch '%s' not stored as a remote-tracking branch"),
				 branch->merge[0]->src);
	}

	return branch->merge[0]->dst;
}