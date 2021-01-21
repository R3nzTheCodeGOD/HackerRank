from copy import deepcopy

DIRECTIONS = ['UP', 'LEFT', 'RIGHT', 'DOWN']
MOVES = {'UP':[-1, 0], 'LEFT':[0, -1], 'RIGHT':[0, 1], 'DOWN':[1, 0]}
ROWS, COLUMNS = 0, 0

def move_next(grid, coordinate):
    next_moves = []
    for direction in DIRECTIONS:
        next_x, next_y = coordinate['x'] + MOVES[direction][0], coordinate['y'] + MOVES[direction][1]
        if next_x < 0 or next_x >= ROWS or next_y < 0 or next_y >= COLUMNS:
            continue
        if grid[next_x][next_y] == '-' or grid[next_x][next_y] == '.':
            grid[next_x][next_y] = '='
            next_moves.append(dict(x=next_x, y=next_y))
    return next_moves

def bfs(grid, source, goal):
    queue = [[source, []]]
    nodes_explored, path = [], None
    while queue:
        coordinate, previous_path = queue.pop(0)
        current_path = deepcopy(previous_path)
        current_path.append(coordinate)
        nodes_explored.append(coordinate)
        if coordinate == goal:
            if path is None:
                path = current_path
                break
        queue += [[node, current_path] for node in move_next(grid, coordinate)]
    return nodes_explored, path

def main():
    pacman_row, pacman_column = map(int, input().strip().split())
    food_row, food_column = map(int, input().strip().split())
    global ROWS, COLUMNS
    ROWS, COLUMNS = map(int, input().strip().split())

    grid = []
    for _ in range(ROWS):
        grid.append(list(input().strip()))

    source = dict(x=pacman_row, y=pacman_column)
    goal = dict(x=food_row, y=food_column)
    nodes_explored, path = bfs(grid, source, goal)

    print(len(nodes_explored))
    for node in nodes_explored:
        print(node['x'], node['y'])

    print(len(path) - 1)
    for node in path:
        print(node['x'], node['y'])

if __name__ == '__main__':
    main()