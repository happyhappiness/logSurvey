{
	if (revs->no_walk && (obj->flags & UNINTERESTING))
		die("object ranges do not make sense when not walking revisions");
	add_object_array_with_mode(obj, name, &revs->pending, mode);
	if (revs->reflog_info && obj->type == OBJ_COMMIT)
		add_reflog_for_walk(revs->reflog_info,
				(struct commit *)obj, name);
}

void add_pending_object(struct rev_info *revs, struct object *obj, const char *name)