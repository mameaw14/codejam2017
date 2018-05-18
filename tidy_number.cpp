#include <stdio.h>
#include <string.h>
main() {
	int T,i;
	char str[20];
	bool chg;
	scanf("%d", &T);
	int tc = T;
	while(T--) {
		scanf("%s",str);
		i = strlen(str)-1;
		while(i>0) {
			// printf("%c %c\n",str[i-1],str[i]);
			if(str[i]<str[i-1]) {
				str[i] = '9';
				str[i-1]--;
			}
			// printf("%c %c\n",str[i-1],str[i]);
			i--;
		}
		bool print = false;
		bool nine = false;
		printf("Case #%d: ", tc-T);
		while(i<strlen(str)){
			if(str[i]!='0') {
				print = true;
			}
			if(str[i] == '9') nine = true;
			if(print){
				if(nine) printf("9");
				else printf("%c", str[i]);
			}
			i++;
		}
		printf("\n");
	}
}