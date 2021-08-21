import java.util.Scanner;
public class Main {
	
	public static void main (String [] args) {
		
		Scanner scanner = new Scanner(System.in);
		int loofNum = scanner.nextInt();
		int arr [] = new int [loofNum];
		
		for (int i = 0; i<loofNum; i++ )
			arr[i] = scanner.nextInt();
		
		int checkTrue = 0; 
		int tmp = 0;
		
		while (true) {
			
			for (int i = 0; i <loofNum-1; i++) {
				if (arr[i] > arr[i+1]) {
					tmp = arr[i+1];
					arr[i+1] = arr[i];
					arr[i] = tmp;
				} else checkTrue++;
			}
			
			if (checkTrue == loofNum -1) break;
			
			checkTrue = 0;
		}
		
		for (int i = 0; i < loofNum; i++)
			System.out.println(arr[i]);

	}
}
	


