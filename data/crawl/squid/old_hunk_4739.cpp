     * to the user, or keep going without ICAP.
     */
    fatal("Fix this case in ClientRequestContext::icapAclCheckDone()");

    http->doCallouts();
}
