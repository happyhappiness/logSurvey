
    buf.append(" [", 2);
    if (stopReason != NULL) {
        buf.appendf("Stopped, reason:%s", stopReason);
    }
    buf.appendf(" %s%u]", id.Prefix, id.value);
    buf.terminate();

    return buf.content();
