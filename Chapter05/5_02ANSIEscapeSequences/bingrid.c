#include "bingrid.h"
#define BOARDSTR (MAX*MAX+1)
#include "neillsimplescreen.h"

bool idx_in_board(int idx, int sz);
int check_pairs_and_decide_value(int i1, int i2);
bool check_pairs_set_value(int i, int j, board* brd);
bool check_OXO_set_value(int i, int j, board* brd);
bool fill_in_row(board* brd, int i, char fill_in);
bool fill_in_col(board* brd, int j, char fill_in);
bool solve_board_pair(board* brd);
bool solve_board_OXO(board* brd);
bool solve_board_counting(board* brd);
bool is_valid(board* brd);
bool contains_unknown(board* brd);

bool str2board(board* brd, char* str);
void board2str(char* str, board* brd);
bool solve_board(board* brd);
void printboard(board* brd);
void test(void);


bool idx_in_board(int idx, int sz)
{
   if (idx < 0){
      return false;
   }
   if (idx >= sz){
      return false;
   }
   return true;
}

int check_pairs_and_decide_value(int i1, int i2)
{
   if ((i1 == ONE) && (i2 == ONE)){
      return ZERO;
   }
   else if ((i1 == ZERO) && (i2 == ZERO)){
      return ONE;
   }
   else{
      return UNK;
   }
}

// check pairs rule for a cell on 4 directions
bool check_pairs_set_value(int i, int j, board* brd)
{
   // up direction
   if (idx_in_board(i-2, brd->sz)){
      char set_value = check_pairs_and_decide_value(brd->b2d[i-2][j], brd->b2d[i-1][j]);
      if (set_value != UNK){
         brd->b2d[i][j] = set_value;
         return true;
      }
   }

   // down direction
   if (idx_in_board(i+2, brd->sz)){
      char set_value = check_pairs_and_decide_value(brd->b2d[i+1][j], brd->b2d[i+2][j]);
      if (set_value != UNK){
         brd->b2d[i][j] = set_value;
         return true;
      }
   }

   // left direction
   if (idx_in_board(j-2, brd->sz)){
      char set_value = check_pairs_and_decide_value(brd->b2d[i][j-1], brd->b2d[i][j-2]);
      if (set_value != UNK){
         brd->b2d[i][j] = set_value;
         return true;
      }
   }

   // right direction
   if (idx_in_board(j+2, brd->sz)){
      char set_value = check_pairs_and_decide_value(brd->b2d[i][j+1], brd->b2d[i][j+2]);
      if (set_value != UNK){
         brd->b2d[i][j] = set_value;
         return true;
      }
   }
   return false;
}

// check OXO rule for a cell on vertical and horizontal axis
bool check_OXO_set_value(int i, int j, board* brd)
{
   // vertical
   if (idx_in_board(i-1, brd->sz) && idx_in_board(i+1, brd->sz)){
      char set_value = check_pairs_and_decide_value(brd->b2d[i-1][j], brd->b2d[i+1][j]);
      if (set_value != UNK){
         brd->b2d[i][j] = set_value;
         return true;
      }
   }

   // horizontal
   if (idx_in_board(j-1, brd->sz) && idx_in_board(j+1, brd->sz)){
      char set_value = check_pairs_and_decide_value(brd->b2d[i][j-1], brd->b2d[i][j+1]);
      if (set_value != UNK){
         brd->b2d[i][j] = set_value;
         return true;
      }
   }
   return false;
}

bool fill_in_row(board* brd, int i, char fill_in)
{
   bool change = false;
   for (int j=0; j<brd->sz; j++){
      if ((brd->b2d[i][j] == UNK) && (brd->b2d[i][j] != fill_in)){
         brd->b2d[i][j] = fill_in;
         change = true;
      }
   }
   return change;
}

bool fill_in_col(board* brd, int j, char fill_in)
{
   bool change = false;
   for (int i=0; i<brd->sz; i++){
      if ((brd->b2d[i][j] == UNK) && (brd->b2d[i][j] != fill_in)){
         brd->b2d[i][j] = fill_in;
         change = true;
      }
   }
   return change;
}

bool solve_board_pair(board* brd)
{
   bool change = false;
   for (int i=0; i<brd->sz; i++){
      for (int j=0; j<brd->sz; j++){
         if (brd->b2d[i][j] == UNK){
            if (check_pairs_set_value(i, j, brd)){
               change = true;
            }
         }
      }
   }
   return change;
}

bool solve_board_OXO(board* brd)
{
   bool change = false;
   for (int i=0; i<brd->sz; i++){
      for (int j=0; j<brd->sz; j++){
         if (brd->b2d[i][j] == UNK){
            if (check_OXO_set_value(i, j, brd)){
               change = true;
            }
         }
      }
   }
   return change;
}

bool solve_board_counting(board* brd)
{
   bool change = false;
   
   // filter by row: calculate amount of ones or zeors in a row
   for (int i=0; i<brd->sz; i++){
      int one_count = 0;
      int zero_count = 0;
      for (int j=0; j<brd->sz; j++){
         if (brd->b2d[i][j] == ONE){
            one_count += 1;      
         }
         else if (brd->b2d[i][j] == ZERO){
            zero_count += 1;      
         }
      }

      if (one_count == (brd->sz/2)){
         change = fill_in_row(brd, i, ZERO);
      }

      if (zero_count == (brd->sz/2)){
         change = fill_in_row(brd, i, ONE);
      }
   }

   // filter by col: calculate amount of ones or zeors in a col
   for (int j=0; j<brd->sz; j++){
      int one_count = 0;
      int zero_count = 0;
      for (int i=0; i<brd->sz; i++){
         if (brd->b2d[i][j] == ONE){
            one_count += 1;      
         }
         else if (brd->b2d[i][j] == ZERO){
            zero_count += 1;      
         }
      }

      if (one_count == (brd->sz/2)){
         change = fill_in_col(brd, j, ZERO);
      }

      if (zero_count == (brd->sz/2)){
         change = fill_in_col(brd, j, ONE);
      }
   }
   return change;
}

bool is_valid(board* brd)
{
   // check amount of ones or zeors in a row
   for (int i=0; i<brd->sz; i++){
      int one_count = 0;
      int zero_count = 0;
      for (int j=0; j<brd->sz; j++){
         if (brd->b2d[i][j] == ONE){
            one_count += 1;      
         }
         else if (brd->b2d[i][j] == ZERO){
            zero_count += 1;      
         }
      }

      if ((one_count > (brd->sz/2)) || (zero_count > (brd->sz/2))){
         return false;
      }
   }

   // check amount of ones or zeors in a col
   for (int j=0; j<brd->sz; j++){
      int one_count = 0;
      int zero_count = 0;
      for (int i=0; i<brd->sz; i++){
         if (brd->b2d[i][j] == ONE){
            one_count += 1;      
         }
         else if (brd->b2d[i][j] == ZERO){
            zero_count += 1;      
         }
      }

      if ((one_count > (brd->sz/2)) || (zero_count > (brd->sz/2))){
         return false;
      }
   }

   //continuous horizontal three ones (or zeros) test (by applying 1*3 convolution)
   for (int i=0; i<brd->sz; i++){
      for (int j=0; j<brd->sz-2; j++){
         char v1, v2, v3;
         v1 = brd->b2d[i][j];
         v2 = brd->b2d[i][j+1];
         v3 = brd->b2d[i][j+2];
         if ((v1 == ONE) && (v2 == ONE) && (v3 == ONE)){
            return false;
         }
         if ((v1 == ZERO) && (v2 == ZERO) && (v3 == ZERO)){
            return false;
         }
      }
   }

   //continuous vertical three ones (or zeros) test (by applying 3*1 convolution)
   for (int i=0; i<brd->sz-2; i++){
      for (int j=0; j<brd->sz; j++){
         char v1, v2, v3;
         v1 = brd->b2d[i][j];
         v2 = brd->b2d[i+1][j];
         v3 = brd->b2d[i+2][j];
         if ((v1 == ONE) && (v2 == ONE) && (v3 == ONE)){
            return false;
         }
         if ((v1 == ZERO) && (v2 == ZERO) && (v3 == ZERO)){
            return false;
         }
      }
   }
   return true;
}

bool contains_unknown(board* brd)
{
   for (int i=0; i<brd->sz; i++){
      for (int j=0; j<brd->sz; j++){
         if (brd->b2d[i][j] == UNK){
            return true;
         }
      }
   }   
   return false;
}

bool str2board(board* brd, char* str)
{
   int length = strlen(str);
   double side_length_double = sqrt((double) length);
   int side_length = (int) side_length_double;
   // check is integer (not double)
   if ((side_length_double - side_length) > 0){
         return false;
   }
   if ((side_length % 2) == 1){
      return false;
   }
   if ((side_length <= 0) || (side_length > MAX)){
      return false;
   }

   brd->sz = side_length;
   for (int i=0; i<brd->sz; i++){
      for (int j=0; j<brd->sz; j++){
         brd->b2d[i][j] = str[((i * brd->sz) + j)];
      }
   }
   return true;
}

void board2str(char* str, board* brd)
{
   for (int i=0; i<brd->sz; i++){
      for (int j=0; j<brd->sz; j++){
         str[((i * brd->sz) + j)] = brd->b2d[i][j];
      }
   }
   str[((int) pow(brd->sz, 2))] = '\0';
}

bool solve_board(board* brd)
{
   bool continue_solving = true;
   while (continue_solving){
      bool change = false;

      if (solve_board_pair(brd)){
         change = true;
      }

      if (solve_board_OXO(brd)){
         change = true;
      }

      if (solve_board_counting(brd)){
         change = true;
      }

      printboard(brd);
      continue_solving = contains_unknown(brd);
      if (!change && continue_solving){
         return false;
      }
   }

   if (!is_valid(brd)){
      return false;
   }
   return true;
}

void printboard(board* brd)
{
   neillclrscrn();
   neillcursorhome();

   // print column indeices, %10 is just for formating
   neillbgcol(white);
   printf("%2i ", -1);
   for (int j=0; j<brd->sz; j++){
      printf("%3d", j%10);
   }
   printf("\n");

   for (int i=0; i<brd->sz; i++){
      printf("%2i ", i);
      for (int j=0; j<brd->sz; j++){
         if (brd->b2d[i][j] == '.'){
            neillfgcol(red);
            neillbgcol(white);
         }
         else{
            neillfgcol(white);
            neillbgcol(red);
         }
         printf("%3c", brd->b2d[i][j]);
      }
      neillbgcol(white);
      printf("\n");
   }
   neillbusywait(0.3);
}

void test(void)
{
   // self test
   board brd;
   char str[BOARDSTR];

   // test str2board & board2str
   assert(str2board(&brd, "...1.0......1..1"));
   board2str(str, &brd);
   assert(strcmp(str, "...1.0......1..1") == 0);

   // test check_pairs_set_value (1: left)
   str2board(&brd, "..11........1..1");
   assert(check_pairs_set_value(0, 1, &brd));
   board2str(str, &brd);
   assert(strcmp(str, ".011........1..1") == 0);

   // test check_pairs_set_value (2: top)
   str2board(&brd, "....1...1......1");
   assert(check_pairs_set_value(0, 0, &brd));
   board2str(str, &brd);
   assert(strcmp(str, "0...1...1......1") == 0);

   // test solve_board_pair (1: left)
   str2board(&brd, "..11........1..1");
   assert(solve_board_pair(&brd));
   board2str(str, &brd);
   assert(strcmp(str, ".011........1..1") == 0);

   // test solve_board_pair (2: top)
   str2board(&brd, "....1...1......1");
   assert(solve_board_pair(&brd));
   board2str(str, &brd);
   assert(strcmp(str, "0...1...1...0..1") == 0);

   // test check_OXO_set_value (1: horizontal)
   str2board(&brd, ".1.1........1..1");
   assert(check_OXO_set_value(0, 2, &brd));
   board2str(str, &brd);
   assert(strcmp(str, ".101........1..1") == 0);

   // test check_OXO_set_value (2: vertical)
   str2board(&brd, "...1.......1....");
   assert(check_OXO_set_value(1, 3, &brd));
   board2str(str, &brd);
   assert(strcmp(str, "...1...0...1....") == 0);

   // test check_OXO_set_value (1: horizontal)
   str2board(&brd, ".1.1........1..1");
   assert(solve_board_OXO(&brd));
   board2str(str, &brd);
   assert(strcmp(str, ".101........1..1") == 0);

   // test check_OXO_set_value (2: vertical)
   str2board(&brd, "...1.......1....");
   assert(solve_board_OXO(&brd));
   board2str(str, &brd);
   assert(strcmp(str, "...1...0...1....") == 0);

   // test solve_board_counting
   str2board(&brd, "..11.......1....");
   assert(solve_board_counting(&brd));
   board2str(str, &brd);
   assert(strcmp(str, "0011...0...1...0") == 0);

   // test is_valid
   str2board(&brd, ".111.......1....");
   assert(is_valid(&brd) == false);

   // test is_valid
   str2board(&brd, "..111..........1..........................");
   assert(is_valid(&brd) == false);

   // test contains_unknown true
   str2board(&brd, "001111000011110.");
   assert(contains_unknown(&brd) == true);

   // test contains_unknown false
   str2board(&brd, "0011110000111100");
   assert(contains_unknown(&brd) == false);
}
