			    "of non-bare repository", current_branch->refname);
}

static int do_fetch(struct transport *transport,
		    struct refspec *refs, int ref_count)
{