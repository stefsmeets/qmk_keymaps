from pathlib import Path
from itertools import pairwise, tee
from collections import Counter


def files():
	# yield from Path('/home/stef/python').glob('cpython/**/*.py')
	yield from Path('/home/stef/python').glob('*/src/**/*.py')
	# yield from Path('/home/stef/python').glob('**/*.md')
	yield from Path('/home/stef/Stuff/writing').glob('**/*.tex')
	yield from Path('/home/stef/Stuff/notes').glob('**/*.md')

def triwise(iterable):
    # pairwise('ABCDEFG') → AC BD CE DF EG
    iterator = iter(iterable)
    a = next(iterator, None)
    b = next(iterator, None)
    for c in iterator:
        yield a, c
        a = b
        b = c


ntot = 0
f = Counter()
b = Counter()
t = Counter()


for fn in files():
	try:
		txt = fn.read_text().lower()
	except:
		print(fn)
		continue

	f += Counter(txt)
	b += Counter(pairwise(txt))
	t += Counter(triwise(txt))
	ntot += 1

print(ntot)

remove = [' ',]

bigrams = Counter()
trigrams = Counter()

for raw,new in ((b,bigrams), (t, trigrams)):
	for (a,b),v in raw.items():
		if a in remove:
			continue
		if b in remove:
			continue

		new[a+b] = v

f.pop(' ')
f.pop('\n')
print('frequency')
for k,v in f.most_common(20):
	print(f'{k} {v/f.total():8.4%}')
print()

combos = 'io iu ie ia eo ea eu ao au uo'.split()

print('bigrams')
for k,v in bigrams.most_common(10):
	print(f'{k} {v/bigrams.total():8.2%}')
print()

for a,b in combos:
	n1 = bigrams[a+b] / bigrams.total()
	n2 = bigrams[b+a] / bigrams.total()
	print(f'{a}{b}: {n1:.3%} | {b}{a}: {n2:.3%} | {n1 + n2:.3%}')

print(bigrams.total())
print()
print('skipgrams')
for k,v in trigrams.most_common(10):
	print(f'{k} {v/trigrams.total():8.2%}')
print()

for a,b in combos:
	n1 = trigrams[a+b] / trigrams.total()
	n2 = trigrams[b+a] / trigrams.total()
	print(f'{a}{b}: {n1:.3%} | {b}{a}: {n2:.3%} | {n1 + n2:.3%}')

print(trigrams.total())


