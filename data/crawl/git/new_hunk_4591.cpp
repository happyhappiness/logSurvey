				break;
			o = parse_object(t->tagged->sha1);
			if (!o)
				ret = error(_("Could not read object %s"),
					    sha1_to_hex(t->tagged->sha1));
			objects[i].item = o;
			i--;
