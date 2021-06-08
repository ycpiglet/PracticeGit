
#define MAX 1
#define MIN 2
#define LIMIT 2//
//14설정시 실제 16단계 까지 늘어지며 늘이는데 2분49초 찾는데 10초 안쪽.
//확장노드 깊이 제한 15설정시 실제 17단계까지 늘어지며 늘이는데 5분 50초 찾는데 4초 안쪽.찾는시간 2초안쪽.
#define spread() srand((unsigned)time(NULL))	//spead rand() ;


typedef struct _node{


	int see[LIMIT]; //포지션 마지막 인덱스가 마지막에 놓여진점. 최대  LIMIT 까지 확장할것이기때문에 10수만 저장함.
    //노드의 크기 감소 위해서 x 는 *100 y 는 그대로
	//좌표 받아와서 돌을 둘때는 x 를 100으로 나누고 y 는 100으로 나눈 나머지를 사용한다.
	int value; // 판에 대한 평가치
	int depth; // 노드 깊이 : 시간제한이나 과도한 확장을 막기위해 깊이 값을 저장해줌. 
	struct _node *parent_move; //부모 노드 주소
	struct _node *sister_move; //형제 노드 주소
	struct _node *headChild_move; //자식중 첫번째 노드 주소


}node;

void MinMax (node *move,int alpha, int beta);
void MaxMove(node *move,int alpha, int beta);
void MinMove(node *move,int alpha, int beta);
void GenerateMoves(node *p_move);//, const int& index, node *_move);

node *get_endNode(node *move);

static struct _node *endHeadNode=NULL;

static const int Random[10] = {12,4,9,5,2,16,13,18,7,9};
static int ran = 0;

static const int INFINITY = 1000000; 
