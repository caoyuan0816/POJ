/**
 * @author Yuan
 */

package Poj;

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		
		Scanner cin = new Scanner(System.in);
		
		while(cin.hasNext())
		{
			BigInteger a = cin.nextBigInteger();
			BigInteger b = cin.nextBigInteger();
			
			if(a.equals(BigInteger.ZERO) && b.equals(BigInteger.ZERO))
				break;
			
			BigInteger c = a.subtract(b);
			BigInteger d = a;
			BigInteger use1 = BigInteger.ONE;
			BigInteger use2 = BigInteger.ONE;
					
			while(!d.equals(c)){
				use1=use1.multiply(d);
				d=d.subtract(BigInteger.ONE);
			}
			
			d=b;
			
			while(!d.equals(BigInteger.ONE)){
				use2=use2.multiply(d);
				d=d.subtract(BigInteger.ONE);
			}
			
			System.out.println(use1.divide(use2));
			
		}

	}

}
