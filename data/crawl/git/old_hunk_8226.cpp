			die("Garbage after path in: %s", command_buf.buf);
		p = p_uq;
	}
	tree_content_remove(&b->branch_tree, p);
	free(p_uq);
}

static void file_change_deleteall(struct branch *b)
{
	release_tree_content_recursive(b->branch_tree.tree);
