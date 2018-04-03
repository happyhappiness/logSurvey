				 */
				if (parse_commit(p) < 0)
					die("cannot simplify commit %s (invalid %s)",
					    sha1_to_hex(commit->object.sha1),
					    sha1_to_hex(p->object.sha1));
				p->parents = NULL;
			}
		/* fallthrough */
