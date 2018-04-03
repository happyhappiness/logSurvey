			line[0] = bytes - 26 + 'a' - 1;
		encode_85(line + 1, cp, bytes);
		cp = (char *) cp + bytes;
		puts(line);
	}
	printf("\n");
	free(data);
}

static void emit_binary_diff(mmfile_t *one, mmfile_t *two)
{
	printf("GIT binary patch\n");
	emit_binary_diff_body(one, two);
	emit_binary_diff_body(two, one);
}

static void setup_diff_attr_check(struct git_attr_check *check)
