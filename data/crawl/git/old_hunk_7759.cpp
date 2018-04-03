		break;
	default:
		if (p->score) {
			puts(" rewrite ");
			write_name_quoted(p->two->path, stdout, ' ');
			printf("(%d%%)\n", similarity_index(p));
		}
