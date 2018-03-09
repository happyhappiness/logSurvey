import re
import urllib2

def retrieve_log_function(file_name):
    """
    @ param file name\n
    @ return log function list\n
    @ involve retrieve log function name from logging statement csv\n
    """
    log_functions = []
    log_statement = open(file_name, 'rb')
    lines = log_statement.readlines()

    for line in lines:
        log_function = line[0:line.find("@")]
        if not log_function in log_functions:
            log_functions.append(log_function)

    log_statement.close()
    return log_functions

def get_log_function_pattern(repos):
    """
    @ param repos name\n
    @ return log pattern\n
    @ involve get log functions and create log pattern based on log functions\n
    """
    log_function_file_name = 'data/analyze/' + repos + '_logging_statement.csv'
    log_functions = retrieve_log_function(log_function_file_name)

    # concate log functions to create log pattern
    regrex_string = r'\W('
    for log_function in log_functions:
        regrex_string += log_function + r'|'
    regrex_string = regrex_string[:-1]
    regrex_string += r')(\s*\(.*|\s*$)'

    return regrex_string


def store_file(file_name, file_content):
    """
    @ param patch(list) and counter\n
    @ return new counter\n
    @ involve write file content into specified file\n
    """
    write_file = open(file_name, 'wb')
    write_file.write('\n'.join(file_content))
    write_file.close()

def urlopen(url, try_times = 20):
    """
    @ param url and retry times\n
    @ return content of given url\n
    @ involve write file content into specified file\n
    """
    times = 0
    try:
        response = urllib2.urlopen(url)
        content = response.read()
    except (urllib2.URLError, urllib2.HTTPError), e:
        print e.reason
        if times < try_times:
            print 'now trying the %d times' %times
            return get_url_content(url, try_times = 0)
        else:
            return None
    else:
        return content

