# 프로그래머스 코딩테스트 연습 > 2021 Dev Matching 상반기 > 행렬 테두리 회전하기
# https://programmers.co.kr/learn/courses/30/lessons/77485

def solution(rows, columns, queries):
    answer = []
    board = [[(i+1) + ((j) * columns) for i in range(columns)] for j in range(rows)]
    
    for i in range(len(queries)):
        x1, y1, x2, y2 = queries[i][0] - 1, queries[i][1] - 1, queries[i][2] - 1, queries[i][3] - 1
        rotateList = []
        # x1 ~ x2 : 세로
        # y1 ~ y2 : 가로
        rotateList.insert(0)
        temp = board[x1][y1]
        for j in range(x1, x2):
            board[j][y1] = board[j+1][y1]
            rotateList.append(board[j+1][y1])
        
        for j in range(y1, y2):
            board[x2][j] = board[x2][j+1]
            rotateList.append(board[x2][j+1])
            
        for j in range(x2, x1, -1):
            board[j][y2] = board[j-1][y2]
            rotateList.append(board[j-1][y2])
        
        for j in range(y2, y1 + 1, -1):
            board[x1][j] = board[x1][j-1]
            rotateList.append(board[x1][j-1])
                    
        board[x1][y1+1] = temp
        rotateList.append(temp)
        answer.append(min(rotateList))
        
    return answer

print(solution(6,6,[[2,2,5,4],[3,3,6,6],[5,1,6,3]]))
print(solution(3,3,[[1,1,2,2],[1,2,2,3],[2,1,3,2],[2,2,3,3]]))
print(solution(100,97,[[1,1,100,97]]))
print(solution(20,10,[[2,2,3,3],[3,3,4,10],[1,1,20,10]]))