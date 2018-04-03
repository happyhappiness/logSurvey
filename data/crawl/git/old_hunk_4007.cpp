            do_list(parser)
        elif parser.check('import'):
            do_import(parser)
        else:
            die('unhandled command: %s' % line)
        sys.stdout.flush()