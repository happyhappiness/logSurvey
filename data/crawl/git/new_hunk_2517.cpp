	leaf.elem = component;
	leaf.elem_len = strlen(component);

	fprintf(out, "%s ", oid_to_hex(&obj->oid));
	show_path_truncated(out, &leaf);
	fputc('\n', out);
}
