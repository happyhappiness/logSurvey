				struct object_id oid;

				if (read_ref_full(name->buf, 0, oid.hash, NULL))
					error("bad ref for %s", name->buf);
				else
					retval = fn(name->buf, &oid, 0, cb_data);
			}