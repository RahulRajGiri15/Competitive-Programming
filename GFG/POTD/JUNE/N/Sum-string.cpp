///Sum-string

///////class Solution {
  public:
    string add_strings(string &str1,string &str2)
    {
        if(str1.length()<str2.length())
        {
            swap(str1,str2);
        }
        
        int len1=str1.length();
        int len2=str2.length();
        int carry=0;
        string sum="";
        
        for(int i=0;i<len2;i++)
        {
            int num1=str1[len1-i-1] - '0';
            int num2=str2[len2-i-1] - '0';
            int digit=(num1+num2+carry)%10;
            carry=(num1+num2+carry)/10;
            sum=char(digit+'0') + sum;
        }
        
        for(int i=len2;i<len1;i++)
        {
            int num1=str1[len1-i-1] - '0';
            int digit=(num1+carry)%10;
            carry=(num1+carry)/10;
            sum=char(digit+'0') + sum;
        }
        
        if (carry) 
        {
            sum = char(carry + '0') + sum;
        }
        
        return sum;
    }
    bool check(string s,int start,int len1, int len2)
    {
        string str1=s.substr(start,len1);
        string str2=s.substr(start+len1,len2);
        string ans_sum=add_strings(str1,str2);
        int ans_len=ans_sum.length();
        
        if(start+len1+len2+ans_len > s.length())return false;
        
        if(ans_sum == s.substr(start+len1+len2,ans_len))
        {
            if(start+len1+len2+ans_len == s.length())return true;
            
            return check(s,start+len1,len2,ans_len);
        }
        return false;
    }
    bool isSumString(string &s) {
        int n=s.length();
        
        for(int l1=1;l1<n;l1++)
        {
            for(int l2=1;l1+l2<n;l2++)
            {
                if(check(s,0,l1,l2))
                {
                    return true;
                }
            }
        }
        return false;
    }
};