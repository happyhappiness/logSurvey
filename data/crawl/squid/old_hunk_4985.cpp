        }

        /* Send it off to the helper */
        memBufDefInit(&buf);

        memBufPrintf(&buf, "%s\n", key);

        helperSubmit(def->theHelper, buf.buf, externalAclHandleReply, state);

        dlinkAdd(state, &state->list, &def->queue);

        memBufClean(&buf);
    }

    if (graceful) {
