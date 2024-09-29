from collections import defaultdict

def solution(h,w):
    if h >= w:
        max_len = 0
        for i in range(h):
            d = defaultdict(int)
            for j in range(1, int(max(n_map[i]))+1):
                cnt = n_map[i].count(str(j))
                if cnt: d[j] += cnt
            d = sorted(d.items(), key=lambda x: (x[1], x[0]))
            d = ''.join(list(map(lambda x: (str(x[0])+str(x[1])), d)))
            n_map[i] = d
            max_len = max(max_len, len(d))

        for i in range(h):
            n_map[i] = n_map[i].ljust(max_len, '0')
    
    if h < w:
        d_list, max_len = [], 0
        for i in range(w):
            d = defaultdict(int)
            for j in range(h):
                if n_map[j][i] != "0": d[n_map[j][i]] += 1
            
            d = sorted(d.items(), key=lambda x: (x[1], x[0]))
            d = ''.join(list(map(lambda x: (str(x[0])+str(x[1])), d)))
            d_list.append(d)
            max_len = max(max_len, len(d))
            max_len = min(100, max_len)

        for i in range(len(d_list)):
            d = d_list[i]
            for j in range(max_len):
                if j<len(d): 
                    n_map[j] = n_map[j][:i] + d[j] + n_map[j][i+1:]
                elif max_len>len(n_map[j]): 
                    n_map[j] += '0'


r,c,k = map(int, input().split())
n_map = [ "" for _ in range(100)]
h, w, chk = 3, 3, 1
for i in range(3): n_map[i]=input().replace(" ","") 

for idx in range(1,101):
    if r<=h and c<=w and int(n_map[r-1][c-1])==k:
        print(idx-1)
        chk = 0
        break

    solution(h,w)

    for i in range(100):
        if n_map[i] == "": break
        h = i+1
        if len(n_map[i]): w = max(w, len(n_map[i]))

if chk: print(-1)