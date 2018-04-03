	return diff_flush_patch_id(options, sha1);
}

static const unsigned char *patch_id_access(size_t index, void *table)
{
	struct patch_id **id_table = table;
	return id_table[index]->patch_id;
}

static int patch_pos(struct patch_id **table, int nr, const unsigned char *id)
{
	return sha1_pos(id, table, nr, patch_id_access);
}

#define BUCKET_SIZE 190 /* 190 * 21 = 3990, with slop close enough to 4K */
