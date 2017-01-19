/*******************************************************/
/* UVa 787 - Maximum Sub-sequence Product              */
/* Version: 2015/02/10                                 */
/* 想法：硬做就好了，直接枚舉左右界                    */
/*					 大數會爆炸所以用java              */
/*******************************************************/
import java.math.BigInteger;
import java.util.Scanner;


public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner scanner = new Scanner(System.in);
		int[] A = new int[105];
		int n, i, j;
		while(scanner.hasNext()) {
			n = 0;
			while(scanner.hasNextInt()) {
				A[n] = scanner.nextInt();
				if(A[n] == -999999)
					break;
				n++;
			}
			BigInteger ans = BigInteger.valueOf(A[0]);
			BigInteger tmp;
			
			for(i = 0; i < n; i++) {
				tmp = new BigInteger("1");
				for(j = i; j < n; j++) {
					tmp = tmp.multiply(BigInteger.valueOf(A[j]));
					ans = tmp.max(ans);
				}
				
			}
			System.out.println(ans);
		}
	}

}
