/* map.h */

int move_agent();
void move_from_NW(int n);
void move_from_NE(int n);
void move_from_SE(int n);
void move_from_SW(int n);
void move_from_east(int n);
void move_from_south(int n);
void move_from_west(int n);
void move_from_north(int n);
void move_from_four(int n);
int choose_from_two(double zero, double one);
int choose_from_three(double zero, double one, double two);
int choose_from_four(double zero, double one, double two, double three);
int choose_proportional_two(double zero, double one);
int choose_proportional_three(double zero, double one, double two);
int choose_proportional_four(double zero, double one, double two, double three);
void init_current_map(int n);
void print_current_map(int n);
void print_memory_map(int n);
void fprint_memory_map(FILE *fp, int n);
int choose_rank_two(double zero, double one);
int choose_rank_three(double zero, double one, double two);
void get_order_three(double zero, double one, double two, int *order);
int choose_rank_four(double zero, double one, double two, double three);
void get_order_four(double zero, double one, double two, double three, int *order);
