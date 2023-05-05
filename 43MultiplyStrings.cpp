class Solution {
    
    short charToInt(char c){
	return c - '0';
    }

    string multiStringChar(const string& s, const char c){
    	string resualt;
    	char temp = 0;
    	char ic = charToInt(c);
    	for(int i = s.size()-1;i >= 0; i--){
    		resualt += to_string((charToInt(s[i]) * ic + temp) % 10);

		    temp = ((charToInt(s[i]) * ic + temp) / 10);    
    	}
	    if(temp) resualt += to_string(temp);
	    reverse(resualt.begin(),resualt.end());
	    return resualt;
    }


    string addTowString(const string& s1, const string& s2){
	    string resualt;
	    if (s1.size()<s2.size()) return addTowString(s2, s1);
	    int s1_size = s1.size();
	    int s2_size = s2.size();
	    char temp=0;
	    for(int i=1;i<=s1_size;i++){
	    	if(i <= s2_size){
		    	resualt += to_string((charToInt(s1[s1_size-i])+charToInt(s2[s2_size-i]+temp))%10);
			temp = (charToInt(s1[s1_size-i])+charToInt(s2[s2_size-i]+temp))/10;
			
	    	}else{
		    	resualt += to_string((charToInt(s1[s1_size-i])+temp)%10);
			    temp = (charToInt(s1[s1_size-i])+temp)/10;
			
		    }
        }
        if(temp) resualt += to_string(temp);
    	reverse(resualt.begin(),resualt.end());
    	return resualt;	
    }


  
    
public:
    string multiply(string s1, string s2) {
     
	    int s2_size = s2.size();
	
	    string resualt;
	    string temp;
        
	    for(int j=1;j<=s2_size;j++){
		
		    temp = multiStringChar(s1,(s2[s2_size-j]));
		    temp.append(j-1,'0');
			resualt = addTowString(temp,resualt);
		
		
	    }
		
	    if(resualt[0]=='0') return "0";
	    return resualt;
        
    }
};