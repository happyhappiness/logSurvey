		    sha1_object_info(blob_sha1, NULL) == OBJ_BLOB)
			return;
	}
	die("no such path '%s' in HEAD", path);
}

static struct commit_list **append_parent(struct commit_list **tail, const unsigned char *sha1)
