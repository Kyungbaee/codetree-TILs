from collections import deque

def down(visited, r, c, R, C):
    if (r+2<=R+1) and not visited[r+2][c] and not visited[r+1][c-1] and not visited[r+1][c+1]:
        return True
    return False

def left(visited, r, c, R, C):
    if (r+2<=R+1) and visited[r+2][c]:
        if (1<c) and not visited[r][c-2] and not visited[r-1][c-1] and not visited[r+1][c-1]:
            if down(visited, r, c-1, R, C):
                return True
    return False

def right(visited, r, c, R, C):
    if (r+2<=R+1) and visited[r+2][c]:
        if (c<C-2) and not visited[r][c+2] and not visited[r-1][c+1] and not visited[r+1][c+1]:
            if down(visited, r, c+1, R, C):
                return True
    return False

def search(visited, r, c, R, C, idx):
    max_depth = r+1
    move = [[0]*C for _ in range(R+2)]
    deq = deque([[r,c]])
    move[r][c]=1

    while deq:
        x, y = deq.popleft()
        max_depth = max(max_depth, x)

        if visited[x][y]==2 or visited[x][y]==3:
            for dx, dy in [[0,1], [1,0], [-1,0], [0,-1]]:
                nx, ny = x+dx, y+dy
                if (2<=nx<R+2) and (0<=ny<C) and not move[nx][ny] and visited[nx][ny]:
                    deq.append([nx, ny])
                    move[nx][ny]=1
        if visited[x][y]==1:
            for dx, dy in [[0,1], [1,0], [-1,0], [0,-1]]:
                nx, ny = x+dx, y+dy
                if (2<=nx<R+2) and (0<=ny<C) and not move[nx][ny] and visited[nx][ny]==3:
                    deq.append([nx, ny])
                    move[nx][ny]=1

    return max_depth-1

R,C,K = map(int, input().split())
soul = [list(map(int, input().split())) for _ in range(K)]
visited = [[0]*C for _ in range(R+2)]
idx, answer = 0, 0

while(idx<len(soul)):
    c, exit_num = soul[idx]
    c, r, max_depth = c-1, 0, 0

    while(True):
        if down(visited, r, c, R, C): r = r+1
        elif left(visited, r, c, R, C): r, c, exit_num = r+1, c-1, (exit_num+3)%4
        elif right(visited, r, c, R, C): r, c, exit_num = r+1, c+1, (exit_num+5)%4
        else:
            if r > 1:
                for j, ss in enumerate([[r-1,c], [r,c+1], [r+1,c], [r,c-1], [r,c]]):
                    x, y = ss
                    if j==exit_num: visited[x][y]=2
                    elif j==4: visited[x][y]=3
                    else: visited[x][y]=1
                answer += search(visited, r, c, R, C, idx)
            else: visited = [[0]*C for _ in range(R+2)]
            idx += 1
            break
print(answer)