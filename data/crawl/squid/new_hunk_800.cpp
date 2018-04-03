        if (isSet(flag) && flag != SC_OTHER) {

            /* print option name */
            p->appendf((pcount ? ", " SQUIDSTRINGPH : SQUIDSTRINGPH),
                         SQUIDSTRINGPRINT(ScFieldsInfo[flag].name));

            /* handle options with values */

            if (flag == SC_MAX_AGE)
                p->appendf("=%d", (int) max_age);

            if (flag == SC_CONTENT)
                p->appendf("=\"" SQUIDSTRINGPH "\"", SQUIDSTRINGPRINT(content_));

            ++pcount;
        }
    }

    if (hasTarget())
        p->appendf(";" SQUIDSTRINGPH, SQUIDSTRINGPRINT(target));
}

void
