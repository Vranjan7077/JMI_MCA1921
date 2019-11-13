//import java.util.scanner;
class Main 
{
    	public static void main(String[] args) 
    	{
        	Main test = new Main();
         	boolean bool = test.checkpalindrome("abaaa");
        	if(!bool)
            		System.out.println("String is not palindrome");
    	}
    	private boolean checkpalindrome(String k)
    	{
        	int[] count= new int[k.length()];
        	boolean[] arr = new boolean[k.length()];
        	for(int t=0;t<k.length();t++)
        	{
            		int j=0;
            		char ch = k.charAt(t);
            		for(int x=t+1;x<k.length();x++)
            		{
        			if(j<count.length)
        			{
            	    			if(ch == k.charAt(x))
                				count[j] = x + 1;
                			else
                    				count[j] = 0;
                			j++;
            			}
            		}
            		arr[t] = workOnArr(count,t,k);
        	}
        	for(int z=0;z<arr.length;z++)
        	{
            	if(arr[z])
                	return true;
        	}
        	return false;
    	}
	private boolean workOnArr(int[] s,int z,String w)
	{
    		int j = s.length - 1; 
    		while(j -- > 0){
        	if(s[j] != 0)
        	{
            		if(ispalindrome(w.substring(z, s[j])))
            		{
                		if(w.substring(z, s[j]).length() > 1)
                		{
                    			System.out.println(w.substring(z, s[j]).length());
                    			System.out.println(w.substring(z, s[j]));
                		}
                		return true;
            		}
        	}
		}
		return false;
    	}
	private boolean ispalindrome(String s)
	{
    		int j= s.length() -1;
    		for(int i=0;i<s.length()/2;i++)
    		{
        		if(s.charAt(i) != s.charAt(j))
            			return false;
            		j--;
    		}
    		return true;
	}
}
