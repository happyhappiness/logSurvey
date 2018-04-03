	if (prepare_revision_walk(&revs))
		die(_("revision walk setup failed"));

	if (is_null_sha1(sb.final->object.sha1)) {
		o = sb.final->util;
		sb.final_buf = xmemdupz(o->file.ptr, o->file.size);
