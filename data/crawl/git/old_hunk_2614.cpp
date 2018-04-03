				die("protocol error: expected sha/ref, got %s'", p);

			ref = alloc_ref(name);
			hashcpy(ref->old_sha1, old_sha1);

			*list = ref;
			list = &ref->next;
