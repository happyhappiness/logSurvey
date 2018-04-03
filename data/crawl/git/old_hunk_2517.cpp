	leaf.elem = component;
	leaf.elem_len = strlen(component);

	fprintf(out, "%s ", sha1_to_hex(obj->sha1));
	show_path_truncated(out, &leaf);
	fputc('\n', out);
}
