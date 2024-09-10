def solve(trees, n, d, d_cnt, special):
    dx, dy = d

    for i in range(len(special)):
        special[i][0], special[i][1] = special[i][0]+(dx*d_cnt), special[i][1]+(dy*d_cnt)
        for j in range(2):
            if special[i][j] < 0: special[i][j] += n
            if special[i][j] >= n : special[i][j] = special[i][j]%n
        
        trees[special[i][0]][special[i][1]] += 1

    for i in range(len(special)):
        for tx, ty in [[-1,-1], [-1,1], [1,-1], [1,1]]:
            x, y = special[i][0]+tx, special[i][1]+ty

            if 0<=x<n and 0<=y<n and trees[x][y]: 
                trees[special[i][0]][special[i][1]] += 1
    
    cut_trees = []
    for i in range(n):
        for j in range(n):
            if trees[i][j] >= 2 and ([i, j] not in special):
                trees[i][j] -= 2
                cut_trees.append([i,j])
    return cut_trees

n, m = map(int, input().split())
trees = [list(map(int, input().split())) for _ in range(n)]
move = [list(map(int, input().split())) for _ in range(m)]

direction = [(0,1), (-1,1), (-1,0), (-1,-1), (0,-1), (1,-1), (1,0), (1,1)]
special = [[n-2,0], [n-2,1], [n-1,0], [n-1,1]]

for d, d_cnt in move:
    special = solve(trees, n, direction[d-1], d_cnt, special)

print(sum([sum(t) for t in trees]))