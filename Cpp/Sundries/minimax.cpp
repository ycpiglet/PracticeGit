#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <windows.h>
#include <iostream>
#include <string> 
#include <ctime>
#include <list>
#include "main.h"

using namespace std ;


int main(void) {


	node *root = new node ;	//root 노드 생성 후

	root->depth = 0;	//값을 줌
	root->parent_move = NULL;

	node* tail = new _node;

		tail->sister_move = NULL;
		tail->parent_move = NULL;
		tail->headChild_move = NULL;

		root->sister_move = tail;

	spread();
	GenerateMoves(root);//노드를 생성하고.일단 한번만

	
	node* rootendNode = new node;
	rootendNode = get_endNode(root);//바닥을 가르키게 하고.
	
	MinMax(rootendNode->parent_move,-INFINITY,INFINITY);//민맥스를 실행하면 뎁스의 단계마다 맥스나 민을 실행.

	// int value = root->value;
	//	cout<<value<<endl;

return 0 ;
}

void MinMax(node *move , int alpha, int beta)
{
	node *p_move = new node;
	p_move = move;
	if( p_move==NULL)
	{	cout<< "루트가 아닌부분에서 오류 발생했음";	
		return;
	}

	if ((move->depth)%2==0)
		MaxMove(p_move,alpha,beta);
	else
		MinMove(p_move,alpha,beta);

}

void MaxMove (node *move, int alpha, int beta) 
{

	int best_value = -INFINITY;
	
	int a , b;
	a = alpha;
	b = beta;

	node *c_node = move->headChild_move;
	
	if(c_node==NULL)//더이상 늘여지지 않아서 하위노드에 찾을것이 없으면
	{
		node* endNode = new node;
		endNode = get_endNode(move->sister_move);//옆노드의 바닥을 찾고
		MinMax(endNode->parent_move,a,INFINITY);

	}


	cout<<"맥스의 실행"<<endl;
	
	int i = 0;
	
	while(c_node->sister_move!=NULL)
	{
		//cout<<i<<"th 값= " <<c_node->value<<"best : "<<best_value;
		//cout<<i<<"th 주소= " <<&c_node<<"  x_best : "<<best_value;
		cout<<c_node->depth<<"뎁스 "<<i<</*"th 주소= " <<&c_node<<*/"  "<<i<<"번째원소 : "<<  c_node->value;
		i++;
		if(c_node->value>best_value)
			best_value = c_node->value;
		if(c_node->value > b) //베타 값보다 크면 
		{
			cout<<endl<<"//beta cutoff//"<<endl;
			break;
		}
		cout<<"   best : "<<best_value<<endl;

		c_node = c_node->sister_move;
	}

		move->value = best_value;//확장된 노드중 최고값을 현재노드에 입력한다.
		cout<<"부모노드 선택값"<<move->value<<endl;
		if(move->value<b)
		{
			b = move->value;
			cout<<"beta 교체"<<endl;
		}
		cout<<"a:"<<a<<" b:"<<b<<endl<<endl;
		if(move->parent_move==NULL)
		{
			cout<<endl<<"root에 최종적으로 들어가는 값은 "<<move->value<<"입니다"<<endl;
			move->pos[0];
			return ;//exit(0);
		
		}
		else if (move->value < a)//현재 선택값이 알파보다 작으면 현재 뎁스에서 선택되도 위에서 안되므로 그냥 부모 노드 값에 지금 값을 넣고 
		{
			cout<<"//연속alpha cutoff//"<<endl;

			move->parent_move->value = move->value;//부모 노드에 밸류 값을 넣어주고 부모널은 위에서 걸렀고
			if(move->parent_move->sister_move->sister_move!=NULL)//옆에 있으면 옆으로 민맥스 
			{
				node* endNode = new node;
				endNode = get_endNode(move->parent_move->sister_move);//옆노드의 바닥을 찾고
				MinMax(endNode->parent_move,a,INFINITY);
			}
			else if(move->parent_move->sister_move->sister_move==NULL)
				if (move->parent_move->parent_move!=NULL)
					MinMax(move->parent_move->parent_move,a,b);
				else
				{
					cout<<endl<<"root에 최종적으로 들어가는 값은 "<<move->value<<"입니다"<<endl;
					return ;
				}
		}

		else if(move->sister_move->sister_move!=NULL&&move->sister_move->headChild_move!=NULL)//옆의 노드가 널이 아니면 
		{	
				node* endNode = new node;
				endNode = get_endNode(move->sister_move);//옆노드의 바닥을 찾고
				MinMax(endNode->parent_move,-INFINITY,b);//옆에가서 민맥스 할때는 바닥부터 시작
				//return;//추가로 붙인 리턴
		}


		else if(move->sister_move->sister_move==NULL&&move->parent_move!=NULL)//옆의 노드가 널이면 (tail이면)위로 올라가서 해당 작업수행 
		{
			MinMax(move->parent_move,a,b);//위로 올라가서 민맥스 할땐 후계노드
			//return;//추가로 붙인 리턴
		}
		
	return;

}


void MinMove (node *move, int alpha, int beta) 
{	
	int best_value = INFINITY;
	int a , b;
	a = alpha;
	b = beta;
	
	node *c_node = move->headChild_move;

	if(c_node==NULL)//더이상 늘여지지 않아 하위노드에 찾을것이 없으면
	{
		node* endNode = new node;
		endNode = get_endNode(move->sister_move);//옆노드의 바닥을 찾고
		MinMax(endNode->parent_move,a,INFINITY);

	}

	cout<<"민의 실행"<<endl;
	
	int i = 0;
	
	while(c_node->sister_move!=NULL)//
	{
		//cout<<i<<"th 값= " <<c_node->value<<"best : "<<best_value;
		//cout<<i<<"th 주소= " << c_node<<"  x_best : "<<best_value;
		cout<<c_node->depth<<"뎁스 "<<i<</*"th 주소= " <<&c_node<<*/"  "<<i<<"번째원소 : "<<  c_node->value;
		i++;
		if(c_node->value<best_value)
			best_value = c_node->value;
		if(c_node->value < a) //
		{
			cout<<endl<<"//alpha cutoff//"<<endl;
			break;
		}
		cout<<"   best : "<<best_value<<endl;
		c_node = c_node->sister_move;
	}

		move->value = best_value;//확장된 노드중 최고값을 현재노드에 입력한다.
		cout<<"부모노드 선택값"<<move->value<<endl;
		if(move->value>a)
		{	
			a = move->value;
			cout<<"alpha 교체"<<endl;
		}
		
		cout<<"a:"<<a<<" b:"<<b<<endl<<endl;

		if (move->value > b)//현재 선택값이 알파보다 작으면 현재 뎁스에서 선택되도 위에서 안되므로 그냥 부모 노드 값에 지금 값을 넣고 
		{
			cout<<"//연속beta cutoff//"<<endl;
			move->parent_move->value = move->value;//부모 노드에 밸류 값을 넣어주고 부모널은 위에서 걸렀고
			if(move->parent_move->sister_move->sister_move!=NULL)//옆에 있으면 옆으로 민맥스 
			{
				node* endNode = new node;
				endNode = get_endNode(move->parent_move->sister_move);//옆노드의 바닥을 찾고
				MinMax(endNode->parent_move,-INFINITY,b);
			}
			else if(move->parent_move->sister_move->sister_move==NULL)
			{
				if (move->parent_move->parent_move!=NULL)
					MinMax(move->parent_move->parent_move,a,b);
				else
				{
					cout<<endl<<"root에 들어가는 값은 "<<move->value<<"입니다"<<endl;
	
					return ;
				}
			}
		}

		else if(move->sister_move->sister_move!=NULL&&move->sister_move->headChild_move!=NULL)//옆의 노드가 널이 아니면 
		{	
				node* endNode = new node;
				endNode = get_endNode(move->sister_move);//옆노드의 바닥을 찾고
				MinMax(endNode->parent_move,a,INFINITY);//옆에가서 민맥스 할때는 바닥부터 시작
		}

		else if(move->sister_move->sister_move==NULL&&move->parent_move!=NULL)//옆의 노드가 널이면 (tail이면)위로 올라가서 해당 작업수행 
		{
			//위로 올라가서 민맥스 할땐 옆노드가 널이고 현단계를 모드 거쳤으므로
			MinMax(move->parent_move,a,b);
		}
	
	return;

}


void GenerateMoves(node *p_move)//, const int& index, node *_move) {
{
	//spread();
	int index =rand() % 3+1; //1에서부터 4까지 랜덤 수 만들기
	//if(index == 0)
	//{
	//	p_move->headChild_move=NULL;
	//	cout<<"3번에서 넘겨줌";
	//	return;
	//}

	node *_move = new node[index];
	
	for (int i = 0 ; i <index ; i++)
	{	
		cout<<p_move->depth+1<<"-"<<i<<"th node  ";
		_move[i].depth = p_move->depth+1;

		_move[i].value = rand() % 20+1;//1부터 20까지 랜덤한 수 입력
		
	

		cout<< "value :"<<_move[i].value;//입력된수 출력
		cout<<"  |  ";//구분짓기위해 간격을 둠
		_move[i].parent_move = p_move ; //부모노드 주소 입력
		cout<<"P_add:"<< _move[i].parent_move<<"  ";
		_move[i].headChild_move=NULL;

		if (i==0) // 첫번째 후계 노드이면 부모노드로 찾아가 자기 주소를 입력하고 자식노드에ptail 을 연결. 
		{
			p_move->headChild_move = &_move[i];
			
			node* ptail = new _node;
			ptail->headChild_move = NULL;
			_move[i].sister_move = ptail;
			_move[i].headChild_move=NULL;

		}

		if (i ==index-1) //형제노드의 막내이면 tail 연결
		{
			node* tail = new _node;

			tail->sister_move = NULL;
			tail->parent_move = NULL;
			tail->headChild_move = NULL;

			_move[i].sister_move = tail;
			
		}

		else //형제노드 주소 입력
		{
			_move[i].sister_move = &_move[i+1];

		}
		cout<<"M_add:"<< &_move[i]<<"  ";
		cout<<"S_add:"<< _move[i].sister_move<<"  ";
		cout<<endl;
	}
	if (p_move->depth<LIMIT)
	{
		//각각에 대하여 또뻣어주기
		for (int i = 0 ; i <index ; i++)
		{	
			GenerateMoves(&_move[i]);
		}
	}
}

node *get_endNode(node *move)// 최하단 노드의 주소값 반환하는 함수.
{
	node* endNode = new _node;
	endNode = move;
	while (endNode->headChild_move!=NULL)
	{
		endNode = endNode->headChild_move;
		cout<<"거치는 주소:"<<endNode<<endl;
	}
	
		cout <<"반환될 주소:";
		cout<< endNode<<endl;
		return endNode;
	
}