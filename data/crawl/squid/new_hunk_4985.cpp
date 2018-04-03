        }

        /* Send it off to the helper */
        buf.init();

        buf.Printf("%s\n", key);

        helperSubmit(def->theHelper, buf.buf, externalAclHandleReply, state);

        dlinkAdd(state, &state->list, &def->queue);

        buf.clean();
    }

    if (graceful) {
