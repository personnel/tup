#ifndef tup_graph_h
#define tup_graph_h

#include "tup/list.h"
#include "tup/tupid.h"

struct edge {
	struct edge *next;
	struct node *dest;
};

#define STATE_INITIALIZED 0
#define STATE_PROCESSING 1
#define STATE_FINISHED 2

#define NODE_FILE 0
#define NODE_CMD 1

struct node {
	struct list_head list;
	struct edge *edges;
	tupid_t tupid;
	int incoming_count;

	char state;
	char type; /* One of TUP_*, must be char (<256) */
	char node; /* One of NODE_* */
	char unused2;
};

struct graph {
	struct list_head node_list;
	struct list_head plist;
	struct node *root;
	int num_nodes;
};

struct node *find_node(const struct graph *g, const tupid_t tupid);
struct node *create_node(const tupid_t tupid);
void remove_node(struct node *n);

int create_edge(struct node *n1, struct node *n2);
struct edge *remove_edge(struct edge *e);

int create_graph(struct graph *g, const tupid_t root);
void dump_graph(const struct graph *g, const char *filename);

#endif
