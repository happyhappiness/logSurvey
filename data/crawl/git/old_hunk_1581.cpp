		if (S_ISGITLINK(p->two->mode))
			d->new_submodule_commits = !!oidcmp(&p->one->oid,
							    &p->two->oid);
	}
}

