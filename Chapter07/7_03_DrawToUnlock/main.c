// #include<stdio.h>
// #include<stdlib.h>
// #include<stdbool.h>
// #include<string.h>
// #include<math.h>
// #define LENGTH 3

// bool is_gate(int square[LENGTH][LENGTH], int row_idx, int col_idx);
// int sum_square(int square[LENGTH][LENGTH]);
// int find_routes_rec(int square[LENGTH][LENGTH], int row_idx, int col_idx, int n_gate);
// void print_arr(int square[LENGTH][LENGTH]);

// int main(void)
// {
//     int row_idx = 0;
//     int col_idx = 0;
//     int n_gate = 1;
//     int num_routes;
//     int square[LENGTH][LENGTH];
//     memset(square, 0, sizeof(square));
//     num_routes = find_routes_rec(square, row_idx, col_idx, n_gate);

//     printf("num_routes: %i\n", num_routes);

// }

// bool is_gate(int square[LENGTH][LENGTH], int row_idx, int col_idx)
// {
//     // out of border
//     if ((row_idx < 0) || (row_idx >= LENGTH) || (col_idx < 0) || (col_idx >= LENGTH)){
//         return false;
//     }

//     // is blocked
//     if (square[row_idx][col_idx] != 0){
//         return false;
//     }

//     return true;
// }

// int sum_square(int square[LENGTH][LENGTH])
// {
//     int summary = 0;
//     for (int i=0; i<LENGTH; i++){
//         for (int j=0; j<LENGTH; j++){
//             if (square[i][j] != 0){
//                 summary += 1;
//             }
//         }
//     }
//     return summary;
// }

// int find_routes_rec(int square[LENGTH][LENGTH], int row_idx, int col_idx, int n_gate)
// {   
//     // printf("entering into: (%i, %i)\n", row_idx, col_idx);
//     // buid wall when going through
//     square[row_idx][col_idx] = n_gate;

//     // find next gate (4 directions)
//     int num_routes = 0;
//     bool no_gates = true;
//     int rcis[4][2] = {{row_idx - 1, col_idx}, {row_idx + 1, col_idx}, {row_idx, col_idx - 1}, {row_idx, col_idx + 1}};
//     for (int i=0; i<4; i ++){
//         int ri_search = rcis[i][0];
//         int ci_search = rcis[i][1];
//         if (is_gate(square, ri_search, ci_search)){
//             num_routes += find_routes_rec(square, ri_search, ci_search, n_gate+1);
//             square[ri_search][ci_search] = 0;
//             no_gates = false;
//         }
//     }

//     // return number of possible routes
//     if (no_gates){
//         if (sum_square(square) == pow(LENGTH, 2)){
//             printf("find route!\n");
//             printf("array:\n");
//             print_arr(square);
//             printf("================\n");
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     else{
//         return num_routes;
//     }
// }


// void print_arr(int square[LENGTH][LENGTH])
// {
//     for (int i=0; i<LENGTH; i++){
//         for (int j=0; j<LENGTH; j++){
//             printf("%i", square[i][j]);
//         }
//         printf("\n");
//     }
// }
