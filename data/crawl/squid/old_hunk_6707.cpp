memPoolPutObj(MemPool *mp, void *obj)
{
    assert(mp);
    /*printf("memPoolPutObj: %p :  %d >= %d\n", obj, mp->alloc_count, mp->free_count);*/
    /* static object? */
    if (mp->buf <= (char*)obj && mp->_buf_end > (char*)obj) {
	assert(!mp->static_stack->is_full); /* never full if we got here! */
