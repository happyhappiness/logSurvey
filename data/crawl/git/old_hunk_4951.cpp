		} \
	} while (0)

void create_notes_commit(struct notes_tree *t, struct commit_list *parents,
			 const char *msg, unsigned char *result_sha1)
{
