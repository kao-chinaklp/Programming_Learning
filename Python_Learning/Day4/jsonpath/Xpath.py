# html
# /html/head/title
# /html//title
# //title
# //title/../..//title
# //title/text() 从开闭标签找文本
# //link/@href 从选中的标签节点获取指定的属性值
# /html/body/div[3]
# /html/body/div[last()] 选中最后一个
# /html/body/div[last() - 1] 选中倒数第二个个
# /html/body/div[position()>=20] 范围选择
# //div[@id="content"]/div/@class 出现在[]中的@是使用标签属性名和属性值修饰节点，出现在/后的@是提取属性值
# //span[i>200] 通过子节点的值修饰节点
# //span[contains(text(),".")] 查找包含内容的标签