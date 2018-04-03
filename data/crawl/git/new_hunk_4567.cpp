
		for (x = 0; x < xopts_nr; x++)
			if (parse_merge_opt(&o, xopts[x]))
				die(_("Unknown option for merge-recursive: -X%s"), xopts[x]);

		o.branch1 = head_arg;
		o.branch2 = remoteheads->item->util;
