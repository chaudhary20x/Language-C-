#include<iostream>
using namespace std;
struct Node {
    int data;
    Node* left;
    Node* right;
};
class stack{
	int top;
	public:
		char a[60];
		string c[60];
		stack(){top=-1;};
		bool empty();
		bool push(char x);
		string push(string x);
		char pop();
		string pk();
		char peak();
};
class Queue {
public:
    int front, rear, size;
    unsigned capacity;
    char* array;
    string* arr;
    int full();
    int empty();
   char enqueue(char);
   string enq(string);
   char dequeue();
   char frnt();
   char rea();
   char d();
   string back();
   
};
Queue* createQueue(unsigned cap)
{
    Queue* queue = new Queue();
    queue->capacity = cap;
    queue->front = queue->size = 0;
    queue->rear = queue->capacity - 1;
    queue->array = new char[queue->capacity];
    queue->arr=new string[queue->capacity];
    return queue;
}
int Queue::full()
{
    return (size == capacity);
}
int Queue::empty()
{
    return (size == 0);
}
char Queue::enqueue(char item)
{
    if (full()){
    	return false;
	}
     
     rear = (rear + 1)
                  % capacity;
    array[rear] = item;
    size = size + 1;
    return item;
}
string Queue::enq(string item)
{
    if (full()){
    	return 0;
	}
     
     rear = (rear + 1)
                  % capacity;
    arr[rear] = item;
    size = size + 1;
    return item;
}

char Queue::dequeue()
{
    if (empty()){
	
        return false; 
    }
    char item =array[front];
    front = (front + 1)
                   % capacity;
    size =size - 1;
    return item;
}
char Queue::d(){
	 if (empty())
        return false;
    char item = array[rear];
   rear = (rear - 1)
                   % capacity;
    size =size - 1;
    return item;
}
char Queue::frnt()
{
    if (empty())
        return false;
    return array[front];
}
char Queue::rea()
{
    if (empty())
        return false;
    return array[rear];
}
string Queue::back()
{
    if (empty())
        return 0;
    return arr[rear];
}
string stack::pk(){
	if(top<0){
		return 0;
	}
	else{
		string k;
		k=c[top];
		return k;
	}
}
char stack::peak(){
	if(top<0){
		return 0;
	}
	else
	{
		char x;
		x=a[top];
		return x;
	}
}
char stack::pop(){
	if(top<0){
		return 0;
	}
	else {
		char x;
		x=a[top--];
		return x;
	}
}
 bool stack::empty(){
  return (top<0);
 }
 string stack::push(string x){
 	if(top>=60-1){
 		return 0;
	 }
	 else{
	 	c[++top]=x;
	 	return x;
	 }
 }
 bool stack::push(char x){
 	if(top>=60-1){
 		return false;
	 }
	 else {
	 	a[++top]=x;
	 	return x;
	 }
 }
bool isop(char c){
	 return (!isalpha(c) && !isdigit(c));

}
bool iopa(char c){
	return (isalpha(c));
}
int pc(char c){
	if(c=='^')
	return 3;
	else if(c=='/'||c=='*')
	return 2;
	else if (c=='+'||c=='-')
	return 1;
	else 
	return 0;
}
string rev(string arr,int l)
{

 string s="";
 for(int i=l-1;i>=0;i--){
 	s+=arr[i];
 }
 return s;
}
bool opd(char x){
	switch(x){
		case '+':
		case '-':
		case '/':
		case '*':
		return true;
	}
	return false;
} 
string inpost(string s){
	class stack  st;
	string store;
	for(int i=0;i<s.length();i++){
		char c=s[i];
		if(isalpha(c)||isdigit(c)){
			store+=c;
		}
		else if(c=='(')
			st.push('(');	
		else if(c==')'){
			while(st.peak()!='('){
				store += st.peak();
				st.pop();
			}
			st.pop();
		}
		else {
			if(isop){
			
				while(!st.empty()&&pc(s[i])<=pc(st.peak())){
					store+=st.peak();
					st.pop();
				}
				st.push(c);
		 }
		}
		
}
while(!st.empty()){
	store+=st.peak();
	st.pop();
}
return store;
//cout<<store<<endl;
} 
string inpre(string s){
	int l = s.size();
	     rev(s,l);
	for(int i=0;i<l;i++){
		if(s[i]=='('){
		    s[i]=')';
		}
		else if (s[i]==')'){
			s[i]=='(';
		}
	}
	string prefix=inpost(s);
	return rev(prefix,l);
}
string postin(string ex)
{
    class stack s;
 
    for (int i=0; ex[i]!='\0'; i++)
    {
        if (iopa(ex[i]))
        {
           string op(1, ex[i]);
           s.push(op);
        } 
        else
        {
            string c1 = s.pk();
            s.pop();
            string c2 = s.pk();
            s.pop();
            s.push("(" + c2 + ex[i] +
                   c1 + ")");
        }
    }
    return s.pk();
}
string postpre(string s){
	class stack ha;
	int l=s.size();
	for(int i=0;i<l;i++){
		if(opd(s[i])){
			string c1=ha.pk();
			ha.pop();
			string c2=ha.pk();
			ha.pop();
			string temp=s[i]+c2+c1;
			ha.push(temp);
		}
		else{
			ha.push(string(1,s[i]));
		}
	}
	string prefix="";
	while(!ha.empty()){
		prefix+=ha.pk();
		ha.pop();
	}
	return prefix;
}
string prein(string x){
	class stack ja;
	int l=x.size();
	for(int i=l-1;i>=0;i--){
		if(opd(x[i])){
			string c1=ja.pk();
			ja.pop();
			string c2=ja.pk();
			ja.pop();
			string temp="("+c1+x[i]+c2+")";
			ja.push(temp);
			
		}
		else{
			ja.push(string(1,x[i]));
		}
	}
	return ja.pk();
}
string prepost(string x){
	class stack sa;
	int l=x.length();
	for(int i=l-1;i>=0;i--){
		if(opd(x[i])){
			string h1=sa.pk();
			sa.pop();
			string h2=sa.pk();
			sa.pop();
			string temp=h1+h2+x[i];
			sa.push(temp);
		}
		else
		{
			sa.push(string(1,x[i]));
		}
		
	}
	return sa.pk();
}
//fuctions of Queue ::
string infixpost(string s){
 class Queue* st = createQueue(100);
	string store;
	for(int i=0;i<s.size();i++){
		char c=s[i];
		if(isalpha(c)||isdigit(c)){
			store+=c;
		}
		else if(c=='(')
			st->enqueue(c);	
		else if(c==')'){
			while(st->rea()!='('){
				store += st->rea();
				st->d();
			}
			st->d();
		}
		else {
			if(isop){
			
				while(!st->empty()&&pc(s[i])<=pc(st->rea())){
					store+=st->rea();
					st->d();
				}
				st->enqueue(c);
		 }
		}
		
}
while(!st->empty()){
	store+=st->rea();
	st->d();
}

//cout<<store<<endl;
return store;
}
string infixpre(string s){
	int l = s.size();
	     rev(s,l);
	for(int i=0;i<l;i++){
		if(s[i]=='('){
		    s[i]=')';
		}
		else if (s[i]==')'){
			s[i]=='(';
		}
	}
	string prefix=infixpost(s);
	return rev(prefix,l);
}
string postinfix(string ex)
{
  class Queue* s =createQueue(1000);
    for (int i=0; ex[i]!='\0'; i++)
    {
        if (iopa(ex[i]))
        {
        	string op(1,ex[i]);
           //string op(1, ex[i]);
           s->enq(op);
        } 
        else
        {
        	
            string c1 = s->back();
            s->d();
            string c2 = s->back();
             s->d();
            s->enq("(" + c2 + ex[i] +
                   c1 + ")");
        }
    }
    return s->back();
}
string postprefix(string s){
class Queue* u =createQueue(1000);
	int l=s.size();
	for(int i=0;i<l;i++){
		if(opd(s[i])){
			string c1=u->back();
		u->d();
			string c2=u->back();
			u->d();
			string temp=s[i]+c2+c1;
			u->enq(temp);
		}
		else{
			u->enq(string(1,s[i]));
		}
	}
	string prefix="";
	while(!u->empty()){
		prefix+=u->back();
		u->d();
	}
	return prefix;
}
string preinfix(string x){
	class Queue* ja = createQueue(100);
	int l=x.size();
	for(int i=l-1;i>=0;i--){
		if(opd(x[i])){
			string c1=ja->back();
			ja->d();
			string c2=ja->back();
			ja->d();
			string temp="("+c1+x[i]+c2+")";
			ja->enq(temp);
			
		}
		else{
			ja->enq(string(1,x[i]));
		}
	}
	return ja->back();
}
string prefixpost(string x){
	class Queue* sa =createQueue(1000);
	int l=x.length();
	for(int i=l-1;i>=0;i--){
		if(opd(x[i])){
			string h1=sa->back();
			sa->d();
			string h2=sa->back();
			sa->d();
			string temp=h1+h2+x[i];
			sa->enq(temp);
		}
		else
		{
			sa->enq(string(1,x[i]));
		}
		
	}
	return sa->back();
} 
Node* CreateNode(int data)
{
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Memory error\n";
        return NULL;
    }
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}
Node* InsertNode(Node* root, int data)
{
    if (root == NULL) {
        root = CreateNode(data);
        return root;
    }
      /*queue<Node*> q;
    q.push(root);
   while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
 
        if (temp->left != NULL)
            q.push(temp->left);
        else {
            temp->left = CreateNode(data);
            return root;
        }
 
        if (temp->right != NULL)
            q.push(temp->right);
        else {
            temp->right = CreateNode(data);
            return root;
        }
    }
    */
}
void inorder(Node* temp)
{
    if (temp == NULL)
        return;
 
    inorder(temp->left);
    cout << temp->data << ' ';
    inorder(temp->right);
}
void preorder(Node* temp){
    if (temp == NULL)
        return;
 	
   cout << temp->data << ' ';	
	 inorder(temp->left);
	 inorder(temp->right);
}
void postorder(Node* temp){
    if (temp == NULL)
        return;
 	
  	
	 inorder(temp->left);
	 inorder(temp->right);
	  cout << temp->data << ' ';
}
int main()
{
	int a;
	int c;
    string p;
    cout<<"PLease select your desire data structure \n 1-Stack\n 2-Queue \n 3-Tree \n";
    cin>>a;
    while(true){
    	if(a==1){
		
    cout<<"Welcome to stack conversion system .Please choose your desire Input expression type.\n 1. Infix expression \n   2. prefix expression \n    3. postfix expression "<<endl;
    cin>>c;
     cout<<"Enter expression"<<endl;
    cin>>p;
       
      	if(c==1){
    		cout<<"The other 2 Expressions are : "<<endl;
    		cout<<"Postfix  "<<inpost(p)<<endl;
    		cout<<"Prefix   "<<inpre(p)<<endl;
    	
		}
		else if(c==2){
			cout<<"The other 2 Expressions are : "<<endl;
			cout<<"Postfix  "<<prepost(p)<<endl;
			cout<<"Infix    "<<prein(p)<<endl;
		}
		else if(c==3){
			cout<<"The other 2 Expressions are : "<<endl;
			cout<<"Infix  "<<postin(p)<<endl;
			cout<<"Prefix "<<postpre(p)<<endl;
			
		}
	  else 
	     break;
	}
	else if(a==2){
			
    cout<<"Welcome to Queue conversion system .Please choose your desire Input expression type.\n 1. Infix expression \n   2. prefix expression \n    3. postfix expression "<<endl;
    cin>>c;
     cout<<"Enter expression"<<endl;
    cin>>p;
    
    	if(c==1){
    		cout<<"The other 2 Expressions are : "<<endl;
    		cout<<"Postfix  "<<infixpost(p)<<endl;
    		cout<<"Prefix   "<<infixpre(p)<<endl;
    	
		}
		else if(c==2){
			cout<<"The other 2 Expressions are : "<<endl;
			cout<<"Postfix  "<<prepost(p)<<endl;
			cout<<"Infix    "<<preinfix(p)<<endl;
		}
		else if(c==3){
			cout<<"The other 2 Expressions are : "<<endl;
			cout<<"Infix  "<<postinfix(p)<<endl;
			cout<<"Prefix "<<postprefix(p)<<endl;
			
		}
		else
		  break;
	}
	else if(a==3){
		cout<<"tree is not done yet try another expressions ";
	}
	else 
	break;
	}
	
/*string b="a+b+c";
cout<<infixpost(b);
string c="a+b/c";
cout<<"\n"<<infixpre(c)<<endl;
string p="abc/+";
cout<<"\n"<<postinfix(p)<<endl;
string d="abc/+";
cout<<"\n"<<postprefix(d)<<endl;
string o="+gp";
cout<<"\n"<<preinfix(o)<<endl;
string y="+gp";
cout<<"\n"<<prefixpost(y)<<endl;*/
	return 0;
}

