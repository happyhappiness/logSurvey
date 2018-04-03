static void all_attrs_init(struct attr_hashmap *map, struct attr_check *check)
{
	int i;

	hashmap_lock(map);

	if (map->map.size < check->all_attrs_nr)
		die("BUG: interned attributes shouldn't be deleted");

	/*
