		o = lookup_object(remote);
		if (!o || !(o->flags & COMPLETE)) {
			retval = 0;
			print_verbose(args, "want %s (%s)", sha1_to_hex(remote),
				      ref->name);
			continue;
		}
		print_verbose(args, "already have %s (%s)", sha1_to_hex(remote),
			      ref->name);
	}
	return retval;
}
