				 * "refs/foo"). So we can stop looking
				 * now and return true.
				 */
				return 1;
			}
			error("'%s' exists; cannot create '%s'", entry->name, refname);
			return 0;
		}


