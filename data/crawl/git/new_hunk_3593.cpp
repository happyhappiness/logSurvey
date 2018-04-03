		 * the output.
		 */
		error("%s does not point to a valid object!", entry->name);
		string_list_append(refs_to_delete, entry->name);
		return 0;
	}

	return 0;
}

static int repack_without_ref(const char *refname)
{
	int fd;
	struct ref_dir *packed;
	struct string_list refs_to_delete = STRING_LIST_INIT_DUP;
	struct string_list_item *ref_to_delete;

	if (!get_packed_ref(refname))
		return 0; /* refname does not exist in packed refs */
