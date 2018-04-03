		    continue;
		  o = patsubst_expand (buffer, name, pattern, d->name,
				       pattern_percent, percent);
		  free (d->name);
		  d->name = savestring (buffer, o - buffer);
		}
