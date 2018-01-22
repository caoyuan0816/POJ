import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		
		while(cin.hasNext()){
			
			BigDecimal a = cin.nextBigDecimal();
			BigDecimal c = BigDecimal.valueOf(1.0);
			int b = cin.nextInt();
			int i;
			
			for(i=0;i<b;i++){
				c=c.multiply(a);
			}
			
			String ans = new String(c.toPlainString());
			
			int q=ans.length()-1;
			int p=0;
			while(ans.charAt(q)=='0')q--;
			if(ans.charAt(q)=='.')q--;
			
			while(ans.charAt(p)=='0')p++;
			for(i=p;i<=q;i++){
				System.out.print(ans.charAt(i));
			}		
			System.out.println();
		}
	}
}

