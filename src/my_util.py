import re
import urllib2
import numpy as np
from scipy.spatial.distance import pdist


"""
log edit type info
"""
LOG_EDIT_TYPES = ["addLog", "removeLog", "moveLog", "updateLog",\
         "addVariable", "removeVariable", "updateVariable", "moveVariable",\
          "addContent", "removeContent", "updateContent", "moveContent"]
# gumtree info
GUMTREE_HOME = '/opt/gumtree/gumtree/dist/build/distributions/gumtree-20170703-2.1.0-SNAPSHOT'
JAVA_CLASS_PATH = '.:/usr/info/code/cpp/LogMonitor/LogMonitor/java:' + GUMTREE_HOME + '/lib/annotations-2.0.1.jar:' + GUMTREE_HOME + '/lib/antlr-3.5.2.jar:' + GUMTREE_HOME + '/lib/antlr-runtime-3.5.2.jar:' + GUMTREE_HOME + '/lib/aopalliance-1.0.jar:' + GUMTREE_HOME + '/lib/app-1.3.200-v20130910-1609.jar:' + GUMTREE_HOME + '/lib/asm-3.1.jar:' + GUMTREE_HOME + '/lib/cglib-2.2.1-v20090111.jar:' + GUMTREE_HOME + '/lib/client.diff-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/client-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/common-3.6.200-v20130402-1505.jar:' + GUMTREE_HOME + '/lib/commons-codec-1.10.jar:' + GUMTREE_HOME + '/lib/commons-io-2.0.1.jar:' + GUMTREE_HOME + '/lib/commons-lang3-3.1.jar:' + GUMTREE_HOME + '/lib/commons-logging-1.2.jar:' + GUMTREE_HOME + '/lib/contenttype-3.4.200-v20140207-1251.jar:' + GUMTREE_HOME + '/lib/core-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.antlr3-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.antlr3-antlr-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.antlr3-json-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.antlr3-php-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.antlr3-r-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.antlr3-xml-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.c-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.css-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.jdt-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.js-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.ruby-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gen.srcml-2.1.0-SNAPSHOT.jar:' + GUMTREE_HOME + '/lib/gson-2.4.jar:' + GUMTREE_HOME + '/lib/guava-18.0.jar:' + GUMTREE_HOME + '/lib/guice-3.0.jar:' + GUMTREE_HOME + '/lib/javassist-3.18.2-GA.jar:' + GUMTREE_HOME + '/lib/javax.inject-1.jar:' + GUMTREE_HOME + '/lib/javax.servlet-api-3.1.0.jar:' + GUMTREE_HOME + '/lib/jetty-http-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/jetty-io-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/jetty-security-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/jetty-server-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/jetty-servlet-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/jetty-util-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/jetty-webapp-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/jetty-xml-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/jobs-3.6.0-v20140424-0053.jar:' + GUMTREE_HOME + '/lib/jrubyparser-0.5.3.jar:' + GUMTREE_HOME + '/lib/jsr305-3.0.1.jar:' + GUMTREE_HOME + '/lib/jtidy-r938.jar:' + GUMTREE_HOME + '/lib/junit-4.8.2.jar:' + GUMTREE_HOME + '/lib/org.eclipse.core.resources-3.10.0.v20150423-0755.jar:' + GUMTREE_HOME + '/lib/org.eclipse.jdt.core-3.11.0.v20150602-1242.jar:' + GUMTREE_HOME + '/lib/osgi-3.10.0-v20140606-1445.jar:' + GUMTREE_HOME + '/lib/ph-commons-8.3.0.jar:' + GUMTREE_HOME + '/lib/ph-css-5.0.1.jar:' + GUMTREE_HOME + '/lib/preferences-3.5.200-v20140224-1527.jar:' + GUMTREE_HOME + '/lib/reflections-0.9.10.jar:' + GUMTREE_HOME + '/lib/registry-3.5.400-v20140428-1507.jar:' + GUMTREE_HOME + '/lib/rendersnake-1.9.0.jar:' + GUMTREE_HOME + '/lib/rhino-1.7.7.jar:' + GUMTREE_HOME + '/lib/runtime-3.10.0-v20140318-2214.jar:' + GUMTREE_HOME + '/lib/simmetrics-core-3.2.3.jar:' + GUMTREE_HOME + '/lib/slf4j-api-1.7.21.jar:' + GUMTREE_HOME + '/lib/spark-core-2.5.2.jar:' + GUMTREE_HOME + '/lib/spring-aop-4.1.6.RELEASE.jar:' + GUMTREE_HOME + '/lib/spring-beans-4.1.6.RELEASE.jar:' + GUMTREE_HOME + '/lib/spring-context-4.1.6.RELEASE.jar:' + GUMTREE_HOME + '/lib/spring-core-4.1.6.RELEASE.jar:' + GUMTREE_HOME + '/lib/spring-expression-4.1.6.RELEASE.jar:' + GUMTREE_HOME + '/lib/spring-web-4.1.6.RELEASE.jar:' + GUMTREE_HOME + '/lib/spring-webmvc-4.1.6.RELEASE.jar:' + GUMTREE_HOME + '/lib/ST4-4.0.8.jar:' + GUMTREE_HOME + '/lib/trove4j-3.0.3.jar:' + GUMTREE_HOME + '/lib/websocket-api-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/websocket-client-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/websocket-common-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/websocket-server-9.3.6.v20151106.jar:' + GUMTREE_HOME + '/lib/websocket-servlet-9.3.6.v20151106.jar'
# regex
SPLIT_LOG = r'[^\w%&/\[\]\*\\]'

# repos info ...
USER_NAME = ''
REPOS_NAME = ''
# patch file, hunk file, log file and cluster file
PATCH_RECORD_FILE = ''
HUNK_RECORD_FILE = ''
LOG_RECORD_FILE = ''
CLUSTER_RECORD_FILE = ''
WAIT_TIME_RECORD_FILE = ''
# patch, hunk file prefix
PATCH_FILE_PREFIX = ''
HUNK_FILE_PREFIX = ''
OLD_HUNK_FILE_PREFIX = ''
NEW_HUNK_FILE_PREFIX = ''

# record title and index
PATCH_RECORD_TITLE = ['url', 'date', 'title', 'changes', 'file_name', 'patch_type', 'other_info']
DATE_INDEX = PATCH_RECORD_TITLE.index('date')
FILE_NAME_INDEX = PATCH_RECORD_TITLE.index('file_name')

HUNK_RECORD_TITLE = PATCH_RECORD_TITLE + ['old_hunk_file','new_hunk_file','old_log_locs', 'new_log_locs']
OLD_LOG_LOCS_INDEX = HUNK_RECORD_TITLE.index('old_log_locs')
NEW_LOG_LOCS_INDEX = HUNK_RECORD_TITLE.index('new_log_locs')

LOG_RECORD_TITLE = PATCH_RECORD_TITLE + ['old_hunk_file','new_hunk_file', 'old_loc', 'new_loc', 'old_log', 'new_log', 'edit_types', 'edit_words', 'edit_feature']
OLD_HUNK_INDEX = LOG_RECORD_TITLE.index('old_hunk_file')
NEW_HUNK_INDEX = LOG_RECORD_TITLE.index('new_hunk_file')
OLD_LOG_INDEX = LOG_RECORD_TITLE.index('old_log')
NEW_LOG_INDEX = LOG_RECORD_TITLE.index('new_log')
EDIT_TYPE_INDEX = LOG_RECORD_TITLE.index('edit_types')
EDIT_FEATURE_INDEX = LOG_RECORD_TITLE.index('edit_feature')

CLUSTER_RECORD_TITLE = LOG_RECORD_TITLE + ['cluster']
WAIT_TIME_RECORD_TITLE = CLUSTER_RECORD_TITLE + ['wait_time']

# log pattern
LOG_PATTERN = ''

def set_user_repos(user_name='', repos_name='tar'):
    """
    @ param user name and repos name\n
    @ return nothing\n
    @ involve update constant vairables according to repos name and user name\n
    """
    global USER_NAME
    USER_NAME = user_name
    global REPOS_NAME
    REPOS_NAME = repos_name
    # patch file, hunk file, log file and cluster file
    global PATCH_RECORD_FILE
    PATCH_RECORD_FILE = 'data/analyze/' + REPOS_NAME + '_log_commit.csv'
    global HUNK_RECORD_FILE
    HUNK_RECORD_FILE = 'data/analyze/' + REPOS_NAME + '_hunk.csv'
    global LOG_RECORD_FILE
    LOG_RECORD_FILE = 'data/analyze/' + REPOS_NAME + '_log.csv'
    global CLUSTER_RECORD_FILE
    CLUSTER_RECORD_FILE = 'data/analyze/' + REPOS_NAME + '_cluster.csv'
    global WAIT_TIME_RECORD_FILE
    WAIT_TIME_RECORD_FILE = 'data/analyze/' + REPOS_NAME + '_wait_time.csv'
    # patch, hunk file prefix
    global PATCH_FILE_PREFIX
    PATCH_FILE_PREFIX = 'data/crawl/' + REPOS_NAME + '/patch_'
    global HUNK_FILE_PREFIX
    HUNK_FILE_PREFIX = 'data/crawl/' + REPOS_NAME + '/hunk_'
    global OLD_HUNK_FILE_PREFIX
    OLD_HUNK_FILE_PREFIX = 'data/crawl/' + REPOS_NAME + '/old_hunk_'
    global NEW_HUNK_FILE_PREFIX
    NEW_HUNK_FILE_PREFIX = 'data/crawl/' + REPOS_NAME + '/new_hunk_'
    # log pattern
    global LOG_PATTERN
    LOG_PATTERN = get_log_function_pattern()

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

def get_log_function_pattern():
    """
    @ param repos name\n
    @ return log pattern\n
    @ involve get log functions and create log pattern based on log functions\n
    """
    log_function_file_name = 'data/analyze/' + REPOS_NAME + '_logging_statement.csv'
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
    @ param file name and file content(list)\n
    @ return nothing\n
    @ involve write file content into specified file\n
    """
    write_file = open(file_name, 'wb')
    write_file.write('\n'.join(file_content))
    write_file.close()

def save_file(file_name, file_content):
    """
    @ param file name and file content(str with line spliter)\n
    @ return nothing\n
    @ involve write file content into specified file\n
    """
    write_file = open(file_name, 'wb')
    write_file.write(file_content)
    write_file.close()

def urlopen(url, try_times = 20):
    """
    @ param url and retry times\n
    @ return content of given url\n
    @ involve open given url with exception handling\n
    """
    times = 0
    try:
        response = urllib2.urlopen(url)
        content = response.read()
    except (urllib2.URLError, urllib2.HTTPError), e:
        print e.reason
        if times < try_times:
            print 'now trying the %d times' %times
            return urlopen(url, try_times = 0)
        else:
            return None
    else:
        return content

def remove_given_element(element, in_list):
    """
    @ param element and list\n
    @ return new list\n
    @ involve remove given element in in_list\n
    """
    # remove element in in_list
    while element in in_list:
        in_list.remove(element)

    return in_list

def compute_similarity(in_vector1, in_vector2, method='braycurtis'):
    """
    @ param two number vectors(same dimension)\n
    @ return similarity\n
    @ involve compute braycurtis similarity of two vectors\n
    """
    if in_vector1 == [] or in_vector2 == []:
        return 1.0
    X = np.vstack([in_vector1, in_vector2])
    # standard distance
    distance = pdist(X, metric=method)
    similairty = 1 - distance
    return similairty

    