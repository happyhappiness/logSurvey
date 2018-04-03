void git_attr_set_direction(enum git_attr_direction new, struct index_state *istate)
{
	enum git_attr_direction old = direction;
	direction = new;
	if (new != old)
		drop_attr_stack();
