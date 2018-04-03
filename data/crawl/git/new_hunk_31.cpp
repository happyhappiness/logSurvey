			obj = parse_object_buffer(oid, type, size, buf,
						  &eaten);
			if (!obj)
				die(_("invalid %s"), type_name(type));
			if (do_fsck_object &&
			    fsck_object(obj, buf, size, &fsck_options))
				die(_("Error in object"));
