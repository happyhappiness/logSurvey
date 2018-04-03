    required_gerrit_options = (options.oldrev, options.newrev, options.refname,
                               options.project)
    if required_gerrit_options != (None,) * 4:
        return compute_gerrit_options(options, args, required_gerrit_options)

    # No special options in use, just return what we started with
    return options, args, {}


def main(args):
    parser = optparse.OptionParser(
        description=__doc__,
