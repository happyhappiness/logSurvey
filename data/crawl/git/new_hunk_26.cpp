		if (!commit) {
			warning("%s: Unexpected object of type %s, skipping.",
				e->name,
				type_name(e->item->type));
			continue;
		}

