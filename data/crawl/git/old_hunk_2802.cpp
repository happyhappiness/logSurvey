				return 0;
		}

		if (points_at.nr && !match_points_at(refname, oid->hash))
			return 0;

		if (!filter->lines) {
			if (filter->sort)
				string_list_append(&filter->tags, refname);
			else
				printf("%s\n", refname);
			return 0;
