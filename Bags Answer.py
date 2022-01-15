# -*- coding: utf-8 -*-
"""
Created on Fri Sep  3 21:17:02 2021

@author: artyomshutoff
"""

bags = [[] for i in range(100)]

for gift in range(1000):
	gift = str(gift)
	if len(gift) == 1:
		gift = '00' + gift
	elif len(gift) == 2:
		gift = '0' + gift

	less_5 = ''
	greater_or_equal_5 = ''
	
	for i in gift:
		if int(i) < 5:
			less_5 += i
		else:
			greater_or_equal_5 += i
	if (not len(less_5)) or (not len(greater_or_equal_5)):
		if len(less_5) > 0:
			bags[int(less_5[1:])].append(gift)
		else:
			bags[int(greater_or_equal_5[1:])].append(gift)
		continue
	if len(less_5) > len(greater_or_equal_5):
		bags[int(less_5)].append(gift)
	else:
		bags[int(greater_or_equal_5)].append(gift)

out = []
for i in range(len(bags)):
	if len(bags[i]) > 0:
		i = str(i)
		if len(i) == 1:
			i = '0' + i
		out.append(i)

print('Кол-во мешков:', len(out))
print('Номера мешков:', ' '.join(out))