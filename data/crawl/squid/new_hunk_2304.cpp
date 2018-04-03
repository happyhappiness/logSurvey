        }
    }

    // A background refresh has no need to piggiback on a pending request:
    // When the pending request completes, the cache will be refreshed anyway.
    if (oldstate && inBackground) {
        debugs(82, 7, HERE << "'" << def->name << "' queue is already being refreshed (ch=" << ch << ")");
        return;
    }

    externalAclState *state = cbdataAlloc(externalAclState);
    state->def = cbdataReference(def);

    state->key = xstrdup(key);

    if (!inBackground) {
        state->callback = &ExternalACLLookup::LookupDone;
        state->callback_data = cbdataReference(checklist);
    }

    if (oldstate) {
        /* Hook into pending lookup */
        state->queue = oldstate->queue;
        oldstate->queue = state;
    } else {
        /* No pending lookup found. Sumbit to helper */

        /* Check for queue overload */

        if (def->theHelper->stats.queue_size >= (int)def->theHelper->childs.n_running) {
            debugs(82, 7, HERE << "'" << def->name << "' queue is too long");
            assert(inBackground); // or the caller should have checked
            cbdataFree(state);
            return;
        }

        /* Send it off to the helper */
        MemBuf buf;
        buf.init();

        buf.Printf("%s\n", key);
