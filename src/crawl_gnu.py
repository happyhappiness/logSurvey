
import urllib2
import os
import re
import csv
import my_util

# some constants
MAIN_URL = 'http://git.savannah.gnu.org'

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
            is_log = re.search(my_util.LOG_PATTERN, line, re.I)
            if is_log:
                file_name = my_util.PATCH_FILE_PREFIX + str(counter) + '.diff'
                my_util.store_file(file_name, patch)
                writer.writerow(record + [file_name])
                return counter + 1
    
    return counter

def generate_record(url, commit_info, counter, writer):
    """
    @ param commit info, counter and writer\n
    @ return counter\n
    @ involve parse commit info and generate commit record\n
    """
    # regex parser for store [url, date, title, changes, patch_file]
    date_pattern = r'Date: \w*, (\d* \w* \d*) \d*:\d*:.*'
    title_pattern = r'Subject: (.*)'
    patch_pattern = r'^---'
    title = None
    date = None
    patch = None
    # retrieve date, title and patch
    for line in commit_info:
        # try to find date(just one time)
        if date is None:
            is_date = re.search(date_pattern, line, re.I)
            if is_date:
                date = is_date.group(1)
        # subject follows date
        else:   
            # find title(just one time)
            if title is None:
                is_title = re.search(title_pattern, line, re.I)
                if is_title:
                    title = is_title.group(1)
            else:
                # find patch(just one time)
                is_patch = re.search(patch_pattern, line, re.I)
                if is_patch:
                    patch = commit_info[commit_info.index(line):]
                    break
                else:
                   title += '\n' + line 
    if patch is None:
        print 'can not retrieve patch for given url: %s' %url
        return counter
    # retrieve modify and diff
    changes = 0
    # modify pattern 1 file changed, 5 insertions, 6 deletions
    modify_pattern = r'\d* \w* changed, (\d*)\D*(\d*)\D*'
    diff_pattern = r'diff --git .*'
    for line in patch:
        # find changes(just one time)
        if changes == 0:
            is_modify = re.search(modify_pattern, line, re.I)
            if is_modify:
                for i in range(1, is_modify.lastindex + 1):
                    num_str = is_modify.group(i)
                    if num_str == '':
                        num_str = '0'
                    else:
                        changes += int(num_str)
        else:
            # find first diff file
            is_diff = re.search(diff_pattern, line, re.I)
            if is_diff:
                return store_patch_file(patch[patch.index(line):], counter, [url, date, title, changes], writer)

    print 'can not retrieve diff for given url: %s' %url
    return counter
            
def analyze_commit(commit_page, counter, writer):
    """
    @ param commit page, counter and writer\n
    @ return counter\n
    @ involve analyze commit page and store commit record[call generate code]\n
    """
    url = MAIN_URL + commit_page
    commit_page = commit_page.replace('commit', 'patch')
    response = urllib2.urlopen(MAIN_URL + commit_page)
    commit_info = response.read()
    commit_info = commit_info.split("\n")
    # regex parser for store [url, time, title, explain, patch_file]
    return generate_record(url, commit_info, counter, writer)

def analyze_commit_list(commit_list_page, total_counter, counter, writer):
    """
    @ param commit list page, counter and file writer\n
    @ return nothing\n
    @ involve fetch and analyze commit list[call analyze commit]\n
    """
    # fetch commit list
    response = urllib2.urlopen(MAIN_URL + commit_list_page)
    html = response.read()
    html = html.split("\n")
    commit_page_pattern = r"(?:href|HREF)='(/cgit/" + my_util.REPOS_NAME + r"\.git/commit/\?id=\w*)'>"
    next_list_page_pattern = r"(?:href|HREF)='(/cgit/" + my_util.REPOS_NAME + r"\.git/log/\?ofs=\d*)'>\[next\]"

    # check html content against git-2.*.tar.gz
    commit_count = 0
    # every commit list page has at most 50 commits
    for line in html:
        # one page has at most 50 commits
        if commit_count == 50:
            # find next page
            is_next_list = re.search(next_list_page_pattern, line, re.I)
            if is_next_list:
                analyze_commit_list(is_next_list.group(1), total_counter, counter, writer)
            else:
                print 'end of repos'
            return
        else:
            # retrieve commit address
            is_commit = re.search(commit_page_pattern, line, re.I)
            if is_commit:
                # analyze commit and counter
                counter = analyze_commit(is_commit.group(1), counter, writer)
                # update commit counter and total counter
                commit_count += 1
                total_counter += 1
                if total_counter % 5 == 0:
                    print 'now analyzing %d total commit, find %d log commit' %(total_counter, counter)
    
    print 'end of repos'

"""
main function
"""
if __name__ == "__main__":

    my_util.set_user_repos('', 'tar')

    record_file = file(my_util.PATCH_RECORD_FILE, 'wb')
    writer = csv.writer(record_file)
    writer.writerow(my_util.PATCH_RECORD_TITLE)
    # analyze commit list
    analyze_commit_list('/cgit/' + my_util.REPOS_NAME + '.git/log/', 0, 0, writer)

    record_file.close()
