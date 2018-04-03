{
    assert(idx && shared_count <= idx->count);

    printf("%s:\t %7d %7.2f%% + %7.2f%%\n", 
	idx->name, 
	idx->count, 
	xpercent(idx->count-shared_count, idx->count),
	xpercent(shared_count, idx->count));
}