#!/usr/bin/python3
""" Count it! """
from requests import get


def count_words(subreddit, word_list, after="", word_dic=None):
    """ function that queries the Reddit API """

    if word_dic is None:
        word_dic = {word: 0 for word in word_list}

    if after is None:
        word_list = sorted(word_dic.items(), key=lambda x: (-x[1], x[0]))
        for word, count in word_list:
            if count:
                print(f"{word.lower()}: {count}")
        return None

    endpoint = f"https://www.reddit.com/r/{subreddit}/hot/.json"
    headers = {'user-agent': 'my-app/0.0.1'}
    params = {'limit': 100, 'after': after}

    resp = get(endpoint, headers=headers, params=params, allow_redirects=False)
    if resp.status_code != 200:
        return None

    try:
        data = resp.json().get("data")
        after = data.get("after")
        children = data.get("children")
        for child in children:
            title = child.get("data").get("title").lower().split()
            for word in word_list:
                word_dic[word] += title.count(word.lower())
    except Exception:
        return None

    count_words(subreddit, word_list, after, word_dic)
