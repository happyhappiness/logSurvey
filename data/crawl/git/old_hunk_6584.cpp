					t->tag,
					diff_get_color_opt(&rev.diffopt, DIFF_RESET));
			ret = show_object(o->sha1, 1, &rev);
			objects[i].item = parse_object(t->tagged->sha1);
			i--;
			break;
		}
