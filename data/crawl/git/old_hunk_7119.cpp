			seen_this = 1;
			graph_output_commit_char(graph, sb);

			if (graph->num_parents < 2)
				strbuf_addch(sb, ' ');
			else if (graph->num_parents == 2)
				strbuf_addstr(sb, "  ");
			else {
				int num_dashes =
					((graph->num_parents - 2) * 2) - 1;
				for (j = 0; j < num_dashes; j++)
					strbuf_addch(sb, '-');
				strbuf_addstr(sb, ". ");
			}
		} else if (seen_this && (graph->num_parents > 1)) {
			strbuf_addstr(sb, "\\ ");
		} else {
			strbuf_addstr(sb, "| ");
		}
