			     o->merge_size);
	if (a && old)
		return o->gently ? -1 :
			error(ERRORMSG(o, ERROR_BIND_OVERLAP), a->name, old->name);
	if (!a)
		return keep_entry(old, o);
	else
