		if (longest < entlen)
			longest = entlen;

		add_cmdname(de->d_name + prefix_len, entlen);
	}
	closedir(dir);

	printf("git commands available in '%s'\n", exec_path);
	printf("----------------------------");
	mput_char('-', strlen(exec_path));
	putchar('\n');
	pretty_print_string_list(cmdname, longest);
	putchar('\n');
}

void list_common_cmds_help(void)
