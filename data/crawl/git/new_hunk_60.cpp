			if (name)
				error("%.*s: expected %s type, but the object "
				      "dereferences to %s type",
				      namelen, name, type_name(expected_type),
				      type_name(o->type));
			return NULL;
		}
	}
