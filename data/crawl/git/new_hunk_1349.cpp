        mailer.__del__()


def check_ref_filter(environment):
    send_filter_regex, send_is_inclusion = environment.get_ref_filter_regex(True)
    ref_filter_regex, ref_is_inclusion = environment.get_ref_filter_regex(False)

    def inc_exc_lusion(b):
        if b:
            return 'inclusion'
        else:
            return 'exclusion'

    if send_filter_regex:
        sys.stdout.write("DoSend/DontSend filter regex (" +
                         (inc_exc_lusion(send_is_inclusion)) +
                         '): ' + send_filter_regex.pattern +
                         '\n')
    if send_filter_regex:
        sys.stdout.write("Include/Exclude filter regex (" +
                         (inc_exc_lusion(ref_is_inclusion)) +
                         '): ' + ref_filter_regex.pattern +
                         '\n')
    sys.stdout.write(os.linesep)

    sys.stdout.write(
        "Refs marked as EXCLUDE are excluded by either refFilterInclusionRegex\n"
        "or refFilterExclusionRegex. No emails will be sent for commits included\n"
        "in these refs.\n"
        "Refs marked as DONT-SEND are excluded by either refFilterDoSendRegex or\n"
        "refFilterDontSendRegex, but not by either refFilterInclusionRegex or\n"
        "refFilterExclusionRegex. Emails will be sent for commits included in these\n"
        "refs only when the commit reaches a ref which isn't excluded.\n"
        "Refs marked as DO-SEND are not excluded by any filter. Emails will\n"
        "be sent normally for commits included in these refs.\n")

    sys.stdout.write(os.linesep)

    for refname in read_git_lines(['for-each-ref', '--format', '%(refname)']):
        sys.stdout.write(refname)
        if not include_ref(refname, ref_filter_regex, ref_is_inclusion):
            sys.stdout.write(' EXCLUDE')
        elif not include_ref(refname, send_filter_regex, send_is_inclusion):
            sys.stdout.write(' DONT-SEND')
        else:
            sys.stdout.write(' DO-SEND')

        sys.stdout.write(os.linesep)


def show_env(environment, out):
    out.write('Environment values:\n')
    for (k, v) in sorted(environment.get_values().items()):
        if k:  # Don't show the {'' : ''} pair.
            out.write('    %s : %r\n' % (k, v))
    out.write('\n')
    # Flush to avoid interleaving with further log output
    out.flush()


def check_setup(environment):
    environment.check()
    show_env(environment, sys.stdout)
    sys.stdout.write("Now, checking that git-multimail's standard input "
                     "is properly set ..." + os.linesep)
    sys.stdout.write("Please type some text and then press Return" + os.linesep)
    stdin = sys.stdin.readline()
    sys.stdout.write("You have just entered:" + os.linesep)
    sys.stdout.write(stdin)
    sys.stdout.write("git-multimail seems properly set up." + os.linesep)


def choose_mailer(config, environment):
    mailer = config.get('mailer', default='sendmail')

