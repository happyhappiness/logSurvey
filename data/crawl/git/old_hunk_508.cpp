				if (!lookup_object(oid.hash))
					die(_("object not found: %s"), line);
				/* make sure that it is parsed as shallow */
				if (!parse_object(oid.hash))
					die(_("error in object: %s"), line);
				if (unregister_shallow(&oid))
					die(_("no shallow found: %s"), line);
