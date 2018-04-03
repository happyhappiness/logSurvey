		case ABORT:
			die ("Tag %s tags unexported object; use "
			     "--tag-of-filtered-object=<mode> to handle it.",
			     oid_to_hex(&tag->object.oid));
		case DROP:
			/* Ignore this tag altogether */
			return;
		case REWRITE:
			if (tagged->type != OBJ_COMMIT) {
				die ("Tag %s tags unexported %s!",
				     oid_to_hex(&tag->object.oid),
				     typename(tagged->type));
			}
			p = (struct commit *)tagged;