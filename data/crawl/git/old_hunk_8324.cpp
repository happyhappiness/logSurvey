
static void check_object(struct object *obj)
{
	if (obj->flags & REACHABLE)
		check_reachable_object(obj);
	else
