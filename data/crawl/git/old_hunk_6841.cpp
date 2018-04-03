		     (stage == 2) ? "our" : "their");
}

static int checkout_paths(struct tree *source_tree, const char **pathspec,
			  struct checkout_opts *opts)
{
