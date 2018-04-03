
			if (!oid_eq(&a->oid, &b->oid))
				result.clean = 0;
		} else {
			die(_("unsupported object type in the tree"));
		}
	}

	return result;
