	free_commit_list(result);
}

/*
 * We use the convention that exiting with an exit code 10 means that
 * the bisection process finished successfully.