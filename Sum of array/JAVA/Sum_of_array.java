import java.util.Arrays;
import java.util.concurrent.Semaphore;

public class Sum_of_array {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		int [] arr= {1,2,3,4,5,6,7,8};
		
		System.out.println(Arrays.toString(arr));
		sumbyindex(arr);
		System.out.println(Arrays.toString(arr));
	}

	private static void sumbyindex(int[] arr) {
		
		Semaphore [] sem =new Semaphore[arr.length];
		Args [] args =new Args[arr.length];
		Thread [] threads =new Thread[arr.length];
		
		for (int i = 0; i < sem.length; i++) {
			sem[i]=new Semaphore((i == sem.length - 1)?1:0);
		}
		for (int i = 0; i < sem.length; i++) {
			args[i]=new Args(i,sem,arr);
			threads[i] = new Thread(new MyRunnableTask(args[i]));
			threads[i].start();
		}
		for (int i = 0; i < threads.length; i++) {
			try {
				threads[i].join();
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
