import requests

url = 'https://github.com/kao-chinaklp'

#请求头
headers = {
    'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/92.0.4515.107 Safari/537.36 Edg/92.0.902.62'
    # ,'Cookie': '_octo=GH1.1.67529157.1625820722; _device_id=9de83cced29277121b6c81ce30ba27d5; color_mode={"color_mode":"auto","light_theme":{"name":"light","color_mode":"light"},"dark_theme":{"name":"dark","color_mode":"dark"}}; tz=Asia/Shanghai; has_recent_activity=1; user_session=J33a5fxZdAqooMArtbV8eKoFGutcrr0VlmktzigSJ0oDYnzv; __Host-user_session_same_site=J33a5fxZdAqooMArtbV8eKoFGutcrr0VlmktzigSJ0oDYnzv; tz=Asia/Shanghai; logged_in=yes; dotcom_user=kao-chinaklp; _gh_sess=bMyV8oDnQzQPDjT1iQo114PL5OImHamnnrNqqfLMnsDohCyHmeLjthJ5hgzD6K1yh6UVPD66+kmBJpWle3H6n6sw4X06+cnsXmWsqs/uy1WOMd2rA+/fKXWHjjSHEw6RmW2r5mh2zWeTYPju6v9DqtGILxzdvZLTGd7bgVfwSuhJf2+lIUnZJa8tWxINLLS9uA/SPfeXkqvNNR89CUnhi0l68sUGf1y8OalYyeJSABSLxYkd7nQuXOe+0HJKpn6XRwJm+0NShFrf6Vl3ykJXqj1WtrAQeL00JUuazfWJOOm9Z4IN1GNZJWAK4y/wj8sjIaDxlkn2W4cp2YuIdeXlsQOq9RCvltJ5ny1Zp1CoQLK8jqo4OqTtA/oHKOt2y5lXThGeSGr/Qq3QmJSFhmntPdVWOBW1lV0NmfGth3dLpa5iI9Wc5LdcD1fM1GZ5sOruuqneXmmr9IXfRbqALgym/Lw4Hci7Y4/eS49xhBRvGLbbzxbztH3F1d0MpArUhhKKAoQ/XqeHJ6UWhrP/ssTQYi1dG6wlwYF0y91eq1d0ufL7xtMd1Vv6hXSf1OOe/03wCVMNQVR3zBxtD0LcjhJqeOupV2sCYS7s5I06o1LSijP4Pcrfx0vxef5OWhyBXmggzPcTLVw7do5ffPHnv0uhzhEMmuZIlmR4tvcehIMJx2MRyBASg5CncEWpjHp+reNRNMyJkwzkopTUEPCXquLsDEEO3r8tylw4pL316C0AOlEOaIcyFJwmhjk7NMZg3h+BuH+H35TRA/VyMVxFF9HEBTNrg7dBuUzrjBNXLguJtZzUY6J7qcM1zPbnDT3/Bp81zpvz/tpG5+eA1ggTuKyGCRq+ZpC/r99eHYYx01w7KTF4kCW2Dc7GFouOGmJvJCKvbLL4Aqt3g/J8kthPBvQz4zj47YU=--Iacsh3XWd0bH28Sd--ERIh9K5i85taD6K/JGTu7g=='
}

# r = requests.get(url, headers=headers)
#
# with open('github.html', 'wb')as f:
#     f.write(r.content.decode())

tmp = '_octo=GH1.1.67529157.1625820722; _device_id=9de83cced29277121b6c81ce30ba27d5; color_mode={"color_mode":"auto","light_theme":{"name":"light","color_mode":"light"},"dark_theme":{"name":"dark","color_mode":"dark"}}; tz=Asia/Shanghai; has_recent_activity=1; user_session=J33a5fxZdAqooMArtbV8eKoFGutcrr0VlmktzigSJ0oDYnzv; __Host-user_session_same_site=J33a5fxZdAqooMArtbV8eKoFGutcrr0VlmktzigSJ0oDYnzv; tz=Asia/Shanghai; logged_in=yes; dotcom_user=kao-chinaklp; _gh_sess=bMyV8oDnQzQPDjT1iQo114PL5OImHamnnrNqqfLMnsDohCyHmeLjthJ5hgzD6K1yh6UVPD66+kmBJpWle3H6n6sw4X06+cnsXmWsqs/uy1WOMd2rA+/fKXWHjjSHEw6RmW2r5mh2zWeTYPju6v9DqtGILxzdvZLTGd7bgVfwSuhJf2+lIUnZJa8tWxINLLS9uA/SPfeXkqvNNR89CUnhi0l68sUGf1y8OalYyeJSABSLxYkd7nQuXOe+0HJKpn6XRwJm+0NShFrf6Vl3ykJXqj1WtrAQeL00JUuazfWJOOm9Z4IN1GNZJWAK4y/wj8sjIaDxlkn2W4cp2YuIdeXlsQOq9RCvltJ5ny1Zp1CoQLK8jqo4OqTtA/oHKOt2y5lXThGeSGr/Qq3QmJSFhmntPdVWOBW1lV0NmfGth3dLpa5iI9Wc5LdcD1fM1GZ5sOruuqneXmmr9IXfRbqALgym/Lw4Hci7Y4/eS49xhBRvGLbbzxbztH3F1d0MpArUhhKKAoQ/XqeHJ6UWhrP/ssTQYi1dG6wlwYF0y91eq1d0ufL7xtMd1Vv6hXSf1OOe/03wCVMNQVR3zBxtD0LcjhJqeOupV2sCYS7s5I06o1LSijP4Pcrfx0vxef5OWhyBXmggzPcTLVw7do5ffPHnv0uhzhEMmuZIlmR4tvcehIMJx2MRyBASg5CncEWpjHp+reNRNMyJkwzkopTUEPCXquLsDEEO3r8tylw4pL316C0AOlEOaIcyFJwmhjk7NMZg3h+BuH+H35TRA/VyMVxFF9HEBTNrg7dBuUzrjBNXLguJtZzUY6J7qcM1zPbnDT3/Bp81zpvz/tpG5+eA1ggTuKyGCRq+ZpC/r99eHYYx01w7KTF4kCW2Dc7GFouOGmJvJCKvbLL4Aqt3g/J8kthPBvQz4zj47YU=--Iacsh3XWd0bH28Sd--ERIh9K5i85taD6K/JGTu7g=='

# way1(稳妥)
#
# cookie_list = tmp.split('; ')
# cookies = {}
#
# for cookie in cookie_list:
#     cookies[cookie.split('=')[0]] = cookie.split('=')[-1]
#
# print(cookies)

# way2(快捷)
cookie_list = tmp.split('; ')
cookies = {cookie.split('=')[0]: cookie.split('=')[-1]for cookie in cookie_list}

r = requests.get(url, headers=headers, cookies=cookies)

with open('github_with_cookie.html', 'wb')as f:
    f.write((r.content))