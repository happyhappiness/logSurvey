		break;
	default:
		if (p->score) {
			fputs(" rewrite ", stdout);
			write_name_quoted(p->two->path, stdout, ' ');
			printf("(%d%%)\n", similarity_index(p));
		}
