from collections import deque

'''
BFS로 바닥판 각 칸의 점수 계산
'''
def fill_score(tx, ty, n):
    visited = score_map.copy()
    direction = [[0,1], [1,0], [0,-1], [-1,0]]
    d, cnt, root, visited[tx][ty] = deque([[tx,ty]]), 1, [(tx, ty)], 1

    while d:
        x, y = d.popleft()

        for mx, my in direction:
            dx, dy = x+mx, y+my

            if 0<=dx<n and 0<=dy<n and not visited[dx][dy] and dice_map[dx][dy] == dice_map[x][y]:
                cnt += 1
                d.append([dx,dy])
                root.append((dx, dy))
                visited[dx][dy] = 1
    
    for dx, dy in root: score_map[dx][dy] = cnt*dice_map[tx][ty]

def solution(n, m):
    direction = [[0,1], [1,0], [0,-1], [-1,0]]
    x, y, d = 0,1,0
    cnt = score_map[x][y]
    up, down, right = 4,2,1

    for _ in range(m-1):
        '''
        <주사위 방향 설정>
        주사위에 깔린 면과 바닥판 값 비교
        '''
        if (7-up) > dice_map[x][y]:
            d = (d+1)%4
        if (7-up) < dice_map[x][y]:
            d = (d+3)%4

        '''
        <좌표 이동>
        주사위가 벽에 튕기지 않는 경우와 튕기는 경우
        '''
        dx, dy = x+direction[d][0], y+direction[d][1]
        if 0<=dx<n and 0<=dy<n:
            cnt += score_map[dx][dy]
            x, y = dx, dy
        else:
            d = (d+2)%4
            x, y = x+direction[d][0], y+direction[d][1]
            cnt += score_map[x][y]
        
        '''
        <주사위 값 재설정>
        '''
        d_up, d_down, d_right = up, down, right

        if d == 0: d_up, d_right = (7-right), up
        elif d == 1: d_up, d_down = (7-down), up
        elif d == 2: d_up, d_right = right, (7-up)
        elif d == 3: d_up, d_down = down, (7-up) 
        
        up, down, right = d_up, d_down, d_right

    return cnt

n, m = map(int, input().split())
dice_map = [list(map(int, input().split())) for _ in range(n)]
score_map = [[0]*n for _ in range(n)]

for tx in range(n):
    for ty in range(n):
        if not score_map[tx][ty]: fill_score(tx,ty,n)

print(solution(n, m))