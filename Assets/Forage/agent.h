/* agent.h */

int init_agent(int n);
int agent_decide(int n);
int agent_act(int n, int step);
void sort_agents();
void print_agents();
void update_current_map(int n, int step);
int update_memory(int n, int success);
void agent_stats();
