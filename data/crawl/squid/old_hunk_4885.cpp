
        if (pool) {
            int obj_size = pool->objectSize() - cbdata::Offset;
            storeAppendPrintf(sentry, "%s\t%d\t%d\t%d\n", pool->objectType() + 7, obj_size, pool->getMeter().inuse.level, obj_size * pool->getMeter().inuse.level);
        }
    }
