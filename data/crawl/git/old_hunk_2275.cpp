						      warn_ambiguous_refs);
			else if (skip_prefix(formatp, "strip=", &arg))
				refname = strip_ref_components(refname, arg);
			else if (!strcmp(formatp, "track") &&
				 (starts_with(name, "upstream") ||
				  starts_with(name, "push"))) {

				if (stat_tracking_info(branch, &num_ours,
						       &num_theirs, NULL))
					continue;

				if (!num_ours && !num_theirs)
					v->s = "";
				else if (!num_ours)
					v->s = xstrfmt("[behind %d]", num_theirs);
				else if (!num_theirs)
					v->s = xstrfmt("[ahead %d]", num_ours);
				else
					v->s = xstrfmt("[ahead %d, behind %d]",
						       num_ours, num_theirs);
				continue;
			} else if (!strcmp(formatp, "trackshort") &&
				   (starts_with(name, "upstream") ||
				    starts_with(name, "push"))) {
				assert(branch);

				if (stat_tracking_info(branch, &num_ours,
							&num_theirs, NULL))
					continue;

				if (!num_ours && !num_theirs)
					v->s = "=";
				else if (!num_ours)
					v->s = "<";
				else if (!num_theirs)
					v->s = ">";
				else
					v->s = "<>";
				continue;
			} else
				die("unknown %.*s format %s",
				    (int)(formatp - name), name, formatp);
		}