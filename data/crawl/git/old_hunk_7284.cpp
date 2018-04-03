					spec->dst ? ":" : "",
					skip_prefix(spec->dst, "refs/heads/"));
			}
		}
cleanup_states:
		/* NEEDSWORK: free remote */
