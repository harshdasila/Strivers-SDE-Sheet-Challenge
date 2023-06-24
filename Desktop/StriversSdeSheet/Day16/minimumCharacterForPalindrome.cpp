
int minCharsforPalindrome(string str) {
	int n =str.size();
	int i=0,j=n-1,trim=j,res=0;
	while(i<j){
		if(str[i]==str[j]){
			i++;
			j--;
		}
		else{
			i=0;
			j=--trim;
			res++;
		}
	}
	return res;
	
}
