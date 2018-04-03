				return 0;
		}

		if (filter->points_at.nr && !match_points_at(refname, oid->hash, &filter->points_at))
			return 0;

		if (!filter->lines) {
			if (tag_sort)
				ref_array_append(array, refname);
			else
				printf("%s\n", refname);
			return 0;
