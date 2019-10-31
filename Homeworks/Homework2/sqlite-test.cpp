#include <iostream>
#include <sqlite3.h>

using namespace std;

int main(){

	sqlite3 *db;
	char *zErrMsg = 0;
	int rc;

	rc = sqlite3_open("schema.sqlite", &db);

	if (rc) {
		cerr<<"cant open db:"<<sqlite3_errmsg(db)<<endl;
		return(0);
	} else {
		cerr<<"db opened"<<endl;
	}
	sqlite3_close(db);
}
