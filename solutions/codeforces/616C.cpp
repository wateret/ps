#include <stdio.h>

void push_to_stacks(char * row_stack, char * col_stack, int row, int col, int *top) {
    row_stack[*top] = row;
    col_stack[*top] = col;
    *top += 1;
}

int main(int argc, const char * argv[]) {
    //stack
    char impassable_stack_row[1100*1100] = {0, };
    char impassable_stack_col[1100*1100] = {0, };
    int impassable_stack_top = 0;
    
    
    //map
    char maze[1100][1100] = {0, };
    char visited_maze[1100][1100] = {0, };
    int ROW, COL;
    
    //loop
    int i, j;
    char stack_row[1100*1100] = {0, };
    char stack_col[1100*1100] = {0, };
    int stack_top = 0;

    //target
    int cur_row;
    int cur_col;
    int __row;
    int __col;
    int count;
    
    scanf("%d %d", &ROW, &COL);
    
    
    for( i = 0 ; i < ROW; i++ ) {
        scanf("%s", maze[i]);
    }
    
    //find impassable
    for( i = 0 ; i < ROW ; i++ ) {
        for( j = 0 ; j < COL ; j++ ) {
            if(maze[i][j] == '*') {
                impassable_stack_row[impassable_stack_top] = i;
                impassable_stack_col[impassable_stack_top] = j;
                impassable_stack_top++;
            }
        }
    }

   
    while(impassable_stack_top > 0) {
        //begin
        __row = impassable_stack_row[--impassable_stack_top];
        __col = impassable_stack_col[impassable_stack_top];
        
        stack_top = 0;
        count = 0;
        
        for(i = 0 ; i < ROW ; i++ ) {
            for(j = 0 ; j < COL ; j++ ) {
                visited_maze[i][j] = 0;
            }
        }
        
        push_to_stacks(stack_row, stack_col, __row, __col, &stack_top);
        count++;
        visited_maze[__row][__col] = -1;
        
        while(stack_top > 0) {
            cur_row = stack_row[--stack_top];
            cur_col = stack_col[stack_top];
            
            if(cur_row - 1 >= 0 && maze[cur_row - 1][cur_col] == '.' && visited_maze[cur_row - 1][cur_col] != -1) {
                push_to_stacks(stack_row, stack_col, cur_row -1, cur_col, &stack_top);
                count++;
                visited_maze[cur_row - 1][cur_col] = -1;
            }
            if(cur_row + 1 < ROW && maze[cur_row + 1][cur_col] == '.' && visited_maze[cur_row + 1][cur_col] != -1) {
                push_to_stacks(stack_row, stack_col, cur_row +1, cur_col, &stack_top);
                count++;
                visited_maze[cur_row + 1][cur_col] = -1;
            }
            if(cur_col - 1 >= 0 && maze[cur_row][cur_col - 1] == '.'  && visited_maze[cur_row][cur_col - 1] != -1) {
                push_to_stacks(stack_row, stack_col, cur_row, cur_col - 1, &stack_top);
                count++;
                visited_maze[cur_row][cur_col - 1] = -1;
            }
            if(cur_col + 1 < COL && maze[cur_row][cur_col + 1] == '.'  && visited_maze[cur_row][cur_col + 1] != -1) {
                push_to_stacks(stack_row, stack_col, cur_row, cur_col + 1, &stack_top);
                count++;
                visited_maze[cur_row][cur_col + 1] = -1;
            }
        }
        maze[__row][__col] = count%10 + '0';
    }
    
    for( i = 0 ; i < ROW ; i++ ) {
        printf("%s\n", maze[i]);
    }
    
    return 0;
}