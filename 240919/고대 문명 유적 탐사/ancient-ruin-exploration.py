from collections import deque

## [1] 탐사 진행 - 회전
def turn(relics, tx, ty, pos):
    turn_relics = [r.copy() for r in relics]
    rotate = [[-1,-1], [-1,0], [-1,1], [0,-1], [0,0], [0,1], [1,-1], [1,0], [1,1]]
    
    for idx, p in enumerate(pos):
        x, y = rotate[idx][0]+tx, rotate[idx][1]+ty
        dx, dy = rotate[p-1][0]+tx, rotate[p-1][1]+ty
        turn_relics[x][y] = relics[dx][dy]

    return turn_relics

## [1] 탐사 진행
def turn_relic(relics, position):
    turn_point = [[x,y] for x in range(1,4) for y in range(1,4)]
    max_cnt, degree, x, y = 0, 3, 0, 0

    for tx, ty in turn_point:
        for deg in range(len(position)):
            turn_relics = turn(relics, tx, ty, position[deg])
            cnt, _ = get_relic(turn_relics) ## 1차 유물 획득

            if max_cnt < cnt:
                max_cnt = cnt
                degree = deg
                x, y = tx, ty

            elif max_cnt == cnt:
                max_cnt = cnt

                if degree > deg:
                    degree = deg
                    x, y = tx, ty
                
    return degree, x, y

## [2] 유물 획득 - 벽면 숫자 채우기
def fill_relic(relics, piece_num, mining_root):
    for r in mining_root:
        relics[r[0]][r[1]] = piece_num.popleft()
    return


## [2] 유물 획득
def get_relic(relics):
    cnt, total_root, visited = 0, [], [[0]*5 for _ in range(5)]
    d = [[0,1], [1,0], [0,-1], [-1,0]]

    for x in range(5):
        for y in range(5):
            if visited[x][y]: continue

            relic, deq, r_cnt, root = relics[x][y], deque([[x,y]]), 1, [[x,y]]
            visited[x][y] = r_cnt

            while deq:
                i, j = deq.popleft()

                for dx, dy in d:
                    nx, ny = i+dx, j+dy
                    if 0<=nx<5 and 0<=ny<5 and relics[nx][ny]==relic and not visited[nx][ny]:
                        r_cnt += 1
                        deq.append([nx, ny])
                        visited[nx][ny] = r_cnt
                        root.append([nx, ny])

            if r_cnt >= 3:
                total_root += root
                cnt += r_cnt

    return cnt, sorted(total_root, key=lambda x:(x[1], -x[0]))

K, M = map(int, input().split())
relics = [list(map(int, input().split())) for _ in range(5)]
piece_num = deque(map(int, input().split()))
position = [[7,4,1,8,5,2,9,6,3], [9,8,7,6,5,4,3,2,1], [3,6,9,2,5,8,1,4,7]]

for _ in range(K):
    answer = 0

    deg, x, y = turn_relic(relics, position)
    relics = turn(relics, x, y, position[deg])
    cnt, mining_root = get_relic(relics)
    fill_relic(relics, piece_num, mining_root)
    answer += cnt

    while cnt>0:
        cnt, mining_root = get_relic(relics)
        fill_relic(relics, piece_num, mining_root)
        answer += cnt

    if answer: print(answer, end=' ')