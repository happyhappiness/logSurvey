		return create_object(sha1, OBJ_TAG, alloc_tag_node());
	if (!obj->type)
		obj->type = OBJ_TAG;
        if (obj->type != OBJ_TAG) {
                error("Object %s is a %s, not a tag",
                      sha1_to_hex(sha1), typename(obj->type));
                return NULL;
        }
        return (struct tag *) obj;
}

int parse_tag_buffer(struct tag *item, void *data, unsigned long size)
