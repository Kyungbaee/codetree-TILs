from collections import deque

## 하단 이동
def down(visited, r, c, R, C):
    if (r+2<=R+1) and not visited[r+2][c] and not visited[r+1][c-1] and not visited[r+1][c+1]:
        return True
    return False

## 좌측 이동
def left(visited, r, c, R, C):
    if not r and (1<c) and down(visited, r, c-1, R, C):
        return True

    if (1<c) and not visited[r][c-2] and not visited[r-1][c-1] and not visited[r+1][c-1]:
        if down(visited, r, c-1, R, C):
            return True
    return False

## 우측 이동
def right(visited, r, c, R, C):
    if not r and (1<c) and down(visited, r, c-1, R, C):
        return True
        
    if (c<C-2) and not visited[r][c+2] and not visited[r-1][c+1] and not visited[r+1][c+1]:
        if down(visited, r, c+1, R, C):
            return True
    return False

## BFS 탐색
def search(visited, r, c, R, C, idx):
    max_depth = r+1
    move = [[0]*C for _ in range(R+2)]
    deq = deque([[r,c]])
    move[r][c]=1

    while deq:
        x, y = deq.popleft()
        max_depth = max(max_depth, x)

        '''이동한 곳이 골렘의 중앙이거나 출구 일 경우'''
        '''다른 모든 골렘 영역으로 이동 가능'''
        if visited[x][y]==2 or visited[x][y]==3:
            for dx, dy in [[0,1], [1,0], [-1,0], [0,-1]]:
                nx, ny = x+dx, y+dy
                if (2<nx<R+2) and (0<=ny<C) and not move[nx][ny] and visited[nx][ny]:
                    deq.append([nx, ny])
                    move[nx][ny]=1

        '''이동한 곳이 골렘의 일반 영역일 경우'''
        '''골렘의 중앙으로만 이동 가능'''
        if visited[x][y]==1:
            for dx, dy in [[0,1], [1,0], [-1,0], [0,-1]]:
                nx, ny = x+dx, y+dy
                if (2<nx<R+2) and (0<=ny<C) and not move[nx][ny] and visited[nx][ny]==3:
                    deq.append([nx, ny])
                    move[nx][ny]=1

    return max_depth-1

"""
초기 값
R, C : 마법의 숲 행과 열, K : 정령의 수
soul : K개의 골렘이 출발하는 열과 방향 정보
visited : 최종 배치된 골렘의 위치를 담을 리스트
"""

R,C,K = map(int, input().split())
soul = [list(map(int, input().split())) for _ in range(K)]
visited = [[0]*C for _ in range(R+2)]
idx, answer = 0, 0

"""
[골렘 이동]

1. 남쪽 이동 가능 시, 남쪽으로 골렘 이동
2. 남쪽 이동 불가 및 좌측 이동 가능 시, 좌측으로 골렘 이동
3. 우측으로만 이동 가능 시, 우측으로 골렘 이동
4. 골렘 이동 불가 시, 가장 남쪽으로 이동
"""
while(idx<len(soul)):
    c, exit_num = soul[idx]
    c, r, max_depth = c-1, 0, 0

    while(True):
        if down(visited, r, c, R, C): r = r+1
        elif left(visited, r, c, R, C): r, c, exit_num = r+1, c-1, (exit_num+3)%4
        elif right(visited, r, c, R, C): r, c, exit_num = r+1, c+1, (exit_num+5)%4
        else:
            if r > 2:
                for j, ss in enumerate([[r-1,c], [r,c+1], [r+1,c], [r,c-1], [r,c]]):
                    x, y = ss
                    if j==exit_num: visited[x][y]=2     ''' 2: 출구 '''
                    elif j==4: visited[x][y]=3          ''' 3: 골렘의 중앙 '''
                    else: visited[x][y]=1               ''' 1: 출구와 골렘의 중앙을 제외한 골렘 영역'''
                answer += search(visited, r, c, R, C, idx)
            else: visited = [[0]*C for _ in range(R+2)]
            idx += 1
            break
print(answer)