	}
}

struct commit *pop_commit(struct commit_list **stack)
{
	struct commit_list *top = *stack;
