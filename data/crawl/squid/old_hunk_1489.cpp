{
    const int index = findIndexOf(conn);
    if (index >= 0) {
        /* might delete this */
        removeAt(index);
        clearHandlers(conn);
