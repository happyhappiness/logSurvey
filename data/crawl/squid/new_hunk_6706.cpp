    return xcalloc(1, mp->obj_size);
}

/*
 * return object to the pool; put on the corresponding stack or free if
 * corresponding stack is full
