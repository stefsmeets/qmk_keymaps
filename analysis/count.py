from pathlib import Path
from itertools import pairwise, tee
from collections import Counter


def files():
    # yield from Path('/home/stef/python').glob('cpython/**/*.py')
    yield from Path("/home/stef/python").glob("*/src/**/*.py")
    # yield from Path('/home/stef/python').glob('**/*.md')
    # yield from Path("/home/stef/Stuff/writing").glob("**/*.tex")
    # yield from Path("/home/stef/Stuff/notes").glob("**/*.md")


def genskipgram(iterable):
    iterator = iter(iterable)
    a = next(iterator, None)
    b = next(iterator, None)
    for c in iterator:
        yield a, c
        a, b = b, c


def genskipgram2(iterable):
    iterator = iter(iterable)
    a = next(iterator, None)
    b = next(iterator, None)
    c = next(iterator, None)
    for d in iterator:
        yield a, d
        a, b, c = b, c, d


def genskipgram3(iterable):
    iterator = iter(iterable)
    a = next(iterator, None)
    b = next(iterator, None)
    c = next(iterator, None)
    d = next(iterator, None)
    for e in iterator:
        yield a, e
        a, b, c, d = b, c, d, e


def gentrigram(iterable):
    iterator = iter(iterable)
    a = next(iterator, None)
    b = next(iterator, None)
    for c in iterator:
        yield a, b, c
        a = b
        b = c


ntot = 0
freq = Counter()
big = Counter()
trig = Counter()
skip = Counter()
skip2 = Counter()
skip3 = Counter()

for fn in files():
    try:
        txt = fn.read_text().lower()
    except:
        print(fn)
        continue

    freq += Counter(txt)
    big += Counter(pairwise(txt))
    trig += Counter(gentrigram(txt))
    skip += Counter(genskipgram(txt))
    skip2 += Counter(genskipgram2(txt))
    skip3 += Counter(genskipgram3(txt))
    ntot += 1

print(f'parsed {ntot} files')
print()

keep = "abcdefghijklmnopqrstuvwxyz',.;\"`-_"

bigrams = Counter()
trigrams = Counter()
skipgrams = Counter()
skipgrams2 = Counter()
skipgrams3 = Counter()

freq = Counter({k: v for k, v in freq.items() if k in keep})

for raw, new in (
    (big, bigrams),
    (skip, skipgrams),
    (skip2, skipgrams2),
    (skip3, skipgrams3),
):
    for (a, b), v in raw.items():
        if a not in keep:
            continue
        if b not in keep:
            continue

        new[a + b] = v

for raw, new in ((trig, trigrams),):
    for (a, b, c), v in raw.items():
        if a not in keep:
            continue
        if b not in keep:
            continue
        if c not in keep:
            continue

        new[a + b + c] = v


for dct in (
    freq,
    bigrams,
    skipgrams,
    skipgrams2,
    skipgrams3,
    trigrams,
):
    total = dct.total()
    for k, v in dct.items():
        dct[k] = v / total

print("### frequency")
print("| key | freq |")
print("| -   | -        |")
for k, v in freq.most_common():
    print(f"| **{k:s}**   | {v:8.2%} |")
print()

combos = "io iu ie ia eo ea eu ao au uo".split()

print("### bigrams")
print("| keys | freq |")
print("| -    | -    |")
for k, v in bigrams.most_common(30):
    print(f"| **{k:s}**    | {v:8.2%} |")
print()
print("### vowel bigrams")
print("|   | freq |   | freq  | total |")
print("| - | -    | - | -     | -     |")
for a, b in combos:
    n1 = bigrams[a + b]
    n2 = bigrams[b + a]
    print(f"| **{a}{b}** | {n1:.3%} | **{b}{a}** | {n2:.3%} | {n1 + n2:.3%} |")
print()
print("### skipgrams")
print("| keys | freq |")
print("| -    | -    |")
for k, v in skipgrams.most_common(30):
    print(f"| **{k:s}**    | {v:8.2%} |")
print()
print("### vowel skipgrams")
print("|   | freq |   | freq  | total |")
print("| - | -    | - | -     | -     |")
for a, b in combos:
    n1 = skipgrams[a + b]
    n2 = skipgrams[b + a]
    print(f"| **{a}{b}** | {n1:.3%} | **{b}{a}** | {n2:.3%} | {n1 + n2:.3%} |")
print()
print("### vowel clusters")
print("| cluster | sfb | sfs | annoying | ltr | rtl |")
print("| -       | -   | -   | -        | -   | -   |")
for cluster in (
    "eo iu a",
    "ao iu e",
    "eu ao i",
    "ao eu i",
):
    m1, m2, r1, r2, p = cluster.replace(" ", "")
    sfb = sum(bigrams[f1 + f2] + bigrams[f2 + f1] for f1, f2 in ((m1, m2), (r1, r2)))
    sfs = sum(
        skipgrams[f1 + f2] + skipgrams[f2 + f1] for f1, f2 in ((m1, m2), (r1, r2))
    )
    annoying = bigrams[r2 + p] + bigrams[p + r2]

    ltr = sum(bigrams[f1 + f2] for f1, f2 in ((m1, r1), (r1, p), (m2, r2)))
    rtl = sum(bigrams[f1 + f2] for f1, f2 in ((p, r1), (r1, m1), (r2, m2), (r1, m2)))

    print(f"| **{cluster}** | {sfb:.3%} | {sfs:.3%} | {annoying:.3%} | {ltr:.3%} | {rtl:.3%} |")

import json

lang = {
    "language": "english",
    "characters": dict(freq.most_common()),
    "bigrams": dict(bigrams.most_common()),
    "skipgrams": dict(skipgrams.most_common()),
    "skipgrams2": dict(skipgrams2.most_common()),
    "skipgrams3": dict(skipgrams3.most_common()),
    "trigrams": dict(trigrams.most_common()),
}

with open("out.json", "w") as f:
    json.dump(lang, f, indent=2)
