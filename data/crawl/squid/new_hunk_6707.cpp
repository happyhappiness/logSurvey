memPoolPutObj(MemPool *mp, void *obj)
{
    assert(mp);
    /* static object? */
    if (mp->buf <= (char*)obj && mp->_buf_end > (char*)obj) {
	assert(!mp->static_stack->is_full); /* never full if we got here! */
