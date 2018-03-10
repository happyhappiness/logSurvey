import os
import re
import csv
import my_util

# some constants
# GIT_REPOS_NAME = 'squid-cache'
# REPOS_NAME = 'squid'
# GIT_REPOS_NAME = 'git'
# REPOS_NAME = 'git'
GIT_REPOS_NAME = 'collectd'
REPOS_NAME = 'collectd'
LOG_PATTERN = my_util.get_log_function_pattern(REPOS_NAME)
MAIN_URL = 'https://github.com/'

def store_patch_file(patch, counter, record, writer):
    """
    @ param patch, counter, record and writer\n
    @ return new counter\n
    @ involve check patch for log modification and store patch file if success\n
    """
    if patch is None:
        print record
    for line in patch:
        if line.startswith('-') or line.startswith('+'):
            is_log = re.search(LOG_PATTERN, line, re.I)
            if is_log:
                file_name = 'data/crawl/' + REPOS_NAME + '/patch_' + str(counter) + '.diff'
                my_util.store_file(file_name, patch)
                writer.writerow(record + [file_name])
                return counter + 1
    
    return counter
            
def analyze_commit(commit_page, record, counter, writer):
    """
    @ param commit page, [date, title], counter and writer\n
    @ return counter\n
    @ involve analyze commit page and store commit record[call generate code]\n
    """
    url = MAIN_URL + commit_page
    commit_info = my_util.urlopen(url)
    if commit_info is None:
        print 'fail to fetch commit: %s; counter: %d' %(url, counter)
        return None
    # response = urllib2.urlopen(url)
    # commit_info = response.read()
    commit_info = commit_info.split("\n")
    # regex parser for store [url, time, title, explain, patch_file]
    modify_pattern = r'<strong>(\d*) (?:addition|deletion)[s]*</strong>'
    # one commit may modify multi files, this is spliter of files
    file_split_pattern = r'title="([^ >]*)">'
    outer_code_pattern = r'<span class="blob-code-inner">(.*)</span>$'
    inner_code_pattern = r'(<span [^>]*>|</span>)'
    hunk_pattern = r'<td class="blob-code blob-code-inner blob-code-hunk">([^>]*)</td>'

    changes = 0
    times = 0
    patch = []
    for line in commit_info:
        if times < 2:
            is_modify = re.search(modify_pattern, line, re.I)
            if is_modify:
                changes += int(is_modify.group(1))
                times += 1
        else:
            # find file spliter
            is_file_split = re.search(file_split_pattern, line, re.I)
            if is_file_split:
                patch.append('----++++' + is_file_split.group(1))
            # find code
            is_code = re.search(outer_code_pattern, line, re.I)
            if is_code:
                # remove inner css span
                patch.append(re.sub(inner_code_pattern, '', is_code.group(1)))
            # find hunk title
            is_hunk = re.search(hunk_pattern, line, re.I)
            if is_hunk:
                patch.append(is_hunk.group(1))

    return store_patch_file(patch, counter, [url] + record + [changes], writer)

def analyze_html(html, counter, writer, failure_commit=None):
    """
    @ param html, counter and writer, commit list page(for error handling)\n
    @ return html/new commit list page, counter and failure commit\n
    @ involve analyze html and find first commit page\n
    """
    commit_page_begin_pattern = r'(?:href|HREF)="/(' + GIT_REPOS_NAME + r'/' + REPOS_NAME + r'/commit/\w*)" class="message"[^>]*title=\W*([^>]*$|[^>]*>).*'
    commit_page_end_pattern = r'([^>]*>)'
    # <relative-time datetime="2018-01-24T02:12:06Z">Jan 24, 2018</relative-time>
    date_pattern = r'relative-time[^>]*>(\w* \d*, \d*)</relative-time>'

    for line in html:
        # search begin of commit
        is_commit_begin = re.search(commit_page_begin_pattern, line, re.I)
        if is_commit_begin:                    
            # retrieve title
            title = is_commit_begin.group(2)
            # search end of commit
            for line_commit in html[html.index(line) + 1:]:
                # end of title
                if title.endswith('>'):
                    # search date
                    for line_commit_date in html[html.index(line_commit) + 1:]:
                        is_date = re.search(date_pattern, line_commit_date, re.I)
                        if is_date:
                            date = is_date.group(1)
                            # compare with the failure commit(restart point)
                            if failure_commit is not None:
                                # find start point and start analyze comming commit
                                if is_commit_begin.group(1) == failure_commit:
                                    failure_commit = None
                                    return html[html.index(line_commit_date) + 1:], analyze_commit(is_commit_begin.group(1), [date, title[:-1]], counter, writer), failure_commit
                                # if have not find start point, skip analyze
                                else:
                                    return html[html.index(line_commit_date) + 1:], counter, failure_commit
                            # no restart point, so analyze every commit
                            else:
                                return html[html.index(line_commit_date) + 1:], analyze_commit(is_commit_begin.group(1), [date, title[:-1]], counter, writer), failure_commit
                # search end of title
                else:
                    is_commit_end = re.search(commit_page_end_pattern, line_commit, re.I)
                    # end of title
                    if is_commit_end:
                        title += '\n' + is_commit_end.group(1)
                    else:
                        title += '\n' + line_commit
            
            # print message if can not commit end
            print 'can not find commit end or date for commit %s' %is_commit_begin.group(1)

    # if can not find new commit, then search next page
    # <a href="https://github.com/squid-cache/squid/commits/master?after=2db9989c5c4397458ef9ef43f8698844cd9ffcea+34" rel="nofollow">Older</a></div>'
    next_list_page_pattern = r'(?:href|HREF)="[^>]*(' + GIT_REPOS_NAME + r'/' + REPOS_NAME + r'/commits/master\?after=[\w\+]*)"'
    for line in html:
        is_next_list_page = re.search(next_list_page_pattern, line, re.I)
        if is_next_list_page:
            # call analyze commit list for analyzing the next commit list
            return is_next_list_page.group(1), counter, failure_commit
    
    return None, None, failure_commit

def analyze_commit_list(commit_list_page, total_counter, counter, writer, failure_commit=None):
    """
    @ param commit list page, counter and file writer\n
    @ return nothing\n
    @ involve fetch and analyze commit list[call analyze commit]\n
    """
    # fetch commit list
    html = my_util.urlopen(MAIN_URL + commit_list_page)
    if html is None:
        print 'fail for commit list page fetch %s' %commit_list_page
        return
    # html = response.read()
    html = html.split("\n")


    # analyze html, include invokement of analyze_commit_list itself
    html, counter, failure_commit = analyze_html(html, counter, writer, failure_commit)

    # deal with the same commit list if this list is not done
    while isinstance(html, list):
        # html is list, then counter is the return value of analyze commit. whose none means fetch failure
        if counter is None:
            print 'fail for commit list page fetch %s' %commit_list_page
            return
        # update and print counter
        total_counter += 1
        if total_counter % 5 == 0:
            print 'have crawled %d commit, find %d log commit' %(total_counter, counter)
        # analyze the lefted html
        html, counter, failure_commit = analyze_html(html, counter, writer, failure_commit)


    # analyze new commit if find next page
    if html is not None:
        analyze_commit_list(html, total_counter, counter, writer)
    # no next page
    else:
        print 'end of repos'

"""
main function
"""
if __name__ == "__main__":
    record_file = file('data/analyze/' + REPOS_NAME + '_log_commit.csv', 'wb')
    writer = csv.writer(record_file)
    writer.writerow(['url', 'date', 'title', 'changes', 'file_name'])
    # analyze commit list
    analyze_commit_list(GIT_REPOS_NAME + '/' + REPOS_NAME + '/commits/master', 0, 0, writer)

    record_file.close()
