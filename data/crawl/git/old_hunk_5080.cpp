			     o->merge_size);
	if (a && old)
		return o->gently ? -1 :
			error(ERRORMSG(o, bind_overlap), a->name, old->name);
	if (!a)
		return keep_entry(old, o);
	else
