        mailer.__del__()


def choose_mailer(config, environment):
    mailer = config.get('mailer', default='sendmail')

