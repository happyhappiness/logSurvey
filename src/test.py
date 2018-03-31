keybord_dict = {}
normal = ['A', 'B']
unormal = ['K', 'D']

length = len(normal)
for i in range(length):
    keybord_dict[normal[i]] = unormal[i]

sentence = 'ABAB'
result = ''
for word in sentence:
    result += keybord_dict[word]


print result
