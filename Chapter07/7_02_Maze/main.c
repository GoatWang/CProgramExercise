#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>
#include<string.h>
#define LINELENGTH 128

typedef struct {
    int row_idx;
    int col_idx;
} Point;
typedef struct {
    int height;
    int width;
} Size;
typedef enum {up, down, left, right} Direction;

void read_maze(char* filename, char maze[][LINELENGTH], Size* size);
void print_maze(char maze[][LINELENGTH]);
void find_entrance(char maze[][LINELENGTH], Point* entrance);
bool is_gate(char maze[][LINELENGTH], Point* point, Size* size);
bool inside_border(int ri, int ci, Size* size);
bool solve_maze_rec(char maze[][LINELENGTH], Point* entrance, Size* size);
void test();

int main(int argc, char* argv[])
{
    test();

    if (argc != 2){
        fprintf(stderr, "please specify the file to read");
        exit(0);
    }

    char* filename = argv[1];
    char maze[LINELENGTH][LINELENGTH];
    memset(maze, '\0', sizeof(maze));
    Size size;
    read_maze(filename, maze, &size);

    Point* entrance=NULL;
    entrance = (Point*) calloc(1, sizeof(Point));
    find_entrance(maze, entrance);
    printf("entrance: %d, %d\n", (int)entrance->row_idx, (int)entrance->col_idx);

    solve_maze_rec(maze, entrance, &size);
    print_maze(maze);

}

void read_maze(char* filename, char maze[][LINELENGTH], Size* size)
{
    FILE* fp = fopen(filename, "r");
    char line[LINELENGTH];
    int line_id = 0;
    fscanf(fp, "%i %i\n", &size->height, &size->width);
    while (fgets(line, LINELENGTH, fp) != NULL){
        strcpy(maze[line_id], line);
        line_id += 1;
    }
    fclose(fp);
}
void print_maze(char maze[][LINELENGTH])
{
    int line_id = 0;
    while (maze[line_id][0] != '\0'){
        printf("%s", maze[line_id]);
        line_id += 1;
    }
}

void find_entrance(char maze[][LINELENGTH], Point* entrance)
{
    int row_id = 0;
    bool found = false;
    while (maze[row_id][0] != '\0'){
        int col_id = 0;
        while (maze[row_id][col_id] != '\0'){
            if ((maze[row_id][col_id] == ' ') && (!found)){
                entrance->row_idx = row_id;
                entrance->col_idx = col_id;
                found = true;
            }
            col_id += 1;
        }
        row_id += 1;
    }
}

bool inside_border(int ri, int ci, Size* size)
{
    if ((ri >= 0) && (ri < size->height) && (ci >= 0) && (ri < size->width)){
        return true;
    }
    return false;
}

bool is_gate(char maze[][LINELENGTH], Point* point, Size* size)
{
    int i = point->row_idx;
    int j = point->col_idx;
    if (inside_border(i, j, size)){
        if (maze[i][j] == ' '){
            return true;
        }
    }
    return false;
}

bool solve_maze_rec(char maze[][LINELENGTH], Point* entrance, Size* size)
{
    int ri = entrance->row_idx;
    int ci = entrance->col_idx;
    bool solved = false;
    // maze[ri][ci] = '-';

    // four directions with x and y
    int test_points[4][2] = {{ri-1, ci}, {ri, ci-1}, {ri+1, ci}, {ri, ci+1}};
    for (int i=0; i<4; i++){
        if (!solved){
            Point test_point;
            test_point.row_idx = test_points[i][0];
            test_point.col_idx = test_points[i][1];
            if (is_gate(maze, &test_point, size)){
                maze[test_point.row_idx][test_point.col_idx] = '-';
                if (test_points[i][1] == size->width-1){
                    solved = true;
                }else{
                    solved = solve_maze_rec(maze, &test_point, size);
                }

                if (solved){
                    maze[test_point.row_idx][test_point.col_idx] = '*';
                }else{
                    maze[test_point.row_idx][test_point.col_idx] = ' ';
                }
                print_maze(maze);
                printf("=========\n");
            }
        }
    }
    return solved;
}

void test()
{
    char* filename = "Mazes/maze.txt";
    char maze[LINELENGTH][LINELENGTH];
    memset(maze, '\0', sizeof(maze));
    Size size;
    read_maze(filename, maze, &size);

    Point entrance;
    find_entrance(maze, &entrance);
    assert(entrance.row_idx == 1);
    assert(entrance.col_idx == 0); 

}

