#include "main.h"
#include "iostream"
#include "user.h"

using namespace std;

void mainMsg(){
	cout<<"message from main"<<endl;
	userMsg();
}


int main(){
	mainMsg();
	getchar();
	return 0;
}
