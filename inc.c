#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
struct node{
char data;
struct node *llink,*rlink;
};
struct stack{
	char data;
	struct stack *link;
	};
struct stacki{
	int data;
	struct stacki *link;
	};
struct stacki *topi=NULL;
struct stack *top=NULL;
struct node *start=NULL , *end=NULL;
int count=0,itemno=0;
char input[20];
char readsymbol();
char pop()
void push(char a);
void op(char a);
int isp(char a);
int icp(char a);
void display();
void evaluate();
//void push(char a);//
int pop();
void main(){
int i;
char x,item;
printf("Enter the expression");
scanf("%s",input);
for(i=0;input[i]!='\0';i++)
{
count++;
input[count]=")";
push("(");
while(top!=NULL){
item=readsymbol();
x=pop();
if(item!="+" && item!="-" && item!="*" && item!="/" && item!="^" && item!="(" && item!=")")
{
op(item);
push(x);
else if (item=="("){
while(x!=")"){
op(x);
x=pop();
push(x);
push(item);
else if(isp(x)>=icp(item)){
while(isp(x)>=icp(item)){
op(x);
x=pop();
}
push(x);
push(item);
}
else if(isp(x)<icp(item)){
push(x);
push(item);
display();
evaluate();
void push(char a){
struct stack* new;
new=(struct stack *) malloc(1*sizeof(struct stack));
new->link=top;
new->data=NULL;
top=new;
}
char pop(){
struct stack* temp;
if(top->link==NULL){
temp=top;
top=NULL;
char x=temp->data;
free(temp);
return x;
}
else{
temp=top;
top=top->link;
char x=tmp->data;
free(temp);
return x;
}
}
char readsymbol(){
char x=input[itemno];
itemno++;
return x;
}
void op(char a){
struct node * new =(struct node*)malloc(1*sizeof(struct node));
if(start==NULL){
new->rlink=NULL;
new->llink=NULL;
new->data=a;
start=new;
end=new;
}
else{
struct node * new =(struct node*)malloc(1*sizeof(struct node));
new->data=a;
end->rlink=new;
new->link=end;
end=new;
end->rlink=NULL;
}
}
int isp(char a){
switch(a){
	case '^':return 3;
		 break;
	case '*':return 2;
		 break;
	case '/':return 2;
		 break;	 	 
	case '+':return 1;
		 break;
	case '-':return 1;
		 break;
	case '(':return 0;
		 break;
	default: break;
	}
	}
int icp(char a){
switch(a){
	case '^':return 4;
		 break;
	case '*':return 2;
		 break;
	case '/':return 2;
		 break;	 	 
	case '+':return 1;
		 break;
	case '-':return 1;
		 break;
	case '(':return 4;
		 break;
	default: break;
	}
	}
void display(){
struct node * temp;
temp=start;
printf("\n");
int i=0;
while(temp->rlink!=NULL){
input[i]=temp->data;
temp=temp->rlink;
i++}
input[i]=temp->data;
input[i+1]='#';
input[i+2]='\0';
printf("\n operator \t arg1 \t arg2 \t result");
}
void evaluate(){
itemno=0;
char item;
char y,z,i,t;
char name='1';
int j,k;
item=readsymbol();
while(item!='#'){
if(item!="+" && item!="-" && item!="*" && item!="/" && item!="^" && item!="(" && item!=")"){
push(item);
item=readsymbol();
}
else{
y=pop();
z=pop();
if(isdigit(z)){
printf("\t%c",z);
}
else{
printf("%c\t",z);
}
if(isdigit(y)){
printf("\t%c",y);
}
else{
printf("%c\t",y);
printf("%c\n",name);

}
push(name++);
for(j=itemno;input[j]!='#';j++){
if((input[j]==item && input[j-1]==y && input[j-2]==z) || (input[j]==item && input[j-1]==z && input[j-2]==y && item!='/' ))
{
input[j-2]= name-1;
for(k=j-1;k>=j-2;k++){
input[k]=input[k+2];
if (input[k]=='#'){
break;
}
}
}
}
item=readsymbol();
}
}
}
