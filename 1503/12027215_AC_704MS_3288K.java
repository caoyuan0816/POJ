import java.io.*;
import java.util.*;
import java.math.*;
import java.text.*;

public class Main {

	public static void main(String[] args) {
		
		Scanner cin=new Scanner(new BufferedInputStream(System.in));
		
		BigInteger a = cin.nextBigInteger();
		
		while(cin.hasNext()){
			
			BigInteger b = cin.nextBigInteger();
			a=a.add(b);
		}
		System.out.println(a);
	}
}
