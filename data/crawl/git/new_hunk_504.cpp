			rev.shown_one = 1;
			if (ret)
				break;
			o = parse_object(&t->tagged->oid);
			if (!o)
				ret = error(_("Could not read object %s"),
					    oid_to_hex(&t->tagged->oid));
