			o = parse_object(get_object_hash(*t->tagged));
			if (!o)
				ret = error(_("Could not read object %s"),
					    oid_to_hex(&t->tagged->oid));
			objects[i].item = o;
			i--;
			break;
