a = map(int, raw_input().split())
print min(map(lambda a, b: a/b, a, [1,1,2,7,4]))