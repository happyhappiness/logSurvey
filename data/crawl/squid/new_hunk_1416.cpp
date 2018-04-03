{
    const int index = findIndexOf(conn);
    if (index >= 0) {
        if (parent_)
            parent_->notifyManager("idle conn closure");
        /* might delete this */
        removeAt(index);
        clearHandlers(conn);
