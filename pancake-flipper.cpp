#include <stdio.h>
#include <string.h>
main() {
	int tc,T,k;
	char s[1002];
	scanf("%d",&T);
	tc=T;
	while(T--){
		int count = 0;
		scanf("%s %d",s,&k);
		int i = 0;
		while(i < strlen(s)-k+1) {
			if(s[i]=='-') {
				count++;
				int j = 0;
				while(j<k) {
					s[i+j] = (s[i+j]=='-')? '+':'-';
					j++;
				}
			}
			i++;
		}
		bool fail = false;
		while(i<strlen(s)) {
			if(s[i]=='-') {
				fail = true;
				break;
			}
			i++;
		}
		if(!fail) printf("case #%d: %d\n", tc-T,count);
		else printf("case #%d: IMPOSSIBLE\n", tc-T);
	}
}