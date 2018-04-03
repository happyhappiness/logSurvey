
		todo_list->total_nr = todo_list->done_nr
			+ count_commands(todo_list);
		todo_list_release(&done);

		if (f) {
			fprintf(f, "%d\n", todo_list->total_nr);
			fclose(f);
		}
	}

	return 0;
