			struct tag *t = (struct tag *)o;

			printf("%stag %s%s\n\n",
					diff_get_color(rev.diffopt.color_diff,
						DIFF_COMMIT),
					t->tag,
					diff_get_color(rev.diffopt.color_diff,
						DIFF_RESET));
			ret = show_object(o->sha1, 1);
			objects[i].item = (struct object *)t->tagged;
			i--;
			break;
		}
		case OBJ_TREE:
			printf("%stree %s%s\n\n",
					diff_get_color(rev.diffopt.color_diff,
						DIFF_COMMIT),
					name,
					diff_get_color(rev.diffopt.color_diff,
						DIFF_RESET));
			read_tree_recursive((struct tree *)o, "", 0, 0, NULL,
					show_tree_object);
			break;